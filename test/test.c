#include <stdio.h>

int main(){
  int i =0;
  printf("init value: %d\n", i);
  for (i=0; i<100; ++i){
    printf("new value: %d\n", i);
  }
  return 0;
}
