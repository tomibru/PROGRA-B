//  version para floyd
void mostrarCamino(int P[][max], int vi, int vj){ //vi=0 en la invocaion y vj es dato
    if(P[vi][vj] != 0){
        mostrarCamino(P,vi,P[vi][vj]);
        mostrarCamino(P,P[vi][vj],vj);
    }
    else{
        printf("%d -> %d\n", vi,vj);
    }
}