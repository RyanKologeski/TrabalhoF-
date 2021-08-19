#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#define cont 3

void menuprincipal();
void cadastroprontuario();
void anamnese();
void procedimento();

void consultarpront();
void imprimedados();
void imprimedados1();
void imprimedados2();

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

struct prontuario pront[cont];

int cpfvalido=0;
int encerra=0;
int loc= -1;

int main ()
{
    setlocale (LC_ALL,"Portuguese");
    int i,j,menu,contpront=0;

    /*Inicializa o vetor dente com 0*/
    for (i=0;i<cont;i++)
    {
        for (j=0;j<32;j++)
        {
            pront[i].proced.dente[j] = 0;
        }
    }
    /*Fim da inicializa��o do vetor*/
    system ("cls");
    menuprincipal:
    menuprincipal();
    menu:
    scanf("%d",&menu);

    if (menu<1 || menu>3)
        goto menu;

    switch (menu)
    {
    case 1:
        loc = loc+1;
        if (loc>2)
        {
            system("cls");
            printf("----------N�mero m�ximo de prontu�rios ja cadastrados----------\n\n");
            goto menuprincipal;
        }
        system ("cls");
        cadastroprontuario();
        system ("cls");
        anamnese();
        system ("cls");
        procedimento();
        system ("cls");
        contpront = contpront + 1;
        goto menuprincipal;
        break;

    case 2:
        system ("cls");
        if (contpront==0)
        {
        	system ("cls");
            printf("----------N�o h� prontu�rio armazenado----------\n\n");
            goto menuprincipal;
        }
        consultarpront();
        switch (encerra)
        {
        case 1:
        	system("cls");
        	printf("\n-----PROGRAMA FINALIZADO-----");
            exit(0);
            break;

        default:
            break;
        }
        system ("cls");
        goto menuprincipal;
        break;
    }

	system("cls");
	printf("\n-----PROGRAMA FINALIZADO-----");

    return 0;
}

void menuprincipal()
{
    printf("***************************************************\n");
    printf("\n        PRONTU�RIO DIGITAL - CL�NICA DENTO TECH ");
    printf("\n\n***************************************************");

    printf("\n\n-----MENU PRINCIPAL");
    printf("\n1. Cadastrar prontu�rio\n2. Consultar prontu�rio\n3. Sair do sistema");

    printf("\n\nInforme a op��o desejada: ");
    return;
}

void cadastroprontuario()
{
    getchar();
    printf("-----CADASTRAR PRONTU�RIO - DADOS PESSOAIS\n\n");
    printf("1. id prontu�rio: ");                    fgets(pront[loc].id,10,stdin);
    printf("2. cpf do paciente (xxxxxxxxx-xx): ");   fgets(pront[loc].cpf,13,stdin);       getchar();
    printf("3. nome do paciente: ");                 fgets(pront[loc].nome,50,stdin);
    printf("4. endere�o: ");                         fgets(pront[loc].endereco,40,stdin);
    printf("5. bairro: ");                           fgets(pront[loc].bairro,30,stdin);
    printf("6. cidade: ");                           fgets(pront[loc].cidade,30,stdin);
    printf("7. Estado: ");                           fgets(pront[loc].estado,30,stdin);
    printf("8. ano de nascimento: ");                fgets(pront[loc].nasc,5,stdin);
    return;
}

void anamnese()
{
    printf("-----CADASTRAR PRONTU�RIO - ANAMNESE\n\n");
    getchar();
    printf("Est� em tratamentos m�dico? "); fgets(pront[loc].anam.trat,4,stdin);   getchar();
    printf("Est� tomando medicamento? ");   fgets(pront[loc].anam.med,4,stdin);    getchar();
    printf("� diab�tico? ");                fgets(pront[loc].anam.diab,4,stdin);   getchar();
    printf("� hipertenso? ");               fgets(pront[loc].anam.hiper,4,stdin);  getchar();
    printf("Tem tosse persistente? ");      fgets(pront[loc].anam.tosse,4,stdin);  getchar();
    printf("Tem algum tipo de alergia? ");  fgets(pront[loc].anam.alergia,4,stdin);getchar();
    return;
}

void procedimento()
{
    int pos,num,ndente,op,continua;


    printf("-----CADASTRAR PRONTU�RIO - PROCEDIMENTOS\n\n");
    printf("1- Obtura��o\n2- Extra��o\n\n");
    goto again;

    opcao:
    printf("Deseja continuar? (1-sim, 2-n�o): ");
    scanf("%d",&op);
   	printf("*************************************************************");
    if (op==2)
    	goto sai;

    again:
    printf("\nQual procedimento deseja realizar: "); scanf("%d",&num);
    if (num<1 || num>2)
    {
    	printf("---N�mero do Procedimento Inv�lido!---\n");
    	goto again;
	}

  	infodente:
    printf("\nInforme o n�mero do dente: ");         scanf("%d",&ndente);

    if (ndente>=11&&ndente<=18 || ndente>=21&&ndente<=28 || ndente>=31&&ndente<=38 || ndente>=41&&ndente<=48)
        goto prox; //Se o n�mero de dente informado for v�lido, vai para o pr�ximo passo
    else
        goto infodente; //Se o n�mero de dente informado for inv�lido, volta e pede para informar novamente

    /*Verifica em que grupo de dentes est� e coloca o procedimento na posi��o correta*/
    prox:
    if (ndente>=11 && ndente<=18)
    {
        pos = ndente -11;
        if (pront[loc].proced.dente[pos]==2)
        {
        	printf("---Dente j� foi extra�do!---\n\n");
        	//goto again;
        	goto opcao;
        }
        pront[loc].proced.dente[pos] = num;
    }
    else if (ndente>=21 && ndente<=28)
    {
        pos = ndente -13;
        if (pront[loc].proced.dente[pos]==2)
        {
        	printf("---Dente j� foi extra�do!---\n\n");
        	//goto again;
        	goto opcao;
        }
        pront[loc].proced.dente[pos] = num;
    }
    else if (ndente>=31 && ndente<=38)
    {
        pos = ndente -15;
        if (pront[loc].proced.dente[pos]==2)
        {
        	printf("---Dente j� foi extra�do!---\n\n");
        	//goto again;
        	goto opcao;
        }
        pront[loc].proced.dente[pos] = num;
    }
    else
    {
        pos = ndente -17;
        if (pront[loc].proced.dente[pos]==2)
        {
        	printf("---Dente j� foi extra�do!---\n\n");
        	//goto again;
        	goto opcao;
        }
        pront[loc].proced.dente[pos] = num;
    }
    /*Fim da verifica��o de grupo*/
	printf("*************************************************************");
    printf("\nDeseja continuar? (1-sim, 2-n�o): ");
    scanf("%d",&continua);
    printf("*************************************************************");

    switch (continua)
    {
    case 1:
        goto again;
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
    printf("-----CONSULTAR PRONTU�RIO");
    printf("\n\nInforme o cpf do paciente: ");
    fgets(consulta,13,stdin);

    retorno  = strcmp(pront[0].cpf, consulta);
    retorno1 = strcmp(pront[1].cpf, consulta);
    retorno2 = strcmp(pront[2].cpf, consulta);

    if (retorno==0)
    {
        cpfvalido = 0; //cpf ta declarado globalmente
        system ("cls");
        goto imprime;
    }
    else if (retorno1==0)
    {
        cpfvalido = 1; //cpf ta declarado globalmente
        system ("cls");
        goto imprime;
    }
    else if (retorno2==0)
    {
        cpfvalido = 2; //cpf ta declarado globalmente
        system ("cls");
        goto imprime;
    }
    else
    {
    	printf("\nCPF n�o cadastrado no sistema!");
        printf("\nDeseja continuar? (1-sim, 2-n�o): ");
        scanf("%d",&continua);
        if (continua==1)
        {
        	system ("cls");
        	goto volta;
    	}
        else
        	goto sai;
    }


    imprime:
    imprimedados();

    sai:
    return;
}

void imprimedados()
{
    int i,continua;
    i = cpfvalido;
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
    printf("\n\nDeseja ir para o Menu-Principal ou Encerrar o programa? (1-Menu, 2-Encerra): ");
    scanf("%d",&continua);

    if (continua==2)
        encerra = 1;
    else
        encerra = 0;

    return;
}
