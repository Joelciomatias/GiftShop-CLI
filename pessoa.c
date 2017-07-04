// * Procedimento que implementa as funções    	      *
// * relacionadas a pessoa                            *
// *                                                  *
// *  ENTRADA:  N/A                                   *
// *  SAIDA: Exibição dos dados                       *
// * ************************************************/
//INCLUSAO DO CABECARIO DE PESSOA
#include "pessoa.h"
//IMPLEMENTACAO DA FUNCAO BASE PESSOA
void BasePessoa(){
	fp = fopen(ARQ_PESSOA, "r+b");
	if(fp==NULL){
        fp = fopen(ARQ_PESSOA, "w+b"); 
        if(fp==NULL){
            printf(" Erro fatal: impossível criar arquivo de dados\n");
            exit(1);
        }
    }
 }
//IMPLEMENTACAO DA FUNCAO INICIALIZAR PESSOA
void InicializarPessoa(Pessoa *pessoa){
	strcpy(pessoa->cod,"");
	strcpy(pessoa->nome,"");
	pessoa->cpf = 0; 
	strcpy(pessoa->email,"");
	strcpy(pessoa->senha,"");
	pessoa->ativo = 1;
	pessoa->tipo = 1;
}

//IMPLEMENTACAO DA FUNCAO QUE REALIZA A LEITURA DOS DADOS DO TECLADO
 void LerPessoa(Pessoa *pessoa){
 	sprintf(pessoa->cod, "%i", CarregaCodigoPes());
 	printf("Código: %s",pessoa->cod);
	
 	printf("\n\nNome: ");
 	fflush(stdin);
	fgets(pessoa->nome, MAX, stdin);
	pessoa->nome[strlen(pessoa->nome) - 1] = '\0';
	
	printf("CPF: ");
	fflush(stdin); 
	scanf("%i",&pessoa->cpf);
	
	printf("Email: ");
	fflush(stdin);
	fgets(pessoa->email, MAX, stdin);
	pessoa->email[strlen(pessoa->email) - 1] = '\0';
	
	printf("Senha: ");
	fflush(stdin);
	fgets(pessoa->senha, MAX, stdin);
	pessoa->senha[strlen(pessoa->senha) - 1] = '\0';
 }
 
 //IMPLEMENTACAO DA FUNCAO EXIBICAO
 void ExibirPessoa(Pessoa *pessoa){
 	printf ("\n CÓDIGO: %s", pessoa->cod); 
 	printf ("\n Nome: %s", pessoa->nome);
	printf ("\n CPF: %i", pessoa->cpf);
	printf ("\n Email: %s", pessoa->email);
	printf ("\n Senha: %s",pessoa->senha);
 }

////IMPLEMENTACAO DA FUNCAO CADASTRO
 void CadastrarPessoa(){
 	Pessoa pessoa;
 	 int op;
 	 InicializarPessoa(&pessoa);
 	 LerPessoa(&pessoa);
 	while(1){
		system("cls");
	 	ExibirPessoa(&pessoa);
	 	printf("\n\n 1 - SALVAR  2 - ALTERAR  3 - SAIR ");
	 	scanf("%i", &op);
	 	 
	 	if(op == 1){
	 		BasePessoa();
			fseek(fp, 0, SEEK_END);
			if(fwrite(&pessoa, sizeof(Pessoa), 1, fp) == 0){
				printf("Erro ao gravar o registro! \n\n");	
				printf("\n Pressione alguma tecla para continuar.");
				getch();
			}else{
				printf("Registro cadastrado com sucesso! \n\n");
				fclose(fp);
				sleep(1);
				break;
			}
		
		}
			
	 	if(op == 2){
	 	 	while(1){
		 		system("cls");
		 	 	printf("ALTERAR \n\n");
		 	 	ExibirPessoa(&pessoa);
		 	 	printf("\n 1 - NOME  2 - CPF  3 - EMAIL  4 - SENHA  5 - VOLTAR \n");
				scanf("%i", &op);

				if(op == 1){
					printf("Nome: ");
					fflush(stdin);
					fgets(pessoa.nome, MAX, stdin);
				}
						
				if(op == 2){
					printf("CPF: ");
					fflush(stdin); 
					scanf("%i",&pessoa.cpf);
				}
						
				if(op == 3){
					printf("Email: ");
					fflush(stdin);
					fgets(pessoa.email, MAX, stdin);
				}
						
				if(op == 4){
					printf("Senha: ");
					fflush(stdin);
					fgets(pessoa.senha, MAX, stdin);
				}
						
				if(op == 5){
					fflush(stdin);
					break;
				}
						
			}
	 	}
	 	 	
	 	if(op == 3){
	 	 		printf("\nVoltando ao menu!");
	 	 		sleep(1);
	 	 		break;
	 	}else{
	 		printf(" \n Opção inválida! \n");
	 	 		sleep(1);
		}
	 	 	
	}
 }
 
 ////IMPLEMENTACAO DA FUNCAO LISTAR
 void ListarPessoa(){
 	//Abrir o arquivo para leitura
 	BasePessoa();
 	Pessoa pessoa;
 	//Inicializar nossa estrutura
 	InicializarPessoa(&pessoa);
	int linha = 0;
 	rewind(fp); // coloca o curso no inicio do arquivo
 	
 	//percorrer o arquivo ate o final dele
 	
 	while(!feof(fp)){ // e mesma coisa que feof(fp) == 0
 		//verifica se contem dados no inicio do arquivo
 		if(fread(&pessoa, sizeof(Pessoa), 1, fp)!= 1){
			break;
		}
		//se pessoa for igual a ativo 0 pula para o final do laco e faz uma nova leitura no proximo registro
		
        if(pessoa.ativo == 0){
			continue;
		}
		if(pessoa.tipo == 0){
			continue;
		}
		ExibirPessoa(&pessoa);
		printf("\n ++++++++++++++++  \n");
		linha++;
	 }
	  //verificador pra ver se tem registros no arquivo
	 if(linha == 0){
	 	printf("\n Não Contem registros \n"); 
	 }
	 printf("\n Precione ENTER para voltar ao MENU.");
	 getche();
 }
 
 ////IMPLEMENTACAO DA FUNCAO PESQUISA
 int PesquisarPessoa(){
 	//abrir o arquivo pessoa
 	BasePessoa();
 	//criar estrutura
 	Pessoa pessoa;
 	//inicializar ela
 	InicializarPessoa(&pessoa);
 	
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
			while(fread(&pessoa, sizeof(Pessoa), 1, fp)){
				//realiza os comparativos
			    if(pessoa.ativo != 0 && strstr(pessoa.nome,valor) || pessoa.ativo != 0 && strstr(pessoa.cod,valor)){
			    	ExibirPessoa(&pessoa);
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
void ExcluirPessoa(){
	//Abrir o Arquivo
	BasePessoa();
	//strutura pessoa
	Pessoa pessoa;
	
	//iniciar Pessoa
	InicializarPessoa(&pessoa);
 	
 	int pos=0,op;
 	
 	pos = PesquisarPessoa();
 	
 	//Bosiciono o curso ate meu registro partindo do inicio 
    fseek(fp,pos*sizeof(Pessoa),SEEK_SET);
	
	//realizo a leitura e vejo se na quela posicao tem algum registro
    if(fread(&pessoa,sizeof(Pessoa),1,fp)==1){
		while(1){
			system("cls");
			ExibirPessoa(&pessoa);
			printf("\n\n 1 - EXCLUIR   2 - SAIR\n");
			scanf("%i", &op);
			if(op == 1){
				//Troca o ativo 1 por 0
				pessoa.ativo = 0;
				//posiciono o curso novamente no registro para sobreescrevelo
				fseek(fp,pos*sizeof(Pessoa),SEEK_SET);
				//realizo a gravacao
		        if(fwrite(&pessoa,sizeof(Pessoa),1,fp) != 1){
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
void AlterarPessoa(){
	//Abre o aquivo
	BasePessoa();
	//Estrutura de pessoa
 	Pessoa pessoa;
 	
 	int pos,op;
 	
 	//Pesquisa pelo registro e retorna a posicao do arquivo
 	pos = PesquisarPessoa();
 	//aponta para a posicao do registyro partindo do inicio
    fseek(fp,pos*sizeof(Pessoa),SEEK_SET);
	
	//realiza a leitura e verifica se na posicao existe um registro
    if(fread(&pessoa,sizeof(Pessoa),1,fp)==1){
		while(1){
			system("cls");
			printf(" +++++++++++ ALTERAR CLIENTE +++++++++++++\n");
		 	ExibirPessoa(&pessoa);
		 	printf("\n 1 - NOME  2 - CPF  3 - EMAIL  4 - SENHA  5 - SALVAR  6 - SAIR \n");
			scanf("%i", &op);
					
			if(op == 1){
				printf("Nome: ");
				fflush(stdin);
				fgets(pessoa.nome, MAX, stdin);
			}
						
			if(op == 2){
				printf("CPF: ");
				fflush(stdin); 
				scanf("%i",&pessoa.cpf);
			}
						
			if(op == 3){
				printf("Email: ");
				fflush(stdin);
				fgets(pessoa.email, MAX, stdin);
			}
						
			if(op == 4){
				printf("Senha: ");
				fflush(stdin);
				fgets(pessoa.senha, MAX, stdin);
			}
						
			if(op == 5){
				fseek(fp,pos*sizeof(Pessoa),SEEK_SET);
		        if(fwrite(&pessoa,sizeof(Pessoa),1,fp) != 1){
		        	printf("\n Falha ao Alterar o resgistro!\n");
		        	printf("\n\n Precione ENTER para continuar.");
					getche();
		        	break;
				}else{
					printf("\n Registro alterado com sucesso!\n");
					printf("\n\n Precione ENTER para continuar.");
					getche();
					break;
				}
			}
			
			if(op == 6){
		    	printf("\n SAINDO \n");
				sleep(1);
			}
						
		}
    	
	}
    fclose(fp);
}

int CarregaCodigoPes(){
	//Abrir o arquivo para leitura
 	BasePessoa();
 	Pessoa pessoa;
 	//Inicializar nossa estrutura
	int linha = 0;
 	rewind(fp); // coloca o curso no inicio do arquivo
 	//percorrer o arquivo ate o final dele
 	while(!feof(fp)){ // e mesma coisa que feof(fp) == 0
 		if(fread(&pessoa, sizeof(Pessoa), 1, fp)!= 1){
 			break;
		 }
		linha++;
	}
	return linha + 1;
	fclose(fp);
}
