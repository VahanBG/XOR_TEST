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
    List() = default;
    List(const T&);
    List(const std::initializer_list<T>&);
    List(const List<T>&);
    List(List<T>&&);
    List& operator = (const List<T>&);
    List& operator = (List<T> &&);
    List& choosing_operation();
    List& choose(int);
    ~List();
    
    void insert(T&, std::size_t);
    void size();
    void push_front(const T&);
    void push_back(const T&);
    void pop_front();
    void pop_back();
    bool empty();
    void clear();
    void traverse();
    
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
