#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#define cont 3
#define CADASTRAR 1
#define CONSULTAR 2
#define SAIR 3
#define OBTURACAO 1
#define EXTRACAO 2
#define SIM 1
#define NAO 2


void limpaconsole();
void desejacontinuar();
void menuprincipal();
void escolha();
void cadastroprontuario();
void anamnese();
void procedimento();

void consultarpront();
void imprimedados();

//Inicializa��o das Struct
struct anamnese
{
    char trat[4],med[4],diab[4],hiper[4],tosse[4],alergia[4];
};

struct procedimento
{
    int dente[32];
};

struct prontuario
{
    char id[10],cpf[13],nasc[5],nome[50],endereco[40],bairro[30],cidade[30],estado[30];
    struct anamnese anam;
    struct procedimento proced;
};
//Fim da inicializa��o das Struct

struct prontuario pront[cont]; //Struct pront recebe 3 posi��es

//Vari�veis globais
int menu;
int cpfvalido=0;
int loc= 0;
int avanca=0;
int voltarmenu = 1;

int main ()
{
    setlocale (LC_ALL,"Portuguese");
    int i,j;

    /*Inicializa o vetor dente com 0*/
    for (i=0; i<cont; i++)
    {
        for (j=0; j<32; j++)
        {
            pront[i].proced.dente[j] = 0;
        }
    }
    /*Fim da inicializa��o do vetor*/

    while (voltarmenu == 1)
    {
        menuprincipal();
        menu = 0;
        avanca = 0;
        cpfvalido = 0;
        limpaconsole();
    }

    limpaconsole();
    printf("\n   -----PROGRAMA FINALIZADO-----");

    return 0;
}

void limpaconsole() //Fun��o para limpar a tela
{
    system("cls");
    return;
}

void desejacontinuar() //Fun��o utilizada quando necessita fazer leitura se o usu�rio deseja continuar
{
    printf("Deseja continuar? (1-sim, 2-n�o): ");
    while(avanca != SIM && avanca != NAO)
    {
        scanf("%d",&avanca);
        if (avanca != SIM && avanca != NAO)
        {
            printf("Op��o Inv�lida! Tente novamente!\n");
        }
    }
}
//In�cio da fun��o menuprincipal
void menuprincipal()
{
    printf("***************************************************\n");
    printf("\n        PRONTU�RIO DIGITAL - CL�NICA DONTO TECH ");
    printf("\n\n***************************************************");

    printf("\n\n-----MENU PRINCIPAL");
    printf("\n1. Cadastrar prontu�rio\n2. Consultar prontu�rio\n3. Sair do sistema");

    printf("\n\nInforme a op��o desejada: ");

    //Realiza a leitura da op��o enquanto est� for diferente de 1, 2 ou 3
    while ((menu != CADASTRAR && menu != CONSULTAR && menu != SAIR) || menu == CONSULTAR && loc == 0 || menu == CADASTRAR && loc > 2)
    {
        scanf("%d",&menu);
        if (menu != CONSULTAR && menu != CADASTRAR)
        {
            printf("---OP��O INV�LIDA! INFORME NOVAMENTE.---\n");
        }
        else //Caso a op��o de cadastro tenha sido escolhida...
        {
            if (menu == CADASTRAR && loc > 2) //Testa se j� foi realizado o cadastro de 3 prontu�rios
                printf("---N�mero m�ximo de prontu�rios ja cadastrados---\n");
            if (menu == CONSULTAR && loc == 0) //Testa se h� prontu�rio armazenado
                printf("---N�o h� prontu�rio armazenado---\n");
        }

    }
    limpaconsole();
    escolha();
    return;
}
//In�cio da fun��o que realiza a leitura da op��o escolhida no menu principal
void escolha()
{
    switch (menu)
    {
    case 1:
        cadastroprontuario();
        limpaconsole();
        anamnese();
        limpaconsole();
        while (avanca != NAO)
        {
            avanca = 0;
            procedimento();
            limpaconsole();
        }
        break;

    case 2:
        while (avanca != NAO)
        {
            avanca = 0;
            consultarpront();
            limpaconsole();
        }
        break;

    case 3:
        printf("\n   -----PROGRAMA FINALIZADO-----");
        exit(0);
        break;
    }

    return;
}
//Fun��o de cadastro de prontu�rio
void cadastroprontuario()
{
    getchar();
    printf("-----CADASTRAR PRONTU�RIO - DADOS PESSOAIS\n\n");
    printf("1. id prontu�rio: ");
    fgets(pront[loc].id,10,stdin);
    printf("2. cpf do paciente (xxxxxxxxx-xx): ");
    fgets(pront[loc].cpf,13,stdin);
    getchar();
    printf("3. nome do paciente: ");
    fgets(pront[loc].nome,50,stdin);
    printf("4. endere�o: ");
    fgets(pront[loc].endereco,40,stdin);
    printf("5. bairro: ");
    fgets(pront[loc].bairro,30,stdin);
    printf("6. cidade: ");
    fgets(pront[loc].cidade,30,stdin);
    printf("7. Estado: ");
    fgets(pront[loc].estado,30,stdin);
    printf("8. ano de nascimento: ");
    fgets(pront[loc].nasc,5,stdin);
    return;
}
//Fun��o da coleta da anamnese
void anamnese()
{
    printf("-----CADASTRAR PRONTU�RIO - ANAMNESE\n\n");
    getchar();
    printf("Est� em tratamentos m�dico? (Sim/N�o) ");
    fgets(pront[loc].anam.trat,4,stdin);
    getchar();
    printf("Est� tomando medicamento? (Sim/N�o) ");
    fgets(pront[loc].anam.med,4,stdin);
    getchar();
    printf("� diab�tico? (Sim/N�o) ");
    fgets(pront[loc].anam.diab,4,stdin);
    getchar();
    printf("� hipertenso? (Sim/N�o) ");
    fgets(pront[loc].anam.hiper,4,stdin);
    getchar();
    printf("Tem tosse persistente? (Sim/N�o) ");
    fgets(pront[loc].anam.tosse,4,stdin);
    getchar();
    printf("Tem algum tipo de alergia? (Sim/N�o) ");
    fgets(pront[loc].anam.alergia,4,stdin);
    getchar();
    return;
}
//Fun��o de procedimentos realizados
void procedimento()
{
    int pos = 0, num = 0, ndente = 0, op = 0, continua = 0;


    printf("-----CADASTRAR PRONTU�RIO - PROCEDIMENTOS\n\n");
    printf("1- Obtura��o\n2- Extra��o\n\n");

    printf("\nQual procedimento deseja realizar: ");

    //Enquanto op��o escolhida for diferente de 1 ou 2...
    while (num!=OBTURACAO && num!=EXTRACAO)
    {
        scanf("%d",&num);
        if (num!=OBTURACAO && num!=EXTRACAO)
            printf("N�mero do Procedimento Inv�lido!\n");
    }

    printf("\nInforme o n�mero do dente: ");

    //Testa se o n�mero do dente informado � v�lido
    while ((ndente<11 || ndente>18) && (ndente<21 || ndente>28) && (ndente<31 || ndente>38) && (ndente<41 || ndente>48))
    {
        scanf("%d",&ndente);
        if ((ndente<11 || ndente>18) && (ndente<21 || ndente>28) && (ndente<31 || ndente>38) && (ndente<41 || ndente>48))
            printf("N�mero de dente inv�lido!\n");
    }
    //N�mero do dente de 11 a 18
    if (ndente>=11 && ndente<=18)
    {
        //Posi��o que o procedimento vai ser guardado dentro do vetor "dente" � igual
        //ao n�mero do dente informado menos 11
        pos = ndente -11;
        if (pront[loc].proced.dente[pos]==2)
        {
            limpaconsole();
            printf("\n   ---Dente j� foi extra�do!---\n\n");
            desejacontinuar();
            if (avanca == NAO)
            {
                loc=loc+1;
            }
            return;
        }
        pront[loc].proced.dente[pos] = num;
    }
    //N�mero do dente de 21 a 28
    else if (ndente>=21 && ndente<=28)
    {
        //Posi��o que o procedimento vai ser guardado dentro do vetor "dente" � igual
        //ao n�mero do dente informado menos 13
        pos = ndente -13;
        if (pront[loc].proced.dente[pos]==2)
        {
            limpaconsole();
            printf("\n   ---Dente j� foi extra�do!---\n\n");
            desejacontinuar();
            if (avanca == NAO)
            {
                loc=loc+1;
            }
            return;
        }
        pront[loc].proced.dente[pos] = num;
    }
    //N�mero do dente de 31 a 38
    else if (ndente>=31 && ndente<=38)
    {
        //Posi��o que o procedimento vai ser guardado dentro do vetor "dente" � igual
        //ao n�mero do dente informado menos 15
        pos = ndente -15;
        if (pront[loc].proced.dente[pos]==2)
        {
            limpaconsole();
            printf("\n   ---Dente j� foi extra�do!---\n\n");
            desejacontinuar();
            if (avanca == NAO)
            {
                loc=loc+1;
            }
            return;
        }
        pront[loc].proced.dente[pos] = num;
    }
    //N�mero do dente de 41 a 48
    else
    {
        //Posi��o que o procedimento vai ser guardado dentro do vetor "dente" � igual
        //ao n�mero do dente informado menos 17
        pos = ndente -17;
        if (pront[loc].proced.dente[pos]==2)
        {
            limpaconsole();
            printf("\n   ---Dente j� foi extra�do!---\n\n");
            desejacontinuar();
            if (avanca == NAO)
            {
                loc=loc+1;
            }
            return;
        }
        pront[loc].proced.dente[pos] = num;
    }
    //L� se o usu�rio deseja continuar realizando procedimentos
    desejacontinuar();
    if (avanca == NAO)
    {
        loc=loc+1;
    }

    return;
}
//Fun��o para consultar prontu�rio
void consultarpront()
{
    int continua,retorno,retorno1,retorno2;
    char consulta[13];

    getchar();
    printf("-----CONSULTAR PRONTU�RIO");
    printf("\n\nInforme o cpf do paciente: ");
    fgets(consulta,13,stdin);

    retorno  = strcmp(pront[0].cpf, consulta);
    retorno1 = strcmp(pront[1].cpf, consulta);
    retorno2 = strcmp(pront[2].cpf, consulta);
    //Se algum dos retornos acima for igual a zero...
    if (retorno==0)
    {
        cpfvalido = 0; //cpf ta declarado globalmente
        limpaconsole();
    }
    else if (retorno1==0)
    {
        cpfvalido = 1; //cpf ta declarado globalmente
        limpaconsole();
    }
    else if (retorno2==0)
    {
        cpfvalido = 2; //cpf ta declarado globalmente
        limpaconsole();
    }
    //Se nenhum dos retornos for igual a zero, cpf inv�lido
    if (retorno!=0 && retorno1!=0 && retorno2!=0)
    {
        limpaconsole();
        printf("\n   ---CPF n�o cadastrado no sistema!---\n\n");
        desejacontinuar();
        return;
    }

    imprimedados();

    return;
}
//Imprime o prontu�rio lido a partir do cpf
void imprimedados()
{
    int i;
    i = cpfvalido; //i � igual a cpf v�lido, esse que recebeu valor na fun��o consultarpront
    system("cls");
    printf("***************************************************************");
    printf("\n\n                        DADOS PESSOAIS"                          );
    printf("\n\n***************************************************************\n");
    printf("\n\n1. id prontuario: %s",pront[i].id);
    printf("\n2. cpf do paciente: %s",pront[i].cpf);
    printf("\n\n3. nome do paciente: %s",pront[i].nome);
    printf("\n4. endere�o: %s",pront[i].endereco);
    printf("\n5. bairro: %s",pront[i].bairro);
    printf("\n6. cidade: %s",pront[i].cidade);
    printf("\n7. Estado: %s",pront[i].estado);
    printf("\n8. ano de nascimento: %s",pront[i].nasc);

    printf("\n\n***************************************************************");
    printf("\n\n                          ANAMNESE"                              );
    printf("\n\n***************************************************************\n");
    printf("\n\nEst� em tratamento m�dico?         -%s",pront[i].anam.trat);
    printf("\nEst� tomando medicamento?          -%s",pront[i].anam.med);
    printf("\n� diab�tico?                       -%s",pront[i].anam.diab);
    printf("\n� hipertenso?                      -%s",pront[i].anam.hiper);
    printf("\nTem tosse persistente?             -%s",pront[i].anam.tosse);
    printf("\nTem algum tipo de alergia?         -%s",pront[i].anam.alergia);

    printf("\n\n***************************************************************");
    printf("\n\n                         PROCEDIMENTOS                        ");
    printf("\n\n***************************************************************\n");
    printf("\n\nDente 11: %d          Dente 31: %d",pront[i].proced.dente[0],pront[i].proced.dente[16]);
    printf("\nDente 12: %d          Dente 32: %d",pront[i].proced.dente[1],pront[i].proced.dente[17]);
    printf("\nDente 13: %d          Dente 33: %d",pront[i].proced.dente[2],pront[i].proced.dente[18]);
    printf("\nDente 14: %d          Dente 34: %d",pront[i].proced.dente[3],pront[i].proced.dente[19]);
    printf("\nDente 15: %d          Dente 35: %d",pront[i].proced.dente[4],pront[i].proced.dente[20]);
    printf("\nDente 16: %d          Dente 36: %d",pront[i].proced.dente[5],pront[i].proced.dente[21]);
    printf("\nDente 17: %d          Dente 37: %d",pront[i].proced.dente[6],pront[i].proced.dente[22]);
    printf("\nDente 18: %d          Dente 38: %d",pront[i].proced.dente[7],pront[i].proced.dente[23]);
    printf("\nDente 21: %d          Dente 41: %d",pront[i].proced.dente[8],pront[i].proced.dente[24]);
    printf("\nDente 22: %d          Dente 42: %d",pront[i].proced.dente[9],pront[i].proced.dente[25]);
    printf("\nDente 23: %d          Dente 43: %d",pront[i].proced.dente[10],pront[i].proced.dente[26]);
    printf("\nDente 24: %d          Dente 44: %d",pront[i].proced.dente[11],pront[i].proced.dente[27]);
    printf("\nDente 25: %d          Dente 45: %d",pront[i].proced.dente[12],pront[i].proced.dente[28]);
    printf("\nDente 26: %d          Dente 46: %d",pront[i].proced.dente[13],pront[i].proced.dente[29]);
    printf("\nDente 27: %d          Dente 47: %d",pront[i].proced.dente[14],pront[i].proced.dente[30]);
    printf("\nDente 28: %d          Dente 48: %d",pront[i].proced.dente[15],pront[i].proced.dente[31]);

    printf("\n\n*********************************************************************************************");
    printf("\n\nPressione alguma tecla para voltar ao menu principal");
    getch();
    avanca = NAO;

    return;
}
