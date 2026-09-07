/*
 * JS stands for job-sequencing problem
 * problem from geeks for geeks page
 * the most basic problem in JS kind of problem
 *
 * Joaco
 */

#include "JS.hpp"


void JS(int* d, int* p, int n){
  // vector idx are vectors whose values are cursors to the real jobs data
  int Jidx[n];
  int *SCidx = (int*) malloc(sizeof(int) * n);
  fill(Jidx, n); // initialize as Jidx[0] = 0 ... Jidx[n-1] = n-1
  
}
void fill(int *v, int n){
  for(int i=0; i<n; i++)
    v[i] = i;
}
void sort(int* v, int n, int(*p)(int,int, int*), int* profits){
  qs(v, 0, n, p, profits);
}
void qs(int *v, int f, int l, int(*p)(int, int, int*), int* profits){
  if (f >= l) return;
  int X = v[f];
  int i = f+1;
  int j = l-1;

  // swapeo v[i] v[j] hasta que i=j donde haremos v[i] = X 
  // dejamos f...i-1 menores que X y i+1 mayores que X
  while (i<j){ // hasta que i == j 
    while(~(p(v[j], X, profits)) && j>= f+1){ // busco el primer vj que sea menor que X desde adelante
      j--;
    }
    while(p(v[i], X, profits) &&  i<l){
      i++;
    }
    if(i<j){ // encontraste vi > X y vj < X
      int aux = v[i];
      v[i] = v[j];
      v[j] = aux;
    }
  }
  v[f] = v[j];
  v[j] = X;
  qs(v, f, j-1, p, profits);
  qs(v, j+1, l, p, profits);
}
void qs_debug(int* v, int f, int l){
  printf("qs(f=%d, l=%d)", f, l);
  if (l-f+1 == 2) {
    if(v[f] < v[l]){
      // is ordered
    } else {
      int aux = v[f];
      v[f] = v[l];
      v[l] = aux;
    }
    return;
  }
  if (f >= l) return;
  int X = v[f]; 
  int i = f+1;
  int j = l-1;
  printf("X is %d separete vec in i=%d and j=%d where vec is\n", X, i, j);
  print(v, f,l);

  // swapeo v[i] v[j] hasta que i=j donde haremos v[i] = X 
  // dejamos f...i-1 menores que X y i+1 mayores que X
  while (i<j){ // hasta que i == j 
    while(v[j] >= X && j>= f+1){ // busco el primer vj que sea menor que X desde adelante
      j--;
    }
    while(v[i] <= X &&  i<l){
      i++;
    }
    printf("j idx is %d => v[j] is %d\n", j, v[j]);
    printf("i idx is %d => v[i] is %d\n", i, v[i]);
    if(i<j){ // encontraste vi > X y vj < X

      int aux = v[i];
      v[i] = v[j];
      v[j] = aux;
    }
  }

  v[f] = v[j];
  v[j] = X;
  printf("from l=%d to l=%d all in j=%d is X=%d and divides vector in <X and >X\n", f, l, j, X);
  print(v,f,l);
  printf("recursive call\n\n");
  qs_debug(v, f, j);
  qs_debug(v, j+1, l);
}

void print(int *v, int f, int l){
  cout << "[ ";
  for(int i=f; i<l; i++)
    cout << v[i] << ((i==l-1)? "]": ", ");
  cout << endl;
}

