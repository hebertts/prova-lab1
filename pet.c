
#include <stdio.h>
#include <locale.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#define SIZE 50  //define globalmente o tamanho do array 
#define HORASM 9 // horas totais para a consulta
#define CARAC 40 // define globalmente o tamanho das carac
int qtdcadastrada = 0; // var global para saber quantos pets foram cadastrados


void  cadastrar(char nome[SIZE][CARAC],char tutor[SIZE][CARAC],char raca[SIZE][CARAC],char dataN[SIZE][CARAC],
  int codigo[SIZE],char motivo[SIZE][CARAC], char vacina[SIZE][CARAC])
  {
    int repit; 
    do{
      if(qtdcadastrada < SIZE){
        system("clear");
        repit = 0;
        printf("-----CADASTRO-----\n");
        codigo[qtdcadastrada] = qtdcadastrada + 1;
    
      
        printf("Nome: ");
        fgets(nome[qtdcadastrada], CARAC, stdin);
        
      
        printf("Raça: ");
        fgets(raca[qtdcadastrada], CARAC, stdin);
        
      
        printf("Tutor: ");
        fgets(tutor[qtdcadastrada], CARAC, stdin);

        printf("Idade: ");
        fgets(dataN[qtdcadastrada], CARAC, stdin);

        strcpy(vacina[qtdcadastrada],"Sem registro de Vacinação");
 
        system("clear");

        printf("\nCadastro concluído\n");     
        printf("----------------------");   
        printf("\nCodigo: %.d", codigo[qtdcadastrada]);
        printf("\nNome: %s", nome[qtdcadastrada]);
        printf("Idade: %s", dataN[qtdcadastrada]);
        printf("Raça: %s", raca[qtdcadastrada]);
        printf("tutor: %s", tutor[qtdcadastrada]);
        printf("----------------------\n");
        sleep(1);
        qtdcadastrada++;
        if(qtdcadastrada < SIZE){     //verifica se tem espaço na memoria
          printf("Digite:\n1.Nova consulta\n2.Para Sair\n");
          scanf(" %d", &repit); 
          getchar(); //coleta o espaço
          system("clear");
        }
      } 
   }while (repit == 1);
      
   system("clear");
   printf("limite alcançado\n"); //printa na tela se o limite da memoria foi alcançada
   printf("Pressione enter para continuar_");
   getchar();
   system("clear");  
};

void consultar(char nome[SIZE][CARAC],char tutor[SIZE][CARAC],char raca[SIZE][CARAC],char dataN[SIZE][CARAC],
  int codigo[SIZE], char motivo[SIZE][CARAC],int escolha, char vacina[SIZE][CARAC],int HoraEsco[SIZE][2])
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
            if (codigo1 == codigo[linha] && codigo1 != 0){   //verifica se o codigo é igual o que foi armazenado na matriz
              printf("\nCodigo: %d", codigo[linha]);
              printf("\nNome do pet: %s", nome[linha]);
              printf("Idade: %s", dataN[linha]);
              printf("Raça: %s", raca[linha]);
              printf("Tutor: %s", tutor[linha]);
              printf("Vacina: %s\n",vacina[linha]);
              if(HoraEsco[linha][1] ==1){
            printf("Consulta: agendado  às %d:00, %s",HoraEsco[linha][0],motivo[linha]);
            }
              printf("----------------------\n"); 
              printf("Pressione enter para continuar_");
              getchar();
              system("clear");   
            }
            else {
              system("clear");
              printf("Pet não encontrado\n\n"); //caso não seja encontrado
              printf("Buscar novamente?\n1.Sim\n2.Nao\n");
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
            if(HoraEsco[i][1] == 1){
            printf("Consulta: agendado  às %d:00, %s",HoraEsco[i][0],motivo[i]);
            }
            printf("----------------------\n");
          } 
            printf("Pressione enter para continuar_");
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

void marcar(char nome[SIZE][CARAC], char motivo[SIZE][CARAC], int codigo[SIZE], int horario[HORASM][2],int HoraEsco[SIZE][2]) {
  int codigo1 = 0, linha = 0, hora = 0, repit = 0, escolha1 = 0,horasdis = 0,repithora =0;


  for (int i = 0; i < HORASM; i++) {
    
      horario[i][0] = hora + 8;
      hora++;
      if(horario[i][1]==0){
        horasdis++;
      } 
  }

  if (qtdcadastrada > 0 && horasdis > 0 ) {
    do {
      linha = 0; 
      repit = 0;
      system("clear");
      printf("Digite o código do Pet: ");
      scanf("%d", &codigo1);
      getchar();

      while (linha < qtdcadastrada && codigo1 != codigo[linha]) {
        linha++;
      }

      
      if (linha < qtdcadastrada && codigo1 == codigo[linha] && HoraEsco[linha][1] ==0) {
        sleep(1);
        do{
          repithora =0;
          horasdis--;
          system("clear");   
          printf("----------------------\n");
          printf("||    INFORMAÇÕES    ||\n");
          printf("----------------------\n");
          printf("     Código: %d\n", codigo[linha]);
          printf("     Pet: %s", nome[linha]);
          printf("----------------------\n");
          printf("Horários disponíveis:\n");
        for (int i = 0; i < HORASM; i++) 
        {
          if(horario[i][1] == 0 && horario[i][0] != 12){
          printf("%d. %d:00\n", i + 1, horario[i][0]);
          }
         }
      
        repithora = 0;
        printf("Digite o número do horário escolhido: ");
        scanf(" %d", &escolha1);  
        getchar();
        
        if (escolha1 >= 1 && escolha1 <= HORASM && HoraEsco[linha][1] == 0 && horario[escolha1-1][1]== 0) {
          HoraEsco[linha][1] = 1;
          horario[escolha1-1][1] = 1;
          HoraEsco[linha][0] = horario[escolha1-1][0];
          system("clear");
          printf("Qual o motivo da consulta?\n");
          fgets(motivo[linha],CARAC,stdin);
          sleep(1);
          system("clear");
          printf("Horário marcado com sucesso!\n");
          printf("----------------------\n");
          printf("Pressione enter para continuar_");
          getchar();
        } else {
          system("clear");
          printf("Horário inválido ou já ocupado.\n");
          printf("Tentar novamente?\n1.Sim\n2.Não\n");
          scanf("%d",&repithora);
        }
       }while(repithora == 1);
      } 
    
      else if(HoraEsco[linha][1] == 1)
      {
        system("clear");
        printf("Pet já possui agendamento\n\n");
        printf("Pressione enter para continuar_");
        getchar();
      }
        else{
        system("clear");
        printf("Pet não encontrado.\n\n");
        printf("Gostaria de procurar novamente?\n1.Sim\n2.Não\n");
        scanf("%d", &repit);
        getchar();
        system("clear");
        }
    }while (repit == 1);
  } 
      else if (horasdis <= 0){
        system("clear");
        printf("Sem horários disponivéis no momento, aguarde o próximo dia\n");
        printf("Pressione enter para continuar_");
        getchar();
        }
    else {
    system("clear");
    printf("----------------------\n");
    printf("Nenhum pet cadastrado\n");
    printf("----------------------\n");
    sleep(2);
    }
  system("clear");
}

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
      if (codigo1 == codigo[linha] && codigo1 != 0)
      {
        system("clear");
        sleep(2);
        printf("----------------------\n");
        printf("||    INFORMAÇÕES    ||\n");
        printf("----------------------\n");
        printf("     Código: %d\n",codigo[linha]);
        printf("     Pet: %s", nome[linha]);
        printf("----------------------\n");
        printf("Confirma a Vacina?\n1.Sim\n2.Não\n");
    
        scanf(" %d",&confir);
        getchar();
        if (confir == 1)
        {
          system("clear");
          strcpy(vacina[linha], "Ok");
          printf("Aguarde alguns instantes, estamos preparando as vacinas...\n");
          sleep(3);
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
        printf("\n");
        system("clear");
        printf("pet não encontrado\n\n");
        printf("Gostaria de procurar novamente?\n1.Sim\n2.Não\n");
        scanf(" %d",&repit);
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

void editar(char nome[SIZE][CARAC],char tutor[SIZE][CARAC],char raca[SIZE][CARAC],char dataN[SIZE][CARAC],
int codigo[SIZE], char motivo[SIZE][CARAC],int horario[HORASM][2],int HoraEsco[SIZE][2])
{
  int codigo1 =0, repit =0,linha = 0,escolha = 0;
  if(qtdcadastrada > 0){
    do{
        escolha = 8;
        linha = 0;
        repit = 0;
        system("clear");
        printf("Digite o código: ");
        scanf(" %d", &codigo1);
        getchar();
        while(linha <qtdcadastrada && codigo1 != codigo[linha]){
        linha++;}
  
        if(codigo[linha] == codigo1 && codigo1 != 0)
        {
          do{
              system("clear");
              printf("-----------------------------\n");
              printf("%s",nome[linha]);
              printf("-------EDITAR CADASTRO-------\n");
              printf("O que você gostaria de editar?\n1.Nome do Pet\n2.Nome do Tutor\n3.Raça\n4.Mudar Horário da Consulta\n5.Cancelar Consulta\n6.Editar Motivo da Consulta\n7.Editar Idade\n8.Sair\n");
              scanf(" %d",&escolha);
              getchar();
          switch(escolha){
          case 1:
            system("clear");
            printf("--------EDIÇÃO--------\n");
            printf("\nDigite o nome do Pet: ");
            fgets(nome[linha],CARAC,stdin);
            system("clear");
            printf("----------------------\n");
            printf("||    CONCLUÍDO    ||\n");
            printf("----------------------\n");
            printf("Nome: %s",nome[linha]);
            printf("----------------------\n");
            printf("Pressione enter para continuar_");
            getchar();
          break;
          case 2:
            system("clear");
            printf("--------EDIÇÃO--------\n");
            printf("\nDigite o nome do tutor: ");
            fgets(tutor[linha],CARAC,stdin);
            system("clear");
            printf("----------------------\n");
            printf("||    CONCLUÍDO    ||\n");
            printf("----------------------\n");
            printf("Tutor: %s",tutor[linha]);
            printf("----------------------\n");
            printf("Pressione enter para continuar_");
            getchar();
          break;
          case 3:
            system("clear");
            printf("--------EDIÇÃO--------\n");
            printf("\nDigite a Raça: ");
            fgets(raca[linha],CARAC,stdin);
            system("clear");
            printf("----------------------\n");
            printf("||    CONCLUÍDO    ||\n");
            printf("----------------------\n");
            printf("Raça: %s",raca[linha]);
            printf("----------------------\n");
            printf("Pressione enter para continuar_");
            getchar();
          break;
          case 4:
            if(HoraEsco[linha][1] == 1)
            {
              HoraEsco[linha][1] = 0;
              marcar(nome, motivo, codigo, horario, HoraEsco);
             }
            else
            {
              system("clear");
              printf("Você não possui consulta agendada\n");
              printf("Pressione enter para continuar_");
              getchar();
            }
          break;
          case 5: 
            if(HoraEsco[linha][1] == 1)
            {
              system("clear");
              HoraEsco[linha][1] = 0;
              printf("Consulta cancelada\n");
              printf("Pressione enter para continuar_");
              getchar();
            }
            else
            {
              system("clear");
              printf("Você não possui consulta agendada\n");
              printf("Pressione enter para continuar_");
              getchar();
            }
          break;
          case 6:
            if(HoraEsco[linha][1] == 1)
            {
              system("clear");
              printf("--------EDIÇÃO--------\n");
              printf("\nDigite o motivo: ");
              fgets(motivo[linha],CARAC,stdin);
              system("clear");
              printf("----------------------\n");
              printf("||    CONCLUÍDO    ||\n");
              printf("----------------------\n");
              printf("Motivo: %s",motivo[linha]);
              printf("----------------------\n");
              printf("Pressione enter para continuar_");
              getchar();
            }
            else
            {
              system("clear");
              printf("Você não possui consulta agendada\n");
              printf("Pressione enter para continuar_");
              getchar();
            }
          break;
          case 7:
            system("clear");
            printf("--------EDIÇÃO--------\n");
            printf("\nDigite a idade: ");
            fgets(dataN[linha],CARAC,stdin);
            system("clear");
            printf("----------------------\n");
            printf("||    CONCLUÍDO    ||\n");
            printf("----------------------\n");
            printf("Idade: %s",dataN[linha]);
            printf("----------------------\n");
            printf("Pressione enter para continuar_");
            getchar();
          break;
          case 8:
            system("clear");
            printf("Saindo...\n");
            sleep(2);
          break;
          default:
            system("clear");
            printf("Escolha inválida.\n\n");
            printf("Aguarde alguns instantes\n");
            sleep(2);
          } 
        }while (escolha != 8);
       }
      else 
      {
        printf("\n");
        system("clear");
        printf("pet não encontrado\n\n");
        printf("Gostaria de procurar novamente?\n1.Sim\n2.Não\n");
        scanf(" %d",&repit);
        getchar();
        system("clear");
      }    
    }while(repit ==1);
 } 
  else{
    system("clear");
    printf("----------------------\n");
    printf("Nenhum pet cadastrado\n");
    printf("----------------------\n");
    sleep(2);
  }
}

int main() {
  char nome[SIZE][CARAC], tutor[SIZE][CARAC], raca[SIZE][CARAC],motivo[SIZE][CARAC], dataN[SIZE][CARAC],vacina[SIZE][CARAC];
  int codigo[SIZE], horario[HORASM][2] ={0},HoraEsco[SIZE][2] = {0};
  int escolha = 0;

  setlocale(LC_ALL,"Portuguese");
 
  do {
      system("clear"); //limpar o terminal
      printf("-----CLINICA VETERINARIA------\n\n");
      printf("Digite:\n1.Cadastrar Pet\n2.Buscar Consulta\n3.Listar Consultas\n4.Marcar consulta\n5.Vacinar Pet\n6.Editar Cadastro\n7.Sair\n");
      scanf(" %d", &escolha);
      getchar(); 
      switch (escolha) {
        case 1:
          cadastrar(nome, tutor, raca, dataN, codigo,motivo,vacina);
        break;
        case 2:
        case 3:
          consultar(nome, tutor, raca, dataN, codigo,motivo,escolha,vacina,HoraEsco);
        break;
        case 4:
         marcar(nome, motivo, codigo, horario, HoraEsco);
        break;
        case 5:
          vacinar(nome,codigo,vacina);
        break;
        case 6:
          editar(nome, tutor, raca, dataN, codigo,motivo,horario,HoraEsco);
        case 7:
        system("clear");
          printf("Saindo...\n\n");
        break;
        default:
          system("clear");
          printf("Escolha inválida.\n\n");
          printf("Aguarde alguns instantes\n");
          sleep(2);
        break;
        }
      }while (escolha != 7);

  return 0;
}
