#include <stdio.h>
#include "common.h"

#ifndef TESTE_COMMON
#define TESTE_COMMON


void teste_common() {
    printf("essa mensagem nao pode aparecer no terminal\n");
    clear_screen();
    printf("digite um inteiro\n");
    int a = read_int();

    printf("digite um float\n");
    float f = read_float();
    
    printf("digite um char\n");
    char c = read_char();
    
    printf("digite uma string\n");
    char str[5];
    read_string(str,5);

    clear_screen();

    printf("inteiro lido %d\n",a);
    printf("float lido %f\n",f);
    printf("char lido %c\n",c);
    printf("string lida %s\n",str);

}

#endif

