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
    Auxiliary<int> oAuxiluary;

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
    std::cout << std::endl;
    std::cout << oAuxiluary.name << "Please Make a choice:" << oAuxiluary.reset << std::endl;
    std::cout << oAuxiluary.choice1 << "0: Login" << oAuxiluary.reset << std::endl;
    std::cout << oAuxiluary.choice2 << "1: Sign In" << oAuxiluary.reset << std::endl;
    std::cout << oAuxiluary.choice3 << "2: Exit" << oAuxiluary.reset << std::endl;
    int choice = oAuxiluary.GetUserChoice();
    if (choice == 0)
    {
        screenContext->SetScreen(new LoginScreen());
    }
    else if (choice == 1)
    {
        screenContext->SetScreen(new SignInScreen());
    }
    else if (choice == 2)
    {
        bRetValue = false;
    }
    return bRetValue;
}

bool LoginScreen::Handle(tScreenContext* screenContext)
{
    std::cout << std::endl;
    std::cout << oAuxiluary.name << "1: Please Make a choice:" << oAuxiluary.reset << std::endl;
    std::cout << oAuxiluary.choice1 << "0: Invitation Screen" << oAuxiluary.reset << std::endl;
    int choice = oAuxiluary.GetUserChoice();
    if (choice == 0)
    {
        screenContext->SetScreen(new InvitationScreen());
    }
    else if (choice == 1)
    {
        screenContext->GetUserManager().CreateUser();
    }
   return true;
}

bool SignInScreen::Handle(tScreenContext* screenContext)
{
   std::cout << std::endl;
   std::cout << oAuxiluary.name << "3: Please Make a choice:" << oAuxiluary.reset << std::endl;
   std::cout << oAuxiluary.choice1 << "0: Show Messsage" << oAuxiluary.reset << std::endl;
   std::cout << oAuxiluary.choice2 << "1: Enter Message" << oAuxiluary.reset << std::endl;
   std::cout << oAuxiluary.choice3 << "2: Invitation Screen" << oAuxiluary.reset << std::endl;
   int choice = oAuxiluary.GetUserChoice();
   if(choice == 0)
   {
       if (screenContext->GetUserManager().isUserAutorized())
       {
          screenContext->SetScreen(new ShowMessagesScreen());
       }
       else
       {
           std::cout << "you can not show message, because you are not autorized" << std::endl;
       }
       
   }
   else if(choice == 1)
   {
       if (screenContext->GetUserManager().isUserAutorized())
       {
           screenContext->SetScreen(new EditMessagesScreen());
       }
       else
       {
           std::cout << "you can not edit message, because you are not autorized" << std::endl;
       }
   }
   else if(choice == 2)
   {
      screenContext->SetScreen(new InvitationScreen());
   }
   else if (choice == 3)
   {
       screenContext->GetUserManager().CheckUser();
   }
   return true;
}

bool ShowMessagesScreen::Handle(tScreenContext* screenContext)
{
   std::cout << std::endl;
   std::cout << oAuxiluary.name << "Please Make a choice:" << oAuxiluary.reset << std::endl;
   std::cout << oAuxiluary.choice1 << "0: Sign In" << oAuxiluary.reset << std::endl;
   std::cout << oAuxiluary.choice2 << "1: Enter Message" << oAuxiluary.reset << std::endl;
   std::cout << oAuxiluary.choice3 << "2: Show Message" << oAuxiluary.reset << std::endl;
   int choice = oAuxiluary.GetUserChoice();
   if(choice == 0)
   {
      screenContext->SetScreen(new SignInScreen());
   }
   else if (choice == 1)
   {
      screenContext->SetScreen(new EditMessagesScreen());
   }
   else if (choice == 2)
   {
       std::cout << "Messages for " << screenContext->GetUserManager().GetCurrentUser() << std::endl;
       screenContext->GetMessageFactory().GetMessage();
   }
   return true;
}

bool EditMessagesScreen::Handle(tScreenContext* screenContext)
{
   std::cout << std::endl;
   std::cout << oAuxiluary.name << "Please Make a choice:" << oAuxiluary.reset << std::endl;
   std::cout << oAuxiluary.choice1 << "0: Sign In" << oAuxiluary.reset << std::endl;
   std::cout << oAuxiluary.choice2 << "1: Show Messsage" << oAuxiluary.reset << std::endl;
   std::cout << oAuxiluary.choice3 << "2: Edit Message" << oAuxiluary.reset << std::endl;
   int choice = oAuxiluary.GetUserChoice();
   if(choice == 0)
   {
      screenContext->SetScreen(new SignInScreen());
   }
   else if (choice == 1)
   {
      screenContext->SetScreen(new ShowMessagesScreen());
   }
   else if (choice == 2)
   {
       std::cout << "Messages from " << screenContext->GetUserManager().GetCurrentUser() << std::endl;
       screenContext->GetMessageFactory().SetMessage();
   }
   return true;
}
