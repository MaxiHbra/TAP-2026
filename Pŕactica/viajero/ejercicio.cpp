#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
int N;
int dist[20][20];
int memo[20][1 << 20]; // memo[ciudad][mascara]

int tsp(int u, int mask) {
    // Caso base: si ya visitamos todas las ciudades
    if (mask == (1 << N) - 1) {
        return dist[u][0]; // Volver a la ciudad de origen
    }

    // Si ya calculamos este subproblema antes, devolvemos la respuesta guardada
    if (memo[u][mask] != -1) {
        return memo[u][mask];
    }

    int res = INF;

    // Intentar visitar cada ciudad 'v' que aún no fue visitada
    for (int v = 0; v < N; v++) {
        if ((mask & (1 << v)) == 0) { // Si el bit 'v' está apagado
            int nuevo_costo = dist[u][v] + tsp(v, mask | (1 << v));
            res = min(res, nuevo_costo);
        }
    }

    return memo[u][mask] = res; // Guardar y retornar
}

int main() {
    // Ejemplo para N = 4
    N = 4;
    memset(memo, -1, sizeof(memo)); // Inicializar la tabla en -1

    // Llamada inicial: parados en la ciudad 0, con solo el bit 0 encendido (1 << 0 = 1)
    int costo_minimo = tsp(0, 1);
    cout << costo_minimo << "\n";
    return 0;
}
