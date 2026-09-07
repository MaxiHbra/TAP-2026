#include <stdio.h>

int main() {

  int H, M, S;
  scanf("%d", &H);  scanf("%d", &M); scanf("%d", &S);

  if (H == 2){
    if (M == 30){
      if (S == 0){
        printf("=");
      }else {
        printf("+");}
    }else {
      if (M < 30){printf("-");}
      else {printf("+");}
    }
  }else {
    if (H < 2){
      printf("-");
    }else {
      printf("+");
    }
  }
  printf("\n");


  return 0;
}
