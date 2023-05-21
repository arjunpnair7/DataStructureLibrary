#include "Node.h"

template <typename T> 
class LinkedList {
    private:
        Node<T> *fake_head;
        Node<T> *fake_tail;


    public:
        LinkedList();
        void insert_at_head(T val);

        friend std::ostream & operator<<(std::ostream & _stream, LinkedList<T>& mc) {
            Node<T> *start = mc.fake_head -> next;
            while (start != nullptr) {
                _stream << start -> data << std::endl;
                start = start -> next;
            }
            return _stream;
        }
};

template <typename T> 
LinkedList<T>::LinkedList() {
    fake_head = new Node<T>();
    fake_tail = new Node<T>();

    fake_head -> next = fake_tail;
    fake_tail -> prev = fake_head;
}

template <typename T>
void LinkedList<T>::insert_at_head(T val) {
    Node<T> *new_node = new Node<T>(val);
    Node<T> *temp = fake_head -> next;

    new_node -> next = temp;
    new_node -> prev = fake_head;

    fake_head -> next = new_node;
    temp -> prev = new_node;
}

