#include <iostream>
#include "LinkedList.h"

int main() {

    LinkedList<int> *list = new LinkedList<int>();

    list -> insert_at_head(7);
    list -> insert_at_head(17);
    list -> insert_at_head(27);
    list -> insert_at_head(37);
    list -> insert_at_head(47);

    std::cout << (*list) << std::endl;
}