#include <stdio.h>

int main(){

   // Declarando variáveis e seus tipos
   char movimentacao;
   int torre = 0, bispo = 0, rainha = 0;

   // Menu interativo
   printf("Qual peça você quer movimentar?\n");
   printf("T - Torre\n");
   printf("B - Bispo\n");
   printf("R - Rainha\n");
   scanf("%c", &movimentacao); // endereça a resposta a variavel movimentacao
 

   switch (movimentacao) {

   case 'T':
   case 't':

      printf("\n***Movimentando torre ***\n"); // Mensagem unica informando qual peça está sendo movimentada
   // Criação da função de repetição
   do
   {

      printf("1 casa para Direita \n");

      torre++;
   } while (torre <= 4);
      
   break;

   case 'B':
   case 'b':

      printf("\n*** Movimentando bispo ***\n"); // Mensagem unica informando qual peça está sendo movimentada
      
   // Criação da função de repetição
   while (bispo <= 4)
   {
   
      printf("1 casa para Direita \n");
      printf("1 casa para Cima \n");
   
      bispo++;
   }

   break;

   case 'R':
   case 'r':

      printf("\n*** Movimentando Rainha ***\n"); // Mensagem unica informando qual peça está sendo movimentada

   // Criação da função de repetição
   for(rainha = 0; rainha <= 7; rainha++){
      printf("1 casa para Esquerda \n");
   }

   break;
   
   default:
      printf("Valor inválido, tente novamente!\n");
   break;


   }


   return 0;
}