/*
Ej 3- Dado un digrafo con aristas ponderadas almacenado en una lista 
de adyacencia, en un único recorrido obtener la cantidad de vértices 
con bucle que tienen al menos una arista de salida con costo menor al
 costo del bucle y, si existe, eliminarla. No eliminar más de una arista
  por vértice.
*/

void incisoC(int M[][max], int n, int *cant){
    int i,j;

    for (i=0;i<n;i++)
        if(M[i][i] != 0){
            j=0;
            while(j<n && M[i][j] >= M[i][i])
                j++;
            if(j<n){
                M[i][j]=0;
                (*cant)++;
            }
        }
}       

//bien hecho

void incisoC(lista V[], int n, int *cant){
    int i,bucle;
    lista aux,ant;

    for(i=0; i<n ; i++){
        hayBucle(V,i,&bucle);
        if(bucle != 0){
            aux= v[i];
            ant= NULL;

            while(aux != NULL && aux->valor >= bucle){
                ant= aux;
                aux= aux->sig;
            }

            if(aux != NULL){
                (*cant)++;
                if(ant == NULL)
                    V[i]= aux->sig;
                else
                    ant->sig = aux->sig;
                free(aux);
            }
        }
    }
}
void hayBucle(lista V[], int i, int *bucle){
    lista aux= V[i];

    while(aux != NULL && aux->destino < i)
        aux= aux->sig;

    if(aux != NULL && aux->destino == i)
        *bucle = aux->valor;
    else
        *bucle = 0;
}

typedef struct nodo{
    int destino,valor;
    struct nodo *sig;
}nodo;
typedef nodo * lista;