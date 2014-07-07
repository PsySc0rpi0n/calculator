#include <stdio.h>
#include <stdlib.h>

#define CLEAR_INPUT while(getchar() != '\n') /*void*/

double func_soma(double var1, double var2){
    return var1 + var2;
}

double func_subtrai(double var1, double var2){
    return var1 - var2;
}

double func_multiplica(double var1, double var2){
    return var1 * var2;
}

double func_divide(double var1, double var2){
    if(var2 == 0){
        printf("Impossível dividir por zero!\n");
        return 0;
    }else{
        return var1 / var2;
    }
}

char main_menu(void){
    int ok=0;
    char op;

    printf("Escolha \"+\", \"-\", \"*\" ou \"/\"\n");
    CLEAR_INPUT;
    do{
        ok = fscanf(stdin, "%c", &op);
        //printf("ok: %d op: %c\n", ok, op);
        if(ok == 0){
            printf("Não introduziu qualquer operador. Por favor introduza um:\n");
        }
    }while(ok == 0);
return op;
}

int chk_input(int ok){
    if(ok != 2){
        printf("Não introduziu os dois algarismos! Tente de novo!\n");
        return 0;
    }
    return 1;
}

double calc_res(double num1, double num2, char *op, double *sol){
    switch (*op){
        case '+': *sol = func_soma(num1, num2);
                  break;
        case '-': *sol = func_subtrai(num1, num2);
                  break;
        case '*': *sol = func_multiplica(num1, num2);
                  break;
        case '/': if (num2 != 0)
                            *sol = func_divide(num1, num2);
                         else{
                            printf("Impossível dividir por zero!\n");
                            exit(0);
                         }
                  break;
        default : printf("Erro desconhecido!\n");
                  return -1.0;
    }
    return 0;
}

int main(int argc, char *argv[]){
    double num1, num2, sol;
    char ok, op;
    
    printf("Introduza dois algarismos pressionando \"Enter\" após cada um:\n");
    do{
        ok = chk_input(fscanf(stdin, "%lf %lf", &num1, &num2));
        //printf("num1: %lf num2: %lf ok: %d\n", num1, num2, ok);
    }while(ok == 0);
    
    do{
        op = main_menu();
        if(op != 'q'){
            sol = calc_res(num1, num2, &op, &sol);
            printf("Resultado: %lf %c %lf = %lf\n", num1, op, num2, sol);
            return 0;
        }
    }while(op != 'q');
return 0;
}
