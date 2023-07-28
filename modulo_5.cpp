#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o de mem�ria
#include <locale.h> //biblioteca de aloca��o de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar das strings

int registro() //fun��o respons�vel por registrar usu�rios no sistema
{
	//in�cio da cria��o de vari�veis/strings. (string = conjunto de vari�veis)
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char numero[40];
	char cargo[40];
	
	printf("Digite o CPF a ser cadastrado: "); //coletando informa��es do usu�rio
	scanf("%s", cpf); //salvando uma string dentro da vari�vel "CPF"("%s" refere-se a strings)
	
	strcpy(arquivo, cpf); //respons�vel por copiar os valores das strings
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w"); //fopen = abre o arquivo no sistema / escreve/grava o arquivo no sistema ("w" = write = escrever)
	fprintf(file,cpf); // escrevendo no arquivo (salva o valor da vari�vel)
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a"); 
	fprintf(file,", Nome: ");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s", nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ", Sobrenome: ");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a");                    
	fprintf(file, sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ", N�mero: ");
	fclose(file);
	
	printf("Digite o n�mero a ser cadastrado: ");
	scanf("%s", numero);
	
	file = fopen(arquivo, "a");
	fprintf(file, numero);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ", Cargo: ");
	fclose(file);	

	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file, cargo);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ".");
	fclose(file);
	
	printf("\nDados cadastrados com sucesso!\n\n");
	
	system("pause");
}

int consulta()
{
	setlocale(LC_ALL, "Portuguese"); //selec�o de lingaugem local
	
	char cpf[40]; //vari�vel
	char conteudo[200]; //vari�vel
	
	printf("Digite o CPF a ser consultado: "); // perguntando ao usu�rio
	scanf("%s",cpf); // salvando na vari�vel
	
	FILE *file; //acessando e consultando o arquivo
	file = fopen(cpf,"r"); //abra o arquivo e fa�a a leitura do cpf
	
	if(file == NULL) //Se(if) o arquivo(file) for(==) nulo(NULL)
	{
		printf("\n\nArquivo n�o localizado! Por favor confira o CPF digitado.\n\n"); //Diga ao usu�rio
	}
	
	while(fgets(conteudo, 200, file) != NULL) // (fgets = indo buscar arquivo) | enquanto(while) estiver buscando na vari�vel ou string conteudo, at� 200 valores que dentro desse arquivo(file).   OBS: (!=) = diferente / NULL = nulo 
	{
		printf("\n\nEssas s�o as informa��es do usu�rio: \n\nCPF: "); //Diga ao usu�rio
		printf("%s", conteudo); // salvando o conteudo que esta dentro da stings(s).
		printf("\n\n"); // pulando linhas para melhor visualiza��o
	}
	
	system("pause");
	fclose(file);
}

int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF a ser deletado: ");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
		printf("\nUsu�rio n�o se encontra no sistema! \n\n");
		system("pause");
		fclose(file);
	}
		
	else
	{
		fclose(file);
		remove(cpf);
		printf("\nUsu�rio excluido com sucesso! \n\n");
		system("pause");
	}
}

int main()
{
	int opcao=0; //definindo vari�vel
	int laco=1; //vari�vel
	
	for(laco=1;laco=1;) //ciclo de repeti��es
	{
		
		system("cls"); //limpa informa��es anteriores
		
		setlocale(LC_ALL, "Portuguese"); //selec�o de lingaugem local
	
		printf("#### Cart�rio da EBAC ####\n \n"); //in�cio do menu
		printf("Selecione abaixo o n�mero da op��o desejada:\n \n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n\n");
		printf("\t4 - Sair do sistema\n\n");
		printf("op��o:"); //fim do menu
		scanf("%d", &opcao); //armazenando a escolha do usu�rio
	
		system("cls"); //limpa informa��es anteriores
		
		
		switch(opcao) //estrutura
		{
			case 1: //in�cio de sele��o
			registro();
			break;
			
			case 2:
			consulta();
			break;
			
			case 3:
			deletar();
			break;
			
			case 4:
			printf("Obrigado por utilizar nosso sistema!\n\n");
			return 0;
			break;
			
			default:
			printf("op��o n�o dispon�vel!\n");
			system("pause");
			break;			
		} //fim de sele��o
		
	}
}
