#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	//ingreso de datos buscando manor y meyor en el proceso
	int n;
	if(cin >> n){
		long long Ma=0;
        	long long m=2e9;
		vector <long long> a(n);
		for(int i=0; i<n; i++){
			cin >> a[i];
			Ma=max(Ma, a[i]);
			m=min(m,a[i]);
		}
		//calculando costos y ganancias posibles
        	long long Pventa=m*m*2 + Ma*Ma; //ya que a=minimo b=minimo c=maximo
        	long long Cfab=m*m + (m*Ma)*2;      //ab + bc + ca = min*min + min*max + min*max
       		long long Gan=Pventa - Cfab;
       	 	cout << "Ganancia maxima:" << Gan << "\n";
	}
	return 0;
}
