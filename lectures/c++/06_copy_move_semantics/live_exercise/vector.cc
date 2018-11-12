#include <iostream> //std::cout
#include <memory> //std::unique_ptr

template <class T>
class Vector {

private:
    std::unique_ptr<T[]> elem; //the real data
    std::size_t _size;
    std::size_t _free_slots = 0;

    void check_and_alloc();

public:
    // No noexcept because of the new operator
    Vector(const std::size_t length) : elem{new T[length]}, _size{length} {}

    // Returns a reference because we can modify the selected element
    T& operator[](const std::size_t i) noexcept { return elem[i]; }

    // The const version is needed when referencing a const vector
    const T& operator[](const std::size_t i) const noexcept { return elem[i]; }

    const auto size() const noexcept { return _size; }

    //adding with copy semantic
    void push_back(const T& e);

    //adding with move semantic, useful for adding custom classes in array. Added in c++11.
    void push_back(T&& e);

    // The function is templated with any number of arguments
    template <class... Args>
    void emplace_back(Args&& ...args)
    {
        // forward is a function that forwards the type it received as parameter
        push_back( T{std::forward(args)... } );
    }
};

// Reference because we want to modify the output stream 
template <class T>
std::ostream& operator<<(std::ostream &os, const Vector<T>& v)
{
    for (auto i = 0llu; i < v.size(); ++i) //llu = long long unsigned
        os << v[i] << " ";
    os << std::endl;
    return os;
}

template <class T>
void Vector<T>::check_and_alloc()
{
    if (_free_slots == 0)
    {
        auto tmp = new T[size()*2];
        _free_slots = size(); //free slots are set to the size of the new half which has been added

        //We want to force a move instead of a copy
        for (auto i = 0llu; i < size(); ++i)
            tmp[i] = std::move( (*this)[i] );
        elem.reset(tmp); //resets the memory and set the pointer to null.
    }
}

template <class T>
void Vector<T>::push_back(const T& e)
{
    check_and_alloc();
    (*this)[size()] = e; //copy semantic
    _size++;
    _free_slots--;
}

template <class T>
void Vector<T>::push_back(T&& e)
{
    check_and_alloc();
    (*this)[size()] = std::move(e); //move semantic
    _size++;
    _free_slots--;
}

class Date
{
private:
    int d, m, y;
public:
    Date(const int day, const int month, const int year): d{day}, m{month}, y{year} {}
    auto day() const noexcept {return d;}
    auto month() const noexcept {return m;}
    auto year() const noexcept {return y;}
};

int main()
{
    Vector<int> v{4};
    {
        auto i = v.size();
        while(--i)
            v[i] = i;
    }
    std::cout << v;

    v.push_back(5);

    std::cout << v;

    Vector<Date> vd{2};

    vd.push_back(Date{1,2,3});
    //same as, since c++11, to prevent redundance
    vd.emplace_back(1,2,3);
    return 0;
}