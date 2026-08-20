#include <bits/stdc++.h>
using namespace std; 
int main(){
	freopen("input.txt", "r", stdin); //lee datos ingresados en input.txt
	freopen("output.txt", "w", stdout); //exporta datos hacia ootput.txt
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	if(cin>>n){
		vector<int> a(n); //Crea un arreglo dinamico con tamaño inicial n
 	      	int suma = 0; //inicializa suma en 0
        	for (int i = 0; i < n; i++) { //desde 0 hasta n-1
           		 cin >> a[i];		//va leyendo el numero en a[i]
           		 suma += a[i];		//va sumando y acumulando en suma
        	}
       		 sort(a.begin(), a.end());     //una vez terminada la suma de todos los numeros ordena el arreglo de menor a mayor
       		 cout << "Elementos ordenados: ";
       		 for (int x : a) {
           		 cout << x << " ";
       		 }
       		 cout << "\n";
       		 cout << "Suma total: " << suma << "\n";
    	}
    return 0;
}
