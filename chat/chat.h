#pragma once
#include <iostream>

template <typename T1, typename T2, typename T3, typename T4, typename T5, typename T6>
class Chat
{
public:
   Chat();
   bool Run();
   ~Chat();

private:
   T3* container;
   T4* messageFactory;
   T5* containerUser;
   T6* userManager;
   T1* sc;  
   
};

template <typename T1, typename T2, typename T3, typename T4, typename T5, typename T6>
Chat<T1, T2, T3, T4, T5, T6>::Chat() : 
    container{ new T3 }, 
    messageFactory{ new T4(container) }, 
    containerUser{ new T5 }, 
    userManager{new T6(containerUser)},
    sc { new T1(new T2(), *messageFactory, *userManager) }
{

}

template <typename T1, typename T2, typename T3, typename T4, typename T5, typename T6>
Chat<T1, T2, T3, T4, T5, T6>::~Chat()
{
    delete container;
    delete messageFactory;
    delete containerUser;
    delete userManager;
    delete sc;
}

template <typename T1, typename T2, typename T3, typename T4, typename T5, typename T6>
bool Chat<T1, T2, T3, T4, T5, T6>::Run()
{
   return sc-> Handle();
}