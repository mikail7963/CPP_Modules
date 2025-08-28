#pragma once

template <typename T>
class Array
{
private:
    T *array;
    unsigned int lengt;
public:
    Array();
    Array(unsigned int n);
    Array(const Array& other);
    Array& operator=(const Array& other);
    ~Array();
    T& operator[](unsigned int i);
    const T& operator[](unsigned int i) const;
    unsigned int size() const;
};

template <typename T>
Array<T>::Array() : array(NULL), lengt(0)
{
    
}

template <typename T>
Array<T>::Array(unsigned int n) : array(NULL), lengt(n)
{
    if (n > 0)
        array = new T[n];
}

template <typename T>
Array<T>::Array(const Array& other) : array(NULL), lengt(other.lengt)
{   
    if (lengt > 0) {
        this->array = new T[other.size()];
        for (unsigned int i = 0; i < other.size(); i++) 
            this->array[i] = other.array[i];
    }
}

template <typename T>
Array<T>& Array<T>::operator=(const Array<T>& other)
{
    if (this != &other)
    {
        delete[] array;
        this->lengt = other.lengt;
        if (lengt > 0) {
            this->array = new T[other.size()];
            for (unsigned int i = 0; i < other.size(); i++)
                this->array[i] = other.array[i];
        } else {
            this->array = NULL;
        }
    }
    return (*this);
}

template <typename T>
Array<T>::~Array()
{
    delete[] this->array;
}

template <typename T>
T& Array<T>::operator[](unsigned int i)
{
    if (i >= this->lengt)
        throw std::out_of_range("Index out of bounds");
    return (this->array[i]);
}

template <typename T>
const T& Array<T>::operator[](unsigned int i) const
{
    if (i >= this->lengt)
        throw std::out_of_range("Index out of bounds");
    return (this->array[i]);
}

template <typename T>
unsigned int Array<T>::size() const
{
    return this->lengt;
}
