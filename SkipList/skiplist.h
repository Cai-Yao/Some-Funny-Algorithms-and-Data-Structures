#ifndef __SKIPLIST_H__
#define __SKIPLIST_H__

#include <cstring>

class Node
{
public:
    int key;
    Node **forward;
public:
    Node(int key, int level) {
        this->key = key;
        forward = new Node*[level + 1];
        memset(forward, 0 ,sizeof(Node*) * (level + 1));
    }
    ~Node() {
        delete[] forward;
    }

};


class SkipList
{
private:
    int MAXLEVEL;
    float P;
    int level;
    Node* header;
    int randomLevel();
    Node* creatNode(int key, int level);

public:
    SkipList(int max_level, float p) : MAXLEVEL(max_level), P(p), level(0) {
        header = new Node(-1, MAXLEVEL);
    }
    ~SkipList() {
        delete header;
    }
    
    void insertElem(int key);
    void deleteElem(int key);
    void searchElem(int key);
    void displayList();
};

#endif


