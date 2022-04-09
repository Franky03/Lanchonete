#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int main(void) {
  system("clear");
  int opc, lanche, quant, card;
  float preco, troco, ced, falta;
  Menu: //Aqui é definido uma marca, um rótulo para o código
  do {
  printf("====LANCHONETE FRANKY====\n");
  printf("[0]Promoçoes\n");
  printf("[1]Cardapio\n");
  printf("[2]Sair\n");
  printf("O que deseja? ");
  scanf("%d", &opc);
    } while (card==1);
  //Escolha das opções com Switch
  switch (opc) {
  case 0: // Promoções
    printf("======PROMOÇOES======\n");
    printf("[1]4+ X-Tudos === 25 por cento de desconto\n");
    printf("[2]2+ Chesseburguer === 30 por cento de desconto\n");
    printf("[3]Primeiro refrigerante sai de graça\n");
    printf("Quer ir para o cardápio ?\n");
    printf("[1]Sim\n");
    printf("[2]Não\n");
    printf("Escolha: ");
    scanf("%d", &card);
    if (card==2){
      break;
    }
    
  case 1: // Cardapio
    printf("\n======CARDAPIO======\n");
    printf("[1] Pao.......... R$2.00\n");
    printf("[2] Chesseburguer..........R$13.00\n");
    printf("[3] X-Tudo..........R$14.50\n");
    printf("[4] Refri..........R$5.99\n");
    printf("[5] Agua..........R$2.00\n");
    printf("[0]Sair\n");
    printf("Escolha seu lanche:  \n");
    scanf("%d", &lanche);
    //Aninhamento de switchs dos lanches
    switch (lanche) { 
    case 1:
      printf("Quantos?");
      scanf("%d", &quant);
      preco = 2.00 * quant;
      printf("\nDeu R$ %.2f", preco);
      break;
    case 2:
      printf("Quantos?");
      scanf("%d", &quant);
      preco = 13.00 * quant;
      if (quant>=2){
        preco= preco * 0.70;
      }
      printf("\nDeu R$ %.2f", preco);
      break;
    case 3:
      printf("Quantos?");
      scanf("%d", &quant);
      preco = 14.50 * quant;
      if (quant>=4){
        preco= preco* 0.75;
      }
      printf("\nDeu R$ %.2f", preco);
      break;
    case 4:
      printf("Quantos?");
      scanf("%d", &quant);
      preco = 5.99 * (quant-1);
      printf("\nDeu R$ %.2f", preco);
      break;
    case 5:
      printf("Quantos?");
      scanf("%d", &quant);
      preco = 2.00 * quant;
      printf("\nDeu R$ %.2f", preco);
      break;
    case 0:
      printf("FIM");
      break;
    default:
      printf("Opção inválida");
    }
    if (lanche>=1 && lanche<=5){
    printf("\nCom qual nota vc vai pagar? ");
      scanf("%f", &ced);
      troco = ced - preco;
      //Se o a cédula oferecida for menor que a conta, ele vai entrar em um laço até a cédula ser suficiente
      while (ced<preco){
        falta= preco- ced;
        printf("Está faltando R$ %.2f", falta);
        printf("\nCom qual nota vc vai pagar? ");
        scanf("%f", &ced);
        troco = ced - preco;
      }
      if (troco>0){
        printf("O troco vai ser R$ %.2f", troco);
      }
      else if(troco==0){
        printf("Não tem troco");
      }
      }
    break;
  case 2: // Sair
    printf("FIM");
    system("clear");
    return 0;
  default:
    printf("Opção inválida\n");
    goto Menu; //Defini um ngc antes do código, o próprio codg, o goto Menu é para voltar ao Menu
  }
}