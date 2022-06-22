template <typename T>
typename List<T>::Node* List<T>::XOR(Node* x, Node *y) const
{
    return (Node*)((uintptr_t)x ^ (uintptr_t)y);
}

template <typename T>
List<T>::List(const T& value)
{
    push_front(value);
}

template <typename T>
List<T>::List(const std::initializer_list<T>& values)
{
    for(auto i : values)
    {
        push_back(i);
    }
}

template <typename T>
List<T>::List(const List<T>& copy)
{
    Node * itrsave;
    Node * lastitr = nullptr;
    Node * itr = copy.first;
    while (itr)
    {
        push_back(itr->data);
        itrsave = itr;
        itr = XOR(lastitr, itr->npx);
        lastitr = itrsave;
    }
}

template<typename T>
List<T>::List(List<T>&& move)
{
    size_of_list = move.size_of_list;
    first = move.first;
    move.first = nullptr;
    last = move.last;
    move.last = nullptr;
}

template<typename T>
List<T>& List<T>::operator = (const List& copy)
{
    List file{copy};
    swap(file);
    return *this;
}

template<typename T>
List<T>& List<T>::operator = (List<T>&& move)
{
    List file {std::move(move)};
    swap(file);
    return *this;
}

template <typename T>
std::ostream& operator << (std::ostream& COUT, const List<T>& oth)
{
    using Node = class List<T>::Node;
    if(oth.first == nullptr){COUT << "nullptr\n"; return COUT;}
    Node* itrsave;
    Node* lastitr = nullptr;
    Node* itr = oth.first;
    while(itr)
    {
        COUT << itr->data << " -> ";
        itrsave = itr;
        itr = oth.XOR(lastitr, itr->npx);
        lastitr = itrsave;
    }
    COUT << "nullptr\n";
    return COUT;
}

template <typename T>
void List<T>::swap(List& swapped)
{
    std::swap(first, swapped.first);
    std::swap(last, swapped.last);
}

template <typename T>
void  List<T>::push_front(const T& object)
{
    Node* newhead = new Node(object);
    newhead->npx = XOR(nullptr, first);
    if (first != nullptr)
    {
        first->npx = XOR(newhead, XOR(nullptr, first->npx));
    }
    first = newhead;
    if(last == nullptr){last = first;}
    ++size_of_list;
}

template <typename T>
void  List<T>::push_back(const T& object)
{
    Node* newtail = new Node(object);
    newtail->npx = XOR(last, nullptr);
    if(last != nullptr)
    {
        last->npx = XOR(XOR(last->npx, nullptr), newtail);
    }
    last = newtail;
    if (first == nullptr){first = last;}
    ++size_of_list;
}

template <typename T>
void List<T>::pop_front()
{
    if(first == last)
    {
        delete first;
        first = last = nullptr;
        return;
    }
    Node* next = XOR(nullptr, first->npx);
    next->npx = XOR(nullptr, XOR(first, next->npx));
    delete first;
    first = next;
    --size_of_list;
}

template <typename T>
void List<T>::pop_back()
{
    if(last == first)
    {
        delete last;
        last = first = nullptr;
        return;
    }
    Node* prev = XOR(last->npx, nullptr);
    prev->npx = XOR(XOR(prev->npx, last), nullptr);
    delete last;
    last = prev;
    --size_of_list;
}

template<typename T>
bool List<T>::empty()
{
    return first == nullptr;
}

template<typename T>
void List<T>::insert( T& value, std::size_t position)
{
    if((position < 0) || (position > size_of_list))
    {
        std::cout << "Error: out of its length !\nCannot insert your entered position !" << std::endl;
        exit(1);
    }
    if(position == 0)
    {
        push_front(value);
        return;
    }
    if(position == size_of_list)
    {
        push_back(value);
        return;
    }
    
    Node* itrsave;
    Node* lastitr = nullptr;
    Node* itr = first;
    std::size_t i = 0;
    std::size_t j = size_of_list;
    while(j > 0)
    {
        if(i == position)
        {
            push_back(value);
            push_back(itr->data);
        }
        else
        {
            push_back(itr->data);
        }
        ++i;
        
        itrsave = itr;
        itr = XOR(lastitr, itr->npx);
        lastitr = itrsave;
        j = j - 1;
    }

    for(int i = 0; i < size_of_list - 1; ++i)
    {
        pop_front();
    }
}

template<typename T>
void List<T>::size()
{
    std::cout << "Size is: " << size_of_list << std::endl;
}

template<typename T>
void List<T>::clear()
{
    if(first == nullptr){return;}
    Node* itrsave;
    Node* lastitr = nullptr;
    Node* itr = first;
    while(itr)
    {
        itrsave = itr;
        itr = XOR(lastitr, itr->npx);
        if(lastitr){delete lastitr;}
        lastitr = itrsave;
    }
    delete lastitr;
    last = first = nullptr;
    size_of_list = 0;
};

template <typename T>
void List<T>::print_forward()
{
    if(first == nullptr){std::cout << "nullptr\n"; return;}
    Node* itrsave;
    Node* lastitr = nullptr;
    Node* itr = first;
    while(itr)
    {
        std::cout << itr->data << " -> ";
        itrsave = itr;
        itr = XOR(lastitr, itr->npx);
        lastitr = itrsave;
    }
    std::cout << "nullptr" << std::endl;
}

template <typename T>
void List<T>::print_back()
{
    if(last == nullptr){std::cout << "nullptr\n"; return;}
    Node * itrsave;
    Node * lastitr = nullptr;
    Node * itr = last;
    std::cout << "nullptr";
    while (itr)
    {
        std::cout << " <- " << itr->data;
        itrsave = itr;
        itr = XOR(itr->npx, lastitr);
        lastitr = itrsave;
    }
    std::cout << std::endl;
}

template <typename T>
void List<T>::traverse()
{
    Node* itrsave;
    Node* lastitr = nullptr;
    Node* itr = first;
    while(itr)
    {
        itrsave = itr;
        itr = XOR(lastitr, itr->npx);
        lastitr = itrsave;
    }
}

template <typename T>
List<T>::~List()
{
    if(first != nullptr)
    {
        Node* itrsave;
        Node* lastitr = nullptr;
        Node* itr = first;
        while(itr)
        {
            itrsave = itr;
            itr = XOR(lastitr, itr->npx);
            if(lastitr){delete lastitr;}
            lastitr = itrsave;
        }
        delete lastitr;
        last = first = nullptr;
    }
}

template <typename T>
List<T>& List<T>::choosing_operation()
{
    std::cout << "============================================================" << std::endl;
    std::cout << "\t\t\t\t\t\tMAIN MANU\t\t\t" << std::endl;
    std::cout << "============================================================" << std::endl;
    std::cout << std::endl << "Which operation do you choose ?" << std::endl << std::endl;
    std::cout << "\t[1]   Insert \t\n" << "\t[2]   Return the list size \t\n" << "\t[3]   Pop from list \t\n" << "\t[4]   Push inside list \t\n" << "\t[5]   Checking the list emptiness \t\n" << "\t[6]   Clear \t\n" << "\t[7]   Traverse \t\n" << "\t[8]   Print \t\n" << "\t[9]   Exit menu operations \t\n" << "\t[10]  EXIT ALL \t\n" << std::endl;
    int index = 0;
    std::cout << "======================================== Choose by index: ";
    std::cin >> index;
    std::cout << std::endl;
    List<T>::choose(index);
    return *this;
}


template <typename T>
List<T>& List<T>::choose(int index)
{
    switch(index)
        {
            case 1:
                List<T>::choose_insert();
                choosing_operation();
                break;
            case 2:
                List<T>::size();
                std::cout << std::endl;
                choosing_operation();
                break;
            case 3:
                List<T>::choose_pop();
                choosing_operation();
                break;
            case 4:
                List<T>::choose_push();
                choosing_operation();
                break;
            case 5:
                if(empty()){std::cout << "It is empty\n\n";}
                else{std::cout << "It is not empty\n\n";}
                choosing_operation();
                break;
            case 6:
                List<T>::clear();
                std::cout << "List is cleared" << std::endl << std::endl;
                choosing_operation();
                break;
            case 7:
                List<T>::traverse();
                std::cout << "List is traversed" << std::endl << std::endl;
                choosing_operation();
                break;
            case 8:
                List<T>::choose_print();
                choosing_operation();
                break;
            case 9:
                break;
            case 10:
                exit(0);
            default:
                std::cout << "No operation, you have entered a wrong index, try again: ";
                int tryagain = 0;
                std::cin >> tryagain;
                choose(tryagain);
        }
    return *this;
}

template <typename T>
void List<T>::choose_insert()
{
    T val{};
    std::size_t index = 0;
    do{
        std::cout << "Enter the position: ";
        std::cin >> index;
    }while(index < 0 || index > size_of_list);
    std::cout << "Enter the value: ";
    std::cin >> val;
    List<T>::insert(val, index);
    std::cout << "\n";
}

template <typename T>
void List<T>::choose_pop()
{
    std::string tmp;
    do{
    std::cout << "Pop from front or from back: ";
    std::cin >> tmp;
    }while((tmp != "front") && (tmp != "back"));
    if(tmp == "front"){List<T>::pop_front();}
    else{List<T>::pop_back();}
}

template <typename T>
void List<T>::choose_push()
{
    std::string tmp;
    do{
    std::cout << "Push from front or from back: ";
    std::cin >> tmp;
    }while((tmp != "front") && (tmp != "back"));
    T dat{};
    std::cout << "Enter the value to push: ";
    std::cin >> dat;
    if(tmp == "front")
    {
        List<T>::push_front(dat);
    }
    else{List<T>::push_back(dat);}
}

template <typename T>
void List<T>::choose_print()
{
    std::string str = "";
    do{
    std::cout << "Print forward or back: ";
    std::cin >> str;
    }while(str != "forward" && str != "back");
    if(str == "forward"){print_forward();}
    else{print_back();}
    std::cout << std::endl;
}