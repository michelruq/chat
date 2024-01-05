#pragma once
#include <iostream>
#include <string>
#include "../auxiliary/auxiliary.h"
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
       bool LoginExistYet = false;
       Auxiliary<std::string> oAuxiliary;
       std::string login, password, name;
       std::cout << std::endl << oAuxiliary.choice1 << "Please create new login, start with your login" << oAuxiliary.reset << std::endl;
       login = oAuxiliary.GetUserChoice();
       for (int i{ 0 }; i < _container->GetSize(); ++i)
       {
           User* temp = _container->GetPointerToElement(i);
           if (login == temp->GetUserLogin())
           {
               std::cout << "This login is exist yet, please try again";
               LoginExistYet = true;
           }
       }
       if (!LoginExistYet)
       {
           std::cout << oAuxiliary.choice2 << "follow with your name" << oAuxiliary.reset << std::endl;
           name = oAuxiliary.GetUserChoice();
           std::cout << oAuxiliary.choice3 << "complete with password:" << oAuxiliary.reset << std::endl;
           std::cin.ignore();
           getline(std::cin, password);
           _container->AddElement(User{ login, password, name });
           std::cout << oAuxiliary.choice1 << "please check credentials for name: " << oAuxiliary.reset << std::endl;
           std::cout << (_container->GetPointerToElement((_container->GetSize() - 1)))->GetUserName() << std::endl;
           std::cout << oAuxiliary.choice2 << "login: " << oAuxiliary.reset << std::endl;
           std::cout << (_container->GetPointerToElement((_container->GetSize() - 1)))->GetUserLogin() << std::endl;
           std::cout << oAuxiliary.choice3 << "password: " << oAuxiliary.reset << std::endl;
           std::cout << (_container->GetPointerToElement((_container->GetSize() - 1)))->GetUserPassword() << std::endl;
       }
   }
   
   void CheckUser()
   {
       std::cout << std::endl;
       Auxiliary<std::string> oAuxiliary;
       if (_activeUser != nullptr)
       {
           std::cout << oAuxiliary.choice1 << "You are autorized with login  " << _activeUser->GetUserLogin() << oAuxiliary.reset << std::endl;
           std::cout << oAuxiliary.choice2 << "Do you really want to exit (y)?" << oAuxiliary.reset << std::endl;
           std::string exit = oAuxiliary.GetUserChoice();
           if (exit == "y")
           {
               _activeUser = nullptr;
           }
       }
       if (_activeUser == nullptr)
       {
           std::cout << oAuxiliary.choice1 << "Please enter your login: " << oAuxiliary.reset << std::endl;
           std::string login = oAuxiliary.GetUserChoice();
           for (int i{ 0 }; i < _container->GetSize(); ++i)
           {
               User* temp = _container->GetPointerToElement(i);
               if (login == temp->GetUserLogin())
               {
                   std::string password;
                   std::cout << oAuxiliary.choice2 << "login is existing " << oAuxiliary.reset << std::endl;
                   std::cout << oAuxiliary.choice3 << "Please enter your password" << oAuxiliary.reset << std::endl;
                   std::cin >> password;
                   if (password == temp->GetUserPassword())
                   {
                       std::cout << oAuxiliary.name << "password is correct " << oAuxiliary.reset << std::endl;
                       std::cout << oAuxiliary.choice1 << "welcome to chat " << temp->GetUserName() << oAuxiliary.reset << std::endl;
                       _activeUser = _container->GetPointerToElement(i);
                       break;
                   }
                   else
                   {
                       std::cout << oAuxiliary.choice2 << "password isn't correct " << oAuxiliary.reset << std::endl;
                   }
               }
           }
           if (_activeUser == nullptr)
           {
               std::cout << oAuxiliary.choice3 << "you are not authorized" << oAuxiliary.reset << std::endl;
           }
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