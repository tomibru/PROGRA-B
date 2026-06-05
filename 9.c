//9. Hallar el vértice con el mayor grado de entrada, en 
// un digrafo representado por una lista de adyacencia. 

void MaxIn(TGrafo V[], int Vin[],int n){
    lista auxL;
    int i,max=-1,vmax;
    for(i=0;i<n;i++){
        auxL = V[i].vertices;
        while(auxL != NULL){
            Vin[(auxL->dato) -1]++;
            auxL = auxL->sig;
        }
    }
    for(i=0;i<n;i++){
        if(Vin[i] > max){
            max = Vin[i];
            vmax=i;
        }
    }

}