#include<string>
#include<iostream>

#include "..\screencontext\screencontext.h"

class Screen;

using tScreenContext = ScreenContext<Screen>;

class Screen
{
private:
    std::string name;
	
public:
    Screen(const std::string& name)
        : name(name) {}
    std::string GetName() const
    {
        return name;
    }
    virtual bool Handle(tScreenContext* screenContext, int choice) = 0;
};

class InvitationScreen : public Screen
{
public:
   InvitationScreen() : Screen("InvitationScreen") {}
   virtual bool Handle(tScreenContext* screenContext, int choice) override;
};

class LoginScreen : public Screen
{
public:
   LoginScreen() : Screen("LoginScreen") {}
   virtual bool Handle(tScreenContext* screenContext, int choice) override;
};

class  SignInScreen: public Screen
{
public:
   SignInScreen() : Screen("SignInScreen") {}
   virtual bool Handle(tScreenContext* screenContext, int choice) override;
};

class  ShowMessagesScreen: public Screen
{
public:
   ShowMessagesScreen() : Screen("ShowMessagesScreen") {}
   virtual bool Handle(tScreenContext* screenContext, int choice) override;
};

class  EditMessagesScreen: public Screen
{
public:
   EditMessagesScreen() : Screen("EditMessagesScreen") {}
   virtual bool Handle(tScreenContext* screenContext, int choice) override;
};

bool InvitationScreen::Handle(tScreenContext* screenContext, int choice)
{
   bool bRetValue = true;
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

bool LoginScreen::Handle(tScreenContext* screenContext, int choice)
{
   if(choice == 0)
   {
      screenContext->SetScreen(new InvitationScreen());
   }
   return true;
}

bool SignInScreen::Handle(tScreenContext* screenContext, int choice)
{
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

bool ShowMessagesScreen::Handle(tScreenContext* screenContext, int choice)
{
   if(choice == 0)
   {
      screenContext->SetScreen(new SignInScreen());
   }
   return true;
}

bool EditMessagesScreen::Handle(tScreenContext* screenContext, int choice)
{
   if(choice == 0)
   {
      screenContext->SetScreen(new SignInScreen());
   }
   return true;
}
