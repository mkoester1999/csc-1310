#include "Node.h"
#include<iostream>
using namespace std;

template<class T>
Node<T>::Node(const T& e = T(), Node<T>* n = NULL)
{
    element (e), next(n); 
}