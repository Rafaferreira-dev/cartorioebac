
#include <stdio.h> // Biblioteca com v�rias fun��es de entrada e sa�da
#include <stdlib.h> // Fun��es b�sicas 
#include <locale.h> // Biblioteca de aloca��o de texto
#include <string.h> // Biblioteca de fun��es string

void registro() // In�cio da fun��o registro
{
	setlocale(LC_ALL, "Portuguese");
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];

	printf("Digite o CPF a ser cadastrado: ");
	scanf("%39s", cpf); // Limita a entrada a 39 caracteres

	strcpy(arquivo, cpf); // Copia os valores das strings

	FILE *file; // Cria o arquivo
	file = fopen(arquivo, "w"); // Cria o arquivo
	fprintf(file, "%s", cpf); // Salva o valor da vari�vel
	fclose(file); // Fecha o arquivo

	file = fopen(arquivo, "a");
	fprintf(file, " :CPF \n");
	fclose(file);

	printf("Digite o nome a ser cadastrado: ");
	scanf("%39s", nome);

	file = fopen(arquivo, "a");
	fprintf(file, "%s", nome);
	fclose(file);

	file = fopen(arquivo, "a");
	fprintf(file, " :Nome\n");
	fclose(file);

	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%39s", sobrenome);

	file = fopen(arquivo, "a");
	fprintf(file, "%s", sobrenome);
	fclose(file);

	file = fopen(arquivo, "a");
	fprintf(file, " :Sobrenome\n");
	fclose(file);

	printf("Digite o cargo a ser cadastrado: ");
	scanf("%39s", cargo);

	file = fopen(arquivo, "a");
	fprintf(file, "%s", cargo); // Adiciona nova linha no final
	fclose(file);

	file = fopen(arquivo, "a");
	fprintf(file, " :Cargo\n");
	fclose(file);

	system("pause");
} // Final da fun��o registro

void consulta() // In�cio da fun��o consulta
{
	setlocale(LC_ALL, "Portuguese"); // Definindo a linguagem

	char cpf[40];
	char conteudo[200];

	printf("Digite o CPF a ser consultado: ");
	scanf("%39s", cpf);

	FILE *file;
	file = fopen(cpf, "r");

	if (file == NULL) 
	{
		printf("N�o foi poss�vel abrir o arquivo, n�o localizado!.\n");
		system("pause");
		return; // Sai da fun��o se o arquivo n�o estiver encontrado
	}

	printf("\nEssas s�o as informa��es do usu�rio: \n");

	while (fgets(conteudo, sizeof(conteudo), file) != NULL) 
	{
		printf("%s", conteudo);
	}
		
	fclose(file); // Fecha o arquivo
	system("pause");
} // Final da fun��o consulta

void deletar() // In�cio da fun��o deletar
{
	char cpf[40];

	printf("Digite o CPF a ser deletado: ");
	scanf("%39s", cpf);

	FILE *file;
	file = fopen(cpf, "r"); // Tenta abrir o arquivo com o CPF informado

	if (file == NULL) 
	{
		printf("Usu�rio n�o encontrado no sistema!\n");
		system("pause");
		return; // Sai da fun��o se o arquivo n�o existir
	} 
	
	else 
	{
		fclose(file); // Fecha o arquivo ap�s a verifica��o

			// Tenta remover o arquivo
			if (remove(cpf) == 0) 
			{
				printf("Usu�rio deletado com sucesso!\n");
			} 
		
			else 
			{
				printf("Erro ao deletar o usu�rio.\n");
			}

				system("pause");
	}
}

void menu() // In�cio da fun��o menu
{
	setlocale(LC_ALL, "Portuguese"); // Definindo a linguagem
	
	int opcao;
	do 
	{
		system("cls"); // Limpa a tela (ou use system("clear") em sistemas Unix)
		printf("==== CARTORIO EBAC!====\n\n");
		printf("==== Menu Principal ====\n");
		printf("1. Registrar Usu�rio!\n");
		printf("2. Consultar Usu�rio!\n");
		printf("3. Deletar Usu�rio!\n");
		printf("4. Sair\n");
		printf("========================\n");
		printf("Escolha uma op��o: ");
		scanf("%d", &opcao);

			switch (opcao) 
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
				printf("Saindo...\n");
				break;
				
				default:
				printf("Op��o inv�lida! Tente novamente.\n");
				system("pause");
				break;
				
			}
	} while (opcao != 4); // O loop continua at� que a op��o 4 seja selecionada
}

int main() // In�cio da fun��o main
{
	menu(); // Chama a fun��o menu
	return 0; // Finaliza o programa
} // Final da fun��o main

