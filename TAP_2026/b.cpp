#include <bits/stdc++.h> 

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string palabra;
	if(!(cin >> palabra)) return 0;

	int j=0;
	set<string> traducciones_posibles;
	if(palabra.length() >= 5){
		while( j <= palabra.length() - 5 ){
			if(palabra[j]=='A' || palabra[j]=='E' || palabra[j]=='I' || palabra[j]=='O' || palabra[j]=='U'){
				if(palabra[j+1]=='G' && palabra[j+2]=='A' && palabra[j+3]=='S'){
					if(palabra[j+4] == palabra[j]){
						string trad_cand=palabra;
						trad_cand.erase(j+1,4);
						traducciones_posibles.insert(trad_cand);
					}
				}
			}
			j++;
		}	
	}
	if(traducciones_posibles.size()==0) cout << "-" << "\n";
	else if(traducciones_posibles.size() > 1)  cout << "+" << "\n";
		else if(traducciones_posibles.size() == 1){
			cout << *traducciones_posibles.begin() << '\n';
		} 
}