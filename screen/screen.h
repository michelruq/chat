#pragma once

#include<string>
#include<iostream>

#include "../auxiliary/auxiliary.h"
#include "../screencontext/screencontext.h"

class Screen;

using tScreenContext = ScreenContext<Screen>;

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

class  SignInScreen: public Screen
{
public:
   SignInScreen() : Screen("SignInScreen") {}
   virtual bool Handle(tScreenContext* screenContext) override;
};

class  ShowMessagesScreen: public Screen
{
public:
   ShowMessagesScreen() : Screen("ShowMessagesScreen") {}
   virtual bool Handle(tScreenContext* screenContext) override;
};

class  EditMessagesScreen: public Screen
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
   if(choice == 0)
   {
      screenContext->SetScreen(new LoginScreen());
   }
   else if(choice == 1)
   {
      screenContext->SetScreen(new SignInScreen());
   }
   else if(choice == 2)
   {
      bRetValue = false;
   }
   return bRetValue;
}

bool LoginScreen::Handle(tScreenContext* screenContext)
{
   std::cout << std::endl;
   std::cout << oAuxiluary.name << "Please Make a choice:" << oAuxiluary.reset << std::endl;
   std::cout << oAuxiluary.choice1 << "0: Invitation Screen" << oAuxiluary.reset << std::endl;
   int choice = oAuxiluary.GetUserChoice();
   if(choice == 0)
   {
      screenContext->SetScreen(new InvitationScreen());
   }
   return true;
}

bool SignInScreen::Handle(tScreenContext* screenContext)
{
   std::cout << std::endl;
   std::cout << oAuxiluary.name << "Please Make a choice:" << oAuxiluary.reset << std::endl;
   std::cout << oAuxiluary.choice1 << "0: Show Messsage" << oAuxiluary.reset << std::endl;
   std::cout << oAuxiluary.choice2 << "1: Enter Message" << oAuxiluary.reset << std::endl;
   std::cout << oAuxiluary.choice3 << "2: Invitation Screen" << oAuxiluary.reset << std::endl;
   int choice = oAuxiluary.GetUserChoice();
   if(choice == 0)
   {
      screenContext->SetScreen(new ShowMessagesScreen());
   }
   else if(choice == 1)
   {
      screenContext->SetScreen(new EditMessagesScreen());
   }
   else if(choice == 2)
   {
      screenContext->SetScreen(new InvitationScreen());
   }
   return true;
}

bool ShowMessagesScreen::Handle(tScreenContext* screenContext)
{
   std::cout << std::endl;
   std::cout << oAuxiluary.name << "Please Make a choice:" << oAuxiluary.reset << std::endl;
   std::cout << oAuxiluary.choice1 << "0: Sign In" << oAuxiluary.reset << std::endl;
   std::cout << oAuxiluary.choice2 << "1: Enter Message" << oAuxiluary.reset << std::endl;
   int choice = oAuxiluary.GetUserChoice();
   if(choice == 0)
   {
      screenContext->SetScreen(new SignInScreen());
   }
   else if (choice == 1)
   {
      screenContext->SetScreen(new EditMessagesScreen());
   }
   return true;
}

bool EditMessagesScreen::Handle(tScreenContext* screenContext)
{
   std::cout << std::endl;
   std::cout << oAuxiluary.name << "Please Make a choice:" << oAuxiluary.reset << std::endl;
   std::cout << oAuxiluary.choice1 << "0: Sign In" << oAuxiluary.reset << std::endl;
   std::cout << oAuxiluary.choice2 << "1: Show Messsage" << oAuxiluary.reset << std::endl;
   int choice = oAuxiluary.GetUserChoice();
   if(choice == 0)
   {
      screenContext->SetScreen(new SignInScreen());
   }
   else if (choice == 1)
   {
      screenContext->SetScreen(new ShowMessagesScreen());
   }
   return true;
}
