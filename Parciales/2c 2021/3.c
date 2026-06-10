/* Ej 3- Dado un digrafo de orden N, almacenado en una matriz de adyacencia, generar un arreglo con 
los vértices cuyo grado de salida es menor al grado de entrada. Además del vértice almacenar en el 
arreglo el promedio de los grados.
- Mostrar la invocación de la solución desarrollada, dentro de un main completo que incluya 
declaraciones, inicializaciones, resultados obtenidos. */


typedef struct{
    int vert;
    float prom;
}RegV;

void incisoC(int M[][max], int n, RegV V[], int *u, int ent, int sal, int i, int j){
    
    if (i >= 0){
        if (j >= 0){
            return incisoC(M, n, V, u, ent + (M[j][i] != 0), sal + (M[i][j] != 0),  i, j - 1);
        }
        else{
            if (sal < ent){
                (*u)++;
                V[*u].vert = i + 1;
                V[*u].prom = (ent + sal) / 2.0;
            }
            return incisoC(M, n, V, u, 0, 0, i - 1, n - 1);
        }
    }
}