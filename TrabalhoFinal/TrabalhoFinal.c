#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#define cont 3

struct anamnese
{
    char tratamento[4],tomando[4],diabetico[4],hipertenso[4],tosse[4],alergia[4];
};
struct procedimento
{
    int dente;
};
struct prontuario
{
    char id[20],nome[60],endereco[50],bairro[30],cidade[30],estado[30],anonasc[30],cpf[12];
    struct anamnese anam;
    struct procedimento proced;
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
        goto opcao;  /*se for diferente das op��es, volta para o r�tulo "opcao:"*/

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
/*Fun��o para mostrar a tela principal, menu, do programa*/
void menuprincipal (void)
{
    printf("************************************************************\n");
    printf("\n          PRONTU�RIO DIGITAL - CL�NICA [NOME]\n");
    printf("\n************************************************************");

    printf("\n\n-------MENU PRINCIPAL\n\n");
    printf("1.Cadastrar prontu�rio\n2. Consultar prontu�rio\n3. Sair do sistema");
    printf("\n\nInforme a op��o desejada: ");
    return;
}
/*Fun��o para recolher dados do paciente caso a op��o 1 foi escolhida*/
void cadastrarprontuario (void)
{
    struct prontuario prontuario[cont];
    int i=0;

    printf("-------CADASTRAR PRONTU�RIO - DADOS PESSOAIS\n");
    printf("\nid prontu�rio: "); fgets(prontuario[i].id,20,stdin); getchar();
    printf("cpf do paciente: "); fgets(prontuario[i].cpf,12,stdin); getchar();
    printf("nome do paciente: "); fgets(prontuario[i].nome,60,stdin); getchar();
    printf("endere�o: "); fgets(prontuario[i].endereco,50,stdin); getchar();
    printf("bairro: "); fgets(prontuario[i].bairro,30,stdin); getchar();
    printf("cidade: "); fgets(prontuario[i].cidade,30,stdin); getchar();
    printf("Estado: "); fgets(prontuario[i].estado,30,stdin); getchar();
    printf("ano de nascimento: "); fgets(prontuario[i].anonasc,30,stdin); getchar();
    return;
}
/*Fun��o relacionada a anamnese do paciente, com perguntas referentes a problemas*/
void anamnese (void)
{
    struct prontuario pront [cont];
    int i=0;

    getchar();
    printf("-------CADASTRAR PRONTU�RIO - ANAMNESE\n");
    printf("\nEst� em tratamento m�dico? "); fgets(pront[i].anam.tratamento,4,stdin); getchar();
    printf("Est� tomando medicamento? "); fgets(pront[i].anam.tomando,4,stdin); getchar();
    printf("� diab�tico? "); fgets(pront[i].anam.diabetico,4,stdin); getchar();
    printf("� hipertenso? "); fgets(pront[i].anam.hipertenso,4,stdin); getchar();
    printf("Tem tosse persistente? "); fgets(pront[i].anam.tosse,4,stdin); getchar();
    printf("Tem algum tipo de alergia? "); fgets(pront[i].anam.alergia,4,stdin); getchar();

    return;
}
/*Fun��o que recolhe o n�mero e a(s) opera��o(�es) realizadas*/
void procedimentos (void)
{
    struct prontuario pront [cont];
    struct procedimento proc[32]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    int i,ndente;

    printf("-------CADASTRAR PRONTU�RIO - PROCEDIMENTOS\n");
    printf("\n1- Obtura��o\n2- Extra��o");

    /* PODEM APAGAR CASO QUISEREM, ESTOU TENTANDO ACHAR UM JEITO, POIS ESTOU MEIO CONFUSO NESTA PARTE. ASS:RYAN KOLOGESKI
    TAMB�M PODEM APAGAR AS STRUCTS DECLARADAS AQUI DENTRO E FAZER DE OUTRO MODO
    infodente:
    printf("Informe o n�mero do dente: ");
    scanf("%d",&ndente);

    if ((ndente>=11 && ndente<=18) || (ndente>=21 && ndente<=28) || (ndente>=31 && ndente<=38) || (ndente>=41 && ndente<=48))
        goto proced;
    else
        goto infodente;

    proced:
    if (ndente>=11 && ndente<=18)
    {
        i = ndente - 11;
        proc[i]
    }*/

    return;
}
