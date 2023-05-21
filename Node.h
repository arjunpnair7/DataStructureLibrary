template <typename T> class Node {
    public:
        Node(T val);
        Node();
        T data;
        Node<T>* prev;
        Node<T>* next;
};

    template <typename T> Node<T>::Node(const T val) {
            data = val;
            prev = nullptr;
            next = nullptr;
    }

    template <typename T> Node<T>::Node() {
        prev = nullptr;
        next = nullptr;
    }