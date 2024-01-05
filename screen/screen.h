#pragma once

#include<string>
#include<iostream>

#include "../auxiliary/auxiliary.h"
#include "../screencontext/screencontext.h"
#include "../container/container.h"
#include "../messagefactory/messagefactory.h"
#include "../message/message.h"
#include "../user/user.h"
#include "../usermanager/usermanager.h"

using tContainerForMessage = Container<Message>;
using tContainerForUser = Container<User>;
using tMessageFactory = MessageFactory<tContainerForMessage>;
using tUserManager = UserManager<tContainerForUser>;

class Screen;

using tScreenContext = ScreenContext<Screen, tMessageFactory, tUserManager>;

class Screen
{

protected:
    Auxiliary<std::string> oAuxiliary;

public:
    Screen() = default;
    virtual bool Handle(tScreenContext* screenContext) = 0;
};

class MainMenuScreen : public Screen
{
public:
    MainMenuScreen() : Screen() {}
    virtual bool Handle(tScreenContext* screenContext) override;
};

class CreateAccountScreen : public Screen
{
public:
    CreateAccountScreen() : Screen() {}
    virtual bool Handle(tScreenContext* screenContext) override;
};

class  LoginScreen : public Screen
{
public:
    LoginScreen() : Screen() {}
    virtual bool Handle(tScreenContext* screenContext) override;
};

class  ReadMessagesScreen : public Screen
{
public:
    ReadMessagesScreen() : Screen() {}
    virtual bool Handle(tScreenContext* screenContext) override;
};

class  WriteMessagesScreen : public Screen
{
public:
    WriteMessagesScreen() : Screen() {}
    virtual bool Handle(tScreenContext* screenContext) override;
};

bool MainMenuScreen::Handle(tScreenContext* screenContext)
{
    bool bRetValue = true;
    std::cout << std::endl << oAuxiliary.name << "Please Make a choice:" << oAuxiliary.reset << std::endl;
    std::cout << oAuxiliary.choice1 << "0: Create an account" << oAuxiliary.reset << std::endl;
    std::cout << oAuxiliary.choice2 << "1: Do log in with any existing account" << oAuxiliary.reset << std::endl;
    std::cout << oAuxiliary.choice3 << "2: Exit" << oAuxiliary.reset << std::endl;
    std::string choice = oAuxiliary.GetUserChoice();
    if (choice == "0")
    {
        screenContext->SetScreen(new CreateAccountScreen());
    }
    else if (choice == "1")
    {
        screenContext->SetScreen(new LoginScreen());
    }
    else if (choice == "2")
    {
        bRetValue = false;
    }
    return bRetValue;
}

bool CreateAccountScreen::Handle(tScreenContext* screenContext)
{
    bool retValue = true;
    do
    {
        screenContext->GetUserManager().CreateUser();
        std::cout << std::endl << oAuxiliary.name << "Please Make a choice:" << oAuxiliary.reset << std::endl;
        std::cout << oAuxiliary.choice1 << "0: Back to main menu " << oAuxiliary.reset << std::endl;
        std::cout << oAuxiliary.choice2 << "1: Do log in with any existing account " << oAuxiliary.reset << std::endl;
        std::cout << oAuxiliary.choice3 << "2: Exit from chat " << oAuxiliary.reset << std::endl;
        std::cout << oAuxiliary.choice4 << "Any key: Create an account " << oAuxiliary.reset << std::endl;
        std::string choice = oAuxiliary.GetUserChoice();
        if (choice == "0")
        {
            screenContext->SetScreen(new MainMenuScreen());
            break;
        }
        else if (choice == "1")
        {
            screenContext->SetScreen(new LoginScreen());
            break;
        }
        else if (choice == "2")
        {
            retValue = false;
            break;
        }
    } while (1);
    return retValue;
}

bool LoginScreen::Handle(tScreenContext* screenContext)
{
   bool retValue = true;
   do
   {
       screenContext->GetUserManager().CheckUser();
       std::cout << std::endl << oAuxiliary.name << "Please Make a choice:" << oAuxiliary.reset << std::endl;
       std::cout << oAuxiliary.choice1 << "0: Back to main menu " << oAuxiliary.reset << std::endl;
       std::cout << oAuxiliary.choice2 << "1: Exit from chat " << oAuxiliary.reset << std::endl;
       if (screenContext->GetUserManager().isUserAutorized())
       {
           std::cout << oAuxiliary.choice3 << "2: Read messsage" << oAuxiliary.reset << std::endl;
           std::cout << oAuxiliary.choice4 << "3: Write message" << oAuxiliary.reset << std::endl;
       }
       std::cout << oAuxiliary.choice5 << "Any key: Do log in with an existing account " << oAuxiliary.reset << std::endl;
       std::string choice = oAuxiliary.GetUserChoice();
       if (choice == "0")
       {
           screenContext->SetScreen(new MainMenuScreen());
           break;
       }
       else if (choice == "1")
       {
           retValue = false;
           break;
       }
       else if (choice == "2")
       {
           if (screenContext->GetUserManager().isUserAutorized())
           {
              screenContext->SetScreen(new ReadMessagesScreen());
              break;
           }    
       }
       else if (choice == "3")
       {
           if (screenContext->GetUserManager().isUserAutorized())
           {
               screenContext->SetScreen(new WriteMessagesScreen());
               break;
           }
       }
   } while (1);
   return retValue;
}

bool ReadMessagesScreen::Handle(tScreenContext* screenContext)
{
   bool retValue = true;
   do
   {
       std::cout << oAuxiliary.choice0 << "Messages for " << screenContext->GetUserManager().GetCurrentUser() << std::endl;
       screenContext->GetMessageFactory().GetMessage(screenContext->GetUserManager().GetCurrentUser());
       std::cout << oAuxiliary.name << "Please Make a choice:" << oAuxiliary.reset << std::endl;
       std::cout << oAuxiliary.choice1 << "0: Back to main menu " << oAuxiliary.reset << std::endl;
       std::cout << oAuxiliary.choice2 << "1: Exit from chat " << oAuxiliary.reset << std::endl;
       std::cout << oAuxiliary.choice3 << "2: Do log in with any existing account " << oAuxiliary.reset << std::endl;
       std::cout << oAuxiliary.choice4 << "3: Write new messsage" << oAuxiliary.reset << std::endl;
       std::cout << oAuxiliary.choice5 << "Any key: Read messsage" << oAuxiliary.reset << std::endl;
       std::string choice = oAuxiliary.GetUserChoice();
       if (choice == "0")
       {
           screenContext->SetScreen(new MainMenuScreen());
           break;
       }
       else if (choice == "1")
       {
           retValue = false;
           break;
       }
       else if (choice == "2")
       {
           screenContext->SetScreen(new LoginScreen());
           break;
       }
       else if (choice == "3")
       {
           screenContext->SetScreen(new WriteMessagesScreen());
           break;
       }
   } while (1);
   return retValue;
}

bool WriteMessagesScreen::Handle(tScreenContext* screenContext)
{
   bool retValue = true;
   do
   {
       std::cout << oAuxiliary.choice0 << "Messages from " << screenContext->GetUserManager().GetCurrentUser() << std::endl;
       screenContext->GetMessageFactory().SetMessage(screenContext->GetUserManager().GetCurrentUser());
       std::cout << std::endl << oAuxiliary.name << "Please Make a choice:" << oAuxiliary.reset << std::endl;
       std::cout << oAuxiliary.choice1 << "0: Back to main menu " << oAuxiliary.reset << std::endl;
       std::cout << oAuxiliary.choice2 << "1: Exit from chat " << oAuxiliary.reset << std::endl;
       std::cout << oAuxiliary.choice3 << "2: Do log in with any existing account " << oAuxiliary.reset << std::endl;
       std::cout << oAuxiliary.choice4 << "3: Read messsage" << oAuxiliary.reset << std::endl;
       std::cout << oAuxiliary.choice5 << "Any key: Write new messsage" << oAuxiliary.reset << std::endl;
       std::string choice = oAuxiliary.GetUserChoice();
       if (choice == "0")
       {
           screenContext->SetScreen(new MainMenuScreen());
           break;
       }
       else if (choice == "1")
       {
           retValue = false;
           break;
       }
       else if (choice == "2")
       {
           screenContext->SetScreen(new LoginScreen());
           break;
       }
       else if (choice == "3")
       {
           screenContext->SetScreen(new ReadMessagesScreen());
           break;
       }
   } while (1);
   return retValue;
}
