#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h>//biblioteca de alocação de espaço de memória
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h>//biblioteca responsável por cuidar das string
int registro()//função responsável por cadastrar os usuários
{
	//declaração de variaveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	printf("\t\t\t\t\t\t- Registro de Nomes -\n\n");
	printf("Digite o CPF a ser cadastrado: ");
	scanf("%s", cpf);//%s refere-se a string
	
	strcpy(arquivo, cpf);//Responsavel por copiar os valores das strings
	
	FILE * file;//cria o arquivo
	
	file = fopen(arquivo, "w");//abre e cria o arquivo (w)significa escrever
	fprintf(file,cpf);//salva o valor na variavel
	fclose(file);//fecha o arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("digite o nome a ser cadastrado: ");
	scanf("%s", nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
}

int consulta()
{
	setlocale(LC_ALL, "Portuguese");//declaração do idioma
	
	char cpf[40];
	char conteudo[200];
	
	printf("\t\t\t\t\t- Digite o CPF a ser consultado: -\n");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r");//r  significa leitura
	
	if(file== NULL)//faz uma comparação com os dados fornecidos para executar uma conculta
	{
		printf("Não foi possivel abrir o arquivo, não localizado!.\n");
	}
	while(fgets(conteudo, 200, file) != NULL)//faz uma comparação com os dados fornecidos para executar uma conculta
	{
		printf("\n Essas são as informações do usuário: ");
		printf("%s", conteudo);
		printf("\n\n");
		
	}
	
	system("pause");
}

int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF a ser deletado:");
	scanf("%s",cpf);
	
	remove(cpf);//remocao dos dados fornecidos
	FILE *file;
	file = fopen(cpf,"r");
	if(file==NULL)//retorno  da ação
	{
		printf("O usuário não se encontra no sistema!.\n");
		system("pause");
    }
    
}

int main ()
{
	int opcao=0;
	int laco=1;
   
    for (laco=1;laco=1;)
    {
		system("cls");//responsavel por limpar a tela
	
	
		setlocale(LC_ALL, "Portuguese");
	
		printf ("\t\t\t\t\t\t### Cartório da EBAC ###\n\n\n\n");    
		printf ("\t\t\t\t\t\t1 - Registrar nomes \n\n");  
		printf ("\t\t\t\t\t\t2 - Consultar nomes \n\n");
	    printf ("\t\t\t\t\t\t3 - Deletar nomes \n\n");
		printf ("\t\t\t\t\t\t4 - Sair do Sistema \n\n\n");
		printf ("\t\t\t\t\t\tOpção:");	
	
		scanf ("%d", &opcao);
	
		system("cls");
	
		switch(opcao)//chamada de funções
		{
			case 1:
			registro();
			break;
			
			case 2:	
			consulta();
			break;
			
			case 3:
			deletar();
			break;
			
			case 4:
			printf("Obrigado por utilizar o Sistema!\n");
			return 0;
			break;	
			default:
			printf("\t\t\t\t\t\t- Essa opção não está disponivel -\n");
			system("pause");
			break;
		}//fim da seleção
	
		
	}
}
