/*Sean A variable de tipo árbol general y p es variable de tipo posición 
Vacio(A)  Devuelve verdadero si A es árbol Vacío. 
Nulo(p)  Devuelve verdadero si p es la posición Nula 
HijoMasIzq(p,A)  Devuelve la posición del hijo más a la izquierda de p, si p es hoja devuelve una 
posición nula. 
HermanoDer(p,A)  Devuelve la posición del hermano a la derecha de p (tiene el mismo padre de p), si p 
es el de la extrema derecha devuelve una posición nula. 
Info(p,A)  Devuelve el dato del en la posición p en el árbol A. 
Raiz(A)  Devuelve una posición que es la raíz del árbol A. 
Padre(p,A)  Devuelve la posición del padre de la posición p en el árbol A, si p es la raíz devuelve una 
posición nula.*/

//23. Dado un árbol N-ario de enteros, desarrollar funciones
//  utilizando TDA N.ARIO para:

//a) retornar la cantidad de nodos que posee.

int cantNodos(arbol a,posicion p){
    posicion c;
    int cantLocaL=0;
    if(nulo(p))
        return 0;
    else{
        c= HijoMasIzq(p,a);
        while(!nulo(c)){
            cantLocaL += 1 + cantNodos(a,c);
            c= HermanoDer(c,a);
        }
        return cantLocaL;
    }
}

//b) hallar el porcentaje de claves pares 

void PromedioPar(arbol a, posicion p,int *cont,int *contP){//cont=contP=0
    posicion c;
    if(!nulo(p)){
        (*cont)++;
        if(Info(p,a) % 2 == 0)
            (*contP)++;
        c=HijoMasIzq(p,a);
        while(!nulo(c)){
            PromedioPar(a,c,cont,contP);
            c = HermanoDer(c,a);
        }
    }
}
/*if(cont != 0)
    printf("Promedio : %2.f\n", (float)contP/cont);*/   
    
//c) retornar su grado

int grado(arbol a, posicion p){
    int maxLocal=0,gradoHijo,maxHijo=0;
    if(nulo(p))
        return 0;
    else{
        c= HijoMasIzq(p,a);
        while(!nulo(c)){
            maxLocal++;
            gradoHijo=grado(a,c);
            if(gradoHijo>maxHijo)
                maxHijo= gradoHijo;

            c= HermanoDer(c,a);
        }
        return (maxHijo > maxLocal) ? maxHijo:maxLocal;
    }
}
//c) retornar su grado

int gradoMax(arbol a,posicion p){
    posicion c;
    int gradoLoc=0,gradoHijo,hijoMax=0;
    if(nulo(p))
        return 0;
    else{
        c=hijomasizq(p,a);
        while(!nulo(c)){
            gradoLoc++;
            gradoHijo= gradoMax(a,c);
            hijoMax = (gradoHijo > hijoMax)? gradoHijo: hijoMax;
            c= hermanoder(a,c);
        } 
        return (gradoLoc > hijoMax)? gradoLoc: hijoMax;
    }
}

//d) hallar la cantidad de nodos de grado impar que hay en niveles impares. 

int incisoD(arbol a, posicion p, int n){
    int gradoLocal=0,cant=0;
    posicion c;
    if(nulo(p))
        return 0;
    else{
        c=HijoMasIzq(p,a);
        while(!nulo(c)){
            gradoLocal++;
            cant += incisoD(a,c,n+1);
            c=HermanoDer(c,a);
        }

        if(n % 2 != 0 && gradoLocal % 2 != 0)
            cant++;
        return cant;

    }

}
//d) hallar la cantidad de nodos de grado impar que hay en niveles impares. 

int incisoD(arbol a, posicion p, int n){
    posicion c;
    int gradoLoc=0, cont=0;
    if(nulo(p))
        return 0;
    else{
        c=hijomazizq(p,a);
        while(!nulo(c)){
            gradoLoc+= n % 2 != 0;
            cont += incisoD(a,c,n+1);
            c= hermanoDer(c,a);
        }
        return cont + (gradoLoc % 2 != 0);
    }
}

/*e) verificar si cumple que para todas las claves salvo las de las hojas, su 
valor numérico es igual  a la cantidad de hijos. (función int y función void) */

int incisoE(arbol a, posicion p){
    posicion c;
    int grado=0,cumple=1;
    c= HijoMasIzq(p,a);
    if(nulo(c))
        return 1;
    else{
        while(!nulo(c) && cumple){
            grado++;
            cumple= cumple && incisoE(a,c);
            c= HermanoDer(c,a);
        }
        return (Info(p,a) == grado) && cumple;
    }
}

void incisoEplus(arbol a, posicion p,int * cumple){
    posicion c;
    int grado=0;
    c= HijoMasIzq(p,a);
    if(!nulo(c)){
        while(!nulo(c) && *cumple){
            grado++;
            incisoEplus(a,c,cumple);
            c= HermanoDer(c,a);
        }
        if(*cumple)
            (*cumple) = Info(p,a) == grado;
    }
}