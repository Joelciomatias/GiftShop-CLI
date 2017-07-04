// ==========================================================
//  	CENTRO UNIVERSITÁRIO INTERNACIONAL UNINTER                                             
// ==========================================================
//  ---------------------------------------------------------
// - Sistema para gerenciar uma loja de presentes.                           -
//  ---------------------------------------------------------
//  - Autores: Caio Felipe, Joelcio Matias                             -
//  - Data: 27/06/2017                                      -
//  ---------------------------------------------------------

/***************************************************
 * Bibliotecas                                     *
 * ************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "login.h"
#include "vendas.h"
#include <locale.h>
#include <windows.h>
//INCLUSAO DE PESSOA
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	setlocale(LC_ALL, "Portuguese");
	SetConsoleTitle("Sistema - Loja de Presentes");
	login();
	return 0;
}
