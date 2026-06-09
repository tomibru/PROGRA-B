//Ej 1- Dado un árbol binario que proviene de la transformación de un bosque de árboles generales,
//  determinar si en el bosque todos los árboles verificaban que su grado era igual al grado de 
// su raíz.

int arboCumple(arbol a){
    int graiz, cumple = 1;
    arbol aux;
    
    aux = a;
    while( aux != null && cumple){
        graiz = gradoNodo(aux);
        cumple = verificarArbol(aux->izq, graiz);
        aux = aux->der;
    }
    return cumple;
}

int verificarArbol(arbol a, int graiz){
    if (a == null)
        return 1;
    else{
        if ( gradoNodo(a) <= graiz )
            return verificarArbol(a->izq, graiz) && verificarArbol(a->der, graiz);
        else
            return 0;
    }
}

int gradoNodo(arbol a){
    int grado = 0;   arbol aux = a->izq;
    while(aux != null){
        grado++;   aux = aux->der;
    }
    return grado;
}