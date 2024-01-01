#include<iostream>

template <typename T>
class ScreenContext
{
private: 
   T* activeScreen;
   
public:
   ScreenContext(T* screen) : activeScreen(screen) {};
   
   bool Handle(int choice)
   {
      std::cout << choice << " "  << activeScreen->GetName(); 
	  return activeScreen->Handle(this, choice);
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
