#pragma once

#include <stdexcept>

template <class T>
class LinkedList
{
public:
    LinkedList() {}
    LinkedList(T* items, int count)
    {
        //TODO: Optimize
        for(int i=0; i < count; ++i)
        {
            Append(items[i]);
        }
    }

    LinkedList(const LinkedList & list)
    {
        //TODO: Optimize
        for(int i=0; i < list.length; ++i)
        {
            Append(list.Get(i));
        }
    }

    T GetFirst() const
    {
        return head->data;
    }

    T GetLast() const
    {
        return tail->data;
    }

    T Get(int index) const
    {
        return GetNode(index)->data;
    }

    T& GetRef(int index)
    {
        return GetNode(index)->data;
    }

    LinkedList<T>* GetSubList(int startIndex, int endIndex) const
    {
        LinkedList<T>* subList = new LinkedList<T>();
        for(Node* i = GetNode(startIndex); i != GetNode(endIndex); i = i->next)
        {
            subList->Append(i->data);
        }
        return subList;
    }

    int GetLength() const
    {
        return length;
    }

    void Append(T item)
    {
        InsertAt(item, length);
    }

    void Prepend(T item)
    {
        InsertAt(item, 0);
    }

    void InsertAt(T item, int index)
    {
        Node* prev = nullptr;
        Node* next = nullptr;
        if(index == 0)
        {
            prev = nullptr;
            next = head;
        }
        else if(index == length)
        {
            prev = tail;
            next = nullptr;
        }
        else
        {
            prev = GetNode(index-1);
            next = prev->next;
        }


        Node* node = new Node(item, prev, next);
        if(prev != nullptr)
        {
            prev->next = node;
        }
        if(next != nullptr)
        {
            next->prev = node;
        }

        if(index == 0)
        {
            head = node;
        }
        if(index == length)
        {
            tail = node;
        }
        length++;
    }

    void RemoveAt(int index)
    {
        Node* toBeRemoved = GetNode(index);
        if(toBeRemoved->prev != nullptr)
        {
            toBeRemoved->prev->next = toBeRemoved->next;
        }
        if(toBeRemoved->next != nullptr)
        {
            toBeRemoved->next->prev = toBeRemoved->prev;
        }

        if(toBeRemoved == tail)
        {
            tail = toBeRemoved->prev;
        }
        if(toBeRemoved == head)
        {
            head = toBeRemoved->next;
        }

        delete toBeRemoved;
        length--;
    }

    LinkedList<T>* Concat(LinkedList<T> * list) const
    {
        LinkedList<T>* copy = new LinkedList(*this);
        for(Node* i = list->head; i != nullptr; i = i->next)
        {
            copy->Append(i->data);
        }
    }

    ~LinkedList()
    {
        if(head != nullptr)
        {
            for(Node* i = head->next; i != nullptr; i = i->next)
            {
                delete i->prev;
            }
        }
        delete tail;
    }
private:
    class Node {
    public:
        Node(T data, Node* prev = nullptr, Node* next = nullptr) :
            data(data), prev(prev), next(next) {}

        T data;
        Node* prev;
        Node* next;
    };

    Node* GetNode(int index) const
    {
        if(index >= length || index < 0)
        {
            throw std::out_of_range("Invalid index " + std::to_string(index));
        }

        if(index < length - index)
        {
            Node* node = head;
            for(int i = 0; i < index; ++i)
            {
                node = node->next;
            }
            return node;
        }
        else
        {
            Node* node = tail;
            for(int i = length-1; i > index; --i)
            {
                node = node->prev;
            }
            return node;
        }
    }

    Node* head = nullptr;
    Node* tail = nullptr;
    int length = 0;
};
