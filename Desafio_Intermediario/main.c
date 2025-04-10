#include <stdio.h>

int main(){

 
   // Declarando variáveis e seus tipos
   char movimentacao;
   int torre = 0, bispo = 0, rainha = 0, cavalo = 0, movimentacao_Cavalo = 0;

   // Menu interativo
   printf("Qual peça você quer movimentar?\n");
   printf("T - Torre\n");
   printf("B - Bispo\n");
   printf("R - Rainha\n");
   printf("C - Cavalo\n");
   scanf("%c", &movimentacao); // endereça a resposta a variavel movimentacao
 

   switch (movimentacao) {

   case 'T':
   case 't':

      printf("\n*** Movimentação Torre ***\n"); // Mensagem unica informando qual peça está sendo movimentada
   // Criação da função de repetição
   do
   {

      printf("1 casa para Direita \n");

      torre++;
   } while (torre <= 4);
      
   break;

   case 'B':
   case 'b':

      printf("\n*** Movimentação Bispo ***\n"); // Mensagem unica informando qual peça está sendo movimentada
      
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

      printf("\n*** Movimentação Rainha ***\n"); // Mensagem unica informando qual peça está sendo movimentada

   // Criação da função de repetição
   for(rainha = 0; rainha <= 7; rainha++){
      printf("1 casa para Esquerda \n");
   }

   break;

   
   case 'C':
   case 'c':
   
      printf("\n*** Movimentação Cavalo ***\n"); // Mensagem unica informando qual peça está sendo movimentada

      // Criação da função de repetição de uma direção
      do
      {

         // Criação da função de repetição de outra direção
         for (movimentacao_Cavalo = 0; movimentacao_Cavalo <= 1; movimentacao_Cavalo++)
         {
            printf("1 casa para Baixo \n");
         }

         printf("1 casa para Esquerda \n");

         cavalo++;
      } while (cavalo < 1);
   
   break;

      
   // Criação da função de erro, caso o usuário insira um valor inválido
   default:
      printf("Valor inválido, tente novamente!\n");
   break;


   }







   return 0;
}