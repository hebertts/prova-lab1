
 #include <stdio.h>
#include <locale.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#define SIZE 10 //define globalmente o tamanho do array 

#define CARAC 40 // define globalmente o tamanho das carac
int qtdcadastrada = 0; // var global para saber quantos pets foram cadastrados


void  cadastro(char nome[SIZE][CARAC],char tutor[SIZE][CARAC],char raca[SIZE][CARAC],char dataN[SIZE][CARAC],
  int codigo[SIZE],char motivo[SIZE][CARAC], char vacina[SIZE][CARAC])
  {
    int repit;
    
    system("clear");
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
        system("clear");

        strcpy(vacina[qtdcadastrada],"Sem registro de Vacinação");

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
        
        if(qtdcadastrada < SIZE){     //verifica se tem espaço na memoria
          printf("Digite:\n1. Nova consulta\n2. Para Sair ");
          scanf(" %d", &repit); 
          getchar(); //coleta o espaço
          system("clear");
        }
      else
      {
        printf("limite alcançado\n"); //printa na tela se o limite da memoria foi alcançada
        printf("Pressione enter para continuar");
        getchar();
      }
      
      }while (repit == 1);
       
        system("clear");  
  };

void consulta(char nome[SIZE][CARAC],char tutor[SIZE][CARAC],char raca[SIZE][CARAC],char dataN[SIZE][CARAC],
  int codigo[SIZE], char motivo[SIZE][CARAC],int escolha, char vacina[SIZE][CARAC])
  {
    int codigo1 = 0; 
    int linha = 0;
    int repit = 0;
    system("clear");
   
    if(qtdcadastrada > 0){
   
      switch(escolha){
        case 2:
          do{
            linha = 0;
            repit = 0;

            printf("Digite o Código: ");   //procurar pelo codigo por ter nomes de pets iguais
            scanf(" %d",&codigo1);
            getchar();
            while( codigo1 != codigo[linha] && linha <= qtdcadastrada)  //procura pelo codigo digita na matriz
              {linha ++;}
            if (codigo1 == codigo[linha]){   //verifica se o codigo é igual o que foi armazenado na matriz
              printf("\nCodigo: %d", codigo[linha]);
              printf("\nNome do pet: %s", nome[linha]);
              printf("Idade: %s", dataN[linha]);
              printf("Raça: %s", raca[linha]);
              printf("Tutor: %s", tutor[linha]);
              printf("Motivo: %s",motivo[linha]);
              printf("Vacina: %s\n",vacina[linha]);
              printf("----------------------\n"); 
              printf("Pressione enter para continuar");
              getchar();
              system("clear");   
            }
            else {
              system("clear");
              printf("Pet não encontrado\n"); //caso não seja encontrado
              printf("Buscar novamente?\n1.Sim\n2.Nao \n");
              scanf("%d",&repit);
              getchar();
              system("clear"); 
              }
          }while(repit == 1);    
        break;
        case 3:
          printf("-----CADASTRADOS-----\n");
          for (int i = 0; i < qtdcadastrada; i++){  //verifica se foi cadastrado algum pet
            
            printf("Codigo: %d\n", codigo[i]);
            printf("Nome: %s", nome[i]);
            printf("Idade: %s", dataN[i]);
            printf("Raça: %s", raca[i]);
            printf("Tutor: %s", tutor[i]);
            printf("Vacinas: %s\n", vacina[i]);
            printf("----------------------\n");
          } 
            printf("Pressione enter para continuar");
            getchar();
            system("clear");
        break;
      }

    }
    else{
      printf("----------------------\n");
      printf("Nenhum pet cadastrado\n");
      printf("----------------------\n");
      sleep(2);
      
    }
    system("clear");

   } 


void banho(){}

void vacinar(char nome[SIZE][CARAC], int codigo[SIZE], char vacina[SIZE][CARAC]){
  int codigo1 = 0;
  int linha  = 0;
  int confir = 0;
  int repit = 0;
  if (qtdcadastrada > 0)
  {
    do{
      linha = 0; //reiniciar a linha 
      repit = 0;
      system("clear");
      printf("Digite o código do Pet a ser Vacinado: ");
      scanf(" %d",&codigo1);
      getchar();
      while (codigo1!=codigo[linha] && linha < SIZE)
      {
        linha++;
      }
      if (codigo1 == codigo[linha])
      {
        printf("Confirma a Vacina no(a) %s? 1.Sim\n2.Não\n",nome[linha]);
    
        scanf(" %d",&confir);
        getchar();
        if (confir == 1)
        {
          strcpy(vacina[linha], "Ok");
          printf("Aguarde alguns instantes, estamos preparando as vacinas...\n");
          sleep(2);
          printf("Estamos quase finalizando...\n");
          sleep(2);
          system("clear");
          printf("-----O Pet está em  dia com as vacinas-------\n");
          printf("Pressione enter para continuar_");
          getchar();
        }
        else
        {
          printf("ok");
        }
      } 
         
      else{
        printf("pet não encontrado\n");
        printf("Gostaria de procurar novamente?\n1.Sim\n2.Não\n");
        scanf("%d",&repit);
        getchar();
        system("clear");
      }
    }while (repit == 1);

    
  }
  else{
     system("clear");
      printf("----------------------\n");
      printf("Nenhum pet cadastrado\n");
      printf("----------------------\n");
      sleep(2);
  }
  system("clear");


}

int main() {
  char nome[SIZE][CARAC], tutor[SIZE][CARAC], raca[SIZE][CARAC],motivo[SIZE][CARAC], dataN[SIZE][CARAC],vacina[SIZE][CARAC];
  int codigo[SIZE], horario[SIZE];
  int escolha = 0;
  
  setlocale(LC_ALL,"Portuguese");
 
  do {
      system("clear"); //limpar o terminal

      printf("-----CLINICA VETERINARIA------\n");
      printf("Digite:\n1.Cadastrar Pet\n2.Buscar Consulta\n3.Pets cadastrados\n4.Banho e Tosa\n5.Vacinar Pet\n6.Sair\n");
      scanf(" %d", &escolha);
      getchar();
        
      switch (escolha) {
        case 1:
          cadastro(nome, tutor, raca, dataN, codigo,motivo,vacina);
        break;

        case 2:
        case 3:
          consulta(nome, tutor, raca, dataN, codigo,motivo,escolha,vacina);
        break;
        case 4:
         banho(nome,codigo,horario);
          break;
          case 5:
           vacinar(nome,codigo,vacina);
           break;
          case 6:
            printf("Saindo...\n");
            break;
          default:
            system("clear");
            printf("Escolha inválida.\n\n");
            printf("Aguarde alguns instantes\n");
            sleep(2);
          break;
        }
      } while (escolha != 6);


  return 0;
}