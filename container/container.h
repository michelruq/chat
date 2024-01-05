#pragma once
#include <iostream>

template <typename T>
class Container
{
private:
    T* items;
    int _size;

public:
    Container() : _size(0)
    {
        items = new T[_size];
    }
    ~Container()
    {
        delete[] items;
    }

    void AddElement(T newItem)
    {
        T* pointer = new T[_size + 1];
        for (int i{ 0 }; i < (_size); ++i)
        {
            pointer[i] = items[i];
        }

        delete[] items;
        items = pointer;
        items[_size] = newItem;
        ++_size;
    }

    T* GetPointerToElement(int index)
    {
        return &items[index];
    }

    int GetSize()
    {
        return _size;
    }
};
