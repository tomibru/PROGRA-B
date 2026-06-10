/*
Ej 2- (Utilizar TDA N-ario) Dado un árbol N-Ario de caracteres verificar que exista algún nodo no hoja de grado par cuya clave sea vocal y todos sus hijos también lo son.
Mostrar la invocación de la solución desarrollada
*/
int esVocal(char c){
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}
int existe(arbol a, posicion p){
    int hijosVocal = 1, grado = 0;
    posicion c, H;
    
    if (nulo(p))
        return 0;
    else{
        // if (!esVocal(info(p,a))) 
        c = H = hijoMasIzq(p,a);
        if (esVocal(info(p,a))){
            while (!nulo(c) && hijosVocal){
                grado++;
                hijosVocal = hijosVocal && esVocal(info(c,a));
                c = hermanoDer(c,a);
            }
            if (grado != 0 && grado % 2 == 0 && hijosVocal)
                return 1;
            else
                return existe(a, H) || existe(a, hermanoDer(p,a));
        }
        else
            return existe(a, H) || existe(a, hermanoDer(p,a));
    }
}