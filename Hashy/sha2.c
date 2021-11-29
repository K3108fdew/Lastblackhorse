#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *tobiner(char*);
char *padding(char*);

int main() {
  char text[] = "i";
  printf("%d\n", padding(tobiner(text)));
}

char *tobiner(char* w){
  if (w == NULL) {
    return(0);
  }
  size_t len = strlen(w);
  char *binbin = malloc(len*8 + 1);
  binbin[0] = '\0';
  for (size_t i = 0; i < len; i++) {
    char eb = w[i];
    for (int b = 7;b >= 0; --b) {
      if (eb & (1 << b)) {
        strcat(binbin,"1");
      }else{
        strcat(binbin,"0");
      }
    }
  }
  return(binbin);
}

char *padding(char* act){
  if (act == NULL) {
    return 0;
  }
  strcat(act,"1");
  float chunksize = 512;
  size_t len = strlen(act) + 64;
  char *chunks = malloc((int)ceil((float)len/512));
  for (size_t i = 0; i < sizeof(chunks); i++) {
    strcat(chunks[i], "1");
    printf("%s\n", chunks[i]);
  }
  printf("%s\n", chunks[0]);
  return 0;
}
