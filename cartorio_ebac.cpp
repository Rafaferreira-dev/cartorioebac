
#include <stdio.h> // Biblioteca com várias funções de entrada e saída
#include <stdlib.h> // Funções básicas 
#include <locale.h> // Biblioteca de alocação de texto
#include <string.h> // Biblioteca de funções string

void registro() // Início da função registro
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
	fprintf(file, "%s", cpf); // Salva o valor da variável
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
} // Final da função registro

void consulta() // Início da função consulta
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
		printf("Não foi possível abrir o arquivo, não localizado!.\n");
		system("pause");
		return; // Sai da função se o arquivo não estiver encontrado
	}

	printf("\nEssas são as informações do usuário: \n");

	while (fgets(conteudo, sizeof(conteudo), file) != NULL) 
	{
		printf("%s", conteudo);
	}
		
	fclose(file); // Fecha o arquivo
	system("pause");
} // Final da função consulta

void deletar() // Início da função deletar
{
	char cpf[40];

	printf("Digite o CPF a ser deletado: ");
	scanf("%39s", cpf);

	FILE *file;
	file = fopen(cpf, "r"); // Tenta abrir o arquivo com o CPF informado

	if (file == NULL) 
	{
		printf("Usuário não encontrado no sistema!\n");
		system("pause");
		return; // Sai da função se o arquivo não existir
	} 
	
	else 
	{
		fclose(file); // Fecha o arquivo após a verificação

			// Tenta remover o arquivo
			if (remove(cpf) == 0) 
			{
				printf("Usuário deletado com sucesso!\n");
			} 
		
			else 
			{
				printf("Erro ao deletar o usuário.\n");
			}

				system("pause");
	}
}

void menu() // Início da função menu
{
	setlocale(LC_ALL, "Portuguese"); // Definindo a linguagem
	
	int opcao;
	do 
	{
		system("cls"); // Limpa a tela (ou use system("clear") em sistemas Unix)
		printf("==== CARTORIO EBAC!====\n\n");
		printf("==== Menu Principal ====\n");
		printf("1. Registrar Usuário!\n");
		printf("2. Consultar Usuário!\n");
		printf("3. Deletar Usuário!\n");
		printf("4. Sair\n");
		printf("========================\n");
		printf("Escolha uma opção: ");
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
				printf("Opção inválida! Tente novamente.\n");
				system("pause");
				break;
				
			}
	} while (opcao != 4); // O loop continua até que a opção 4 seja selecionada
}

int main() // Início da função main
{
	menu(); // Chama a função menu
	return 0; // Finaliza o programa
} // Final da função main

