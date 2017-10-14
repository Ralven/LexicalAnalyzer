#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "lex.yy.h"

char string_table[1000];
int yylval= 0;

int yylex() {
    static int yyline = 0;
    static int yycolumn = 0;
    static char fileContent[1000];
    static char buffer[256];
    static char *cptr;
    int bufferLocation = 0;
    int fileLocation = 0;
    int sizeBuffer = sizeof(buffer) / sizeof(buffer[0]);

    /* File opening just for testing purposes
    FILE *fp;
    fp = fopen("p14.cal", "r");
    if (fp == NULL) {
        perror("Error Opening File");
    }
    /*******************************************/

    /* Load full file Contents into FileContents Array */
    if (fileContent[0] == '\000') {
        while (!feof(stdin)) {
            cptr = fgets(buffer, 256, stdin);
            while (buffer[bufferLocation] != '\000') {
                fileContent[fileLocation] = buffer[bufferLocation];
                bufferLocation++;
                fileLocation++;
            }
    /*********************clearing buffer of any extra info*************************/
            if (buffer[bufferLocation] == '\000') {
                bufferLocation = 0;
                for (int i = 0; i < sizeBuffer; i++) { //
                    if (buffer[i] == '\000') {
                        break;
                    }
                    buffer[i] = '\000';
                }
            }
        }
    }
    /*************** Main loop checking through fileContents array*********************/
    for (int i = 0; i < sizeBuffer; ++i) {
    /************************checking for spaces***************************************/
        if (fileContent[yycolumn] == 32) {
            yycolumn++;
        }
    /************************checking for left parenthesis*****************************/
        if (fileContent[yycolumn] == '(') {
            yycolumn++;
            return 2;
        }
    /************************checking for right parenthesis*****************************/
        if (fileContent[yycolumn] == ')') {
            yycolumn++;
            return 3;
        }
    /************************checking for semicolon*****************************/
        if (fileContent[yycolumn] == ';') {
            yycolumn++;
            return 1;
        }
    /************************checking for newline character*****************************/
        if (fileContent[yycolumn] == '\n') {
            yyline++;
            yycolumn++;
        }
    /************************checking for begin keyword*****************************/
        if (fileContent[yycolumn] == 'b') {
            if (fileContent[yycolumn + 1] == 'e')
                if (fileContent[yycolumn + 2] == 'g')
                    if (fileContent[yycolumn + 3] == 'i')
                        if (fileContent[yycolumn + 4] == 'n') {
                            yycolumn = yycolumn + 5;
                            return 5;
                        }
        }
    /************************checking for program keyword*****************************/
        if (fileContent[yycolumn] == 'p') {
            if (fileContent[yycolumn + 1] == 'r')
                if (fileContent[yycolumn + 2] == 'o')
                    if (fileContent[yycolumn + 3] == 'g')
                        if (fileContent[yycolumn + 4] == 'r')
                            if (fileContent[yycolumn + 5] == 'a')
                                if (fileContent[yycolumn + 6] == 'm') {
                                    yycolumn = yycolumn + 7;
                                    return 6;
                                }
        }
    /************************checking for print keyword*****************************/
        if (fileContent[yycolumn] == 'p') {
            if (fileContent[yycolumn + 1] == 'r')
                if (fileContent[yycolumn + 2] == 'i')
                    if (fileContent[yycolumn + 3] == 'n')
                        if (fileContent[yycolumn + 4] == 't') {
                            yycolumn = yycolumn + 5;
                            return 16;
                        }
        }
    /************************checking for var keyword*****************************/
        if (fileContent[yycolumn] == 'v') {
            if (fileContent[yycolumn + 1] == 'a')
                if (fileContent[yycolumn + 2] == 'r') {
                    yycolumn = yycolumn + 3;
                    return 9;
                }
        }
    /************************checking for minus sign*****************************/
        if (fileContent[yycolumn] == '-') {
            yycolumn++;
            return 7;
        }
    /************************checking for multiplication sign*****************************/
        if (fileContent[yycolumn] == '*') {
            yycolumn++;
            return 8;
        }
    /************************checking for <<EOF>>*****************************/
        if (fileContent[yycolumn] == '<') { //
            yycolumn = yycolumn + 7;
            return 0;
        }
    /************************checking for comma*****************************/
        if (fileContent[yycolumn] == ',') { //
            yycolumn++;
            return 10;
        }
    /************************checking for end keyword*****************************/
        if (fileContent[yycolumn] == 'e') {
            if (fileContent[yycolumn + 1] == 'n')
                if (fileContent[yycolumn + 2] == 'd') {
                    yycolumn = yycolumn + 3;
                    return 12;
                }
        }
    /************************checking for is keyword*****************************/
        if (fileContent[yycolumn] == 'i') {
            if (fileContent[yycolumn + 1] == 's') {
                yycolumn = yycolumn + 2;
                return 13;
            }
        }
    /************************checking for addition character*****************************/
        if (fileContent[yycolumn] == '+') {
            yycolumn++;
            return 14;
        }
    /************************checking for div keyword*****************************/
        if (fileContent[yycolumn] == 'd') {
            if (fileContent[yycolumn + 1] == 'i')
                if (fileContent[yycolumn + 2] == 'v') {
                    yycolumn = yycolumn + 3;
                    return 15;
                }
        }
    /************************checking for equals character*****************************/
        if (fileContent[yycolumn] == '=') {
            yycolumn++;
            return 17;
        }
    /********************checking for integer constant*************************/
        if (isdigit(fileContent[yycolumn])) {
            yylval = 0;
            char temp[32] = {0};
            int i = 0;
            while (isdigit(fileContent[yycolumn])) {
                temp[i] = fileContent[yycolumn];
                yycolumn++;
                i++;
            }
            yylval = atoi(temp);
            return 4;
        }
    /************************checking for identifier*****************************/
        if (isalpha(fileContent[yycolumn])) {
            yylval = 0;
            int sizeStringTable = sizeof(string_table) / sizeof(string_table[0]);
            for (int i = 0; i < sizeStringTable; i++) { //Clearing StringTable of previous Data
                if (string_table[i] == '\000') {
                    break;
                }
                string_table[i] = '\000';
            }
            while (fileContent[yycolumn] != 32) {
                if (fileContent[yycolumn] == ','
                    || fileContent[yycolumn] == ';'
                    || fileContent[yycolumn] == '\n') {
                    break;
                }
                string_table[yylval] = fileContent[yycolumn];
                yycolumn++;
                yylval++;
            }
            yylval = 0;
            return 11;
        }
    /************************checking for end of the array*****************************/
        if (fileContent[yycolumn] == '\000') {
            return 0;
        }
    }
    return 0;
}
