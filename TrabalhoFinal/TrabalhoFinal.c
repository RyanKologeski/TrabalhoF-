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


void controlaFluxo();
int defineMenu(int menu);
void limpaConsole();

void menuPrincipal();
void cadastroProntuario();
void anamnese();
void procedimentos();

void consultarpront();
void imprimeDados();

struct anamnese
{
    char trat[1],med[1],diab[1],hiper[1],tosse[1],alergia[1];
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

struct prontuario pront[cont];

int cpfvalido=0;
int encerra=0;
int loc= -1;
int i,j,menu,contpront=0;


int main ()
{
    setlocale (LC_ALL,"Portuguese");
    //int i,j,menu,contpront=0;

    /*Inicializa o vetor dente com 0*/
    for (i=0;i<cont;i++)
    {
        for (j=0;j<32;j++)
        {
            pront[i].proced.dente[j] = 0;
        }
    }
    /*Fim da inicialização do vetor*/

    limpaConsole();

    controlaFluxo();

    return 0;
}

void limpaConsole()
{
    system ("cls");
    return;
}

void controlaFluxo()
{
    menuPrincipal();
    while ((menu != CADASTRAR && menu != CONSULTAR && menu != SAIR) || menu == CONSULTAR && contpront == 0 || menu == CADASTRAR && loc > 2)
    {
        scanf("%d",&menu);
        if (menu != CONSULTAR && menu != CADASTRAR)
            printf("Opção inválida, digite novamente! \n");
        else
        {
            if (menu == CONSULTAR)
                printf("Não há prontuário armazenado! \n");
            else
                printf("Número máximo de prontuários ja cadastrados! \n");
        }
    }
    limpaConsole();
    defineMenu(menu);
    return;
}

int defineMenu(int menu)
{
    switch (menu)
    {
    case CADASTRAR:
        loc = loc+1;
        cadastroProntuario();
        limpaConsole();
        anamnese();
        limpaConsole();
        procedimentos();
        limpaConsole();
        contpront = contpront + 1;
        break;
    case CONSULTAR:
        consultarpront();
        limpaConsole();
        break;
    case SAIR:
        limpaConsole();
        printf("\n-----PROGRAMA FINALIZADO-----");
        break;
    }
    if (menu != SAIR)
        controlaFluxo();
    return;
}

void menuPrincipal()
{
    printf("***************************************************\n");
    printf("\n        PRONTUÁRIO DIGITAL - CLÍNICA DENTO TECH ");
    printf("\n\n***************************************************");

    printf("\n\n-----MENU PRINCIPAL");
    printf("\n1. Cadastrar prontuário\n2. Consultar prontuário\n3. Sair do sistema");

    printf("\n\nInforme a opção desejada: ");
    return;
}

void cadastroProntuario()
{
    getchar();
    printf("-----CADASTRAR PRONTUÁRIO - DADOS PESSOAIS\n\n");
    printf("1. id prontuário: ");                    fgets(pront[loc].id,10,stdin);
    printf("2. cpf do paciente (xxxxxxxxx-xx): ");   fgets(pront[loc].cpf,13,stdin);       getchar();
    printf("3. nome do paciente: ");                 fgets(pront[loc].nome,50,stdin);
    printf("4. endereço: ");                         fgets(pront[loc].endereco,40,stdin);
    printf("5. bairro: ");                           fgets(pront[loc].bairro,30,stdin);
    printf("6. cidade: ");                           fgets(pront[loc].cidade,30,stdin);
    printf("7. Estado: ");                           fgets(pront[loc].estado,30,stdin);
    printf("8. ano de nascimento: ");                fgets(pront[loc].nasc,5,stdin);
    return;
}

void anamnese()
{
    printf("-----CADASTRAR PRONTUÁRIO - ANAMNESE\n\n");
    getchar();
    printf("Está em tratamentos médico? (S/N) "); fgets(pront[loc].anam.trat,1,stdin);   getchar();
    printf("Está tomando medicamento? (S/N) ");   fgets(pront[loc].anam.med,1,stdin);    getchar();
    printf("É diabético? (S/N) ");                fgets(pront[loc].anam.diab,1,stdin);   getchar();
    printf("É hipertenso? (S/N) ");               fgets(pront[loc].anam.hiper,1,stdin);  getchar();
    printf("Tem tosse persistente? (S/N) ");      fgets(pront[loc].anam.tosse,1,stdin);  getchar();
    printf("Tem algum tipo de alergia? (S/N) ");  fgets(pront[loc].anam.alergia,1,stdin);getchar();
    return;
}

void procedimentos()
{
    int pos, tipoProcedimento, ndente, op, continua;


    printf("-----CADASTRAR PRONTUÁRIO - PROCEDIMENTOS\n\n");
    printf("1- Obturação\n2- Extração\n\n");

    printf("\nQual procedimento deseja realizar: ");

    while (tipoProcedimento != OBTURACAO && tipoProcedimento != EXTRACAO)
    {
        scanf("%d",&tipoProcedimento);
        printf("Opção inválida, digite novamente! \n");
	}


    opcao:
    printf("Deseja continuar? (1-sim, 2-não): ");
    scanf("%d",&op);
   	printf("*************************************************************");
    if (op==2)
    	controlaFluxo();


  	infodente:
    printf("\nInforme o número do dente: ");         scanf("%d",&ndente);

    if (ndente>=11&&ndente<=18 || ndente>=21&&ndente<=28 || ndente>=31&&ndente<=38 || ndente>=41&&ndente<=48)
        goto prox; //Se o número de dente informado for válido, vai para o próximo passo
    else
        goto infodente; //Se o número de dente informado for inválido, volta e pede para informar novamente

    /*Verifica em que grupo de dentes está e coloca o procedimento na posição correta*/
    prox:
    if (ndente>=11 && ndente<=18)
    {
        pos = ndente -11;
        if (pront[loc].proced.dente[pos]==2)
        {
        	printf("---Dente já foi extraído!---\n\n");
        	//goto again;
        	goto opcao;
        }
        pront[loc].proced.dente[pos] = tipoProcedimento;
    }
    else if (ndente>=21 && ndente<=28)
    {
        pos = ndente -13;
        if (pront[loc].proced.dente[pos]==2)
        {
        	printf("---Dente já foi extraído!---\n\n");
        	//goto again;
        	goto opcao;
        }
        pront[loc].proced.dente[pos] = tipoProcedimento;
    }
    else if (ndente>=31 && ndente<=38)
    {
        pos = ndente -15;
        if (pront[loc].proced.dente[pos]==2)
        {
        	printf("---Dente já foi extraído!---\n\n");
        	//goto again;
        	goto opcao;
        }
        pront[loc].proced.dente[pos] = tipoProcedimento;
    }
    else
    {
        pos = ndente -17;
        if (pront[loc].proced.dente[pos]==2)
        {
        	printf("---Dente já foi extraído!---\n\n");
        	//goto again;
        	goto opcao;
        }
        pront[loc].proced.dente[pos] = tipoProcedimento;
    }
    /*Fim da verificação de grupo*/
	printf("*************************************************************");
    printf("\nDeseja continuar? (1-sim, 2-não): ");
    scanf("%d",&continua);
    printf("*************************************************************");

    switch (continua)
    {
    case 1:
        procedimentos();
        break;

    default:
        break;
    }

	sai:
    return;
}


void consultarpront()
{
    int continua,retorno,retorno1,retorno2;
    char consulta[13];

    volta:
    getchar();
    printf("-----CONSULTAR PRONTUÁRIO");
    printf("\n\nInforme o cpf do paciente: ");
    fgets(consulta,13,stdin);

    retorno  = strcmp(pront[0].cpf, consulta);
    retorno1 = strcmp(pront[1].cpf, consulta);
    retorno2 = strcmp(pront[2].cpf, consulta);

    if (retorno==0)
    {
        cpfvalido = 0; //cpf ta declarado globalmente
        limpaConsole();
        imprimeDados();
    }
    else if (retorno1==0)
    {
        cpfvalido = 1; //cpf ta declarado globalmente
        limpaConsole();
        imprimeDados();
    }
    else if (retorno2==0)
    {
        cpfvalido = 2; //cpf ta declarado globalmente
        limpaConsole();
        imprimeDados();
    }
    else
    {
    	printf("\nCPF não cadastrado no sistema!");
        printf("\nDeseja continuar? (1-sim, 2-não): ");
        scanf("%d",&continua);
        if (continua==1)
        {
            limpaConsole();
        	goto volta;
    	}
        else
        	goto sai;
    }

    sai:
    return;
}

void imprimeDados()
{
    int i,continua;
    i = cpfvalido;
    limpaConsole();
    printf("***************************************************************");
    printf("\n\n                        DADOS PESSOAIS"                          );
    printf("\n\n***************************************************************\n");
    printf("\n\n1. id prontuario: %s",pront[i].id);
    printf("\n2. cpf do paciente: %s",pront[i].cpf);
    printf("\n\n3. nome do paciente: %s",pront[i].nome);
    printf("\n4. endereço: %s",pront[i].endereco);
    printf("\n5. bairro: %s",pront[i].bairro);
    printf("\n6. cidade: %s",pront[i].cidade);
    printf("\n7. Estado: %s",pront[i].estado);
    printf("\n8. ano de nascimento: %s",pront[i].nasc);

	printf("\n\n***************************************************************");
    printf("\n\n                          ANAMNESE"                              );
    printf("\n\n***************************************************************\n");
    printf("\n\nEstá em tratamento médico?         -%s",pront[i].anam.trat);
    printf("\nEstá tomando medicamento?          -%s",pront[i].anam.med);
    printf("\nÉ diabético?                       -%s",pront[i].anam.diab);
    printf("\nÉ hipertenso?                      -%s",pront[i].anam.hiper);
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
    printf("\n\nDeseja ir para o Menu-Principal ou Encerrar o programa? (1-Menu, 2-Encerra): ");
    scanf("%d",&continua);

    if (continua==2)
        encerra = 1;
    else
        encerra = 0;

    return;
}
