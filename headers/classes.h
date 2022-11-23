#pragma once

#include <iostream>
#include <fstream>

template<typename T>
class List
{
public:
    List();
    ~List();
    void Init(const char* str);
    void Insert(T data, int index);
    void PushFront(T data);
    void PushBack(T data);
    void PopFront();
    void PopBack();
    void RemoveAt(int index);
    void ReadFromFile(char*);
    int GetSize();
    void Clear();
    T& operator[](size_t index);
private:
    class Node
    {
    public:
        Node *pNext;
        T data;
        explicit Node(T data, Node *pNext= nullptr)
        {
            this->data=data;
            this->pNext=pNext;
        }
    };
    int size;
    Node *head;
};

// Конструкторы
template<typename T>
List<T>::List()
{
    size = 0;
    head = nullptr;
}

// Деструктор
template<typename T>
List<T>::~List(){
    {
        Clear();
    }
}


template<typename T>
void List<T>::PushBack(T data)
{
    if (head == nullptr)
    {
        head = new Node(data);
    }
    else
    {
        Node *current = this->head;
        while(current->pNext != nullptr)
        {
            current = current->pNext;
        }
        current->pNext=new Node(data);
    }
    size++;
}

template<typename T>
int List<T>::GetSize() {
    return this->size;
}


template<typename T>
void List<T>::ReadFromFile(char* path)
{
    Clear();
    std::fstream file(path, std::ios::in);
    if (file.is_open())
    {
        T buf;
        file.read(&buf, sizeof(T));
        while (!file.eof())
        {
            this->PushBack(buf);
            file.read(&buf, sizeof(T));

        }
    }
    file.close();
    if (file.is_open())
    {
        throw std::exception();
    }
}

template<typename T>
void List<T>::PopFront()
{
    Node *temp = head;
    head = head->pNext;
    delete temp;
    size--;
}

template<typename T>
void List<T>::Clear()
{
    while(size)
    {
        this->PopFront();
    }
}

template<typename T>
void List<T>::PushFront(T data)
{
    head = new Node(data, head);
    size++;
}

template<typename T>
void List<T>::Insert(T data, int index)
{
    if (index > size-1)
    {
        throw std::exception();
    }

    if (index == 0)
    {
        PushFront(data);
    }
    else
    {
        Node *previos = this->head;
        for (int i=0; i < index-1; i++)
        {
            previos = previos->pNext;
        }
        previos->pNext = new Node(data, previos->pNext);
    }
    size++;
}

template<typename T>
void List<T>::RemoveAt(int index)
{
    if (index > size-1)
    {
        throw std::exception();
    }

    if (index == 0)
    {
        PopFront();
    }
    else
    {
        Node *previos = this->head;
        for (int i=0; i < index-1; i++)
        {
            previos = previos->pNext;
        }
        Node *temp = previos->pNext;
        previos->pNext = temp->pNext;
        delete temp;
    }
    size--;
}

template<typename T>
void List<T>::PopBack()
{
    RemoveAt(size-1);
}

template<typename T>
T &List<T>::operator[](const size_t index) {
    size_t counter{0};
    Node *current = this->head;
    while(current != nullptr)
    {
        if (counter == index)
        {
            return current->data;
        }
        current = current->pNext;
        counter++;
    }
    throw std::exception();

}

template<typename T>
void List<T>::Init(const char* str)
{
    Clear();
    int i =0;
    while(*(str+i) != '\0')
    {
        PushBack(*(str+i));
        i++;
    }
}

