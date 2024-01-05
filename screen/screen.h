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
private:
    std::string name;

protected:
    Auxiliary<std::string> oAuxiliary;

public:
    Screen(const std::string& name)
        : name(name) {}
    std::string GetName() const
    {
        return name;
    }
    virtual bool Handle(tScreenContext* screenContext) = 0;
};

class InvitationScreen : public Screen
{
public:
    InvitationScreen() : Screen("InvitationScreen") {}
    virtual bool Handle(tScreenContext* screenContext) override;
};

class LoginScreen : public Screen
{
public:
    LoginScreen() : Screen("LoginScreen") {}
    virtual bool Handle(tScreenContext* screenContext) override;
};

class  SignInScreen : public Screen
{
public:
    SignInScreen() : Screen("SignInScreen") {}
    virtual bool Handle(tScreenContext* screenContext) override;
};

class  ShowMessagesScreen : public Screen
{
public:
    ShowMessagesScreen() : Screen("ShowMessagesScreen") {}
    virtual bool Handle(tScreenContext* screenContext) override;
};

class  EditMessagesScreen : public Screen
{
public:
    EditMessagesScreen() : Screen("EditMessagesScreen") {}
    virtual bool Handle(tScreenContext* screenContext) override;
};

bool InvitationScreen::Handle(tScreenContext* screenContext)
{
    bool bRetValue = true;
    std::cout << std::endl << oAuxiliary.name << "Please Make a choice:" << oAuxiliary.reset << std::endl;
    std::cout << oAuxiliary.choice1 << "0: Login" << oAuxiliary.reset << std::endl;
    std::cout << oAuxiliary.choice2 << "1: Sign In" << oAuxiliary.reset << std::endl;
    std::cout << oAuxiliary.choice3 << "2: Exit" << oAuxiliary.reset << std::endl;
    std::string choice = oAuxiliary.GetUserChoice();
    if (choice == "0")
    {
        screenContext->SetScreen(new LoginScreen());
    }
    else if (choice == "1")
    {
        screenContext->SetScreen(new SignInScreen());
    }
    else if (choice == "2")
    {
        bRetValue = false;
    }
    return bRetValue;
}

bool LoginScreen::Handle(tScreenContext* screenContext)
{
    bool retValue = true;
    do
    {
        screenContext->GetUserManager().CreateUser();
        std::cout << std::endl << oAuxiliary.name << "Please Make a choice:" << oAuxiliary.reset << std::endl;
        std::cout << oAuxiliary.choice1 << "0: Back to main menu " << oAuxiliary.reset << std::endl;
        std::cout << oAuxiliary.choice2 << "1: Do log in with an existing account " << oAuxiliary.reset << std::endl;
        std::cout << oAuxiliary.choice3 << "2: Exit from chat " << oAuxiliary.reset << std::endl;
        std::cout << oAuxiliary.choice4 << "Any key: Create an account " << oAuxiliary.reset << std::endl;
        std::string choice = oAuxiliary.GetUserChoice();
        if (choice == "0")
        {
            screenContext->SetScreen(new InvitationScreen());
            break;
        }
        else if (choice == "1")
        {
            screenContext->SetScreen(new SignInScreen());
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

bool SignInScreen::Handle(tScreenContext* screenContext)
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
           screenContext->SetScreen(new InvitationScreen());
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
              screenContext->SetScreen(new ShowMessagesScreen());
              break;
           }    
       }
       else if (choice == "3")
       {
           if (screenContext->GetUserManager().isUserAutorized())
           {
               screenContext->SetScreen(new EditMessagesScreen());
               break;
           }
       }
   } while (1);
   return retValue;
}

bool ShowMessagesScreen::Handle(tScreenContext* screenContext)
{
   bool retValue = true;
   do
   {
       std::cout << oAuxiliary.choice0 << "Messages for " << screenContext->GetUserManager().GetCurrentUser() << std::endl;
       screenContext->GetMessageFactory().GetMessage(screenContext->GetUserManager().GetCurrentUser());
       std::cout << oAuxiliary.name << "Please Make a choice:" << oAuxiliary.reset << std::endl;
       std::cout << oAuxiliary.choice1 << "0: Back to main menu " << oAuxiliary.reset << std::endl;
       std::cout << oAuxiliary.choice2 << "1: Exit from chat " << oAuxiliary.reset << std::endl;
       std::cout << oAuxiliary.choice3 << "2: Leave the current account and do log in with new existing account " << oAuxiliary.reset << std::endl;
       std::cout << oAuxiliary.choice4 << "3: Write new messsage" << oAuxiliary.reset << std::endl;
       std::cout << oAuxiliary.choice5 << "Any key: Read messsage" << oAuxiliary.reset << std::endl;
       std::string choice = oAuxiliary.GetUserChoice();
       if (choice == "0")
       {
           screenContext->SetScreen(new InvitationScreen());
           break;
       }
       else if (choice == "1")
       {
           retValue = false;
           break;
       }
       else if (choice == "2")
       {
           screenContext->SetScreen(new SignInScreen());
           break;
       }
       else if (choice == "3")
       {
           screenContext->SetScreen(new EditMessagesScreen());
           break;
       }
   } while (1);
   return retValue;
}

bool EditMessagesScreen::Handle(tScreenContext* screenContext)
{
   bool retValue = true;
   do
   {
       std::cout << oAuxiliary.choice0 << "Messages from " << screenContext->GetUserManager().GetCurrentUser() << std::endl;
       screenContext->GetMessageFactory().SetMessage(screenContext->GetUserManager().GetCurrentUser());
       std::cout << std::endl << oAuxiliary.name << "Please Make a choice:" << oAuxiliary.reset << std::endl;
       std::cout << oAuxiliary.choice1 << "0: Back to main menu " << oAuxiliary.reset << std::endl;
       std::cout << oAuxiliary.choice2 << "1: Exit from chat " << oAuxiliary.reset << std::endl;
       std::cout << oAuxiliary.choice3 << "2: Leave the current account and do log in with new existing account " << oAuxiliary.reset << std::endl;
       std::cout << oAuxiliary.choice4 << "3: Read messsage" << oAuxiliary.reset << std::endl;
       std::cout << oAuxiliary.choice5 << "Any key: Write new messsage" << oAuxiliary.reset << std::endl;
       std::string choice = oAuxiliary.GetUserChoice();
       if (choice == "0")
       {
           screenContext->SetScreen(new InvitationScreen());
           break;
       }
       else if (choice == "1")
       {
           retValue = false;
           break;
       }
       else if (choice == "2")
       {
           screenContext->SetScreen(new SignInScreen());
           break;
       }
       else if (choice == "3")
       {
           screenContext->SetScreen(new ShowMessagesScreen());
           break;
       }
   } while (1);
   return retValue;
}
