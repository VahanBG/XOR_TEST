#include "list_header.h"

int main()
{

     //test cosntructors
  /* List<int> list1{1,2,3,4,5,6,7,8};
    List<int> list2(10);
    List<int> list3;
  /*  List<int> list4(-11);
    List<int> list5(111700);
    List<int> list6{1,2,3,4,5,6,7,8 ,1,2,3,4,5,6,7,8};*/
    List<int> list1{1,2,3,4,5,6,7,8};
    List<int> list2(10);
    List<int> list3(list1);
     int val = -1555;
    list1.print_forward();
    list2.print_forward();
    list3.print_forward();
     list1.insert(val , 0);
     list1.print_forward();
    
    
   /* std::cout << "Your initial list below\n";
    list1.print_forward();
    list2.print_forward();
    list3.print_forward();
     list4.print_forward();
      list5.print_forward();
       list6.print_forward();*/
     
     // test insert() ,size() ,push_front() ,push_back() , pop_back(), pop_front() ,empty()
 /*    List<int> list1{1,2,3,4,5,6,7,8};
     list1.print_forward();
     int val = -1555;
     int position = 8;
     
     list1.insert(val,position);
     list1.print_forward();*/
     //list1.size();
  /*  list1.push_front(val);
    list1.print_forward();
    list1.push_front(val);
    list1.print_forward();
    list1.push_front(0);
    list1.print_forward();
    list1.push_back(0);
    list1.print_forward();
    list1.push_back(val);
    list1.print_forward();
    list1.pop_back();
    list1.pop_front();
    list1.print_forward();
    list1.pop_back();
    list1.print_forward();
    list1.pop_front();
    list1.pop_front();    
    list1.print_forward();*/
 //   List<int> list3;
   // std::cout<<list1.empty();
    //std::cout<<list3.empty();
   // list1.clear();
    //std::cout<<list1.empty();
    //list1.print_forward();
  //   list1.traverse();
 //    list1.print_forward();
//
    
   /* int val = 9;
    list1.insert(val, 4);
    list2.push_front(val);
    list2.push_back(val);
    list1.pop_back();
    list1.pop_front();
    
    list1.traverse();*/
   /*  List<int> list1{1,2,3,4,5,6,7,8};
    List<int> list2(10);
    List<int> list3;
    //list1.insert(10,5);
    //list1.print_forward();
    
    list1.choosing_operation();*/
   // list2.choosing_operation();
   // list3.choosing_operation();
    
   /* std::cout << std::endl << "Your results below\n";
    std::cout << list1 << list2 << list3 << std::endl;*/
    
  //  list1.empty() ? std::cout << "List1 is empty\n" : std::cout << "List1 is not empty\n";
    //list1.size();
   // list2.empty() ? std::cout << "List2 is empty\n" : std::cout << "List2 is not empty\n";
   // list2.size();
   // list3.empty() ? std::cout << "List3 is empty\n" : std::cout << "List3 is not empty\n";
   // list3.size();
    
/*    std::cout << "\nClearing\n";
    list1.clear();
    list2.clear();
    list3.clear();
    list1.empty() ? std::cout << "List1 is empty\n" : std::cout << "List1 is not empty\n";
    list2.empty() ? std::cout << "List2 is empty\n" : std::cout << "List2 is not empty\n";
    list3.empty() ? std::cout << "List3 is empty\n" : std::cout << "List3 is not empty\n";
    */
   
    
    return 0;
}
