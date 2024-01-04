#pragma once
#include<iostream>

template <typename T, typename T2, typename T3>
class ScreenContext
{
private: 
   T* activeScreen;
   T2& _messageFactory;
   T3& _userManager;
   
public:
   ScreenContext(T* screen, T2& messageFactory, T3& userManager) : activeScreen(screen), _messageFactory(messageFactory), _userManager(userManager){};
   
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

   T2& GetMessageFactory()
   {
       return _messageFactory;
   }

   T3& GetUserManager()
   {
       return _userManager;
   }
   
   ~ScreenContext()
   {
      delete activeScreen;
   }
};
