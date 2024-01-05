#pragma once
#include <iostream>
#include <string>



template <typename T>
class Auxiliary
{
public: 
    Auxiliary() = default;
   ~Auxiliary() = default;
   
   T GetUserChoice()
   {
       T returnValue;
       std::cin >> returnValue;
       return returnValue;
   }

   const std::string reset = "\033[0m";
   const std::string name = "\033[1m\033[4m\033[31m";
   const std::string choice1 = "\033[1m\033[32m";
   const std::string choice2 = "\033[1m\033[33m";
   const std::string choice3 = "\033[1m\033[34m";
   const std::string choice4 = "\033[1m\033[35m";
   const std::string choice5 = "\033[1m\033[36m";
   const std::string choice0 = "\033[1m\033[37m";
};