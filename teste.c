#include <stdio.h>
int main()
{
int numero = 30;
int *ptr;
ptr = &numero;
printf("Valor: %d\n", numero);
printf("Valor via ponteiro: %d\n",*ptr);
return 0;
}