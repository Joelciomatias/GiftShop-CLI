// * Procedimento que simula de forma simples uma     *
// * operadora de cartao                              *
// *                                                  *
// *  ENTRADA:  numero do cartao                      *
// *  SAIDA: Situa��o do pagamento                    *
// * ************************************************/
#include "cartao.h"

void exibirCartao(char *cod){
	char numero[17], codigo[4];
	
	while(1){
		system("cls");
		printf("////////////////////////////////////////////////////\n");
		printf("\n               PAGAMENTO\n");
		printf("\n////////////////////////////////////////////////////\n");
		
		printf("\n\n Digite o número do cart�o: ");
		fflush(stdin);
		fgets(numero, sizeof(numero), stdin);

		size_t len = strlen(numero);
		if (len > 0 && numero[len - 1] == '\n') {
			numero[len - 1] = '\0';
		}
		
		printf("\n\n Digite o c�digo de segura�a do cart�o: ");
		fflush(stdin);
		fgets(codigo, sizeof(codigo), stdin);

		size_t len2 = strlen(codigo);
		if (len2 > 0 && codigo[len2 - 1] == '\n') {
			codigo[len2 - 1] = '\0';
		}
		
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
