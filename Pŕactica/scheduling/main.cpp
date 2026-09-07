#include "JS.hpp"

int p(int a, int b, int* v){
  return v[a]<v[b];
}
#define N 8
int main() {
  int arr[N] = {1,2,3,4,5,6,7,8};
  int profits[N] = {5,4,2,6,1,7,8,3};
  qs(arr, 0, N, p, profits);
  print(arr, 0, N);
  return 0;
}
