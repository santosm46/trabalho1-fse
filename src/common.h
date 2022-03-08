#include <stdio.h>
#include <stdlib.h>     /*para usar atoi */
#include <string.h>

#ifndef COMMON_H
#define COMMON_H

void clear_screen() {
    system("clear");
}

char read_char() {
    char c, lixo;
    scanf("%c", &c);
    lixo = c;
    while (lixo != '\n') { lixo = getc(stdin); }
    return c;
}

char upper_char(char letter) {
    if (letter >= 'a' && letter <= 'z')
        return (letter-32);
    return letter;
}

void upper_string(char *string) {
    for (int i = 0; string[i]; i++) {
        string[i] = upper_char(string[i]);
    }
}

void read_string(char *string, int nroLetras) {
  int i = 0;
  char lixo;
  scanf("%c", string);
  if (*string != '\n')
    while ( ((string[++i] = getc(stdin) ) != '\n') && (i < nroLetras-1)) {}
  if(i == nroLetras-1) while ((lixo = getc(stdin) ) != '\n') {}
  string[i] = '\0';
}



#define MAX_INPUT 25

void getMaxMinInt(int *min, int *max) {
    // valor int em c depende da arquitetura da cpu
    // geralmente é
    // max= 2147483647
    // min= -2147483648
    *max = ~0U >> 1;
    *min = *max+1;
}

// verifica se a string é um inteiro

int is_integer(char *integer) {
    int i = 0;
    if (integer[0] == '-')
        i++;
    
    for(; integer[i] != '\0'; i++) {
        if((integer[i] < '0') || (integer[i] > '9')) { // if isn't digit
            return 0;
        }
    }
    return 1;
}


int valid_integer(char *valor) {
    // valida se foi digitado apenas números
    if (!is_integer(valor)) {
        printf("Digite apenas um numero inteiro\n");
        return 0;
    }
    int min, max;
    getMaxMinInt(&min, &max);
    char cmin[MAX_INPUT], cmax[MAX_INPUT];
    sprintf(cmin,"%d",min);
    sprintf(cmax,"%d",max);
    int valido=1;
    int tamValor = strlen(valor);
    int tamcmax = strlen(cmax);
    int tamcmin = strlen(cmin);
    
    // caso o número for positivo
    if(valor[0] != '-') {
        //ver se o número é maior que o int máximo suportado
        if (tamValor > tamcmax) {
            valido = 0;
        } else if (tamValor == tamcmax) {
            int i;
            for(i=0; i<tamValor; i++) {
                if(valor[i]>cmax[i]) {
                    valido = 0;
                    break;
                } else if(valor[i]<=cmax[i]){
                    valido = 1;
                    break;
                }
            }
        }
        if(!valido) {
            printf("Digite um numero menor ou igual a %d\n",max);
            return 0;
        }
    } else {
        //ver se o número é menor que o int mínimo suportado
        if (tamValor > tamcmin) {
            valido = 0;
        } else if (tamValor == tamcmin) {
            int i;
            for(i=1; i<tamValor; i++) {
                if(valor[i]>cmin[i]) {
                    valido = 0;
                    break;
                } else if(valor[i]<=cmin[i]){
                    valido = 1;
                    break;
                }
            }
        }
        if(!valido) {
            printf("Digite um numero maior ou igual a %d\n",min);
            return 0;
        }
    }

    return 1; // valor válido
}

// ler valor inteiro e retorna, não deixa lixo no buffer
int read_int() {
    char inteiro[MAX_INPUT];
    do {
        read_string(inteiro,MAX_INPUT);
    } while (!valid_integer(inteiro));

    return atoi(inteiro);
}


// serão feitas validações para float e double futuramente

float read_float() {
    float flutuante;
    scanf("%f",&flutuante);
    getc(stdin);
     
    return flutuante;
}

double read_double() {
    double dobro;
    scanf("%lf",&dobro);
    getc(stdin);
    return dobro;
}



#endif // COMMON_H

