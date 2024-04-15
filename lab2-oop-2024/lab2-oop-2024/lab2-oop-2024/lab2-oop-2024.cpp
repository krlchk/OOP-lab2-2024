#include <iostream>
#include "SinglyLinkedList.h"
#include "ListPrinter.h"
#include "Iterator.h"
#include "BubbleSortStrategy.h"

using namespace std;

int main()
{
    SinglyLinkedList<int> lst;
    lst.subscribe(new ListPrinter<int>);
    lst.pushBack(30);
    lst.pushFront(60);
    lst.pushBack(10);
    lst.pushFront(40);
    lst.pushBack(50);
    lst.pushFront(20);
    lst.changeSortStrategy(new BubbleSortStrategy<int>);
    lst.sort();
    lst.popBack();
    lst.popFront();
}
