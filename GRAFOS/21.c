//21. Dada la matriz de alcance correspondiente a un digrafo, realizar una función recursiva para 
//hallar el vértice alcanzado por la mayor cantidad de vértices. En el caso de que existan más de 
//uno, devolver el primero encontrado. 

void mayorAlcance(int R[][max], int n,int cont1, int *maxV,int *max,int i, int j){ //max= 0
    if(j>=0){
        if(i>=0){
            if(R[i][j])
                mayorAlcance(R,n,cont1+1,maxV,max,i-1,j);
            else
                mayorAlcance(R,n,cont1,maxV,max,i-1,j);
        }
        else{
            if(cont1 >= *max){
                *max = cont1;
                *maxV= j;     
            }
            mayorAlcance(R,n,0,maxV,max,n-1,j-1);            
        }

    }
}