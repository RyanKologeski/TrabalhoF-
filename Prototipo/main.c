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

void limpaconsole();
void desejacontinuar();
void menuprincipal();
void escolha();
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

int menu;
int contpront=0;
int cpfvalido=0;
int encerra=0;
int loc= 0;
int avanca=0;

int main ()
{
    setlocale (LC_ALL,"Portuguese");
    int i,j;

    /*Inicializa o vetor dente com 0*/
    for (i=0;i<cont;i++)
    {
        for (j=0;j<32;j++)
        {
            pront[i].proced.dente[j] = 0;
        }
    }
    /*Fim da inicialização do vetor*/

    menuprincipal();

	limpaconsole();
	printf("\n   -----PROGRAMA FINALIZADO-----");

    return 0;
}

void limpaconsole()
{
	system("cls");
	return;
}

void desejacontinuar()
{
	printf("Deseja continuar? (1-sim, 2-não): ");
	scanf("%d",&avanca);

	while (avanca<1 || avanca>2)
	{
		printf("\n   ---Opção Inválida---\n");
		printf("Deseja continuar? (1-sim, 2-não): ");
		scanf("%d",&avanca);
	}

	switch (avanca)
	{
	case 2:
		avanca=0;
		limpaconsole();
		menuprincipal();
	}
}

void menuprincipal()
{
    printf("***************************************************\n");
    printf("\n        PRONTUÁRIO DIGITAL - CLÍNICA DENTO TECH ");
    printf("\n\n***************************************************");

    printf("\n\n-----MENU PRINCIPAL");
    printf("\n1. Cadastrar prontuário\n2. Consultar prontuário\n3. Sair do sistema");

    printf("\n\nInforme a opção desejada: ");
    scanf("%d",&menu);

	{
	    while (menu!=CADASTRAR && menu!=CONSULTAR && menu!=SAIR)
	    {
	        limpaconsole();
	        printf("\n   ---OPÇÃO INVÁLIDA! INFORME NOVAMENTE.---\n\n");
	        menuprincipal();
	        scanf("%d",&menu);
	    }
	}
	escolha();
    return;
}

void escolha()
{
	switch (menu)
    {
    case 1:
        if (loc>2)
        {
            limpaconsole();
            printf("\n   ----------Número máximo de prontuários ja cadastrados----------\n\n");
            menuprincipal();
        }
        limpaconsole();
        cadastroprontuario();
        limpaconsole();
        anamnese();
        limpaconsole();
        procedimento();
        limpaconsole();
        contpront = contpront + 1;
        menuprincipal();
        break;

    case 2:
        limpaconsole();
        if (contpront==0)
        {
        	limpaconsole();
            printf("\n   ----------Não há prontuário armazenado----------\n\n");
            menuprincipal();
        }
        consultarpront();
        if (encerra==0)
        {
        	limpaconsole();
        	menuprincipal();
        }
        case 3:
        	limpaconsole();
        	printf("\n   -----PROGRAMA FINALIZADO-----");
        	exit(0);
        break;
    }

    return;
}

void cadastroprontuario()
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
    printf("Está em tratamentos médico? (Sim/Não) "); fgets(pront[loc].anam.trat,4,stdin);   getchar();
    printf("Está tomando medicamento? (Sim/Não) ");   fgets(pront[loc].anam.med,4,stdin);    getchar();
    printf("É diabético? (Sim/Não) ");                fgets(pront[loc].anam.diab,4,stdin);   getchar();
    printf("É hipertenso? (Sim/Não) ");               fgets(pront[loc].anam.hiper,4,stdin);  getchar();
    printf("Tem tosse persistente? (Sim/Não) ");      fgets(pront[loc].anam.tosse,4,stdin);  getchar();
    printf("Tem algum tipo de alergia? (Sim/Não) ");  fgets(pront[loc].anam.alergia,4,stdin);getchar();
    return;
}

void procedimento()
{
    int pos,num,ndente,op,continua;


    printf("-----CADASTRAR PRONTUÁRIO - PROCEDIMENTOS\n\n");
    printf("1- Obturação\n2- Extração\n\n");

    printf("\nQual procedimento deseja realizar: ");
	scanf("%d",&num);

    if (num!=OBTURACAO && num!=EXTRACAO)
    {
    	limpaconsole();
    	printf("   \n---Número do Procedimento Inválido!---\n\n");
    	procedimento();
	}

    printf("\nInforme o número do dente: ");
	scanf("%d",&ndente);

    if((ndente<11 || ndente>18) && (ndente<21 || ndente>28) && (ndente<31 || ndente>38) && (ndente<41 || ndente>48))
    {
    	limpaconsole();
    	printf("        \n-----Número de dente inválido!-----\n\n");
    	procedimento();
	}

    prox:
    if (ndente>=11 && ndente<=18)
    {
        pos = ndente -11;
        if (pront[loc].proced.dente[pos]==2)
        {
        	limpaconsole();
        	printf("\n   ---Dente já foi extraído!---\n\n");
        	desejacontinuar();
        	limpaconsole();
        	procedimento();
        }
        pront[loc].proced.dente[pos] = num;
    }
    else if (ndente>=21 && ndente<=28)
    {
        pos = ndente -13;
        if (pront[loc].proced.dente[pos]==2)
        {
        	limpaconsole();
        	printf("\n   ---Dente já foi extraído!---\n\n");
        	desejacontinuar();
        	limpaconsole();
        	procedimento();
        }
        pront[loc].proced.dente[pos] = num;
    }
    else if (ndente>=31 && ndente<=38)
    {
        pos = ndente -15;
        if (pront[loc].proced.dente[pos]==2)
        {
        	limpaconsole();
        	printf("\n   ---Dente já foi extraído!---\n\n");
        	desejacontinuar();
        	limpaconsole();
        	procedimento();
        }
        pront[loc].proced.dente[pos] = num;
    }
    else
    {
        pos = ndente -17;
        if (pront[loc].proced.dente[pos]==2)
        {
        	limpaconsole();
        	printf("\n   ---Dente já foi extraído!---\n\n");
        	desejacontinuar();
        	limpaconsole();
        	procedimento();
        }
        pront[loc].proced.dente[pos] = num;
    }
    /*Fim da verificação de grupo*/

	printf("*************************************************************");
    printf("\nDeseja continuar? (1-sim, 2-não): ");
    scanf("%d",&continua);
    printf("*************************************************************");

    switch (continua)
    {
    case 1:
    	limpaconsole();
    	procedimento();
        break;

    default:
    	loc=loc+1;
        break;
    }

	contpront=contpront+1;
	limpaconsole();
	menuprincipal();

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

    if (retorno!=0 && retorno1!=0 && retorno2!=0)
    {
    	limpaconsole();
    	printf("\n   ---CPF não cadastrado no sistema!---\n\n");
    	desejacontinuar();
    	limpaconsole();
    	consultarpront();
    }

    imprimedados();

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
