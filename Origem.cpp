#include <stdlib.h>//
#include<stdio.h>//
#include<string.h>//
#include<conio.h>//bibliotecas

int main()//fun��o principal
{
	FILE* p_arq;//declara��o de um ponteiro
	errno_t err;//
	char frase1[50],nome[50];//
	char frase2[50];//
	char frase3[50];//
	char frase4[50];//
	char frase5[50];//declara��o das vari�veis
	printf("Escolha o nome do arquivo!\n");//imprime mensagem na tela
	gets_s(nome);//l� o que foi digitado
	strcat_s(nome, 50 - strlen(nome) - 1, ".txt");//adiciona .txt ao nome do arquivo
	printf("Nome do arquivo:%s\n", nome);//imprime o nome do arquivo 
	err = fopen_s(&p_arq, nome, "w+");//cria��o do arquivo
	if (err == 0)//condi��o de n�o ter erro
	{
		printf("Arquivo criado.\n");//impress�o na tela
	}
	else//caso contr�rio
	{
		printf("Erro na criacao do arquivo!\n");//impress�o na tela
	}
	printf("Digite a primeira frase!\n");//solicita ao usu�rio uma frase
	fgets(frase1, 49, stdin);//faz a leitura
	fprintf(p_arq, "%d %s", strlen(frase1), frase1);//grava no arquivo
	printf("Digite a segunda frase!\n");//A defini��o � a mesma para as 5 frases.
	fgets(frase2, 49, stdin);
	fprintf(p_arq, "%d %s", strlen(frase2), frase2);
	printf("Digite a terceira frase!\n");
	fgets(frase3, 49, stdin);
	fprintf(p_arq, "%d %s", strlen(frase3), frase3);
	printf("Digite a quarta frase!\n");
	fgets(frase4, 49, stdin);
	fprintf(p_arq, "%d %s", strlen(frase4), frase4);
	printf("Digite a quinta frase!\n");
	fgets(frase5, 49, stdin);
	fprintf(p_arq, "%d %s", strlen(frase5), frase5);
	fclose(p_arq);//fecha o arquivo


	err = fopen_s(&p_arq, nome, "r");//faz a abertura do arquivo no modo leitua
	if (err == 0)//condi��o de n�o haver erro
	{
		printf("lendo arquivo\n");//impress�o na tela
	
	}
	else //caso contr�rio
	{
		printf("arquivo nao existe\n");//impress�o na tela
	}while (!feof(p_arq)) //condi��o para repeti��o do processo
	{
		fscanf_s(p_arq, "%s", frase1, _countof(frase1));//Faz a leitura da primeira frase gravada no arquivo 
		printf("%s\n", frase1);//imprime a frase na tela 
		fscanf_s(p_arq, "%s", frase2, _countof(frase2));//A defini��o � a mesma para as 5 frases.
		printf("%s\n", frase2);
		fscanf_s(p_arq, "%s", frase3, _countof(frase3));
		printf("%s\n", frase3);
		fscanf_s(p_arq, "%s", frase4, _countof(frase4));
		printf("%s\n", frase4);
		fscanf_s(p_arq, "%s", frase5, _countof(frase5));
		printf("%s\n", frase5);
		
	}
	fclose(p_arq);//fecha o arquivo

	system("pause");//pausa a tela
	return 0;
}