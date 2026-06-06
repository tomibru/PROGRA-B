/*8. Desarrollar funciones recursivas para: */
//a)  generar un arreglo con el grado de cada vértice de un grafo 
// almacenado en una matriz de adyacencia. 

void incisoA(int M[][max],int n,int V[],int i,int j){//V[n]={0}
    if(i>=0){
        if(j<0)
            incisoA(M,n,V,i-1,n-1);
        else{
            V[i]+= M[i][j];
            incisoA(M,n,V,i,j-1);
        }        
    }  
}

//LLAMADO incisoA(M, n, V, n-1, n-1);


//b) hallar el vértice con el mayor 
// grado de entrada, en un digrafo representado por 
// una matriz de adyacencia.

//=> tengo que recorrer por columna

void incisoB(int M[][MAX], int n, int i, int j,int gact,int *gmax, int *vid){
    if(j>=0){
        if(i>=0){ 
            incisoB(M,n,i-1,j,gact+ M[i][j],gmax,vid);
        }else{
            if(gact > (*gmax)){
                *gmax = gact;
                *vid = j;
            }
            incisoB(M,n,n-1,j-1,0,gmax,vid);
        }
    }
}

//c) determinar si todos los vértices de 
// un grafo almacenado en media matriz de adyacencia 
//(triángulo superior) tienen al menos un 
// vértice adyacente con costo mayor a X (dato). 

int incisoC(int M[][max],int n, int i, int j,int x){
    if(i < 0)
        return 1;
    else
        if (j < 0)
            return 0;
        else{
            if(j > i)
                if(M[i][j] >= x)
                    return incisoC(M,n,i-1,n-1,x);
                else
                    return incisoC(M,n,i,j-1,x);
            else
                if(j < i)
                    if(M[j][i] >= x)
                        return incisoC(M,n,i-1,n-1,x);
                    else
                        return incisoC(M,n,i,j-1,x);
                else
                    return incisoC(M,n,i,j-1,x);                            
        }
}



//d) generar un vector de registros con grado y vértice
//  para aquellos vértices, de un grafo 
// almacenado en una matriz de adyacencia, cuyo grado sea mayor a 3.

typedef struct{
    unsigned int grado,vert;
}regV;
int k=-1;

void incisoD(int M[][max],int n, regV v[],int i,int j,int gact,int *k){
    if(j>=0){
        if(i>=0){
            incisoD(M,n,v,i-1,j, gact + M[i][j],k);
        }
        else{//i<0
            if(gact > 3){
                (*k)++;
                v[*k].grado = gact;
                v[*k].vert = j;
            }
            incisoD(M,n,v,n-1,j-1,0,k);
        }
    }
}