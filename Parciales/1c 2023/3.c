/*
Ej 3- Dado un digrafo $G = (V, E)$ con $|V|=N$, almacenado en una matriz de adyacencia, mostrar los vértices en los que teniendo bucle, coincide el grado de entrada con el grado de salida. Al finalizar el proceso, informar el porcentaje de vértices mostrados. Cada vértice se halla etiquetado con letras en orden alfabético, comenzando desde la A.
*/

void incisoC(int M[][max], int n){
    int bucle;
    int i, j;
    int entrada, salida;
    int mostrados = 0;
    for (i=0 ; i<n ; i++){
        bucle = 1;
        entrada = salida = 0;
        j=0;
        while (j<n && bucle){
            if (i == j)
                bucle = (M[i][j] != 0);
            entrada += (M[j][i] != 0);
            salida += (M[i][j] != 0);
            j++;
        }
        if (bucle && entrada == salida){
            mostrados ++;
            printf ("Vertice %c \n", 'A' + i);
        }
    }
    printf("Porcentaje de mostrados %.2f %%", 
            (float) mostrados / n * 100);
}