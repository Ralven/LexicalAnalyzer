
/* Use the token definitions below to return token.
   symbolically */
#define EOFnumber 0
#define SEMInumber 1
#define LPARENnumber 2
#define RPARENnumber 3
#define ICONSTnumber 4
#define BEGINnumber 5
#define PROGRAMnumber 6
#define MINUSnumber 7
#define TIMESnumber 8
#define VARnumber 9
#define COMMAnumber 10
#define IDnumber 11
#define ENDnumber 12
#define ISnumber 13
#define PLUSnumber 14
#define DIVnumber 15
#define PRINTnumber 16
#define EQnumber 17

#include "lex.yy.c"     /* Your scanner code will be included here */

int main(){
    int i;

    /* Call yylex() as long as an EOF token is not returned */
    while((i = yylex()) != EOFnumber){
        switch(i){
            case IDnumber:
                printf("Found identifier. Image: %s \n", string_table+yylval);
                break;
            case ICONSTnumber:
                printf("Found integer constant. Image: %d \n", yylval);
                break;
            case SEMInumber:
                printf("Found ';' \n");
                break;
            case LPARENnumber:
                printf("Found '(' \n");
                break;
            case RPARENnumber:
                printf("Found ')' \n");
                break;
            case BEGINnumber:
                printf("Found \"begin\" \n");
                break;
            case PROGRAMnumber:
                printf("Found \"program\" \n");
                break;
            case MINUSnumber:
                printf("Found '-' \n");
                break;
            case TIMESnumber:
                printf("Found '*' \n");
                break;
            case VARnumber:
                printf("Found \"var\" \n");
                break;
            case COMMAnumber:
                printf("Found ',' \n");
                break;
            case ENDnumber:
                printf("Found \"end\" \n");
                break;
            case ISnumber:
                printf("Found \"is\" \n");
                break;
            case PRINTnumber:
                printf("Found \"print\" \n");
                break;
            case DIVnumber:
                printf("Found \"div\" \n");
                break;
            case PLUSnumber:
                printf("Found '+' \n");
                break;
            case EQnumber:
                printf("Found '=' \n");
                break;
        }

    }
    printf("End of file found. \n");

}
