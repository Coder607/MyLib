#ifndef DYNAMICLIST_H
#define DYNAMICLIST_H

#include "SeqList.h"
#include "Exception.h"

namespace MyLib
{

template <typename T>
class DynamicList : public SeqList<T>
{
protected:
    int m_capacity;     // 顺序存储空间的大小
public:
    DynamicList(int capacity)   // 申请空间
    {
        this->m_array = new T[capacity];

        if (this->m_array != nullptr)
        {
            this->m_length = 0;
            this->m_capacity = capacity;
        }
        else
        {
            THROW_EXCEPTION(NoEnoughMemoryException, "No memory to create DynamicList object...");
        }
    }

    int capacity() const
    {
        return m_capacity;
    }

    // 重新设置顺序存储空间的大小
    void resize(int capacity)
    {
        if (capacity != m_capacity)
        {
            T* new_array = new T[capacity];

            if (new_array != nullptr)
            {
                int size = (this->m_length < capacity ? this->m_length : capacity);

                for (int i = 0; i < size; i++)
                {
                    new_array[i] = this->m_array[i];
                }

                T* temp = this->m_array;

                this->m_array = new_array;
                this->m_length = size;
                this->m_capacity = capacity;

                delete[] temp;
            }
            else
            {
                THROW_EXCEPTION(NoEnoughMemoryException, "No memory to create DynamicList object...");
            }
        }

    }

    // 归还空间
    ~DynamicList()
    {
        delete[] this->m_array;
    }
};

}

#endif // DYNAMICLIST_H
