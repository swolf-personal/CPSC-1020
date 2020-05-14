/*The program as it is below prints 20.  This is not the behavior I was
 *expecting I was expecting this to print 30.  Change this program so that when
 *I run it 30 will print. */


#include <stdio.h>

/*This program demonstrasts the problem with passing by value rather than
 *pass by reference (pointer)*/
void fun(int x);
int main()
{
  int y = 20;
  /*With respect to memory, what happens when we pass a variable to a
   *function by value???  The actual variable is not passed in, a copy of the
   *variable is made.*/

  fun(y);

  printf("%d \n", y);
  return 0;
}
/*Does x get changed in this function???*/
void fun(int x)
{/*You know the saying  "What happens in Vegas stays in Vegas!"" Well this is
   *the same principle here!!!*/  
    x = 30;
}
