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
	  return activeScreen->Handle(this);
   }
   
   void SetScreen(T* newScreen)
    {
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
