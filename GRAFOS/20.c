//20. ¿Cómo modificaría el algoritmo anterior si además quisiera saber por cuántos vértices debe 
// pasar para llegar de vi a vj?


void profundidad(int M[][max], int n, int vi,int vj){
    int v,j,cantv=0;
    Tpila p;
    int vv[];
    iniciaP(&p);
    poneP(&p,vi);
    vv[vi]=1;


    while(!vaciaP(p) && !vv[vj]){
        sacaP(&p,&v);
        contv++;
        for(j=0;j<n;j++)
            if(M[v][j] != 0 && !vv[j]){
                poneP(&p,j);
                vv[j]=1;
            }    
    }

    if(vv[vj] != 0)
        printf("Es alcanzable");
    else
        printf("No es alcanzable");
}