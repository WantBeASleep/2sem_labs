#pragma once

#include <algorithm>
#include <stdexcept>


template <class T>
class DynamicArray
{
public:
    DynamicArray(T* items, int count)
    {
        Resize(count);
        this->size = count;
        std::copy(items, items + count, array);
    }

    DynamicArray(int size)
    {
        Resize(size);
    }

    DynamicArray(const DynamicArray<T> & source)
    {
        Resize(source.size);
        this->size = source.size;
        std::copy(source.array, source.array + size, array);
    }

    T& operator[](int index)
    {
        if(index >= size || index < 0)
        {
            throw std::out_of_range("Invalid index " + std::to_string(index));
        }
        return array[index];
    }

    int GetSize() const
    {
        return size;
    }

    T Get(int index) const
    {
        if(index >= size || index < 0)
        {
            throw std::out_of_range("Invalid index " + std::to_string(index));
        }
        return array[index];
    }

    void Set(int index, T value)
    {
        (*this)[index] = value;
    }

    void Resize(int newSize)
    {
        T* buff = array;
        array = new T[newSize];
        std::copy(buff, buff + std::min(size, newSize), array);
        delete[] buff;
        size = newSize;
    }

    ~DynamicArray()
    {
        delete[] array;
    }

private:
    T* array = nullptr;
    int size = 0;
};
