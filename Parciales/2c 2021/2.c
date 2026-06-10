/* Ej 2- (Utilizar TDA N-ario) Dado un árbol N-Ario de números enteros retornar la cantidad de nodos 
no hoja cuyo grado es menor al promedio de las claves de sus hijos.
- Mostrar la invocación de la solución desarrollada, dentro de un main completo que incluya 
declaraciones, inicializaciones, resultados obtenidos. */

int contN(arbol a, posicion p){
    int grado = 0, cont = 0;
    float acumHijos = 0;
    posicion c;
    
    if (nulo(p))
        return 0;
    else {
        c = hijoMasIzq(p, a);
        while (!nulo(c)){
            grado++;
            acumHijos += info(c, a);
            cont += contN(a, c);
            c = hermanoDer(c, a);
        }
        return cont + (grado != 0 && grado < acumHijos / grado);
    }
}