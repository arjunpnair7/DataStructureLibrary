#include "Node.h"

template <typename T> 
class LinkedList {
    private:
        Node<T> *fake_head;
        Node<T> *fake_tail;
        size_t size;

    public:
        LinkedList();
        void insert_at_head(T val);
        void insert_at_tail(T val);
        Node<T> *get_list_head();
        Node<T> *get_list_tail();
        void insert_after(Node<T> *prev, T val);
        size_t get_size();

        friend std::ostream & operator<<(std::ostream & _stream, LinkedList<T>& mc) {
            Node<T> *start = mc.fake_head -> next;
            while (start != mc.fake_tail) {
                _stream << start -> data << std::endl;
                start = start -> next;
            }
            return _stream;
        }
};

template <typename T>
Node<T> *LinkedList<T>::get_list_head() {
    return fake_head -> next;
}

template <typename T>
Node<T> *LinkedList<T>::get_list_tail() {
    return fake_tail -> prev;
}

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
    size++;
}

template <typename T>
void LinkedList<T>::insert_at_tail(T val) {
    Node<T> *new_node = new Node<T>(val);
    Node<T> *temp = fake_tail -> prev;

    new_node -> next = fake_tail;
    new_node -> prev = temp;

    fake_tail -> prev = new_node;
    temp -> next = new_node;
    size++;
}

template <typename T>
void LinkedList<T>::insert_after(Node<T> *prev, T val) {
    
    if (!prev) {
        throw std::invalid_argument("Null pointer");
    }

    Node<T> *next = prev -> next;
    Node<T> *new_node = new Node<T>(val);

    new_node -> next = next;
    new_node -> prev = prev;

    prev -> next = new_node;
    next -> prev = new_node;
    size++;
}

template <typename T>
size_t LinkedList<T>::get_size() {
    return size;
}





