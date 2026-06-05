//12. Idem ejercicio 11 pero suponiendo
//  el grafo almacenado en una lista de adyacencia 

//a) mostrar todos sus vértices mediante recorrido en profundidad 

void MostarProf(grafo V[], int n, int v,int visitados[]){
    lista aux;

    aux= V[v].vertices;
    visitados[v]=1;
    printf("%d\n", v);
    while(aux != NULL){
        if(!visitados[aux-> dato - 1])
            MostarProf(V,n,aux->dato -1,visitados);
        aux=aux->sig;
    }
}

//b) mostrar todos sus vértices mediante recorrido en amplitud 

void MostarAmp(grafo V[], int n,int visitados[]){
    int v;
    lista aux;
    Tcola c;

    v=0;
    visitados[v]=1;
    iniciaC(&c);
    poneC(&c,v);

    while(!vaciaC(c)){
        sacaC(&c,&v);
        printf("%d\t",v);
        aux= V[v].vertices;

        while(aux != NULL){
            if(!visitados[aux->dato -1]){
                poneC(&c, aux->dato -1);
                visitados[aux->dato -1] =1;
            }
            aux= aux->sig;
        }
    }
}



//c) devolver la cantidad de componentes conexas 

void profundidad(grafo V[], int v, int visitados[]){
    visitados[v]=1;
    aux= V[v].vertices;
    lista aux;

    while(aux!= NULL){
        if(!visitados[aux->dato -1])
            profundidad(V,n,aux->dato-1,visitados);
        aux = aux-> sig;
    }
}

int cantConexas(grafo V[],int n,int visitados[]){
    int i;
    int componentes=0;
    for(i=0;i<n;i++){
        if(!visitados[i]){
            componentes++;
            profundidad(V,i,visitados);
        }
    }
    return componentes;
}