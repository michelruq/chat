#include <iostream>

template <typename T1, typename T2>
class Chat
{
public:
   Chat();
   bool Run();
   ~Chat();

private:
   T1* sc;   
};

template <typename T1, typename T2>
Chat<T1, T2>::Chat() : sc{new T1(new T2())}
{

}

template <typename T1, typename T2>
Chat<T1, T2>::~Chat()
{
    delete sc;
}

template <typename T1, typename T2>
bool Chat<T1, T2>::Run()
{
   int temp{ 0 };
   std::cin >> temp;
   return sc-> Handle(temp);
}