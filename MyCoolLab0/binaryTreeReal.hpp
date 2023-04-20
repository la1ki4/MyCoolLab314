#include "binaryTreeInit.hpp"

template<typename T>
BinaryTree<T>::BinaryTree()
{
    this->root = nullptr;
}

template<typename T>
BinaryTree<T>::~BinaryTree()
{
    clearHelpler(root);
}

template<typename T>
void BinaryTree<T>::insert(T data)
{
    if (root == nullptr)
    {
        root = new Node<T>(data);
    }
    else
    {
        insertHelper(data, root);
    }
}

template<typename T>
void BinaryTree<T>::simmetricBypass()
{
    simmetricBypassHelper(root);
}

template<typename T>
void BinaryTree<T>::directBypass()
{
    directBypassHelper(root);
}

template<typename T>
void BinaryTree<T>::reverseBypass()
{
    reverseBypassHelper(root);
}

template<typename T>
void BinaryTree<T>::remove(T data)
{
    removeHelper(data, root);
}

template<typename T>
bool BinaryTree<T>::search(T searchData)
{
    T tmp;
    tmp = searchHelper(searchData, root);
    if (tmp == searchData)
    {
        return true;
    }
    else
    {
        return false;
    }
}