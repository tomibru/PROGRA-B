void incisoC(int M[][max], int n) {
    int Msubgrafo_deR = 1, Rsubgrafo_deM = 1;
    int i, j;
    
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (j < i) {
                if (M[i][j] && Msubgrafo_deR)
                    Msubgrafo_deR = M[j][i] != 0;
                
                if (M[j][i] && Rsubgrafo_deM)
                    Rsubgrafo_deM = M[i][j] != 0;
            }
            else {
                if (j > i) {
                    if (M[j][i] && Msubgrafo_deR)
                        Msubgrafo_deR = M[i][j] != 0;
                    if (M[i][j] && Rsubgrafo_deM)
                        Rsubgrafo_deM = M[j][i] != 0;
                }
            }
        }
    }
}