#include <bits/stdc++.h>

using namespace std;

int N=4;
int X=5;
int W[]={2, 3, 3, 5};
int mejor_viaje=20; //Peor caso posible si se usa un ascensor por persona
int peso_asc[20]; //Guarda peso acumulado

void fuerza_bruta(int persona_actual, int viajes_activos){
	//Poda si ya excedimos
	if(viajes_activos>=mejor_viaje)
		return;
	//Si ya acomodamos a todas las personas
	if(persona_actual==N){
		mejor_viaje=min(mejor_viaje, viajes_activos);
		return;
	}
	//Intentar meter a una persona en un ascensor abierto
	for(int i=0; i < viajes_activos ; i++){
		if(peso_asc[i] + W[persona_actual] <= X){
			peso_asc[i]+=W[persona_actual];
			fuerza_bruta(persona_actual+1, viajes_activos);
			peso_asc[i] -= W[persona_actual];
		}
	}
	//Abrir un nuevo ascensor
	peso_asc[viajes_activos] = W[persona_actual]; 
	fuerza_bruta(persona_actual + 1, viajes_activos + 1);
	peso_asc[viajes_activos]=0;
}

int main(){
	fuerza_bruta(0,0);
	cout << "Cantidad minima de viajes por fuerza bruta= " << mejor_viaje << "\n";
	return 0;
}
