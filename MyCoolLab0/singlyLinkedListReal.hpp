#include "singlyLinkedListInit.hpp"

template<typename T>
singlyLinkedList<T>::singlyLinkedList()
{
    size = 0;
    head = nullptr;
}

template<typename T>
singlyLinkedList<T>::~singlyLinkedList()
{
    /*”даление списка происходит с конца. ¬ первом цикле считаетс€ количество удаленых €чеек (i=0 - 0 удаленных €чеек). ѕеред входом во втором цикле
    инициализируем временные переменные, где current инициализируетс€ хедом, от которого происходит движение во втором цикле. ¬торой цикл с каждым вызовом делает меньше итерации.
    ѕон€тное дело, что он не выйдет за границы €чеек, потому что его ограничивает (size-i), который показывает количество €чеек в списке на данный момент.*/
    for (int i = 0; i < size; i++)
    {
        Node<T>* current = head;

        for (int j = 0; j < size - i; j++)
        {
            current = current->next; //двигаемс€ к крайнему элемент
        }

        delete current; //удал€ем крайний элемент
    }
    //при выходе из счЄтчика все €чейки списка удалены, осталс€ только size и указатель head

    size = 0;
    delete head;
    head = nullptr;
}

template<typename T>
int singlyLinkedList<T>::getSize()
{
    return size;
}

template<typename T>
void singlyLinkedList<T>::push_front(T data)
{
    if (this->head == nullptr)
    {
        this->head = new Node<T>(data);
        this->size++;
    }
    else
    {
        Node<T>* newElement = new Node<T>(data);
        newElement->next = this->head;
        this->head = newElement;
        this->size++;
    }
}

template<typename T>
bool singlyLinkedList<T>::isEmpty()
{
    return this->head == nullptr ? true : false;
}

template<typename T>
void singlyLinkedList<T>::push_back(T data)
{
    if (this->head == nullptr) // если голова списка пуста
    {
        this->head = new Node<T>(data); //вносим данные в голову списка
        this->size++;
    }
    else
    {
        Node<T>* current = this->head; //начинаем движение от головы списка до крайней €чейки списка
        while (current->next != nullptr)
        {
            current = current->next;
        }
        this->size++;
        current->next = new Node<T>(data); //в крайней €чейке списка, указываем адресс на новую €чейку
    }
}

template<typename T>
T& singlyLinkedList<T>::operator[](const int index)
{
    int counter = 0;
    Node<T>* current = this->head;
    while (current != nullptr)
    {
        if (counter == index)
        {
            return current->data;
        }
        current = current->next;
        counter++;
    }
}

template<typename T>
void singlyLinkedList<T>::printList()
{
    Node<T>* current = this->head; //начинаем движение от головы списка до крайней €чейке списка
    for (int i = 0; i < size; i++)
    {
        std::cout.width(5);
        std::cout << current->data;
        current = current->next;
    }
}

template<typename T>
size_t singlyLinkedList<T>::search(T searchData)
{
    Node<T>* current = this->head;
    for (size_t i = 0; i < size; i++)
    {
        if (current->data == searchData)
        {
            return i;
        }
        else
        {
            current = current->next;
        }
    }

    if (current == nullptr)
    {
        return -1;
    }
}

template<typename T>
void singlyLinkedList<T>::pop_front()
{
    Node<T>* current = this->head;
    this->head = current->next;
    delete current;
    current = nullptr;
    size--;
}

template<typename T>
void singlyLinkedList<T>::removeAt(const int index)
{
    if (index == 0)
    {
        pop_front();
    }
    else
    {
        Node<T>* previous = this->head;
        for (int i = 0; i < index - 1; i++)
        {
            previous = previous->next;
        }

        Node<T>* toDelete = previous->next;

        previous->next = toDelete->next;

        delete toDelete;

        size--;
    }
}

template<typename T>
void singlyLinkedList<T>::insert(T data, const int index)
{
    if (index == 0)
    {
        push_front(data);
    }
    else
    {
        Node<T>* current = this->head;
        for (int i = 0; i < index - 1; i++)
        {
            current = current->next;
        }
        Node<T>* newData = new Node<T>(data, current->next);

        current->next = newData;

        size++;
    }

}

template<typename T>
void singlyLinkedList<T>::pop_back()
{
    removeAt(size - 1);
}