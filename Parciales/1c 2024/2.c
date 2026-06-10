/*
Ej 2- (Utilizar TDA N-ario) Dado un árbol N-Ario de enteros determinar mediante una función int, 
si existe algún nodo (no hoja) que verifique que el grado de todos sus hijos es creciente.
*/

int incisoB(arbol a, posicion p){
    int gant , cumple = 1, gact;
    posicion c;
    
    if (nulo(p))
        return 0;
    else{
        c = HijoMasIzq(p, a);
        if(!nulo(c)){//si no es hoja
            gant= gradoNodo(c,a);
            c= hermanoDer(c,a);
        
            while (!nulo(c)){
                gact = gradoNodo(c, a);
                cumple =  ((cumple) && gant < gact) || incisoB(a, c);
                gant = gact;
                c = HermanoDer(c, a);
            }
            return cumple;
        }
        else
            return incisoB(a,c);    
    }
}

int gradoNodo(posicion p, arbol a){
    int grado = 0;   posicion c;
    c = HijoMasIzq(p, a);
    while (!nulo(c)){
        grado++;
        c = HermanoDer(c, a);
    }
    return grado;
}