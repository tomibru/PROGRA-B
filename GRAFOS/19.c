/*
19. Desarrollar un subprograma que determine si un vértice (vj)
 es alcanzable desde otro (vj) para 
un digrafo almacenado en:
*/ 

//a) una matriz de adyacencia 

void profundidad(int M[][max], int n, int vi,int vj){
    int v,j;
    Tpila p;
    int vv[];
    iniciaP(&p);
    poneP(&p,vi);
    vv[vi]=1;


    while(!vaciaP(p)){
        sacaP(&p,&v);
        for(j=0;j<n;j++)
            if(M[v][j] != 0 && !vv[j]){
                poneP(&p,j);
                vv[v]=1;
            }    
    }

    if(vv[vj] != 0)
        printf("Es alcanzable");
    else
        printf("No es alcanzable");
}



//b) una lista de adyacencia

int esAlcanzable(digrafo V[], int n, int vi, int vj){
    int v,vv[max]={0};
    Tpila p;
    lista aux;

    iniciaP(&p);
    poneP(&p,vi);
    vv[vi]=1;

    while(!vaciaP(p) && !vv[vj]){
        sacaP(&p,&v);
        aux= V[v].vertices;

        while(aux != NULL){
            if(!vv[aux->dato]){
                poneP(&p,aux->dato);
                vv[aux->dato] =1;
            }
            aux = aux->sig;
        }
    }

    return vv[vj];

}
