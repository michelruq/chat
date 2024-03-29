#pragma once
#include <iostream>
#include <string>
#include "../message/message.h"
#include "../auxiliary/auxiliary.h"

template <typename TContainer>
class MessageFactory
{
private:
   TContainer* _container;

public:
    MessageFactory(TContainer* container) : _container{ container } {};
   ~MessageFactory() = default;
   
   void SetMessage( std::string from)
   {
       Auxiliary<std::string> oAuxiliary;
       std::cout << oAuxiliary.choice1 <<  "Please choose the collocutor's user name: " << oAuxiliary.reset << std::endl;
       std::string to = oAuxiliary.GetUserChoice();
       std::cout << oAuxiliary.choice2 << "Enter the message's text: " << oAuxiliary.reset << std::endl;
       std::string text;
       std::cin.ignore();
       getline(std::cin, text);
       _container->push_back(Message{ from, to, text});
   }
   
   void GetMessage(std::string to)
   {
      Auxiliary<std::string> oAuxiliary;
      bool remainMessageExist = false;
      for (const Message& it : *(_container))
      {
          if (((it.GetTo()) == to) || ((it.GetTo()) == "all"))
          {
              std::cout << oAuxiliary.choice1 << "Message from " << it.GetFrom() << oAuxiliary.reset << std::endl;
              std::cout << oAuxiliary.choice2 << "contains text: " << it.GetText() << oAuxiliary.reset << std::endl;
              remainMessageExist = true;
              std::cout << oAuxiliary.choice3 << "Do you need to go ahead? or quit (q) from reading?" << oAuxiliary.reset << std::endl;
              std::string temp = oAuxiliary.GetUserChoice();
              if (temp == "q")
              {
                  break;
              }
              else
              {
                  remainMessageExist = false;
              }
          }
      }
      if (!remainMessageExist)
      {
          std::cout << oAuxiliary.choice2 << "There are no messages for you" << oAuxiliary.reset << std::endl;
      }
   }

};