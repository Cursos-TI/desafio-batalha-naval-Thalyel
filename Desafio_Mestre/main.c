#include <stdio.h>

// Criação da função de chamada para realizar um bloco de código ja pré definido
void movimento_Torre (int casas){
   if (casas < 4)
   {
      printf("1 casa para Direita\n");
      movimento_Torre(casas + 1);
   }

}

// Criação da função de chamada para realizar um bloco de código ja pré definido
void movimento_Bispo (int casas){
   for(int casas; casas < 5; casas++){
      printf("1 casa para Cima\n");
      for (int i = 0; i < 1; i++)
      {
         printf("1 casa para Direita\n");
      } 
   }
}

// Criação da função de chamada para realizar um bloco de código ja pré definido
void movimento_Rainha (int casas){
   if (casas < 8)
   {
      printf("1 casa para Esquerda\n");
      movimento_Rainha(casas + 1);
   }
}

// Criação da função de chamada para realizar um bloco de código ja pré definido
void movimento_Cavalo (int casas){
   int i = 2;

   for (casas; casas < i; casas++)
   {
      for(i; i > 0; i--){
         printf("1 casa para Cima \n");
      }

      printf("1 casa para Direita \n");
   }
}

int main(){

   // Declarando variáveis e seus tipos
   char movimentacao;
   int torre = 0, bispo = 0, rainha = 0, cavalo = 0;

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
      
   // Chamando a função com bloco de códigos pré definidos acima
      movimento_Torre(torre);

   break;

   case 'B':
   case 'b':

      printf("\n*** Movimentação Bispo ***\n"); // Mensagem unica informando qual peça está sendo movimentada
      
   // Chamando a função com bloco de códigos pré definidos acima
      movimento_Bispo(bispo);

   break;

   case 'R':
   case 'r':

      printf("\n*** Movimentação Rainha ***\n"); // Mensagem unica informando qual peça está sendo movimentada

   // Chamando a função com bloco de códigos pré definidos acima
      movimento_Rainha(rainha);

   break;

   
   case 'C':
   case 'c':
   
      printf("\n*** Movimentação Cavalo ***\n"); // Mensagem unica informando qual peça está sendo movimentada

   // Chamando a função com bloco de códigos pré definidos acima
      movimento_Cavalo(cavalo);
   
   break;

      
   // Criação da função de erro, caso o usuário insira um valor inválido
   default:
      printf("Valor inválido, tente novamente!\n");
   break;


   }







   return 0;
}