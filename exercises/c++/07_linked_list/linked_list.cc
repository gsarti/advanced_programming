#include <iostream>
#include <memory>
#include <stdexcept>

// ITERATORS
// T& operator*()
// T& operator->()
// iterator operator++() is pre-increment
// iterator operator++(int) is post-increment

enum class push_method
{
    PUSH_BACK, // Adds the element to the end of a list
    PUSH_FRONT // Adds the element to the front of a list
};

// Only public symbols of Node are accessible to the class List.
// They are however not accessible by the user.
template <class T> 
class List{
private:
    struct Node {
        T value;
        std::unique_ptr<Node> next;

        Node(const T& val, Node* n): value{val}, next{n} {}
        ~Node() = default;
    };

    std::unique_ptr<Node> head;

    void push_front(const T& v){
        head.reset(new Node{v, head.release()}); // We have to release because the reset wouldn't work
    }
    void push_back(const T& v);

public:
    List() = default;
    void push(const T& v, const push_method pm = push_method::PUSH_BACK){
        if (head == nullptr){
            head.reset(new Node{v, nullptr});
            return;
        }
        
        switch (pm)
        {
            case push_method::PUSH_BACK:
                push_back(v);
                break;
            case push_method::PUSH_FRONT:
                push_front(v);
                break;
            default:
                throw std::runtime_error("Error: unknown push method");
        }

    }

    class Iterator;
    class ConstIterator;
    Iterator begin() { return Iterator{head.get()}; }
    Iterator end() { return Iterator{nullptr}; } 

    ConstIterator begin() const {return ConstIterator{head.get()}; }
    ConstIterator end() const {return ConstIterator{nullptr}; }

    template <class ot>
    friend std::ostream& operator<<(std::ostream& os, List<T>& l); //Used to allow access to values which are private to the class. Implied between objects of the same type
};

template <class T>
class List<T>::Iterator{
private:
    using Node = List<T>::Node;
    
    Node* current;
public:
    Iterator(Node* n): current{n}{}
    T& operator*() const { return current->value; }
    Iterator& operator++() 
    {
        current = current->next.get();
        return *this;
    }
    // Iterator& operator++(int)
    // {
    //     Iterator it{*this};
    //     ++(*this);
    //     return it;
    // }
    bool operator==(const Iterator& other){
        return current == other.current;
    }
    bool operator!=(const Iterator& other){
        return !(*this == other);
    }
};

template <class T>
class List<T>::ConstIterator : public List<T>::Iterator
{
public:
    using parent = List<T>::Iterator;
    using parent::Iterator;
    const T& operator*() const { return parent::operator*(); }
};

template <class T>
void List<T>::push_back(const T& v)
{
    Node * tmp = head.get();
    while(tmp->next)
        tmp = tmp-> next.get();
    tmp->next.reset(new Node{v, nullptr});
}

template <class T>
std::ostream& operator<<(std::ostream& os, List<T>& l)
{
    // How we would print without iterators
    // auto tmp = l.head.get();
    // while (tmp)
    // {
    //     os << tmp->value << "\t";
    //     tmp = tmp->next.get();
    // }
    // os << std::endl;
    // return os;

    //Using this approach, we do not need to know the inner structure of the class
    auto it = l.begin();
    auto stop = l.end();
    for(;it != stop; ++it)
        os << *it << "\t";
    os << std::endl;
    return os;
}

int main()
{
    List<int> list;
    std::cout << "Starting List" << std::endl;
    std::cout << list << std::endl;
    list.push(42);
    list.push(1, push_method::PUSH_FRONT);
    list.push(43, push_method::PUSH_BACK);
    std::cout << "After push list:" << std::endl;
    std::cout << list << std::endl;
    // std::cout << list;
    for (auto& x: list)
        ++x;
    std::cout << "After add list:" << std::endl;
    std::cout << list << std::endl;
    return 0;
}