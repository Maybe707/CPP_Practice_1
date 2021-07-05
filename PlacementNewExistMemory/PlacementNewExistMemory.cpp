#include <iostream>
 
struct Simple {
  Simple(int val)
    : field(val) {}
 
  int field;
};
 
int main() {
  char another_memory[sizeof(Simple)] {};
  Simple *simple_ptr = (Simple *)another_memory;
 
  std::cout << simple_ptr->field << std::endl;
 
  new (simple_ptr) Simple { 42 };
  std::cout << simple_ptr->field << std::endl;
 
  new (simple_ptr) Simple { 123 };
  std::cout << simple_ptr->field << std::endl;
 
  new (simple_ptr) char[sizeof another_memory] { 56 };
  std::cout << simple_ptr->field << std::endl;
 
  return 0;
}
