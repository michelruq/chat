#pragma once
#include<iostream>

template <typename T>
class ScreenContext
{
private: 
   T* activeScreen;
   
public:
   ScreenContext(T* screen) : activeScreen(screen) {};
   
   bool Handle()
   {
      std::cout << activeScreen->GetName(); 
	  return activeScreen->Handle(this);
   }
   
   void SetScreen(T* newScreen)
    {
        std::cout << "Changing state from " << activeScreen->GetName()
                  << " to " << newScreen->GetName() << "..." << std::endl;
        delete activeScreen;
        activeScreen = newScreen;
    }  
   
   ~ScreenContext()
   {
      delete activeScreen;
   }
};
