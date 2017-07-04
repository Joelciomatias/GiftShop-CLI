#ifndef MENU_H
#define MENU_H

/***************************************************
 * Bibliotecas                                     *
 * ************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "pessoa.h"
#include "produtos.h"
#include "selecao.h"
#include "vendas.h"

void MenuGerente(Pessoa *pessoa);

void MenuCliente(Pessoa *pessoa);

#endif
