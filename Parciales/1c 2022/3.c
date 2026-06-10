/*
Ej 3- Dado un digrafo de orden N almacenado en una matriz de adyacencia 
(los vértices numerados de 1 a N) generar mediante una única función recursiva un arreglo
 con los vértices que tengan bucle, almacenando además su grado de salida. Mostrar el vector
  generado.

Desarrollar un main completo que incluya declaraciones, inicializaciones, invocaciones y 
resultados obtenidos.
*/

typedef struct {
    int vert, salida;
} RegistroV;
#define max 30

void incisoC(int M[][max], int n, RegistroV V[], int bucle, int sal, int *u,int i, int j){
    if (i >= 0){
        if (j >= 0 && bucle){
            if (i == j)
                return incisoC(M, n, V, M[i][j] != 0, sal + M[i][j] != 0, u,i,j-1);
            else
                return incisoC(M, n, V, bucle, sal + M[i][j] != 0, u,i,j-1);
        }
        else{
            if (bucle){
                (*u)++;
                V[*u].vert = i + 1;
                V[*u].salida = sal;
            }
            return incisoC(M, n, V, 1, 0, u,i-1,n-1);
        }
    }
}

int main(){
    int u, M[max][max], n,i; 
    RegistroV V[max];  
    u = -1; 

    cargarGrafo(M, &n);

    incisoC(M, n, V, 1, 0, &u,n-1,n-1);
    for (i=0; i <= u; i++)
        printf("Vertice: %d , salida: %d\n", V[i].vert, V[i].salida);
    return 0;
}

