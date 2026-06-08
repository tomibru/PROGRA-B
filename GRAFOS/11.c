//11. Para un grafo almacenado en una matriz de adyacencia,
//desarrollar funciones para: 
//a) mostrar todos sus vértices mediante recorrido en profundidad 

#include "Pilas.h"
void MostrarProf(int M[][max], int n){
    Tpila p;
    int visitados[max] = {0};
    int v,i,encontro;

    iniciaP(&p);
    v=0; 
    visitados[v] = 1;
    printf("%d\t",v);
    poneP(&p,v);
    while(!vaciaP(p)){
        i = encontro = 0;
        v= consultaP(p);
        while(i<n && !encontro){
            if(M[v][i] && !visitados[i]){
                poneP(&p,i);
                visitados[i] = 1;
                printf("%d\t",i);
                encontro = 1;
            }
            i++;
        }
        if(!encontro)
            sacaP(&p,&v);
    }
}

//Segunda version

void mostrarProf2(int M[][max], int n, int VV[]){
    int i,visitados=0,v,j;
    Tpila p;

    while(i<n && visitados<n){
        if(!VV[i]){
            iniciaP(&p);
            poneP(&p,i);

            while(!vaciaP(p)){
                sacoP(&p,&v);
                if(!VV[v]){
                    visitados++;
                    VV[v]++;
                    for(j=0;j<n;j++){
                        if(M[v][j])
                            poneP(&p,j);
                    }
                }

            }
        }
        i++
    }

}

//b) mostrar todos sus vértices mediante recorrido en amplitud 

void MostrarAmp(int M[][max],int n){
    Tcola c;
    int i,v,visitados[max]={0},cantV=0;
    iniciaC(&c);
    v=0;
    visitados[0] = 1;
    printf("%d\t", v);
    poneC(&c,v);

    while(!vaciaC(c)){
        sacaC(&c,&v);
        for(i=0;i<n;i++){
            if(M[v][i] && !visitados[i]){
                visitados[i]=1;
                poneC(&c,i);
                printf("%d\t", i);
            }
        }
    }
}

//version correcta

void mostrarAmp2(int M[][max], int n, int VV[]){
    int i=0,visitados=0,v,j;
    Tcola c;

    while(i<n && visitados<n){
        if(!VV[i]){
            iniciaC(&c);
            poneC(&c,i);

            while(!vaciaC(c)){
                sacaC(&c,&v);
                printf("%d\n", v);
                VV[v]++;
                visitados++;

                for(j=0; j<n; j++){
                    if(M[v][j] && !VV[j])
                        poneC(&c,j);
                }
            }
        }

        i++;
    }
}



//c) devolver la cantidad de componentes conexas 

void profundidad(int M[][max],int n,int v, int visitados[]){
    int i;

    visitados[v]=1;
    for(i=0;i<n;i++){
        if(M[v][i] && !visitados[i]){
            profundidad(M,n,i,visitados);
        }
    }
}

int componentes(int M[][max], int n, int visitados[]){
    int i,comp=0;

    for(i=0;i<n;i++){
        if(!visitados[i]){
            comp++;
            profundidad(M,n,i,visitados); //Va encontra de los principios de la programacion?
        }
    }
    return comp;
}