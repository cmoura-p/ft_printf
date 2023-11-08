/*
    As Variadic Functions sao uma forma de chamar funcoes com 
    numero variado de argumentos assim como seus tipos.
    Tem de incluir a biblioteca stdarg.h
    Ai tem declarado o type va_list e a definicao de 3 macros que
    possibilitam a utilizacao da lista de argumentos que 
    desconhecemos quantos sao e seus tipos
    Aproveite o exemplo 
*/

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

float avarage(int num, ...)   // essa eh a assinatura da funcao que utiliza
                            // esse special object chamado va_list
{
    int soma = 0;
    int i = 0;
    va_list ap; // va_list eh o special object que circula na lista
                // ap eh um nome padrao que significa "argument pointer"
                // essa ap aponta para o primeiro argumento que 
                // nesse caso eh num, e dai seguimos

    va_start(ap, num);  // a funcao va_start faz o acesso a lista de argumentos
                        // passamos por parametro o argument pointer e
                        // o primeiro argumento da nossa funcao (num)
                        // basicamente estamos a mover uma posicao do 
                        // nosso argument pointer para o proximo argumento
                        // (o primeiro desconhecido)
    while(i < num)
    {
        soma = soma + va_arg(ap, int);  // a funcao va_arg faz a recuperacao dos 
                                        // valores contidos na lista
                                        // passamos por parametro o ap e o tipo da
                                        // variavel que estamos recuperando
        i++;
    }
    va_end(ap); // faz a limpeza da memoria utilizada por ap nas funcoes anteriores
    return (float)(soma / num);
}

int main(void)
{
    float media = avarage(5,  13,47,63,82,28);
    
    printf("A media eh %.2f\n", media);
    
}

/*
    Em um nivel mais baixo do funcionamento das variadics temos:
    typedef __builtin_va_list va_list;
    #define va_start(ap, param) __builtin_va_start(ap, param)
    #define va_arg(ap, type)    __builtin_va_arg(ap, type)
    #define va_end(ap)          __builtin_va_end(ap)

    typedef eh usado para criar um novo nome de type 
    para um tipo de dado existente
    #define eh usado para criar a macro
    
*/
