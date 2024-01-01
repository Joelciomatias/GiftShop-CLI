// * Procedimento que realiza a seleção dos produtos  *
// *  												  *
// *                                                  *
// *  ENTRADA:  N/A                                   *
// *  SAIDA: Exibição dos dados                       *
// * ************************************************/
//INCLUSAO DO CABECARIO DE PESSOA
#include "selecao.h"

//IMPLEMENTACAO DA FUNCAO BASE PESSOA
void BaseSelecao(char cod[]){ 
	sel = fopen(cod, "r+b"); // LEITURA E GRAVACAO
	if(sel ==NULL){
        sel = fopen(cod, "w+b"); //ALTERAR
        if(sel==NULL){
            printf(" Erro fatal: impossível criar arquivo de dados\n");
            exit(1);
        }
    }
 }


void inicializarSelecao(Selecao *selecao){
	strstr(selecao->valor,"");
	selecao->quantidade = 0;
}

void lerSelecao(Selecao *selecao){
	printf("\n Digite o codigo ou nome do produto: ");
	fflush(stdin);
	fgets(selecao->valor, MAX, stdin);
	selecao->valor[strlen(selecao->valor) - 1] = '\0';
	
	selecao->produto =  BuscarProduto(selecao->valor);
	
	if(selecao->produto.estoque > 1){
		while(1){
			printf("\n Digite quantidade de produtos: ");
			scanf("%i",&selecao->quantidade);
			if(selecao->quantidade < selecao->produto.estoque && selecao->quantidade > 0){
				break;
			}else{
				printf("\n Quantidade invalida! \n");
				sleep(1);
			}
		}
	}else{
		printf("\n Sem estoque disponivel! \n");
	}
}

void exibirSelecao(Selecao *selecao){
	printf ("\n CODIGO: %s", selecao->valor); 
 	printf("\n NOME: %s",selecao->produto.nome);
 	printf("\n DESCRICAO: %s",selecao->produto.descricao);
 	printf("\n CATEGORIA: %s",selecao->produto.categoria);
 	printf("\n VALOR: %f",selecao->produto.preco);
 	printf ("\n QUANTIDADE:  %i", selecao->quantidade);
}

void cadastrarSelecao(){
	Selecao selecao;
	inicializarSelecao(&selecao);
	lerSelecao(&selecao);
	fseek(sel, 0, SEEK_END);
	fwrite(&selecao, sizeof(Selecao), 1, sel);
	fclose(sel);
}

void listarSelecao(){
 	Selecao selecao;
 	//Inicializar nossa estrutura
 	inicializarSelecao(&selecao);
	int linha = 0;
 	rewind(sel); // coloca o curso no inicio do arquivo
 	
 	//percorrer o arquivo ate o final dele
 	
 	while(!feof(sel)){ // e mesma coisa que feof(fp) == 0
 		//verifica se contem dados no inicio do arquivo
 		if(fread(&selecao, sizeof(Selecao), 1, sel)!= 1){
			break;
		}
		//se pessoa for igual a ativo 0 pula para o final do laco e faz uma nova leitura no proximo registro
		exibirSelecao(&selecao);
		printf("\n ++++++++++++++++  \n");
		linha++;
	 }
	  //verificador pra ver se tem registros no arquivo
	 if(linha == 0){
	 	printf("\n Não Contem registros \n"); 
	 }
	fclose(sel);
}
