#ifndef PESSOA_H
#define PESSOA_H

/***************************************************
 * Bibliotecas                                     *
 * ************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// CONSTANTES PARA O BUFFERS DE TECLADO E OUTROS
#define MAX 30

#define ARQ_PESSOA "pessoa.txt"

FILE *fp;

//ESTRUTURA DO TIPO PESSOA
//PESSOA VAI TER O QUE?- Nome, CPF , email PARAMETROS PARA CONFIGURACAO E ALGUMAS ACOES  tipo, ativo
typedef struct{
	char cod[MAX];
	char nome[MAX];
	int cpf;
	char email[MAX];
	char senha[MAX];
	int ativo;
	int tipo;
}Pessoa; 

void BasePessoa();

void InicializarPessoa(Pessoa *pessoa);

void LerPessoa(Pessoa *pessoa);

void ExibirPessoa(Pessoa *pessoa);

void CadastrarPessoa();

void ListarPessoa();

int PesquisarPessoa();

void ExcluirPessoa();

void AlterarPessoa();

int CarregaCodigoPes();
#endif
