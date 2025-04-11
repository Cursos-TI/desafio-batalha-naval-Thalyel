#include <stdio.h>


// Função para inicializar o tabuleiro com zeros
void iniciar_Tabuleiro (int tabuleiro[10][10]){
   for (int i = 0; i < 10; i++)
   {
      for (int j = 0; j < 10; j++)
      {
         tabuleiro[i][j] = 0;
      }  
   }
}

// Função para validar o posicionamento de um navio
int validar_Navio (int tabuleiro[10][10], int linha, int coluna, int tamanho, int horizontal){

   // Verificar se as coordenadas estão dentro do tabuleiro
   if (linha < 0 || linha >= 10 || coluna < 0 || coluna >= 10){
      return 0; // Fora dos limites
   }

   // Verificar se o navio cabe no tabuleiro
   if(horizontal){
      if (coluna + tamanho > 10)
      {
         return 0; // Navio ultrapassa o limite horizontal
      }

      // Verificar sobreposição
      for(int j = coluna; j < coluna + tamanho; j++){
         if (tabuleiro[linha][j] != 0)
         {
            return 0; // Já existe um navio aqui
         }  
      }
   } else {
      if (linha + tamanho > 10){
         return 0; // Navio ultrapassa o limite vertical
      }

      // Verificar sobreposição
      for(int i = linha; i < linha + tamanho; i++){
         if (tabuleiro[i][coluna] != 0)
         {
            return 0; // Já existe um navio aqui
         }
         
      }
   }

   return 1; // Posicionamento válido
}

// Função para posicionar um navio no tabuleiro
void posicionar_Navio(int tabuleiro[10][10], int linha, int coluna, int tamanho, int horizontal){
   if (horizontal)
   {
      for (int j = coluna; j < coluna + tamanho; j++){
         tabuleiro[linha][j] = 3;
      }
   } else {
      for (int i = linha; i < linha + tamanho; i++)
      {
         tabuleiro[i][coluna] = 3;
      }
      
   }
}

// Função para exibir o tabuleiro
void exibir_Tabuleiro(int tabuleiro[10][10]){
   printf("\n ");
   for (int j = 0; j < 10; j++)
   {
      printf("1 ");
   }
   printf("\n");

   for (int i = 0; i < 10; i++)
   {
      printf("1 ");
      for (int j = 0; j < 10; j++)
      {
         printf("%d ", tabuleiro[i][j]);
      }
      printf("\n");
   }

}

int main(){

   int tabuleiro[10][10];
   printf("*** Jogo de Batalha Naval ***\n");
 
   // Inicializar o tabuleiro
   iniciar_Tabuleiro(tabuleiro);

   // Definindo coordenadas iniciais dos navios
   int navio_Linha1 = 1, navio_Coluna1 = 2; // Navio horizontal
   int navio_Linha2 = 2, navio_Coluna2 = 3; // Navio vertical

   // Validar e posicionar o primeiro navio (horizontal)
   if(validar_Navio(tabuleiro, navio_Linha1, navio_Coluna1, 3, 1)){
      posicionar_Navio(tabuleiro, navio_Linha1, navio_Coluna1, 3, 1);
   } else {
      printf("Erro: Posicionamento inválido para o navio horizontal!\n");
      return 1;
   }

   // Validar e posicionar o segundo navio (vertical)
   if (validar_Navio(tabuleiro, navio_Linha2, navio_Coluna2, 3, 0)) {
      posicionar_Navio(tabuleiro, navio_Linha2, navio_Coluna2, 3, 0);
   } else {
      printf("Erro: Posicionamento inválido para o navio vertical!\n");
      return 1;
   }

   // Exibir o tabuleiro
   printf("Tabuleiro com navios posicionados:\n");
   exibir_Tabuleiro(tabuleiro);
  
   return 0;
}