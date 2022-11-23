#pragma once

#include <iostream>
#include <fstream>

template<typename T>
class List
{
public:
    List();
    explicit List(const char*);
    ~List();
    void Insert(T, int);
    void PushFront(T);
    void PushBack(T);
    void PopFront();
    void PopBack();
    void RemoveAt(int);
    void ReadFromFile(char*);
    void WriteToFile(char*);
    int FindFirst(List<T>);
    void DeleteAllSeq(List<T>);
    int GetSize();
    void Clear();
    T& operator[](size_t);
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
    List<int> PrefixFunction (List<T> image);
};

// Конструкторы
template<typename T>
List<T>::List()
{
    size = 0;
    head = nullptr;
}

template<typename T>
List<T>::List(const char *str)
{
    size =0;
    while(*(str+size) != '\0')
    {
        PushBack(*(str+size));
    }
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
        Node *previous = this->head;
        for (int i=0; i < index-1; i++)
        {
            previous = previous->pNext;
        }
        previous->pNext = new Node(data, previous->pNext);
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
        Node *previous = this->head;
        for (int i=0; i < index-1; i++)
        {
            previous = previous->pNext;
        }
        Node *temp = previous->pNext;
        previous->pNext = temp->pNext;
        delete[] temp;
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
void List<T>::WriteToFile(char *path)
{
    std::fstream file(path, std::ios::out|std::ios::trunc);
    if (file.is_open())
    {
        Node *tmp = head;
        for(int i=0;i<size;i++)
        {
            file.write(&tmp->data,sizeof(T));
            tmp->pNext=tmp->pNext;
        }
    }
    file.close();
    if (file.is_open())
    {
        throw std::exception();
    }
}

template<typename T>
void List<T>::DeleteAllSeq(List<T> image)
{
    int index = FindFirst(image);
    while(index >= 0)
    {
        for(int i =0; i<image.GetSize();i++)
        {
            RemoveAt(index);
        }
        index = FindFirst(image);
    }
}

template<typename T>
List<int> List<T>::PrefixFunction(List<T> image)
{
    List<int> pi{};// В i-м элементе (его индекс i-1) количество совпавших символов в начале и конце для подстроки длины i.
    // p[0]=0 всегда, p[1]=1, если начинается с двух одинаковых
    pi.PushBack(0);
    for (int i=1; i<image.GetSize(); ++i)
    {
        // ищем, какой префикс-суффикс можно расширить
        int j = pi[i-1]; // длина предыдущего префикса-суффикса, возможно нулевая
        while ((j > 0) && (image[i] != image[j]))// этот нельзя расширить,
        {
            j = pi[j - 1];   // берем длину меньшего префикса-суффикса
        }
        if (image[i] == image[j])
        {
            ++j;  // расширяем найденный (возможно пустой) префикс-суффикс
        }
        pi.PushBack(j);
    }
    return pi;
}

template<typename T>
int List<T>::FindFirst(List<T> image)
{
    List<T> *txt = *this;
    List<int> pi = PrefixFunction(image);
    int txtLen=txt->GetSize(), imgLen=image.GetSize();
    for(int k=0,l=0;k<txtLen;)
    {
        if(txt[k] != image[l])
        {
            l == 0?k++:l = pi[l-1];
        }
        else
        {
            if(l == imgLen-1)
            {
                return (k-imgLen+1);
            }
            k++;
            l++;
        }
    }
    return -1;
}

