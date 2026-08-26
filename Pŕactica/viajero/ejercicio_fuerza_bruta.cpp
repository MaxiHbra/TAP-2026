#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
int N;
int dist_matrix[20][20];
bool visitado[20];
int mejor_costo = INF;

void tsp_forza_bruta(int ciudad_actual, int visitadas, int costo_actual) {
    // Caso base: si ya visite las N ciudades
    if (visitadas == N) {
        // Sumamos el costo de volver a la ciudad de inicio (0)
        mejor_costo = min(mejor_costo, costo_actual + dist_matrix[ciudad_actual][0]);
        return;
    }

    //Si el costo actual ya supera el mejor encontrado, cortamos el camino
    if (costo_actual >= mejor_costo) {
        return;
    }

    // Pruebo ir a todas las demas ciudades
    for (int v = 0; v < N; v++) {
        if (!visitado[v]) {
            visitado[v] = true;
            tsp_forza_bruta(v, visitadas + 1, costo_actual + dist_matrix[ciudad_actual][v]);
            visitado[v] = false; // desmarco al volver
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    N = 4; // Ejemplo con 4 ciudades
    
    // dist_matrix[i][j]
    int ejemplo[4][4] = {
        {0, 10, 15, 20},
        {10, 0, 35, 25},
        {15, 35, 0, 30},
        {20, 25, 30, 0}
    };

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            dist_matrix[i][j] = ejemplo[i][j];
        }
    }

    // Arrancamos en la ciudad 0
    visitado[0] = true;
    tsp_forza_bruta(0, 1, 0);

    cout << "Costo minimo por fuerza bruta: " << mejor_costo << "\n";

    return 0;
}
