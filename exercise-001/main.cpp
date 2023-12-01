#include <stdio.h>
  int a;
  int c = 0;
  int b = 100;
  const int d = 42;
int main() {
  printf("Address of a: %p value: %d \n",&a,a);
  printf("Address of b: %p value: %d \n",&b,b);
  printf("Address of c: %p value: %d \n",&c,c);
  printf("Address of d: %p value: %d \n",&d,d);
  printf("sizeof(int): %lu\n",sizeof(int));
  return 0;
}