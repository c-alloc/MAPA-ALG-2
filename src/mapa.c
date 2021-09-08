#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>


typedef struct pessoa
{
    char cpf[15];
    char nome[30];
    char sexo;
    int idade;
}pessoa;

typedef struct sintomas
{
    char febre[3+1];
    char dorcabeca[3+1];
    char espirro[3+1];
    char dorgarganta[3+1];
    char tosseseca[3+1];
    char difrespira[3+1];
    char dorescorpo[3+1];
    char diarreia[3+1];
    char contato[3+1];
    char localaglo[3+1];
}sintomas;

void cadastro(pessoa *paciente);
void taxaderisco(int risco);
void criarficha(pessoa *paciente, sintomas *sintomas, int risco);
int teste_covid(sintomas *sintomas);

int main()
{
    sintomas sintomas;
    pessoa paciente;
    int risco;

    cadastro(&paciente);
    risco = teste_covid(&sintomas);

    taxaderisco(risco);

    criarficha(&paciente, &sintomas, risco);

    return 0;
}

void cadastro(pessoa *paciente)
{
    char temp;

    system("clear");

    printf(
        "**************************\n"
        "*  CADASTRO DE PACIENTE  *\n"
        "**************************\n");

    printf("Insira CPF do paciente: ");
    scanf("%s", paciente->cpf);
    fflush(stdin);

    system("clear");

    printf(
        "**************************\n"
        "*  CADASTRO DE PACIENTE  *\n"
        "**************************\n");
    printf("Insira nome do paciente: ");
    scanf("%c", &temp);
    scanf("%[^\n]", paciente->nome);
    fflush(stdin);

    system("clear");

    printf(
        "**************************\n"
        "*  CADASTRO DE PACIENTE  *\n"
        "**************************\n");
    printf("Insira sexo do paciente (M,F): ");
    scanf("%s", &paciente->sexo);
    fflush(stdin);

    system("clear");

    printf(
        "**************************\n"
        "*  CADASTRO DE PACIENTE  *\n"
        "**************************\n");
    printf("Insira idade do paciente: ");
    scanf("%d", &paciente->idade);
    fflush(stdin);

    system("clear");

    printf(
        "**************************\n"
        "*    FICHA DO PACIENTE   *\n"
        "**************************\n");

    printf("Nome do paciente: %s\n", paciente->nome);
    printf("CPF: %s\n", paciente->cpf);
    printf("Sexo: %s\n", &paciente->sexo);
    printf("Idade: %d\n", paciente->idade);

    printf("Enter para continuar");
    scanf("%c", &temp);
    getchar();
    fflush(stdin);
}

int teste_covid(sintomas *sintomas)
{
    int comp;
    int result = 0;

    system("clear");
    printf("Questionario de sintomas!\n");
    printf("O questionario deve ser respondido com sim ou nao\n");

    printf("1 - Tem febre? ");
    scanf("%s", sintomas->febre);
    fflush(stdin);

    comp = strcmp(sintomas->febre, "sim");
    if (comp == 0)
    {
        result = result + 5;
    }

    printf("2 - Tem dor de cabeça? ");
    scanf("%s", sintomas->dorcabeca);
    fflush(stdin);

    comp = strcmp(sintomas->dorcabeca, "sim");
    if (comp == 0)
    {
        result = result + 1;
    }

    printf("3 - Tem sencreção nasal ou espirros? ");
    scanf("%s", sintomas->espirro);
    fflush(stdin);

    comp = strcmp(sintomas->espirro, "sim");
    if (comp == 0)
    {
        result = result + 1;
    }

    printf("4 - Tem dor/irritaçao na garganta? ");
    scanf("%s", sintomas->dorgarganta);
    fflush(stdin);

    comp = strcmp(sintomas->dorgarganta, "sim");
    if (comp == 0)
    {
        result = result + 1;
    }

    printf("5 - Tem tosse seca? ");
    scanf("%s", sintomas->tosseseca);
    fflush(stdin);

    comp = strcmp(sintomas->tosseseca, "sim");
    if (comp == 0)
    {
        result = result + 3;
    }

    printf("6 - Tem dificuldade respiratoria? ");
    scanf("%s", sintomas->difrespira);
    fflush(stdin);

    comp = strcmp(sintomas->difrespira, "sim");
    if (comp == 0)
    {
        result = result + 10;
    }

    printf("7 - Tem dores no corpo? ");
    scanf("%s", sintomas->dorescorpo);
    fflush(stdin);

    comp = strcmp(sintomas->dorescorpo, "sim");
    if (comp == 0)
    {
        result = result + 1;
    }

    printf("8 - Tem diarreia? ");
    scanf("%s", sintomas->diarreia);
    fflush(stdin);

    comp = strcmp(sintomas->diarreia, "sim");
    if (comp == 0)
    {
        result = result + 1;
    }

    printf("9 - Esteve em contato, nos ultimos 14 dias, com um caso diagnosticado com COVID-19? ");
    scanf("%s", sintomas->contato);
    fflush(stdin);

    comp = strcmp(sintomas->contato, "sim");
    if (comp == 0)
    {
        result = result + 10;
    }

    printf("10 - Esteve em locais com grande aglomeraçao? ");
    scanf("%s", sintomas->localaglo);
    fflush(stdin);

    comp = strcmp(sintomas->localaglo, "sim");
    if (comp == 0)
    {
        result = result + 3;
    }

    return result;
}

void taxaderisco(int risco)
{
    system("clear");

    if (risco <= 9)
    {
        printf("O paciente sera enviado para a ala de baixo risco!\n"
               "Marcando %d pontos no teste...\n",
               risco);
    }
    else if (risco >= 10 && risco <= 19)
    {
        printf("O paciente sera enviado para a ala de medio risco!\n"
               "Marcando %d pontos no teste...\n",
               risco);
    }
    else if (risco >= 20)
    {
        printf("O paciente sera enviado para a ala de alto risco!\n"
               "Marcando %d pontos no teste...\n",
               risco);
    }
    else
    {
        printf("erro");
    }
}

void criarficha(pessoa *paciente, sintomas *sintomas, int risco)
{
    FILE *file;
    char data[1000];

    snprintf(data, 1000, 
            "FICHA DO PACIENTE!!\n\n"
            "Nome: %s\nCPF: %s\nSexo: %c\nIdade: %d\n\n"
            "QUESTIONARIO PARA COVID-19\n\n"
            "1 - Tem febre? \n"
            "R - %s\n"
            "2 - Tem dor de cabeça? \n"
            "R - %s\n"
            "3 - Tem sencreção nasal ou espirros? \n"
            "R - %s\n"
            "4 - Tem dor/irritaçao na garganta? \n"
            "R - %s\n"
            "5 - Tem tosse seca? \n"
            "R - %s\n"
            "6 - Tem dificuldade respiratoria? \n"
            "R - %s\n"
            "7 - Tem dores no corpo? \n"
            "R - %s\n"
            "8 - Tem diarreia? \n"
            "R - %s\n"
            "9 - Esteve em contato, nos ultimos 14 dias, com um caso diagnosticado com COVID-19? \n"
            "R - %s\n"
            "10 - Esteve em locais com grande aglomeraçao? \n"
            "R - %s\n\n"
            "PONTUAÇÃO DO QUESTIONARIO: %d!\n", 
            paciente->nome, paciente->cpf, paciente->sexo, paciente->idade, 
            sintomas->febre, sintomas->dorcabeca, sintomas->espirro, sintomas->dorgarganta, sintomas->tosseseca, sintomas->difrespira, sintomas->dorescorpo, sintomas->diarreia, sintomas->contato, sintomas->localaglo, risco);

    file = fopen("paciente.txt", "w");

    if (file == NULL)
    {
        printf("Impossibilitado de criar o arquivo.\n");
        exit(EXIT_FAILURE);
    }

    fputs(data, file);

    fclose(file);

    printf("Arquivo criado e salvo com sucesso!\n");
}