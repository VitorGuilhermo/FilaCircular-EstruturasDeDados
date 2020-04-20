#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio2.h>
#include <string.h>
#include <windows.h>
#include "TADFilaCircular.h"

char menu(){
    system("cls");
    printf("\n\n\n\n\n\n\n\t\t\t\t\t====================================\n");
    printf("\t\t\t\t\t      SIMULACAO FILA CIRCULAR            \n");
    printf("\t\t\t\t\t====================================\n");
    printf("\t\t\t\t\t   [ ENTER ]  -  Iniciar\n");
    printf("\t\t\t\t\t   [ Qualquer tecla ]  - Sair\n");
    printf("\t\t\t\t\t====================================\n");

    return toupper(getch());
}


int main(){

    TpFilaCirc fila;

    char op, letra, elemento;
    int ut, sorteado, linhaI, colunaI, linhaR, colunaR;

    op = menu();
    while(op == 13){

        //desenhos
        system("cls");
        desenhaVetor(11, 30);
        desenhaDescricao();
        desenhaPlacaInformacoes(22, 5);

        //inicializacoes
        FCInicializar(fila);
        ut = 1;
        letra = 65;
        colunaI =  colunaR = 36;
        linhaI = linhaR = 14;

        while(!FCCheia(fila.cont) && !kbhit()){

            //Printa informacoes
            textcolor(6);
            limpaLinha(20, 24);
            gotoxy(20, 24);
            printf("UT = %d", ut);
            limpaLinha(20, 25);
            gotoxy(20, 25);
            printf("Inicio da fila = %d", fila.inicio);
            limpaLinha(20, 26);
            gotoxy(20, 26);
            printf("Final da fila = %d", fila.fim);
            limpaLinha(20, 27);
            gotoxy(20, 27);
            printf("Qtde elementos = %d", fila.cont);
            limpaLinha(50, 25);
            gotoxy(50, 25);
            if(!FCVazia(fila.cont))
                printf("Ultimo elemento a entrar = %c", FCElementoInicio(fila));
            limpaLinha(50, 27);
            gotoxy(50, 27);
            if(!FCVazia(fila.cont))
                printf("Ultimo elemento a sair = %c", elemento);
            textcolor(15);

            //Reset's
            if(letra == 90)
                letra = 65;
            if(colunaI == 86)
                colunaI = 36;
            if(colunaR == 86)
                colunaR = 36;

            //insercao
            if(ut % 3 == 0){

                FCInserir(fila, letra);
                gotoxy(colunaI, linhaI);
                colunaI += 5;
                textcolor(14);
                printf("%c", letra++);
                textcolor(15);

            }

            //Remocao
            if(ut % 6 == 0){

                elemento = FCRetirar(fila);
                gotoxy(colunaR, linhaR);
                colunaR += 5;
                printf(" ");

            }


            Sleep(1000);
            ut++;
        }
        getch();
        op = menu();
    }



    return 1;
}
