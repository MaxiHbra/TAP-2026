#include <bits/stdc++.h>
using namespace std;
int main(){
	int h,m,s;
 	cin >> h  >> m  >> s;
	if(h == 2){
		if(m==30){
			if(s==0){
				cout << "=";
			}
		else if(0 < s) cout  << "+";
			else cout << "-";
		
		}
		else if(m  < 30) cout  << "-";
			else cout  << "+";
	}
	else if(h < 2) cout  << "-";
		else cout  << "+";
	cout << "\n";	
	return 0;
}
