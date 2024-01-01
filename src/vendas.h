#ifndef _VENDAS_H
#define _VENDAS_H

/***************************************************
 * Bibliotecas                                     *
 * ************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "pessoa.h"
#include "selecao.h"
#include "cartao.h"
// CONSTANTES PARA O BUFFERS DE TECLADO E OUTROS
#define MAX 30

#define ARQ_VENDAS "vendas.txt"


FILE *ven;

//ESTRUTURA DO TIPO PESSOA
typedef struct{
	char cod[MAX];
	char nome[MAX];
	Selecao selecao[MAX];
	int pagamento;
	float total;
	int tamanho;
}Venda; 

void baseVenda();

void inicializarVenda(Venda *venda);

void exibirVenda(char nome[MAX], char cod[MAX]);

void carregarSelecao(char *cod, Venda *venda);

void carregarVenda(char *cod, char *nome);

void exibirProdVenda(Venda *venda);

void listarVenda();

void exibirListaVenda(Venda *venda);

void AlterarVenda(char *cod);

int PesquisarVenda(char *cod);

int carregaCodigo();
#endif
