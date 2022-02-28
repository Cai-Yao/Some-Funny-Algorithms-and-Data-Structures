#include "skiplist.h"
#include <random>

int SkipList::randomLevel() {
    float r = (float)rand() / RAND_MAX;
    int level = 0;
    while (r < P && level < MAXLEVEL) {
        level ++;
        r = (float)rand() / RAND_MAX;
    }
    return level;
}

Node* SkipList::creatNode(int key, int level) {
    Node *node = new Node(key, level);
    return node;
}

void SkipList::insertElem(int key) {
    Node *current = header;
    Node **update = new Node*[MAXLEVEL + 1];

    for (int i = level; i >= 0; i--) {
        while (current->forward[i] != nullptr && current->forward[i]->key < key) {
            current = current->forward[i];
        }
        update[i] = current;
    }

    current = current->forward[0];
    if (current == nullptr || current->key != key) {
        int new_level = randomLevel();
        if (new_level > level) {
            for (int i = level + 1; i < new_level + 1; i++) {
                update[i] = header;
            }
            level = new_level;
        }
        Node *node = creatNode(key, new_level);
        for (int i = 0; i <= new_level; i++) {
            node->forward[i] = update[i]->forward[i];
            update[i]->forward[i] = node;
        }

        printf("Successfully Insert Element, key is %d \n", key);
    }
    else {
        printf("Unsuccessfully Insert Element, key is %d \n", key);
    }

    delete[] update;
    
}

void SkipList::deleteElem(int key) {
    Node *current = header;
    Node **update = new Node*[MAXLEVEL + 1];;

    for (int i = level; i >= 0; i--) {
        while (current->forward[i] != nullptr && current->forward[i]->key < key) {
            current = current->forward[i];
        }
        update[i] = current;
    }

    current = current->forward[0];

    if (current == nullptr || current->key != key) {
        printf("Unsuccessfully Delete Element. No found the Element, key is %d \n", key);
    }
    else {
        for (int i = 0; i <= level; i++) {
            if (update[i]->forward[i] != current)
                break;
            update[i]->forward[i] = current->forward[i];
        }

        while (level > 0 && header->forward[level] == nullptr) 
            level--;

        printf("Successfully Delete Element, key is %d \n", key);
    }

    delete[] update;
}

void SkipList::searchElem(int key) {
    Node *current = header;

    for (int i = level; i >= 0; i--) {
        while (current->forward[i] != nullptr && current->forward[i]->key < key) {
            current = current->forward[i];
        }
    }

    current = current->forward[0];

    if (current != nullptr && current->key == key) {
        printf("Successfully search Element, key is %d \n", key);
    }
    else {
        printf("Unsuccessfully search Element, key is %d \n", key);
    }
}

void SkipList::displayList() {

    for (int i = level; i >= 0; i--) {
        Node *current = header->forward[i];
        while (current != nullptr) {
            printf("%d", current->key);
            current = current->forward[i];
            if (current != nullptr)
                printf(" -> ");
        }
        printf("\n");
    }
    
}