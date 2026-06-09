/*
Ej 2- (Utilizar TDA N-ario) Dado un árbol N-Ario de enteros determinar,
mediante una función int, si para todo nodo positivo no hoja de grado
par ubicado en un nivel menor a K (dato), se verifica que el promedio de 
las claves de sus hijos es al menos el doble de la clave del nodo analizado.
*/

int incisoB(arbol a, posicion p, int k, int n){
    posicion c;
    int grado=0, acumH=0, cumple =1,act;

    if(nulo(p) || n==k)
        return 1;
    else{
        act = info(p,a);
        c=hijomasizq(p,a);
        while(!nulo(c)){
            grado++;
            acumH+= info(c,a);
            cumple = cumple && incisoB(a,c,k,n+1);
            c= hermanoDer(c,a);
        }
        if(act >0 && grado>0 && grado %2 == 0)
            return cumple && (float)acumH/grado >= 2*act;
        else
            return cumple;
    }
}