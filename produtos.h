#ifndef PRODUTOS_H
#define PRODUTOS_H

/***************************************************
 * Bibliotecas                                     *
 * ************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// CONSTANTES PARA O BUFFERS DE TECLADO E OUTROS
#define MAX 30

#define ARQ_PRODUTOS "produto.txt"

FILE *fp;

//ESTRUTURA DO TIPO PESSOA
//PESSOA VAI TER O QUE?- Nome, CPF , email PARAMETROS PARA CONFIGURACAO E ALGUMAS ACOES  tipo, ativo
typedef struct{
	char cod[MAX];
	char nome[MAX];
	char descricao[MAX];
	char categoria[MAX];
	int estoque;
	float preco;
	int ativo;
}Produto; 

void BaseProduto();

void InicializarProduto(Produto *produto);

void LerProduto(Produto *produto);

void ExibirProduto(Produto *produto);

void CadastrarProduto();

void ListarProduto();

int PesquisarProduto();

void ExcluirProduto();

void AlterarProduto();

Produto BuscarProduto(char *valor);

int carregaCodigoPro();

void ListarProdutoPro();
#endif
