// * Procedimento que direcionao cliente para a venda *
// * e o administrados para as sua oções              *
// *                                                  *
// *  ENTRADA:  N/A                                   *
// *  SAIDA: Exibição dos dados                       *
// * ************************************************/
#include "menu.h"

void MenuCliente(Pessoa *pessoa){
	int op;
	printf(" //////////////////////////////////////////////////////////////////////\n");
	printf("\n");
	printf("                      AREA DO CLIENTE   \n");
	printf("\n");
	printf(" //////////////////////////////////////////////////////////////////////\n\n");
	printf(" DATA: %s                                  USUÁRIO: %s \n HORA: %s",__DATE__,pessoa->nome,__TIME__);
	
	printf("\n\n ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ \n");
	ListarProduto();
	while(1){
		BaseSelecao(pessoa->cod);
		cadastrarSelecao();
		printf("\n Deseja continuar a compra: 1 - SIM  2 - NÃO: ");
		scanf("%i",&op);
		if(op == 1){
			continue;
		}else if(op == 2){
			exibirVenda(pessoa->nome,pessoa->cod);
			break;
		}else{
			printf("\n\n Opção inválida! \n");
			sleep(1);
		}
	}
}

void MenuGerente(Pessoa *pessoa){
	int op;
	do{
		system("cls");
		printf(" //////////////////////////////////////////////////////////////////////\n");
		printf("\n");
		printf("                      AREA ADMINISTRATIVA   \n");
		printf("\n");
		printf(" //////////////////////////////////////////////////////////////////////\n\n");
		printf(" DATA: %s                                  USUÁRIO: %s \n HORA: %s",__DATE__,pessoa->nome,__TIME__);
		
		printf("\n\n ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ \n\n");
		printf("1 - CADASTRAR CLIENTE \n");
		printf("2 - PESQUISAR CLIENTE \n");
		printf("3 - ALTERAR CLIENTE \n");
		printf("4 - EXCLUIR CLIENTE \n");
		printf("5 - LISTAR CLIENTE \n");
		printf("6 - CADASTRAR PRODUTOS \n");
		printf("7 - ALTERAR PRODUTOS \n");
		printf("8 - EXCLUIR PRODUTOS \n");
		printf("9 - PESQUISAR PRODUTOS \n");
		printf("10 - LISTAR PRODUTOS \n");
		printf("11 - LISTAR VENDAS \n");
		printf("0 - SAIR \n");
		
		printf("\n Escolha uma das opçoes acima: ");
		scanf("%d",&op);
		
		switch(op){
			case 1:
				system("cls");
				printf("////////////////////////////////////////////////////\n");
				printf("\n               CADASTRAR CLIENTES\n");
				printf("\n////////////////////////////////////////////////////\n");
				CadastrarPessoa();
			break;
			
			case 2:
				system("cls");
				printf("////////////////////////////////////////////////////\n");
				printf("\n               PESQUISAR CLIENTES\n");
				printf("\n////////////////////////////////////////////////////\n");
				PesquisarPessoa();
			break;
			
			case 3:
				system("cls");
				printf("////////////////////////////////////////////////////\n");
				printf("\n               ALTERAR CLIENTES\n");
				printf("\n////////////////////////////////////////////////////\n");
				AlterarPessoa();
			break;
			
			case 4:
				system("cls");
				printf("////////////////////////////////////////////////////\n");
				printf("\n               EXCLUIR CLIENTES\n");
				printf("\n////////////////////////////////////////////////////\n");
				ExcluirPessoa();
			break;
			
			case 5:
				system("cls");
				printf("////////////////////////////////////////////////////\n");
				printf("\n               LISTAR CLIENTES\n");
				printf("\n////////////////////////////////////////////////////\n");
				ListarPessoa();
			break;
			
			case 6:
				system("cls");
				printf("////////////////////////////////////////////////////\n");
				printf("\n               CADASTRAR PRODUTOS\n");
				printf("\n////////////////////////////////////////////////////\n");
				CadastrarProduto();
			break;
			
			case 7:
				system("cls");
				printf("////////////////////////////////////////////////////\n");
				printf("\n               ALTERAR PRODUTOS\n");
				printf("\n////////////////////////////////////////////////////\n");
				AlterarProduto();
			break;
			
			case 8:
				system("cls");
				printf("////////////////////////////////////////////////////\n");
				printf("\n               EXCLUIR PRODUTOS\n");
				printf("\n////////////////////////////////////////////////////\n");
				ExcluirProduto();
			break;
			
			case 9:
				system("cls");
				printf("////////////////////////////////////////////////////\n");
				printf("\n               PESQUISAR PRODUTOS\n");
				printf("\n////////////////////////////////////////////////////\n");
				PesquisarProduto();
			break;
			
			case 10:
				system("cls");
				printf("////////////////////////////////////////////////////\n");
				printf("\n               LISTAR PRODUTOS\n");
				printf("\n////////////////////////////////////////////////////\n");
				ListarProdutoPro();
			break;
			case 11:
				system("cls");
				printf("////////////////////////////////////////////////////\n");
				printf("\n               LISTAR VENDAS\n");
				printf("\n////////////////////////////////////////////////////\n");
				listarVenda();
			break;
		}
	}while(op != 0);
}



