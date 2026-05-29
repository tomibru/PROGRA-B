//c) obtener la altura del árbol original

int altura(arbol a){
    if(a == NULL)
        return 0;
    else{
        if (a-> izq != NULL)
            return 1 + altura(a->izq) + altura(a->der);
        else
            return altura(a->der);
    }
}
//Altura del arbol = altura(a) + 1.

int altura(arbol a){
    int izq, der;

    if (a == NULL)
        return -1;
    else{
        izq= 1 + altura(a->izq);
        der= altura(a->der);
        
        return (izq > der) ? izq : der;
    }
}