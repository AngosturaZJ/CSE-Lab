#include <stdio.h>
#include <stdlib.h>

int bitCount (unsigned int n);

int main(int argc, char* argv[]) {
  if (argc > 2){
    printf("Too many arguments!\n");
  } else if (argc == 1){
    printf("# 1-bits in base 2 representation of %u = %d, should be 0\n", 0, bitCount(0));
    printf("# 1-bits in base 2 representation of %u = %d, should be 1\n", 1, bitCount(1));
    printf("# 1-bits in base 2 representation of %u = %d, should be 16\n", 2863311530u, bitCount(2863311530u));
    printf("# 1-bits in base 2 representation of %u = %d, should be 1\n", 536870912, bitCount(536870912));
    printf("# 1-bits in base 2 representation of %u = %d, should be 32\n", 4294967295u, bitCount(4294967295u));
  } else {
    int result = bitCount(atoi(argv[1]));
    printf("%d\n", result);
  }
  return 0;
}

int bitCount(unsigned int n){
  int counter = 0;

  if (n == 0){
    return 0;
  }
  
  while (n != 0){
    if (n % 2  ==  1){
      counter++;
      n = n / 2;
    } else {
      n = n / 2;
    }
  }
  return counter;
}
