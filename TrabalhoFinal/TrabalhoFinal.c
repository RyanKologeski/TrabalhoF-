#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#define cont 3

struct prontuario
{
    char id[20],nome[60],endereco[50],bairro[30],cidade[30],estado[30],anonasc[30],cpf[12];
};
struct anamnese
{
    char tratamento[4],tomando[4],diabetico[4],hipertenso[4],tosse[4],alergia[4];
};

void menuprincipal (void);
void cadastrarprontuario (void);
void anamnese (void);
void procedimentos (void);

int main()
{
    setlocale (LC_ALL,"Portuguese");
    int i,opcao;
    menuprincipal();

    opcao:
    scanf("%d",&opcao);

    if (opcao<1 || opcao>3)
        goto opcao;  /*se for diferente das opções, volta para o rótulo "opcao:"*/

    switch (opcao)
    {
    case 1:
        i=0;
        system("cls");
        cadastrarprontuario();
        system ("cls");
        anamnese();
        system ("cls");
        procedimentos();
        break;

    default:
        break;
    }

    return 0;
}
/*Função para mostrar a tela principal, menu, do programa*/
void menuprincipal (void)
{
    printf("************************************************************\n");
    printf("\n          PRONTUÁRIO DIGITAL - CLÍNICA [NOME]\n");
    printf("\n************************************************************");

    printf("\n\n-------MENU PRINCIPAL\n\n");
    printf("1.Cadastrar prontuário\n2. Consultar prontuário\n3. Sair do sistema");
    printf("\n\nInforme a opção desejada: ");
    return;
}
/*Função para recolher dados do paciente caso a opção 1 foi escolhida*/
void cadastrarprontuario (void)
{
    struct prontuario prontuario[cont];
    int i=0;

    printf("-------CADASTRAR PRONTUÁRIO - DADOS PESSOAIS\n");
    printf("\nid prontuário: "); fgets(prontuario[i].id,20,stdin); getchar();
    printf("cpf do paciente: "); fgets(prontuario[i].cpf,12,stdin); getchar();
    printf("nome do paciente: "); fgets(prontuario[i].nome,60,stdin); getchar();
    printf("endereço: "); fgets(prontuario[i].endereco,50,stdin); getchar();
    printf("bairro: "); fgets(prontuario[i].bairro,30,stdin); getchar();
    printf("cidade: "); fgets(prontuario[i].cidade,30,stdin); getchar();
    printf("Estado: "); fgets(prontuario[i].estado,30,stdin); getchar();
    printf("ano de nascimento: "); fgets(prontuario[i].anonasc,30,stdin); getchar();
    return;
}
/*Função relacionada a anamnese do paciente, com perguntas referentes a problemas*/
void anamnese (void)
{
    struct anamnese anamnese[cont];
    int i=0;

    getchar();
    printf("-------CADASTRAR PRONTUÁRIO - ANAMNESE\n");
    printf("\nEstá em tratamento médico? "); fgets(anamnese[i].tratamento,4,stdin); getchar();
    printf("Está tomando medicamento? "); fgets(anamnese[i].tomando,4,stdin); getchar();
    printf("É diabético? "); fgets(anamnese[i].diabetico,4,stdin); getchar();
    printf("É hipertenso? "); fgets(anamnese[i].hipertenso,4,stdin); getchar();
    printf("Tem tosse persistente? "); fgets(anamnese[i].tosse,4,stdin); getchar();
    printf("Tem algum tipo de alergia? "); fgets(anamnese[i].alergia,4,stdin); getchar();

    return;
}
/*Função que recolhe o número e a(s) operação(ões) realizadas*/
void procedimentos (void)
{
    int dente[32][32]={(11,0),(12,0),(13,0),(14,0),(15,0),(16,0),(17,0),(18,0),(21,0),(22,0),(23,0),(24,0),(25,0),
    (26,0),(27,0),(28,0),(31,0),(32,0),(33,0),(34,0),(35,0),(36,0),(37,0),(38,0),(41,0),(42,0),(43,0),(44,0),(45,0),
    (46,0),(47,0),(48,0),};
    int i,j;

    printf("-------CADASTRAR PRONTUÁRIO - PROCEDIMENTOS\n");
    printf("\n1- Obturação\n2- Extração");

    return;
}
