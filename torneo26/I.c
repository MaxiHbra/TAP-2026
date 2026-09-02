#include <stdio.h>

int main(){
  int N, K;
  scanf("%d", &N);scanf("%d", &K);

  if ( N == 1 || K == 1 ){ printf("S"); }
  else if ( N >= K ) { printf("N"); }
  else {
    if (N > 2){ printf("N"); }
    else { // N = 2
      if ( K % 2 == 1 ){ printf("S"); }
      else { printf("N"); }
    }
  }
  printf("\n");
  return 0;
}
