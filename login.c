// * Procedimento que realiza a verificação dos dados *
// * de login										  *
// *                                                  *
// *          	                  *
// *                    *
// * ************************************************/
#include "login.h"

void VerificaLogin(char *email, char *senha){
	BasePessoa();
	Pessoa pessoa;
 	InicializarPessoa(&pessoa);
 	int linha = 0, confirm = 0;
 	
 	rewind(fp);
 	while(1){
        if(fread(&pessoa, sizeof(Pessoa), 1, fp)!= 1){
			break;
		}
        if(pessoa.ativo == 0){
			continue;
		}
		if(strcmp(pessoa.email,email) == 0 && pessoa.ativo == 1){
			if(strcmp(pessoa.senha,senha) == 0){
				if(pessoa.tipo == 1){
					system("cls");
					MenuCliente(&pessoa);
				}else{
					system("cls");
					MenuGerente(&pessoa);
				}
			}else{
				printf("\n SENHA INVÁLIDA! Pressione enter para continuar.");
				getch();
			}
			confirm = 1;
		}
        linha++;
    }
    if(confirm == 0){
    	printf("\n Usuário Inválido! Pressione enter para continuar.");
    	getch();
	}
    if(linha == 0){
    	printf("Não há registros\n\n");
	}
	fclose(fp);
}

void login(){
	char email[MAX], senha[MAX];
	while(1){
		system("cls");
		printf(" //////////////////////////////////////////////////////////////////////\n");
		printf("\nLogin da gerência: admin@admin.com //senha: admin\n");
		printf("                           SEJA BEM VINDO \n");
		printf("\n");
		printf(" //////////////////////////////////////////////////////////////////////\n\n");
		printf(" EMAIL: ");
		fflush(stdin);
		fgets(email,sizeof(email),stdin);
		email[strlen(email) - 1] = '\0';
		
		printf("\n SENHA: ");
		fflush(stdin);
		fgets(senha,sizeof(senha),stdin);
		senha[strlen(senha) - 1] = '\0';
		
		VerificaLogin(email,senha);
	}
	
}

