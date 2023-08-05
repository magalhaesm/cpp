#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <cstddef>
#include <stdexcept>

template <typename T>
class Array
{
public:
    Array(unsigned int = 0);
    Array(const Array&);
    ~Array();
    size_t size() const;

    const Array& operator=(const Array&);
    T& operator[](size_t);
    T operator[](size_t) const;

private:
    size_t m_size;
    T* m_ptr;
    void copy(const Array&);
};

template <typename T>
Array<T>::Array(unsigned int size)
    : m_size(size)
    , m_ptr(new T[m_size])
{
    for (size_t i = 0; i < m_size; ++i)
    {
        m_ptr[i] = 0;
    }
}

template <typename T>
Array<T>::Array(const Array<T>& arrayToCopy)
    : m_size(arrayToCopy.m_size)
    , m_ptr(new T[m_size])
{
    copy(arrayToCopy);
}

template <typename T>
Array<T>::~Array()
{
    delete[] m_ptr;
}

template <typename T>
size_t Array<T>::size() const
{
    return m_size;
}

template <typename T>
const Array<T>& Array<T>::operator=(const Array<T>& rhs)
{
    if (&rhs != this)
    {
        if (m_size != rhs.m_size)
        {
            delete[] m_ptr;
            m_size = rhs.m_size;
            m_ptr = new T[m_size];
        }
        copy(rhs);
    }
    return *this;
}

template <typename T>
T& Array<T>::operator[](size_t subscript)
{
    if (subscript >= m_size)
    {
        throw std::out_of_range("Index out of bounds");
    }
    return m_ptr[subscript];
}

template <typename T>
T Array<T>::operator[](size_t subscript) const
{
    if (subscript >= m_size)
    {
        throw std::out_of_range("Index out of bounds");
    }
    return m_ptr[subscript];
}

template <typename T>
void Array<T>::copy(const Array<T>& rhs)
{
    for (size_t i = 0; i < m_size; ++i)
    {
        m_ptr[i] = rhs.m_ptr[i];
    }
}

#endif // !ARRAY_HPP
