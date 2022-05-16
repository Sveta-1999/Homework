#include <iostream>
#include "vector.h"

template <typename T>
Vector<T>::Vector() {
    m_size = 0;
    m_cap = 5;
    m_buff = new T[m_cap];
}

template <typename T>
Vector<T>::Vector(T in_cap) {
    m_size = 0;
    m_cap = in_cap;
    m_buff = new T[m_cap];
}

template <typename T>
Vector<T>::~Vector() {
    delete[] m_buff;
}

template <typename T>
void Vector<T>::push_back(T element) {
    if(m_cap == m_size) 
    {
        m_cap *= 2;
        T* tmp = new T[m_cap];
        for(int i = 0; i < m_size; ++i)
        {
            tmp[i] = m_buff[i];
        }
        delete[] m_buff;
        m_buff = tmp;
    }
    m_buff[m_size++] = element;
}

template <typename T>
T Vector<T>::at(T index) {
    if(index >= 0 && index < m_size) 
    {
        return m_buff[index];
    }
    else
    {
        throw;
    }
}

template <typename T>
void Vector<T>::pop_back() {
    m_size--;
}

template <typename T>
void Vector<T>::empty() {
    if(m_size == 0) {
        std::cout<<"Vector is empty.\n";
    }
    else
    {
        std::cout<<"Vector is not empty.\n";
    }
}

template <typename T>
void Vector<T>::insert(T element, T index) 
{
    if(m_size != m_cap) 
    {
        for(int i = m_size; i > index; --i) 
        {
            m_buff[i] = m_buff[i-1];
        }
        m_buff[index] = element;
    }
    else 
    {
        m_cap *= 2;
        T* tmp = new T[m_cap];
        int i;
        for(i = 0; i < index; i++) {
            tmp[i] = m_buff[i];
        }
        tmp[index] = element;
        for( ; i < m_size; ++i) 
        {
            tmp[i+1] = m_buff[i];
        }
        delete[] m_buff;
        m_buff = tmp;
    }
    m_size++;
}

template <typename T>
T  Vector<T>::size(){ return m_size; }

template <typename T>
T  Vector<T>::capacity(){ return m_cap; }

template <typename T>
T Vector<T>::operator[](T indexs)
{
    return m_buff[indexs] ;
}

template <typename T>
void Vector<T>::erase(T index) 
{
    if(index > m_size || index < 0) { return; }
    for(int i = index ; i < m_size-1; ++i)
    {
        m_buff[i] = m_buff[i+1];
    }
    m_size--;
}

template <typename T>
void Vector<T>::clear() 
{
    for(int i = m_size; i > 0; --i)
    {
        m_size--;
    }
}

template <typename T>
void Vector<T>::shrink_to_fit()
{
    m_cap == m_size;
}

template <typename T>
void Vector<T>::data()
{
    T array[m_size];
    for(int i = 0; i<m_size; ++i)
    {
       array[m_size] = m_buff[i];
    }
    for(int i = 0; i<m_size; ++i) 
    {
        std::cout << array[i];
    }
}

template <typename T>
const T &Vector<T>::operator[](int Index) const
{
    return m_buff[Index];
}

template <typename T>
typename Vector<T>::Iterator Vector<T>::begin() const
{
    return Vector<T>::Iterator{ this, 0 };
}

template <typename T>
typename Vector<T>::Iterator Vector<T>::end() const
{
    return Vector<T>::Iterator{ this, m_size };
}


template <typename T>
Vector<T>::Iterator::Iterator(const Vector<T> *Vector, int Index)
    : m_Vector(Vector),
    m_Index(Index)
{
}

template <typename T>
const T &Vector<T>::Iterator::operator*() const
{
    return m_Vector->operator[](m_Index);
}

template <typename T>
typename Vector<T>::Iterator& Vector<T>::Iterator::operator++()
{
    ++m_Index;
    return *this;
}

template <typename T>
typename Vector<T>::Iterator& Vector<T>::Iterator::operator--()
{
    --m_Index;
    return *this;
}

template <typename T>
typename Vector<T>::Iterator& Vector<T>::Iterator::operator-(const Vector<T>::Iterator& other) const
{
    return *this -= other;
}

template <typename T>
typename Vector<T>::Iterator& Vector<T>::Iterator::operator+(const Vector<T>::Iterator& other) const
{
    return *this += other;
}

template <typename T>
bool Vector<T>::Iterator::operator!=(const Vector<T>::Iterator& other) const
{
    return m_Index != other.m_Index;
}

template <typename T>
bool Vector<T>::Iterator::operator==(const Vector<T>::Iterator& other) const
{
    return m_Index == other.m_Index;
}

template <typename T>
bool Vector<T>::Iterator::operator<(const Vector<T>::Iterator& other) const
{
    return m_Vector < other.m_Vector;
}

template <typename T>
bool Vector<T>::Iterator::operator>(const Vector<T>::Iterator& other) const
{
    return m_Vector > other.m_Vector;
}