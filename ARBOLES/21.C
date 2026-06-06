//21. Dado un árbol binario que proviene de la transformación de un bosque

//a) hallar la cantidad de árboles del bosque que tenían
//  altura al menos K (dato de entrada)

int incisoA(arbol a,int k){
    //Recorro las raices de los arboles de forma iterativa
    arbol aux = a;
    int cont=0;

    while (aux != NULL){
        if(altura(aux->izq) + 1 >= k)
            cont++;
        aux = aux->der;
    }
    return cont;
}
int altura(arbol a){
    int izq, der;

    if (a == NULL)
        return -1;
    else{
        izq =1 + altura(a->izq);
        der = altura(a->der);

        return (izq > der) ? izq : der;
    }
}

//b) generar un arreglo con la clave mayor de 
// cada uno de los árboles que conforman el bosque. 

//int v[max];

void incisoB(arbol a, int v[]){
    arbol aux = a;
    int max,i=0;

    while(aux != NULL){
        i++;
        max = maximo(a->izq);
        if (max > aux->dato)
            v[i] = max;
        else
            v[i] = aux->dato;

            aux= aux->der;
    }
}

int maximo(arbol a){
    int izq,der
    if (a == NULL)
        return -9999;
    else{
        izq = maximo(a->izq);
        der = maximo(a->der);

        if (a->dato > izq && a->dato > der)
            return a->dato;
        else
            if(izq > a->dato && izq > der)
                return izq;
            else
                return der;
    }
}

//c) verificar que todos los árboles contengan 
// al menos un nodo de grado K (dato de entrada). 
int gradoNodo(arbol a){
    arbol aux;
    int cont=0;

    aux=a->izq;
    cont += aux != NULL; 
    while(aux != NULL){
        aux= aux->der;
        cont++;
    }
    return cont;
}

int hayK(arbol a, int k){
    if (a==NULL)
        return 0;
    else{
        if (gradoNodo(a) == k)
            return 1;
        else
            return hayK(a->izq,k) || hayK(a->der,k);
    }

}

void incisoC(arbol a, int k){
    arbol aux = a;
    int nohay=0;

    while(aux != NULL && !nohay){
            if(gradoNodo(aux) != k)
                if(!hayK(aux->izq))
                    nohay=1;
            aux= aux->der;
    }
}
