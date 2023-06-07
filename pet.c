
 #include <stdio.h>
#include <unistd.h>
#include <locale.h>
#include <string.h>
#include <stdlib.h>

#define SIZE 10

#define CARAC 40
int qtdcadastrada = 0;


void  cadastro(char nome[SIZE][CARAC],char tutor[SIZE][CARAC],char raca[SIZE][CARAC],char dataN[SIZE][CARAC],
  int codigo[SIZE],char motivo[SIZE][CARAC])
  {
    int repit;
    
    
    printf("-----CADASTRO-----\n");
    do{
      repit = 0;
        
      codigo[qtdcadastrada] = qtdcadastrada + 1;
    
      
      printf("Nome: ");
      fgets(nome[qtdcadastrada], CARAC, stdin);

      printf("Raca: ");
      fgets(raca[qtdcadastrada], CARAC, stdin);

      printf("Tutor: ");
      fgets(tutor[qtdcadastrada], CARAC, stdin);

      printf("Idade: ");
      fgets(dataN[qtdcadastrada], CARAC, stdin);

      printf("Qual o motivo da consulta? ");
      fgets(motivo[qtdcadastrada], CARAC ,stdin);
      system("cls");

      printf("----------------------");
              
      printf("\nCodigo: %.d", codigo[qtdcadastrada]);
      printf("\nNome: %s", nome[qtdcadastrada]);
      printf("Idade: %s", dataN[qtdcadastrada]);
      printf("Raca: %s", raca[qtdcadastrada]);
      printf("tutor: %s", tutor[qtdcadastrada]);
      printf("Motivo: %s",motivo[qtdcadastrada]);
      printf("----------------------\n");
      sleep(1);

      qtdcadastrada++;
      if(qtdcadastrada < SIZE){
      printf("Digite:\n1. Nova consulta\n2. Para Sair ");
      scanf(" %d", &repit); 
      getchar();
      system("cls");
      }
      else
      {
        printf("limite alcançado\n");
        printf("Pressione enter para continuar");
        getchar();
      }
      
      }while (repit == 1);
       
        system("cls");  
     
      
    };

void consulta(char nome[SIZE][CARAC],char tutor[SIZE][CARAC],char raca[SIZE][CARAC],char dataN[SIZE][CARAC],
  int codigo[SIZE], char motivo[SIZE][CARAC],int escolha)
  {
    int codigo1 = 0; 
    int linha = 0;
    int repit = 0;
    system("cls");
   
    if(qtdcadastrada > 0){
   
      switch(escolha){
        case 2:
          do{
            linha = 0;

            printf("Digite o Código: ");   //procurar pelo codigo por ter nomes de pets iguais
            scanf(" %d",&codigo1);
            getchar();
            while( codigo1 != codigo[linha] && linha <= qtdcadastrada) 
              {linha ++;}
            if (codigo1 == codigo[linha]){
              printf("\nCodigo: %d", codigo[linha]);
              printf("\nNome do pet: %s", nome[linha]);
              printf("Idade: %s", dataN[linha]);
              printf("Raça: %s", raca[linha]);
              printf("Tutor: %s", tutor[linha]);
              printf("Motivo: %s",motivo[linha]);
              printf("----------------------\n"); 
              printf("Pressione enter para continuar");
              getchar();
              system("cls");   
            }
            else {
              system("clear");
              printf("Pet não encontrado\n");
              printf("Buscar novamente?\n1.Sim\n2.Nao \n");
              scanf("%d",&repit);
              getchar();
              system("cls"); 
              }
          }while(repit == 1);    
        break;
        case 3:
          printf("-----CADASTRADOS-----\n");
          for (int i = 0; i < qtdcadastrada; i++){
            
            printf("Codigo: %d\n", codigo[i]);
            printf("Nome: %s", nome[i]);
            printf("Idade: %s", dataN[i]);
            printf("Raça: %s", raca[i]);
            printf("Tutor: %s", tutor[i]);
            printf("----------------------\n");
          } 
            printf("Pressione enter para continuar");
            getchar();
            system("cls");
        break;
      }
//asd
    }
    else{
      printf("----------------------\n");
      printf("Nenhum pet cadastrado\n");
      printf("----------------------\n");
      sleep(2);
      
    }
    system("cls");

   } 


int main() {
  char nome[SIZE][CARAC], tutor[SIZE][CARAC], raca[SIZE][CARAC],motivo[SIZE][CARAC], dataN[SIZE][CARAC],vacina[SIZE][CARAC];
  int codigo[SIZE];
  int escolha = 0;
  
  setlocale(LC_ALL,"Portuguese");
 
  do {
      system("cls"); //limpar o terminal
      
      printf("Digite:\n1.Cadastrar Pet\n2.Buscar Consulta\n3.Pets cadastrados\n4.Sair\n");
      scanf(" %d", &escolha);
      getchar();
        
      switch (escolha) {
        case 1:
          cadastro(nome, tutor, raca, dataN, codigo,motivo);
        break;

        case 2:
        case 3:
          consulta(nome, tutor, raca, dataN, codigo,motivo,escolha);
        break;
        case 4:
          printf("Saindo...\n");
          break;
          default:
            system("cls");
            printf("Escolha inválida.\n\n");
            printf("Aguarde alguns instantes\n");
            sleep(2);
          break;
      }
    } while (escolha != 4);


  return 0;
}
