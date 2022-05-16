#ifndef VECTOR_H
#define VECTOR_H
#include <iostream>

template <typename T>
class Vector {
public:
    class Iterator : public std::iterator<std::random_access_iterator_tag, T>
    {
    public:
        Iterator();
        Iterator(const Vector<T> *vector, int Index);

    public:
        const T& operator*() const;
        Iterator& operator++();
        Iterator& operator--();
        Iterator& operator+(const Iterator& other) const;
        Iterator& operator-(const Iterator& other) const;
        bool operator!=(const Iterator& other) const;
        bool operator==(const Iterator& other) const;
        bool operator<(const Iterator& other) const;
        bool operator>(const Iterator& other) const;

    private:
        const Vector<T> *m_Vector;
        int m_Index = -1;
    };
public:
    Vector();
    Vector(T);
    ~Vector();
public:
    void push_back(T);
    T at(T);
    void pop_back();
    void empty();
    void insert(T,T);
    void erase(T);
    T  size();
    T capacity();
    T operator[](T);
    void clear();
    void shrink_to_fit();
    void data();

    const T &operator[](int nIndex) const;
    Iterator begin() const;
    Iterator end() const;

private:
    int m_cap;
    int m_size;
    int* m_buff;
};

#endif //VECTOR_H
