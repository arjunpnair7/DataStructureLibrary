#include <iostream>
#include "LinkedList.h"

int main() {

    LinkedList<int> *list = new LinkedList<int>();

    

    list -> insert_at_tail(57);
    list -> insert_at_tail(67);

    list -> insert_at_head(7);
    list -> insert_at_head(17);
    list -> insert_at_head(27);
    list -> insert_at_head(37);
    list -> insert_at_head(47);

    list -> insert_after(list->get_list_head() -> next, -7);


    std::cout << (*list) << std::endl;
    std::cout << "List size: " << (*list).get_size() << std::endl;
}