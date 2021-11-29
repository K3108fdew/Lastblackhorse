#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

int isprime(int count, int primes[], int a){
  float check = 0;
  for (size_t i = 0; i < a; i++) {
    check = (float)count/(float)primes[i];
    if (floor(check) == check) {
      return(0);
    }
  }
  return(1);
}

int *prime(int antall){
  int count = 3, a = 1, bool, b = antall;
  int *primes = malloc(sizeof(b));
  primes[0] = 2;
  while (a <= b) {
    if (isprime(count, primes, a) == 1) {
      primes[a] = count;
      a++;
    }
    count++;
  }
  return(primes);
}

char* sqrtn(int num, int power, int des){
  float root = sqrt((float)num);
  char *s = malloc(32);
  root = (root - floor(root))*(pow(2,32));
  sprintf(s,"%.32f", root);
  return(s);
}

int main(int argc, char const *argv[]) {
  int i, b = 12;
  int *primes = prime(b);

  printf("%s\n", sqrtn(2,2,2));
  return 0;
}
