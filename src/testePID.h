#include "pid.h"

#ifndef TESTE_PID
#define TESTE_PID


/*

Entradas:



*/

int testePID() {
    

    pid_configura_constantes(20.0, 0.1, 100.0);

    pid_atualiza_referencia(25.0);

    double resultado = pid_controle(25.5);

    printf("resultado = %lf \n", resultado);



    return 0;
}


#endif

