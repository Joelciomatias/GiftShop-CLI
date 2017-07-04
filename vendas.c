// * Procedimento que realiza a execução da venda     *
// *  												  *
// *                                                  *
// *  ENTRADA:  N/A                                   *
// *  SAIDA: Exibição dos dados                       *
// * ************************************************/
#include "vendas.h"

void exibirVenda(char nome[MAX], char cod[MAX]){
	system("cls");
	printf(" //////////////////////////////////////////////////////////////////////\n");
	printf("\n");
	printf("                      FINALIZAR VENDA   \n");
	printf("\n");
	printf(" //////////////////////////////////////////////////////////////////////\n\n");
	printf(" DATA: %s                                  USUARIO: %s \n HORA: %s",__DATE__,nome,__TIME__);
	printf("\n\n ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ \n");
	carregarVenda(cod,nome);
}

void inicializarVenda(Venda *venda){
	int i;
	strstr(venda->cod,"");
	strstr(venda->nome,"");
	for(i = 0; i < MAX; i++){
		strstr(venda->selecao->produto.cod,"");
		strstr(venda->selecao->produto.nome,"");
		strstr(venda->selecao->produto.descricao,"");
		strstr(venda->selecao->produto.categoria,"");
		venda->selecao->produto.estoque = 0;
		venda->selecao->produto.preco = 0;
	}
	venda->pagamento = 0;
	venda->total = 0;
	venda->tamanho = 0;
}

void carregarSelecao(char *cod, Venda *venda){
	BaseSelecao(cod);
	Selecao selecao;
 	inicializarSelecao(&selecao);
 	inicializarVenda(venda);
	int linha = 0, i = 0;
 	rewind(sel); 
 	
 	while(!feof(sel)){ 
 		if(fread(&selecao, sizeof(Selecao), 1, sel)!= 1){
			break;
		}
		strcpy(venda->selecao[i].produto.cod,selecao.produto.cod);
		strcpy(venda->selecao[i].produto.nome,selecao.produto.nome);
		strcpy(venda->selecao[i].produto.descricao,selecao.produto.descricao);
		strcpy(venda->selecao[i].produto.categoria,selecao.produto.categoria);
		venda->selecao[i].produto.estoque = selecao.produto.estoque;
		venda->selecao[i].produto.preco = selecao.produto.preco;
		venda->selecao[i].quantidade = selecao.quantidade;
		venda->total = venda->total + (venda->selecao[i].quantidade * venda->selecao[i].produto.preco);
		venda->tamanho++;
		i++;
		linha++;
		
	 }
	  //verificador pra ver se tem registros no arquivo
	 if(linha == 0){
	 	printf("\n Não Contem registros \n"); 
	 }
	fclose(sel);
}

void carregarVenda(char *cod, char *nome){
	int op;
	Venda venda;
	sprintf(venda.cod, "%i", carregaCodigo());
	strcpy(venda.nome,nome);
	carregarSelecao(cod, &venda);
	exibirProdVenda(&venda);
	printf("\n\n VALOR TOTAL: %.2f",venda.total);
	printf("\n\n Deseja Finalizar compra: 1 - SIM  2 - CANCELAR: ");
	scanf("%i",&op);
	if(op == 1){
		baseVenda();
		fseek(ven, 0, SEEK_END);
		if(fwrite(&venda, sizeof(Venda), 1, ven) == 0){
			printf("Erro ao gravar o registro! \n\n");
			remove(cod);		
			printf("\n Pressione alguma tecla para continuar.");
			getch();
		}else{
			fclose(ven);
			remove(cod);
			sleep(1);
			exibirCartao(venda.cod);
		}
		
	}else{
		remove(cod);
	}
}

void baseVenda(){
	ven = fopen(ARQ_VENDAS, "r+b"); // LEITURA E GRAVACAO
	if(ven==NULL){
        ven = fopen(ARQ_VENDAS, "w+b"); //ALTERAR
        if(ven==NULL){
            printf(" Erro fatal: impossível criar arquivo de dados\n");
            exit(1);
        }
    }
}

void exibirProdVenda(Venda *venda){
	int i;
	for(i = 0; i < venda->tamanho; i++){
		printf("\n\n CODIGO: %s",venda->selecao[i].produto.cod);
		printf("\n NOME: %s",venda->selecao[i].produto.nome);
		printf("\n DESCRICAO: %s",venda->selecao[i].produto.descricao);
		printf("\n PRECO: %.2f",venda->selecao[i].produto.preco);
		printf("\n QUANTIDADE: %i",venda->selecao[i].quantidade);
	}
}
void exibirListaVenda(Venda *venda){
	int i;
	printf("\n CODIGO VENDA: %s", venda->cod);
	printf("\n\n CLIENTE: %s", venda->nome);
	for(i = 0; i < venda->tamanho; i++){
		printf("\n\n CODIGO: %s",venda->selecao[i].produto.cod);
		printf("\n NOME: %s",venda->selecao[i].produto.nome);
		printf("\n DESCRICAO: %s",venda->selecao[i].produto.descricao);
		printf("\n CATEGORIA: %s",venda->selecao[i].produto.categoria);
		printf("\n ESTOQUE: %i",venda->selecao[i].produto.estoque);
		printf("\n PRECO: %.2f",venda->selecao[i].produto.preco);
		printf("\n QUANTIDADE: %i",venda->selecao[i].quantidade);
	}
	printf("\n\n VALOR TOTAL: %.2f",venda->total);
	if(venda->pagamento == 0){
		printf("\n\n Pagamento pendente \n");
	}else{
		printf("\n\n Pagamento efetuado \n");
	}
}

void listarVenda(){
	//Abrir o arquivo para leitura
 	baseVenda();
 	Venda venda;
 	//Inicializar nossa estrutura
 	inicializarVenda(&venda);
	int linha = 0;
 	rewind(fp); // coloca o curso no inicio do arquivo
 	//percorrer o arquivo ate o final dele
 	while(!feof(ven)){ // e mesma coisa que feof(fp) == 0
 		if(fread(&venda, sizeof(Venda), 1, ven)!= 1){
 			break;
		 }
		exibirListaVenda(&venda);
		printf("\n ++++++++++++++++  \n");
		linha++;
	 }
	  //verificador pra ver se tem registros no arquivo
	 if(linha == 0){
	 	printf("\n Não Contem registros \n"); 
	 }
	 fclose(ven);
	 printf("\n\n Precione enter para voltar\n");
	 getche();
}


////IMPLEMENTACAO DA FUNCAO PESQUISA
 int PesquisarVenda(char *cod){
 	//abrir o arquivo produto
 	baseVenda();
 	//criar estrutura
 	Venda venda;
 	//inicializar ela
 	inicializarVenda(&venda);
	int pos = 0, linha = 0,op;

	//colocar o cursor no inicio do arquivo
    rewind(ven);
	while(!feof(ven)){
		while(fread(&venda, sizeof(Venda), 1, ven)){
			//realiza os comparativos
			if(strstr(venda.cod,cod)){
			    pos = 1;
			    return linha;
			}
			linha++;
		}
		if(pos == 0){
			printf("Registro não encontrado");
		}
		break;
	}
	fclose(ven);
 }

////IMPLEMENTACAO DA FUNCAO DE EXCLUSAO
void AlterarVenda(char *cod){
	//Abrir o Arquivo
	baseVenda();
	//strutura produto
	Venda venda;
	
	//iniciar Produto
	inicializarVenda(&venda);
 	
 	int pos=0,op;
 	
 	pos = PesquisarVenda(cod);
 	
 	//Bosiciono o curso ate meu registro partindo do inicio 
    fseek(ven,pos*sizeof(Venda),SEEK_SET);
	
	//realizo a leitura e vejo se na quela posicao tem algum registro
    if(fread(&venda,sizeof(Venda),1,ven)==1){
		while(1){
			venda.pagamento = 1;
			//posiciono o curso novamente no registro para sobreescrevelo
			fseek(ven,pos*sizeof(Venda),SEEK_SET);
			//realizo a gravacao
		    if(fwrite(&venda,sizeof(Venda),1,ven) != 1){
		       	printf("\n Falha ao Concluir Pagamento!\n");
		       	printf("\n\n Precione ENTER para continuar.");
				getche();
		       	break;
			}else{
				printf("\n\n Pagamento realizado com sucesso!\n");
				sleep(2);
				break;
			}
		}
	}
	fclose(ven);
}

int carregaCodigo(){
	//Abrir o arquivo para leitura
 	baseVenda();
 	Venda venda;
 	//Inicializar nossa estrutura
 	inicializarVenda(&venda);
	int linha = 0;
	char codigo;
 	rewind(fp); // coloca o curso no inicio do arquivo
 	//percorrer o arquivo ate o final dele
 	while(!feof(ven)){ // e mesma coisa que feof(fp) == 0
 		if(fread(&venda, sizeof(Venda), 1, ven)!= 1){
 			break;
		 }
		linha++;
	}
	return linha + 1;
	 fclose(ven);
}
