#include <iostream>

class Program
{
  string str = "Hello bich!";
  char c = 'x';
};

class StringExtention
{
  static int charCount(this string str, char value)
  {
    int counter = 0;
    for (int i = 0; i < 11; ++i)
      {
        if (str[i] == c)
          counter++;
      }
      return counter;
  }
};

int main()
{
  StringExtention obj;
  Program pr;
  
  std::cout << obj.charCount(pr.c) << std::endl;
  
  return 0;
}

















