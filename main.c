/*
Ismat - Engenheria Informática 1º Ano
Fundamentos de Programação - Prof. Francisco Pereira
Leandro Fonseca
22/12/2020 - 02:18
Resumo: Programa com menus e 5 opçoes em funçoes
Inputs:
Outputs:
 */

#include <stdio.h>
#include <ctype.h>
#include <locale.h>

//Define do tamanho dos arrays
#define ARRAY_DIMENSION 5
#define ARRAY_MEDIA_COLUMNS 2
#define ARRAY_MEDIA_LINES 5

//Define dos Textos do printMenu()
#define TEXT_MENU_LINE1 "|--------------------------------------------------|\n"
#define TEXT_MENU_LINE2 "|                       Menu                       |\n"
#define TEXT_MENU_LINE3 "|__________________________________________________|\n"
#define TEXT_MENU_LINE4 "1. Calcula a soma (x+y-3²), produto (x-5)*(y+4), e a potência (x^y)\n"
#define TEXT_MENU_LINE5 "2. Escreve a média das notas dos 5 alunos de uma turma sabendo que têm 2 disciplinas\n"
#define TEXT_MENU_LINE6 "3. Calcular recursivamente a soma dos n números impares\n"
#define TEXT_MENU_LINE7 "4. Cria dois vetores com 5 elementos e em seguida somá-los e multiplica-los termo a termo\n"
#define TEXT_MENU_LINE8 "5. Sair do programa\n\n"
#define TEXT_MENU_LINE9 "Escolha a opção do menu: "

//Define dos Textos para proceguir options
#define TEXT_CONTINUE_MENU_OPTION "\nDeseja continuar na Opção? (s ou n): "
#define TEXT_CONTINUE_OPTION "Continuar na opção\n"
#define TEXT_EXIT_OPTION "Obrigado pela sua escolha, volte sempre\n"
#define TEXT_INVALID_OPTION "Opção invalida!\n"

//Define dos Textos da entrada de valores
#define TEXT_OPTION4_ARRAY "Array %d :\n"
#define TEXT_OPTION4_ARRAY_INPUT "Elemento do array de index %d: "
#define TEXT_OPTION1_INPUT "Escolha um valor para %c: "

//Define dos Textos das Opçoes Selecionadas e Resultados
#define TEXT_OPTION1 "Opção 1 selecionada - Calcula a soma (x+y-3²), produto (x-5)*(y+4), e a potência (x^y)\n\n"
#define TEXT_OPTION1_RESULT "Soma (x+y-3²) = %d; Produto (x-5)*(y+4) = %d; Potência (x^y) = %d"
#define TEXT_OPTION2 "Opção 2 selecionada - Escreve a média das notas dos 5 alunos de uma turma sabendo que têm 2 disciplinas\n\n"
#define TEXT_OPTION2_RESULT "Média das notas dos alunos: %g"
#define TEXT_OPTION3 "Opção 3 selecionada - Calcular recursivamente a soma dos n números impares\n"
#define TEXT_OPTION3_RESULT "Soma de n (%d) números impares: %d"
#define TEXT_OPTION4 "Opção 4 selecionada - Cria dois vetores com 5 elementos e em seguida somá-los e multiplica-los termo a termo\n"
#define TEXT_OPTION4_RESULT1 "\nSoma dos elementos: \n"
#define TEXT_OPTION4_RESULT2 "\nProduto dos elementos: \n"

#define TEXT_OPTION5 "Opção 5 selecionada - Sair\n"

int checkArrayValueZero(float fltArray[ARRAY_DIMENSION])
{
    int intContador, intFlag = 0;
    for(intContador = 0; intContador < ARRAY_DIMENSION; intContador++)
    {
        if(fltArray[intContador] != 0){
            intFlag = 1;
        }
    }
    return intFlag;
}

int resetArrays(float fltArray1[ARRAY_DIMENSION], float fltArray2[ARRAY_DIMENSION])
{
    int intContador, intResultOK, intResultCheck;

    //Percorre array em toda a sua dimensao
    for (intContador = 0; intContador < ARRAY_DIMENSION; intContador++)
    {
        //Igual todos os elementos do array a 0
        fltArray1[intContador] = 0;
        fltArray2[intContador] = 0;
    }

    intResultCheck = checkArrayValueZero(fltArray1);

    //Verificar se o array2  foi resetado
    if(intResultCheck != 1){
        intResultOK = 0;
    }else{
        //Primeiro array OK; Verificar segundo
        intResultCheck = checkArrayValueZero(fltArray2);
        if(intResultCheck != 1){
            intResultOK = 0;
        }else{
            //Ambos OK; Resultado OK
            intResultOK = 1;
        }
    }

    return intResultOK;
}

void printMenu()
{
    //system("cls");
    printf(TEXT_MENU_LINE1);
    printf(TEXT_MENU_LINE2);
    printf(TEXT_MENU_LINE3);
    printf(TEXT_MENU_LINE4);
    printf(TEXT_MENU_LINE5);
    printf(TEXT_MENU_LINE6);
    printf(TEXT_MENU_LINE7);
    printf(TEXT_MENU_LINE8);
    printf(TEXT_MENU_LINE9);
}

int checkExit(float fltArrayLocal[ARRAY_DIMENSION], float fltArrayLocal2[ARRAY_DIMENSION])
{
    int intResult = 1;
    char chrOptionConfirm;

    printf(TEXT_CONTINUE_MENU_OPTION);
    scanf(" %c",&chrOptionConfirm);
    chrOptionConfirm = tolower(chrOptionConfirm);

    //Verificar a opçao escolhida

    if((chrOptionConfirm == 110) || (chrOptionConfirm == 115))
    {
        if(chrOptionConfirm == 's')
        {
            //Caso seja 's', da reset arrays e continua
            printf(TEXT_CONTINUE_OPTION);
            resetArrays(fltArrayLocal,fltArrayLocal2);
        }else if (chrOptionConfirm == 'n')
        {
            //Caso seja 'n' da print do menu e passa a flag a 0
            printf(TEXT_EXIT_OPTION);
            printMenu();
            intResult = 0;
        }
    }else
    {
        //Caso nao seja s/n Erro e segue para menu
        printf(TEXT_INVALID_OPTION);
        printMenu();
        intResult = 0;
    }

    return intResult;
}

void getArrayMedia(float floatMatrix[ARRAY_MEDIA_LINES][ARRAY_MEDIA_COLUMNS])
{
    float fltValueReturn = 0;
    int intCounterLines, intCounterColumns;
    //Percorre o array em toda a sua dimensao
    for (intCounterLines = 0; intCounterLines < ARRAY_MEDIA_LINES; intCounterLines++)
    {
        for (intCounterColumns = 0; intCounterColumns < ARRAY_MEDIA_COLUMNS; intCounterColumns++)
        {
            //Somatorio dos elementos
            fltValueReturn += floatMatrix[intCounterLines][intCounterColumns];
        }

    }
    printf(TEXT_OPTION2_RESULT , fltValueReturn / 10);
}

void get2ArrayCalc(float fltArray1[ARRAY_DIMENSION], float fltArray2[ARRAY_DIMENSION])
{
    int intCounter;

    printf(TEXT_OPTION4_RESULT1);
    //Percorre o array em toda sua dimensao
    for (intCounter = 0; intCounter < ARRAY_DIMENSION; intCounter++)
    {
        //Somatorio dos elementos
        printf("%g; ",(fltArray1[intCounter] + fltArray2[intCounter]));
    }
    printf(TEXT_OPTION4_RESULT2);
    for (intCounter = 0; intCounter < ARRAY_DIMENSION; intCounter++)
    {
        //Produtorio dos elementos
        printf("%g; ",(fltArray1[intCounter] * fltArray2[intCounter]));
    }
}

void optionCase1()
{
    int intValueOfX = 0, intValueOfY = 0, intPotenciaX_Y = 1;

    //Pedir ao user Valores para X e Y
    printf(TEXT_OPTION1_INPUT, 'x');
    scanf("%d", &intValueOfX);
    printf(TEXT_OPTION1_INPUT, 'y');
    scanf("%d", &intValueOfY);


    for(int intCounter = 0; intCounter < intValueOfY ; intCounter++)
    {
        intPotenciaX_Y *= intValueOfX;
    }

    printf(TEXT_OPTION1_RESULT,(intValueOfX + intValueOfY - 9), (intValueOfX - 5)*(intValueOfY + 4), intPotenciaX_Y );

}

void optionCase2()
{
    float fltMediaArray[ARRAY_MEDIA_LINES][ARRAY_MEDIA_COLUMNS];
    int intArrayLinesCounter, intArrayColumnsCounter;

    //Percorre o array em linhas e colunas
    for (intArrayLinesCounter = 0; intArrayLinesCounter < ARRAY_MEDIA_LINES; intArrayLinesCounter++){
        for (intArrayColumnsCounter = 0; intArrayColumnsCounter < ARRAY_MEDIA_COLUMNS; intArrayColumnsCounter++){
            printf("[%d][%d]<- ", intArrayLinesCounter+1, intArrayColumnsCounter+1);
            scanf(" %f", &fltMediaArray[intArrayLinesCounter][intArrayColumnsCounter]);
        }
    }

    getArrayMedia(fltMediaArray);

}

void optionCase3()
{
    int intContador, intN = 0, intSomaNImpares = 0, intImpar = 1;

    printf(TEXT_OPTION1_INPUT, 'n');
    scanf(" %d", &intN);

    for (intContador = 0; intContador < intN; intContador++)
    {
        intSomaNImpares += intImpar;
        intImpar += 2;
    }

    printf(TEXT_OPTION3_RESULT, intN, intSomaNImpares);
}

void optionCase4()
{
    float fltArray1[ARRAY_DIMENSION], fltArray2[ARRAY_DIMENSION];
    fltArray1[ARRAY_DIMENSION]=0 , fltArray2[ARRAY_DIMENSION] = 0;
    int i;

    printf(TEXT_OPTION4_ARRAY, 1);
    for (i = 0; i < ARRAY_DIMENSION; ++i) {
        printf(TEXT_OPTION4_ARRAY_INPUT,i);
        scanf("%f",&fltArray1[i]);
    }

    printf(TEXT_OPTION4_ARRAY, 2);
    for (i = 0; i < ARRAY_DIMENSION; ++i) {
        printf(TEXT_OPTION4_ARRAY_INPUT,i);
        scanf("%f",&fltArray2[i]);
    }

    get2ArrayCalc(fltArray1, fltArray2);


}

int optionCase5()
{
    int intExit=0;
    printf(TEXT_OPTION5);
    printf(TEXT_EXIT_OPTION);
    return intExit;

}

void main(){
    setlocale(LC_ALL, "Portuguese");
    int intExit, intOptionResult;
    float fltArray1[ARRAY_DIMENSION], fltArray2[ARRAY_DIMENSION];
    char chrMenuOption;
    intExit = 1;

    printMenu();
    scanf(" %c",&chrMenuOption);

    while(intExit != 0)
    {
        switch (chrMenuOption) {

            case '1':
                printf(TEXT_OPTION1);
                optionCase1();

                intOptionResult = checkExit(fltArray1,fltArray2);

                if(intOptionResult != 1)
                {
                    scanf(" %c",&chrMenuOption);
                    break;
                }else
                {
                    continue;
                }

            case '2':
                printf(TEXT_OPTION2);
                optionCase2();

                intOptionResult = checkExit(fltArray1,fltArray2);

                if(intOptionResult != 1)
                {
                    scanf(" %c",&chrMenuOption);
                    break;
                }else
                {
                    continue;
                }

            case '3':
                printf(TEXT_OPTION3);
                optionCase3();
                intOptionResult = checkExit(fltArray1,fltArray2);

                if(intOptionResult != 1)
                {
                    scanf(" %c",&chrMenuOption);
                    break;
                }else
                {
                    continue;
                }
            case '4':
                printf(TEXT_OPTION4);
                optionCase4();

                intOptionResult = checkExit(fltArray1,fltArray2);

                if(intOptionResult != 1)
                {
                    scanf(" %c",&chrMenuOption);
                    break;
                }else
                {
                    continue;
                }
            case '5':
                intExit = optionCase5();
                break;
            default:
                printf(TEXT_INVALID_OPTION);
                printMenu();
                scanf(" %c",&chrMenuOption);
                break;
        }
    }

}