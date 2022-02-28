#include "skiplist.h"

int main()
{
    SkipList skiplist(10, 0.618);
    skiplist.insertElem(1);
    skiplist.insertElem(3);
    skiplist.deleteElem(1);
    skiplist.insertElem(5);
    skiplist.searchElem(5);
    skiplist.searchElem(6);
    skiplist.insertElem(7);
    skiplist.displayList();
    skiplist.insertElem(9);
    skiplist.insertElem(11);
    skiplist.insertElem(13);
    skiplist.displayList();
    skiplist.insertElem(15);
    skiplist.displayList();
}