#include <iostream>
/*
int foonc2(int *var, int *sum);

int foonc1(int *var, int *sum)
{
    if(*var > 1)
    {
        foonc2(var, sum);
    }
    sum = 1;
}

int foonc2(int *var, int *sum)
{
    *var--;
    foonc1(var, sum);
    *var++;
    *sum = *var*(*sum);
}

int main()
{
    int sum = 1;
    int *sumPointer = &sum;
    int variable = 0;
    int *pointer = &variable;
    std::cout << foonc1(pointer, sumPointer) << std::endl;
    return 0;
}
*/
    
/*    
unsigned proc_fact(unsigned); 

int main() {
  register unsigned n = 3;                    // mov $3, %bx
  std::cout << proc_fact(n) << std::endl;                               // call proc_fact;
}

unsigned proc_fact(register unsigned n) {     
  register unsigned result;
  
  if(n > 1)                                   // cmp %bl, $1
      goto do_calculate;                      // jg do_calculate
  
  result = 1;                                 // mov $1, %al
  return result;                              // ret
  
do_calculate:
    --n;                                      // dec %bl
    result = proc_fact(n);                    // call proc_fact
    ++n;                                      // inc %bl
    result *= n;                              // mul %bl
    return result;                            // ret
} */

unsigned do_calculate(register unsigned n, unsigned result);
    
unsigned proc_fact(register unsigned n, unsigned result); 

int main() 
{
  register unsigned result = 0;
  register unsigned n = 3;                    // mov $3, %bx
  std::cout << proc_fact(n, result) << std::endl;                               // call proc_fact;
}

unsigned proc_fact(register unsigned n, unsigned result) 
{     
  if(n > 1)                                   // cmp %bl, $1
        do_calculate(n, result);                      // jg do_calculate
  
  result = 1;                                 // mov $1, %al
  return result;                              // ret
}


unsigned do_calculate(register unsigned n, unsigned result)
{
    --n;                                      // dec %bl
    result = proc_fact(n, result);                    // call proc_fact
    ++n;                                      // inc %bl
    result *= n;                              // mul %bl
    return result;                            // ret
}


