#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço de memória
#include <locale.h> //biblioteca de alocação de texto por região
#include <string.h> //biblioteca responsável por cuidar das strings

int registro() //função responsável por registrar usuários no sistema
{
	//início da criação de variáveis/strings. (string = conjunto de variáveis)
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char numero[40];
	char cargo[40];
	
	printf("Digite o CPF a ser cadastrado: "); //coletando informações do usuário
	scanf("%s", cpf); //salvando uma string dentro da variável "CPF"("%s" refere-se a strings)
	
	strcpy(arquivo, cpf); //responsável por copiar os valores das strings
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w"); //fopen = abre o arquivo no sistema / escreve/grava o arquivo no sistema ("w" = write = escrever)
	fprintf(file,cpf); // escrevendo no arquivo (salva o valor da variável)
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
	fprintf(file, ", Número: ");
	fclose(file);
	
	printf("Digite o número a ser cadastrado: ");
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
	setlocale(LC_ALL, "Portuguese"); //selecão de lingaugem local
	
	char cpf[40]; //variável
	char conteudo[200]; //variável
	
	printf("Digite o CPF a ser consultado: "); // perguntando ao usuário
	scanf("%s",cpf); // salvando na variável
	
	FILE *file; //acessando e consultando o arquivo
	file = fopen(cpf,"r"); //abra o arquivo e faça a leitura do cpf
	
	if(file == NULL) //Se(if) o arquivo(file) for(==) nulo(NULL)
	{
		printf("\n\nArquivo não localizado! Por favor confira o CPF digitado.\n\n"); //Diga ao usuário
	}
	
	while(fgets(conteudo, 200, file) != NULL) // (fgets = indo buscar arquivo) | enquanto(while) estiver buscando na variável ou string conteudo, até 200 valores que dentro desse arquivo(file).   OBS: (!=) = diferente / NULL = nulo 
	{
		printf("\n\nEssas são as informações do usuário: \n\nCPF: "); //Diga ao usuário
		printf("%s", conteudo); // salvando o conteudo que esta dentro da stings(s).
		printf("\n\n"); // pulando linhas para melhor visualização
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
		printf("\nUsuário não se encontra no sistema! \n\n");
		system("pause");
		fclose(file);
	}
		
	else
	{
		fclose(file);
		remove(cpf);
		printf("\nUsuário excluido com sucesso! \n\n");
		system("pause");
	}
}

int main()
{
	int opcao=0; //definindo variável
	int laco=1; //variável
	
	for(laco=1;laco=1;) //ciclo de repetições
	{
		
		system("cls"); //limpa informações anteriores
		
		setlocale(LC_ALL, "Portuguese"); //selecão de lingaugem local
	
		printf("#### Cartório da EBAC ####\n \n"); //início do menu
		printf("Selecione abaixo o número da opção desejada:\n \n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n\n");
		printf("\t4 - Sair do sistema\n\n");
		printf("opção:"); //fim do menu
		scanf("%d", &opcao); //armazenando a escolha do usuário
	
		system("cls"); //limpa informações anteriores
		
		
		switch(opcao) //estrutura
		{
			case 1: //início de seleção
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
			printf("opção não disponível!\n");
			system("pause");
			break;			
		} //fim de seleção
		
	}
}
