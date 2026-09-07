#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

bool esVocal(char c){
  return c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
}
bool patternMatch(char* s, int i, int n){
  // determina si s cumple patron VGASV
  // s[i] = Vocal
  // N es strlen con \0
  // chequea si i+4 < N => esta dentro del string
  if (i+4 < n){
    if (s[i+1] == 'G' && s[i+2] == 'A' && s[i+3] == 'S' && s[i] == s[i+4]){
      return true;
    }
  }
  return false;
}
void traducir(char* s, int n, int j){
  int i = 0;
  while(i < n){
    if(i != j){
      printf("%c", s[i]);
      i ++;
    }else {
      printf("%c", s[i]);
      i += 5;
    }
  }
}
int main(){
  char* s = (char*) malloc(sizeof(char)*1024);

  scanf("%s", s);
  int n = strlen(s);
  int i = 0, j, c = 0;

  while(i < n){
    if (esVocal(s[i]) && patternMatch(s, i, n)){
      j = i; c++; i += 5;
    }else {
      i ++;
    }
  }
  switch(c){
  case 0: { printf("-"); break;}
  case 1: { traducir(s, n, j); break;}
  default: { printf("+"); break;}
  }
  printf("\n");

  return 0;
}
