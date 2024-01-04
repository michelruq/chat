#include <iostream>
#include <string>
#include "../message/message.h"

template <typename TContainer>
class MessageFactory
{
private:
   TContainer* _container;

public:
    MessageFactory(TContainer* container) : _container{ container } {};
   ~MessageFactory() = default;
   
   void SetMessage()
   {
       std::string to, text;
       std::cin >> to;
       std::cout << "Text: ";
       std::cin.ignore();
       getline(std::cin, text);
       _container->addItem(Message{"Me", to, text});
   }
   
   void GetMessage()
   {
      int index{ 0 };
      std::cout << "Please enter index";
      std::cin >> index;
      Message temp = _container->getItem(index);
      std::cout << temp.GetFrom() << std::endl;
      std::cout << temp.GetTo() << std::endl;
      std::cout << temp.GetText() << std::endl;
   }

};