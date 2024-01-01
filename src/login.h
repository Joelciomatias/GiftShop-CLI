#ifndef LOGIN_H
#define LOGIN_H

/***************************************************
 * Bibliotecas                                     *
 * ************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h> // Inclui a biblioteca para o comando sleep
#include "pessoa.h"
#include "menu.h"

void login();
void VerificaLogin(char *nome, char *senha);
#endif

