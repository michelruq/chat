#pragma once
#include <iostream>
#include <string>
#include "../user/user.h"

template <typename TContainer>
class UserManager
{
private:
   TContainer* _container;
   User* _activeUser;

public:
    UserManager(TContainer* container) : _container{ container }, _activeUser{ nullptr } {};
   ~UserManager() = default;
   
   void CreateUser()
   {
       std::string login, password;
       std::cout << "Please create new login, start with your login";
       std::cin >> login;
       std::cout << "Password: ";
       std::cin.ignore();
       getline(std::cin, password);
       _container->addItem(User{ login, password, "Me" });
   }
   
   void CheckUser()
   {
       std::string login;
       std::cout << "Please enter your login";
       std::cin >> login;
       int counter = int{ 0 };
       for (int i{ 0 }; i < 5; ++i)
       {
           User temp = _container->getItem(i);
           if (login == temp.GetUserLogin())
           {
               std::string password;
               std::cout << "login is existing";
               std::cout << "Please enter your password";
               std::cin >> password;
               if (password == temp.GetUserPassword())
               {
                   std::cout << "password is correct";
                   std::cout << "welcome to chat " << temp.GetUserName();
                   _activeUser = new User(temp.GetUserLogin(), temp.GetUserPassword(), temp.GetUserName());
                   break;
               }
               else
               {
                   std::cout << "password isn't correct";
               }
           }
           ++counter;
       }
       if (counter == 5)
       {
           std::cout << "no item with this login";
       }
   }
   
   std::string GetCurrentUser()
   {
       return _activeUser->GetUserName();
   }

   bool isUserAutorized()
   {
       return (_activeUser != nullptr);
   }
};