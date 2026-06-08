//22. Desarrollar un subprograma para mostrar el camino del vértice origen al vértice v (dato) 
// a partir del vector P generado por el algoritmo de Dijkstra. 
 
//PARA DIJKSTRA

void mostrarCamino(int P[], int vj){
    if(P[vj] != 0)
        mostrarCamino(P,P[vj]);

    printf("%d\t", vj);
}

