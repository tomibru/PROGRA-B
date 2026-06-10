/*
Ej 2- a) (Utilizar TDA N-Ario) Dado un árbol N-Ario de enteros, verificar, mediante una función
 recursiva int, que exista al menos un nodo con grado G (dato) y clave negativa e impar. 
 [De resolverse mediante una función VOID, el puntaje obtenido no superará 1.5p]
 b) Si en el inciso a) en lugar de al menos un nodo, dijera exactamente un nodo, 
 explique con sus palabras qué debería cambiar en la lógica del algoritmo (no desarrollar).
*/

int existe(arbol a, posicion p, int G){
    posicion c, H;
    int grado=0;
    
    if (nulo(p))
        return 0;
    else{
        H = c=hijomasizq(p,a);
        while (!nulo(c) && grado <= G){
            grado++;
            c = hermanoDer(c,a);
        }
        
        if (grado == G && info(p,a) < 0 && info(p,a)%2 !=0)
            return 1;
        else
            return existe(a, hermanoDer(p,a), G) ||
                   existe(a, H, G);
    }
}

/* si quisiera verificar que solo un nodo cumple
en todo el arbol entonces:
- No cortaria cuando encuentro 1, sigo recorriendo
- Llevaria un contador como parametro, para
retornar 0 ni bien este pase 1.
- Si llego a null y el cont == 1 retorno 1
*/