#include <stdio.h>
#include <stdlib.h>

int main(){
  int f[9] = {0, 5, 1, 6, 2, 7, 3, 8, 4};
  int N, i;

  scanf("%d", &N);
  int* l = (int*) malloc(sizeof(int)*N);

  for (i = 0; i < N; i++){
    scanf("%d", l+i);
  }
  for (i = 0; i < N; i++){
    if (i != N-1) printf("%d ", f[l[i]]);
    else printf("%d\n", f[l[i]]);
  }

  return 0;
}
