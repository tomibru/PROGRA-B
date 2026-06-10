/*
Ej 3- Dado un dígrafo G1=(V,E1) con aristas ponderadas almacenado en una matriz de adyacencia y
 un dígrafo G2=(V,E2) con aristas ponderadas almacenado en una lista de adyacencia, se pide 
 determinar si el grado de salida de cada vértice de G1 que no tiene bucle es menor al grado de 
 salida del mismo vértice de G2. El recorrido sobre G1 debe ser recursivo.
*/

#include <stdio.h>
#include <stdlib.h>

#define max 50

// Estructura para la lista de adyacencia de G2
typedef struct nodoG {
    int destino;
    int valor;
    struct nodoG* sig;
} nodoG;

typedef nodoG* ListaAdy;


// Prototipos de las funciones
int cumple(int M[max][max], ListaAdy V[], int n, int i, int j, int NBucle, int sal);
int verificarG2(ListaAdy V[], int v, int sal);


/* --- PROGRAMA PRINCIPAL (MAIN) --- */
int main() {
    int M[max][max], n;
    ListaAdy V[max]; // Vector de listas de adyacencia para G2
    
    cargarG1(M, &n); 
    cargarG2(V, n);
    
    // Llamada inicial pasando los índices desde (n-1) para i y j
    if (cumple(M, V, n, n - 1, n - 1, 1, 0)) {
        printf("G1 y G2 cumplen \n");
    } else {
        printf("no cumplen \n");
    }
    
    return 0;
}


/* --- DESARROLLO DE LA FUNCIÓN COMPLEMENTARIA (CUMPLE) --- */
int cumple(int M[max][max], ListaAdy V[], int n, int i, int j, int NBucle, int sal) {
    
    if (i < 0) {
        return 1;
    } else {
        if (j >= 0 && NBucle) {
            if (i == j) {
                // Evalúa si el nodo actual tiene un bucle en G1
                return cumple(M, V, n, i, j - 1, M[i][j] == 0, sal);
            } else {
                // Acumula el grado de salida de G1 sumando si la arista existe (>0)
                return cumple(M, V, n, i, j - 1, NBucle, sal + (M[i][j] > 0));
            }
        } else { // j < 0 o !NBucle
            if (!NBucle) {
                // Si tiene bucle, no se procesa este vértice y se salta a la fila anterior
                return cumple(M, V, n, i - 1, n - 1, 1, 0);
            } else {
                // Si no tiene bucle, valida la condición contra G2 antes de continuar
                if (verificarG2(V, i, sal)) {
                    return cumple(M, V, n, i - 1, n - 1, 1, 0);
                } else {
                    return 0;
                }
            }
        }
    }
}


/* --- FUNCIÓN AUXILIAR (VERIFICARG2) --- */
int verificarG2(ListaAdy V[], int v, int sal) {
    ListaAdy aux;
    int salLoc = 0;
    
    aux = V[v];
    while (aux != NULL) {
        salLoc++;
        aux = aux->sig;
    }
    
    // Retorna verdadero si el grado de salida de G1 es menor al de G2
    return sal < salLoc;
}