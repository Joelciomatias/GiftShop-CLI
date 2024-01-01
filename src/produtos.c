// *   Procedimento que implementa as funções         *
// *   relacionadas a produtos        				  *					  *
// *  												  *
// *                                                  *
// *  ENTRADA:  N/A                                   *
// *  SAIDA: Exibição dos dados                       *
// * ************************************************//
//INCLUSAO DO CABECARIO DE PESSOA
#include "produtos.h"

//IMPLEMENTACAO DA FUNCAO BASE PESSOA
void BaseProduto(){
	fp = fopen(ARQ_PRODUTOS, "r+b"); // LEITURA E GRAVACAO
	if(fp==NULL){
        fp = fopen(ARQ_PRODUTOS, "w+b"); //ALTERAR
        if(fp==NULL){
            printf(" Erro fatal: impossível criar arquivo de dados\n");
            exit(1);
        }
    }
 }
//IMPLEMENTACAO DA FUNCAO INICIALIZAR PESSOA
void InicializarProduto(Produto *produto){
	strcpy(produto->cod,"");
	strcpy(produto->nome,"");
	strcpy(produto->descricao,"");
	strcpy(produto->categoria,"");
	produto->estoque = 0;
	produto->preco = 0;
	produto->ativo = 1;
}

//IMPLEMENTACAO DA FUNCAO QUE REALIZA A LEITURA DOS DADOS DO TECLADO
 void LerProduto(Produto *produto){
 	sprintf(produto->cod, "%i", carregaCodigoPro());
 	printf("Codigo: %s",produto->cod);
 	
 	printf("\nNome: ");
 	fflush(stdin);
	fgets(produto->nome, MAX, stdin);
	produto->nome[strlen(produto->nome) - 1] = '\0';
	
	printf("Descricao: ");
 	fflush(stdin);
	fgets(produto->descricao, MAX, stdin);
	produto->descricao[strlen(produto->descricao) - 1] = '\0';
	
	printf("Categoria: ");
	fflush(stdin);
	fgets(produto->categoria, MAX, stdin);
	produto->categoria[strlen(produto->categoria) - 1] = '\0';
	
	printf("Estoque: ");
	scanf("%i",&produto->estoque);
	
	printf("Preço: ");
	scanf("%f",&produto->preco);
 }
 
 //IMPLEMENTACAO DA FUNCAO EXIBICAO
 void ExibirProduto(Produto *produto){
 	printf ("\n Codigo: %s", produto->cod); 
 	printf ("\n Nome: %s", produto->nome);
	printf ("\n Descricao: %s", produto->descricao);
	printf ("\n Categoria: %s", produto->categoria);
	printf ("\n Estoque: %i",produto->estoque);
	printf ("\n Preco: %.2f",produto->preco);
 }

////IMPLEMENTACAO DA FUNCAO CADASTRO
 void CadastrarProduto(){
 	Produto produto;
 	 int op;
 	 InicializarProduto(&produto);
 	 LerProduto(&produto);
 	 while(1){
 	 	system("cls");
		ExibirProduto(&produto);
		printf("\n\n 1 - SALVAR  2 - ALTERAR  3 - SAIR ");
		scanf("%i", &op);
		 	 
		if(op == 1){
		 	BaseProduto();
			fseek(fp, 0, SEEK_END);
			if(fwrite(&produto, sizeof(Produto), 1, fp) == 0){
				printf("Erro ao gravar o registro! \n\n");		
				printf("\n Pressione alguma tecla para continuar.");
				getch();
			}else{
				printf("Registro cadastrado com sucesso! \n\n");
				sleep(1);
			}
			fclose(fp);
		}
		 	 	
		if(op == 2){
		 	while(1){
			 	system("cls");
			 	printf("ALTERAR \n\n");
			 	ExibirProduto(&produto);
			 	printf("\n 1 - NOME  2 - DESCRICAO  3 - CATEGORIA  4 - ESTOQUE  5 - PRECO  6 - VOLTAR \n");
				scanf("%i", &op);
						
				if(op == 1){
					printf("Nome: ");
					fflush(stdin);
					fgets(produto.nome, MAX, stdin);
					produto.nome[strlen(produto.nome) - 1] = '\0';
				}
							
				if(op == 2){
					printf("Descricao: ");
				 	fflush(stdin);
					fgets(produto.descricao, MAX, stdin);
					produto.descricao[strlen(produto.descricao) - 1] = '\0';
				}
							
				if(op == 3){
					printf("Categoria: ");
					fflush(stdin);
					fgets(produto.categoria, MAX, stdin);
					produto.categoria[strlen(produto.categoria) - 1] = '\0';
				}
							
				if(op == 4){
					printf("Estoque: ");
					scanf("%i",&produto.estoque);
				}
						
				if(op == 5){
					printf("Preço: ");
					scanf("%f",&produto.preco);
				}
				if(op == 6){
					break;
				}
			}
		}
		 	 	
		if(op == 3){
		 	break;
		}
	}
}
 
 ////IMPLEMENTACAO DA FUNCAO LISTAR
 void ListarProduto(){
 	//Abrir o arquivo para leitura
 	BaseProduto();
 	Produto produto;
 	//Inicializar nossa estrutura
 	InicializarProduto(&produto);
	int linha = 0;
 	rewind(fp); // coloca o curso no inicio do arquivo
 	
 	//percorrer o arquivo ate o final dele
 	
 	while(!feof(fp)){ // e mesma coisa que feof(fp) == 0
 		//verifica se contem dados no inicio do arquivo
 		if(fread(&produto, sizeof(Produto), 1, fp)!= 1){
			break;
		}
		//se produto for igual a ativo 0 pula para o final do laco e faz uma nova leitura no proximo registro
		
        if(produto.ativo == 0){
			continue;
		}
		ExibirProduto(&produto);
		printf("\n ++++++++++++++++  \n");
		linha++;
	 }
	  //verificador pra ver se tem registros no arquivo
	 if(linha == 0){
	 	printf("\n Não Contem registros \n"); 
	 }
 }
 
  ////IMPLEMENTACAO DA FUNCAO LISTAR
 void ListarProdutoPro(){
 	//Abrir o arquivo para leitura
 	BaseProduto();
 	Produto produto;
 	//Inicializar nossa estrutura
 	InicializarProduto(&produto);
	int linha = 0;
 	rewind(fp); // coloca o curso no inicio do arquivo
 	
 	//percorrer o arquivo ate o final dele
 	
 	while(!feof(fp)){ // e mesma coisa que feof(fp) == 0
 		//verifica se contem dados no inicio do arquivo
 		if(fread(&produto, sizeof(Produto), 1, fp)!= 1){
			break;
		}
		//se produto for igual a ativo 0 pula para o final do laco e faz uma nova leitura no proximo registro
		
        if(produto.ativo == 0){
			continue;
		}
		ExibirProduto(&produto);
		printf("\n ++++++++++++++++  \n");
		linha++;
	 }
	  //verificador pra ver se tem registros no arquivo
	 if(linha == 0){
	 	printf("\n Não Contem registros \n"); 
	 }
	 printf("\n\n Pressione Enter para voltar.");
	 getche();
 }
 
 ////IMPLEMENTACAO DA FUNCAO PESQUISA
 int PesquisarProduto(){
 	//abrir o arquivo produto
 	BaseProduto();
 	//criar estrutura
 	Produto produto;
 	//inicializar ela
 	InicializarProduto(&produto);
 	
 	//variaveis de captura para a comparacao dos paramentros
 	char valor[MAX];
 	strcpy(valor,"");
 	
	int pos = 0, linha = 0,op;

	//colocar o cursor no inicio do arquivo
    rewind(fp);
	while(!feof(fp)){
		
		printf("Digite o nome ou codigo a ser procurado: ");
	    fflush(stdin);
	    fgets(valor, MAX, stdin);
	    valor[strlen(valor) - 1] = '\0';
	    
	    //verifica a quantidade de caracteres digitados
	    if(strlen(valor) < 1){
	    	printf("Nome Invalido! \n\n");
		}else{
			//realiza a leitura dos registros
			while(fread(&produto, sizeof(Produto), 1, fp)){
				//realiza os comparativos
			    if(produto.ativo != 0 && strstr(produto.nome,valor) || produto.ativo != 0 && strstr(produto.cod,valor)){
			    	ExibirProduto(&produto);
			    	//informa se achou o registro
			    	pos = 1;
			    	printf("\n\n Precione ENTER para continuar.");
					getche();
			    	//manda a posicao do registro no arquivo para exclusao e alteracao
			    	return linha;
				}
				linha++;
			}
			if(pos == 0){
				printf("Registro não encontrado");
			}
			printf("\n\n Precione ENTER para continuar.");
			getche();
			
			break;
		}
	}
	fclose(fp);
 }

////IMPLEMENTACAO DA FUNCAO DE EXCLUSAO
void ExcluirProduto(){
	//Abrir o Arquivo
	BaseProduto();
	//strutura produto
	Produto produto;
	
	//iniciar Produto
	InicializarProduto(&produto);
 	
 	int pos=0,op;
 	
 	pos = PesquisarProduto();
 	
 	//Bosiciono o curso ate meu registro partindo do inicio 
    fseek(fp,pos*sizeof(Produto),SEEK_SET);
	
	//realizo a leitura e vejo se na quela posicao tem algum registro
    if(fread(&produto,sizeof(Produto),1,fp)==1){
		while(1){
			system("cls");
			ExibirProduto(&produto);
			printf("\n\n 1 - EXCLUIR   2 - SAIR\n");
			scanf("%i", &op);
			if(op == 1){
				//Troca o ativo 1 por 0
				produto.ativo = 0;
				//posiciono o curso novamente no registro para sobreescrevelo
				fseek(fp,pos*sizeof(Produto),SEEK_SET);
				//realizo a gravacao
		        if(fwrite(&produto,sizeof(Produto),1,fp) != 1){
		        	printf("\n Falha ao excluir o resgistro!\n");
		        	printf("\n\n Precione ENTER para continuar.");
					getche();
		        	break;
				}else{
					printf("\n Registro excluido com sucesso!\n");
					printf("\n\n Precione ENTER para continuar.");
					getche();
					break;
				}
			}
			if(op == 2){
				break;
			}
    	}
	}
	fclose(fp);
}

////IMPLEMENTACAO DA FUNCAO ALTERAR
void AlterarProduto(){
	//Abre o aquivo
	BaseProduto();
	//Estrutura de produto
 	Produto produto;
 	
 	int pos,op;
 	
 	//Pesquisa pelo registro e retorna a posicao do arquivo
 	pos = PesquisarProduto();
 	//aponta para a posicao do registyro partindo do inicio
    fseek(fp,pos*sizeof(Produto),SEEK_SET);
	
	//realiza a leitura e verifica se na posicao existe um registro
    if(fread(&produto,sizeof(Produto),1,fp)==1){
		while(1){
			system("cls");
			printf("ALTERAR \n\n");
			ExibirProduto(&produto);
			printf("\n 1 - NOME  2 - DESCRICAO  3 - CATEGORIA  4 - ESTOQUE  5 - PRECO  6 - SALVAR  7 - VOLTAR \n");
			scanf("%i", &op);
						
			if(op == 1){
				printf("Nome: ");
				fflush(stdin);
				fgets(produto.nome, MAX, stdin);
				produto.nome[strlen(produto.nome) - 1] = '\0';
			}
							
			if(op == 2){
				printf("Descricao: ");
				fflush(stdin);
				fgets(produto.descricao, MAX, stdin);
				produto.descricao[strlen(produto.descricao) - 1] = '\0';
			}
							
			if(op == 3){
				printf("Categoria: ");
				fflush(stdin);
				fgets(produto.categoria, MAX, stdin);
				produto.categoria[strlen(produto.categoria) - 1] = '\0';
			}
							
			if(op == 4){
				printf("Estoque: ");
				scanf("%i",&produto.estoque);
			}
							
			if(op == 5){
				printf("Preço: ");
				scanf("%f",&produto.preco);
			}
										
			if(op == 6){
				fseek(fp,pos*sizeof(Produto),SEEK_SET);
			       if(fwrite(&produto,sizeof(Produto),1,fp) != 1){
			       	printf("\n Falha ao Alterar o resgistro!\n");
			       	printf("\n\n Precione ENTER para continuar.");
					getche();
				}else{
					printf("\n Registro alterado com sucesso!\n");
					printf("\n\n Precione ENTER para continuar.");
					getche();
				}
			}
				
			if(op == 7){
			    break;
			}
		}
	}
    fclose(fp);
}

Produto BuscarProduto(char *valor){
 	//abrir o arquivo produto
 	BaseProduto();
 	//criar estrutura
 	Produto produto;
 	//inicializar ela
 	InicializarProduto(&produto);
	int pos = 0, linha = 0,op;

	//colocar o cursor no inicio do arquivo
    rewind(fp);
	while(!feof(fp)){
		
	    //verifica a quantidade de caracteres digitados
	    if(strlen(valor) < 1){
	    	printf("Nome Invalido! \n\n");
		}else{
			//realiza a leitura dos registros
			while(fread(&produto, sizeof(Produto), 1, fp)){
				//realiza os comparativos
			    if(produto.ativo != 0 && strstr(produto.nome,valor) || produto.ativo != 0 && strstr(produto.cod,valor)){
			    	//ExibirProduto(&produto);
			    	//informa se achou o registro
			    	pos = 1;
			    	return produto;
				}
				linha++;
			}
			if(pos == 0){
				printf("Registro não encontrado");
			}
		}
	}
	fclose(fp);
 }
 
 int carregaCodigoPro(){
	//Abrir o arquivo para leitura
 	BaseProduto();
 	Produto produto;
 	//Inicializar nossa estrutura
	int linha = 0;
 	rewind(fp); // coloca o curso no inicio do arquivo
 	//percorrer o arquivo ate o final dele
 	while(!feof(fp)){ // e mesma coisa que feof(fp) == 0
 		if(fread(&produto, sizeof(Produto), 1, fp)!= 1){
 			break;
		 }
		linha++;
	}
	return linha + 1;
	fclose(fp);
}
