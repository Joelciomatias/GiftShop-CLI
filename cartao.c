// * Procedimento que simula de forma simples uma     *
// * operadora de cartao                              *
// *                                                  *
// *  ENTRADA:  numero do cartao                      *
// *  SAIDA: Situa��o do pagamento                    *
// * ************************************************/
#include "cartao.h"

void exibirCartao(char *cod){
	char numero[16], codigo[3];
	
	while(1){
		system("cls");
		printf("////////////////////////////////////////////////////\n");
		printf("\n               PAGAMENTO\n");
		printf("\n////////////////////////////////////////////////////\n");
		
		printf("\n\n Digite o n�mero do cart�o: ");
		fflush(stdin);
		gets(numero);
		//numero[strlen(numero) - 1] = '\0';
		
		printf("\n\n Digite o c�digo de segura�a do cart�o: ");
		fflush(stdin);
		gets(codigo);
		
		if(strlen(numero) < 16){
			printf(" \n N�mero do cart�o Inv�lido! ");
			printf("\n\n Pressione Enter para continuar.");
			getche();
		}else if(strlen(codigo) < 3){
			printf(" \n C�digo de seguran�a Inv�lido! ");
			printf("\n\n Pressione Enter para continuar.");
			getche();
		}else{
			printf("\n\n Verificando Pagamento...");
			sleep(3);
			AlterarVenda(cod);
			break;
		}
	}
}
