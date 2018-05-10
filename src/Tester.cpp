#include <iostream>
#include "LinkList.h"

void main()
{
    linkList<int> tester;
    tester.pushBack(1);
    tester.pushBack(2);
    tester.pushBack(3);
    tester.pushFront(4);
    tester.popBack();

    linkList<int> tester2 = tester;
    tester2.pushFront(3);

    tester.printList();
    tester2.printList();
    const linkList<int> tester3 = tester;
    tester3.printList();
}