#include <iostream>
#include "logic/includes/LinkedList.h"

int main(int, char**) {
    LinkedList<int> *l = new LinkedList<int>;

    int *a = new int(4);
    int *b = new int(3);
    int *c = new int(2);
    int *d = new int(1);

    l->add(a);
    l->add(b);
    l->add(c);
    l->add(d);

    l->display();

    return 0;
}
