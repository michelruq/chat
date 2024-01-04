#pragma once
#include <iostream>

template<typename T>
class Container
{
private:
    T arr[5] = { {" ", " ", " "}, {" ", " ", " "}, {" ", " ", " "}, {" ", " ", " "}, {" ", " ", " "} };
   int currentItem = int{0};

public:
    Container(){};
   ~Container() = default;
   
   void addItem(T item)
   {
      arr[currentItem] = item;
      std::cout << currentItem << "it has been added" << std::endl;
      ++currentItem;
   }

   T getItem( int index )
   {
      return arr[index];
   }
};