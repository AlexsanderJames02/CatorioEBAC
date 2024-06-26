#include <stdio.h> //biblioteca de comunica��o com o usuario
#include <stdlib.h> //biblioteca de aloca��o de espa�o em memoria
#include <locale.h> // biblioteca de aloca��o de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar das strings

int registro() //fun��o respons�vel por cadastrar o usu�rio no sistema
{
	setlocale(LC_ALL, "Portuguese");
	
	int opcao; //vari�vel para perguntar ao usu�rio se deseja retornar ao menu
	
	//in�cio cria��o de vari�veis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da cria��o de vari�veis/string
	
	do //loop para perguntar se o usu�rio deseja voltar ao menu principal "do" significa fa�a
	{
	
		printf("Digite o cpf a ser cadastrado: ");//coletando informa��o
		scanf("%s", cpf); //armazena o dado inserido pelo usu�rio sendo %s para string
		
		strcpy(arquivo, cpf); //respons�vel por captar os valores das string
		
		FILE *file; //cria o arquivo
		file = fopen(arquivo, "w"); //abrindo e "w" cria o arquivo
		fprintf(file,cpf); // salva o valor da variavel
		fclose(file); //fecha o arquivo
		
		file = fopen(arquivo, "a"); //atualiza o arquivo
		fprintf(file, ",");// organizar melhor as informa��es quando for consultar
		fclose(file);//fecha arquivo
		
		printf("Digite o nome a ser cadastrado: ");//coletando informa��o
		scanf("%s", nome);//armazenando o nome do usu�rio
		
		file = fopen(arquivo, "a");//abrindo e atualizando o arquivo
		fprintf(file,nome);//salvabdo a informa��o (no caso o nome)
		fclose(file);//fechando o arquivo
		
		file = fopen(arquivo, "a"); //atualiza o arquivo
		fprintf(file, ",");
		fclose(file);
		
		printf("Digite o sobrenome a ser cadastrado: ");//coletando informa��o
		scanf("%s",sobrenome);//armazenando a informa��o
		
		file = fopen(arquivo, "a");//abrindo o arquivo utilizando"a" para atualizar
		fprintf(file,sobrenome);//salvando o sobrenome
		fclose(file);//fechando arquivo
		
		file = fopen(arquivo, "a"); //atualiza o arquivo
		fprintf(file, ",");//colocando a virgula para organizar melhor
		fclose(file);//fechando arquivo
	
		printf("Digite o cargo a ser cadastrado: ");//coletando informa��o
		scanf("%s", cargo);////armazenando a informa��o
	
		file = fopen(arquivo, "a");//abrindo e atualizando o arquivo
		fprintf(file, cargo);//salvando o cargo
		fclose(file);//fechando o arquivo
	
		printf("Deseja retornar ao menu?\n");//perguntando se o usu�rio deseja retornar ao menu
		printf("\t1 - Sim\n");//op��o de sim ou n�o
		printf("\t2 - N�o\n");
		scanf("%d", &opcao); //lendo o que o usu�rio digitou sendo este um numero inteiro ou seja %d
	}

	while (opcao != 1); //while significa enquanto e neste caso � utilizado para o usu�rio continuar no loop
	
	main(); //retorna ao menu principal
	
	system("pause");//Pausar para o usu�rio ler 
}

int consulta()
{
	int opcao;
	
	setlocale(LC_ALL, "Portuguese");//definindo linguagem
	
	//in�cio de var�avel/string
	char cpf[40];
	char conteudo[200];
	//final de vari�vel/string
	
	do
	{
	printf("Digite o cpf a ser consultado: ");//solicitando qual cpf quer consultar
	scanf("%s", cpf);//escaneando a informa��o
	
	FILE *file;//abrindo arquivo
	file = fopen(cpf, "r");//"r" significa ler arquivo
	
	if(file == NULL)//se n�o achar o arquivo
	{
		printf("N�o foi poss�vel abrir o arquivo, n�o localizado. \n");//arquivo n�o encontrado
	}
	
	while(fgets(conteudo, 200, file) != NULL)//O comando while � uma estrutura de controle de fluxo que permite repetir um bloco de c�digo enquanto uma condi��o for verdadeira. no caso se o cpf a ser consultado existe no banco de dados
	{
		printf("\nEssas s�o as informa��es do usu�rio: ");//achou o arquivo
		printf("%s", conteudo);//mostrando as informa��es do usu�rio cadastrado
		printf("\n\n");//espa�amento para melhor organiza��o
	}
	
		printf("Deseja retornar ao menu?\n");
		printf("\t1 - Sim\n");
		printf("\t2 - N�o\n");
		scanf("%d", &opcao);
		
		if (opcao == 2) //caso o usu�rio n�o querer voltar ao menu principal
		consulta();
	}
	
	while (opcao != 1);//usu�rio volta ao menu principal
	
	main();
	
	system("pause");//pausar paea o usu�rio ler
}

int deletar()
{
	int opcao;
	
	char cpf[40];//v�riavel/string
	
	do
	{
		printf("Digite o CPF do usu�rio a ser deletado: ");//solicitando qual cpf ser� excluido
		scanf("%s", cpf);//armazenando a informa��o
		
		remove(cpf);
		
		FILE *file;//puxando arquivo
		file = fopen(cpf, "r"); //"r" essa string serve para ler o arquivo
		fclose(file);//fechando arquivo
		
		if(file == NULL)//se o cpf n�o existir
		{
			printf("O usu�rio n�o se encontra no sistema!. \n");//n�o encontrando o usu�rio no sistema
			system("pause");//pausando para o usu�rio ler
		}
		printf("Deseja retornar ao menu?\n");//perguntando ao usu�rio se deseja retornar ao menu
		printf("\t1 - Sim\n");//op�ao de sim ou n�o
		printf("\t2 - N�o\n");
		scanf("%d", &opcao);//escaneando a op��o que o usu�rio escolheu. no caso um numero inteiro
	}
	
	while (opcao != 1);//uwsu�rio volta ao menu principal
	
	main();
}


								int main ()
								{
									int opcao=0; //Definindo as vari�veis
									int laco=1;
									char senhadigitada[]="a"; //senha
									int comparacao; 
									
									printf("### Cart�rio da EBAC ###\n\n");
									printf("Login de administrador!\n\nDigite a sua senha: ");
									scanf("%s", senhadigitada);
									
									comparacao = strcmp(senhadigitada, "admin");
									
									if(comparacao == 0)
									{
									
										system("cls");
										for(laco=1;laco=1;) //atribuindo valor ao laco
										{
										
											system("cls"); //limpa a tela
										
											setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem								
										
											printf("### Cart�rio da EBAC ###\n\n");									
											printf("Escolha a op��o desejada no menu:\n\n"); //Inicio do menu
											printf("\t1 - Registrar nomes\n"); //\t1 ir� tabelar as op��es
											printf("\t2 - Consultar nomes\n");
											printf("\t3 - Deletar nomes\n");
											printf("\t4 - Sair do sistema\n");
											printf("Op��o: "); //Fim do menu
										
											scanf("%d", &opcao); //armazenamento da escolha do usuario sendo %d numero inteiro
										
											system("cls");
											
											
											switch(opcao) //in�cio da sele��o do menu
											{
												case 1: 
												registro(); //chamada de fun��es
												break;										//inicio de sele��o
																							
												case 2:
												consulta();
												break;
												
												case 3:
												deletar();
												break;
												
												case 4:
												printf("Obrigado por utilizar o sistema\n");
												return 0; //fecha o sistema
												break;
												
												default:
												printf("Essa op��o n�o est� dispon�vel\n"); //Caso usu�rio clique em op��o que n�o existe
												system("pause");	
												break;
											}//Fim da sele��o
										}
									}
									else
										printf("Senha incorreta");
								}
