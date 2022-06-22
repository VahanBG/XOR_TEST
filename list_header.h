#ifndef LIST_HEADER_H
#define LIST_HEADER_H
#include <iostream>
#include <initializer_list>
#include <utility>

template <typename T>
class List;

template <typename T>
std::ostream& operator << (std::ostream& COUT, const List<T>& oth);

template <typename T>
class List
{
public:
    template <typename N>
    friend std::ostream& operator << (std::ostream& COUT, const List<N>& oth);
    List() = default; // ok
    List(const T&); // 
    List(const std::initializer_list<T>&); //ok
    List(const List<T>&); //ok
    List(List<T>&&); //ok
    List& operator = (const List<T>&); //wrong
    List& operator = (List<T> &&); //wrong
    List& choosing_operation(); //ok
    List& choose(int);//ok
    ~List();
    
    void insert( T&, std::size_t); //ok
    void size();//ok
    void push_front(const T&); //ok
    void push_back(const T&);//ok
    void pop_front();//ok
    void pop_back();//ok
    bool empty();//ok
    void clear();//ok
    void traverse();//ok
    
    void swap(List&);
    void print_forward();
    void print_back();
    void choose_insert();
    void choose_push();
    void choose_pop();
    void choose_print();
    
private:
    class Node
    {
    public:
        Node *npx{nullptr};
        T data{};
    public:
        Node(const T& Data){data = Data;}
    };
    
    Node* first = nullptr;
    Node* last = nullptr;
    Node* XOR(Node*, Node*)const;
    std::size_t size_of_list{};
};

#include "implementation.hpp"
#endif /* LIST_HEADER_H */
