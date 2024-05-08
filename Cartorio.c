#include <stdio.h> //biblioteca de comunicação com o usuario
#include <stdlib.h> //biblioteca de alocação de espaço em memoria
#include <locale.h> // biblioteca de alocação de texto por região
#include <string.h> //biblioteca responsável por cuidar das strings

int registro() //função responsável por cadastrar o usuário no sistema
{
	//início criação de variáveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da criação de variáveis/string
	
	printf("Digite o cpf a ser cadastrado: ");//coletando informação
	scanf("%s", cpf); //armazena o dado inserido pelo usuário sendo %s para string
	
	strcpy(arquivo, cpf); //responsável por captar os valores das string
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w"); //abrindo e "w" cria o arquivo
	fprintf(file,cpf); // salva o valor da variavel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //atualiza o arquivo
	fprintf(file, ",");// organizar melhor as informações quando for consultar
	fclose(file);//fecha arquivo
	
	printf("Digite o nome a ser cadastrado: ");//coletando informação
	scanf("%s", nome);//armazenando o nome do usuário
	
	file = fopen(arquivo, "a");//abrindo e atualizando o arquivo
	fprintf(file,nome);//salvabdo a informação (no caso o nome)
	fclose(file);//fechando o arquivo
	
	file = fopen(arquivo, "a"); //atualiza o arquivo
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");//coletando informação
	scanf("%s",sobrenome);//armazenando a informação
	
	file = fopen(arquivo, "a");//abrindo o arquivo utilizando"a" para atualizar
	fprintf(file,sobrenome);//salvando o sobrenome
	fclose(file);//fechando arquivo
	
	file = fopen(arquivo, "a"); //atualiza o arquivo
	fprintf(file, ",");//colocando a virgula para organizar melhor
	fclose(file);//fechando arquivo
	
	printf("Digite o cargo a ser cadastrado: ");//coletando informação
	scanf("%s", cargo);////armazenando a informação
	
	file = fopen(arquivo, "a");//abrindo e atualizando o arquivo
	fprintf(file, cargo);//salvando o cargo
	fclose(file);//fechando o arquivo
	
	system("pause");//Pausar para o usuário ler 
}

int consulta()
{
	setlocale(LC_ALL, "Portuguese");//definindo linguagem
	
	//início de varíavel/string
	char cpf[40];
	char conteudo[200];
	//final de variável/string
	
	printf("Digite o cpf a ser consultado: ");//solicitando qual cpf quer consultar
	scanf("%s", cpf);//escaneando a informação
	
	FILE *file;//abrindo arquivo
	file = fopen(cpf, "r");//"r" significa ler arquivo
	fclose(file); //fechando arquivo
	
	if(file == NULL)//se não achar o arquivo
	{
		printf("Não foi possível abrir o arquivo, não localizado. \n");//arquivo não encontrado
	}
	
	while(fgets(conteudo, 200, file) != NULL)//O comando while é uma estrutura de controle de fluxo que permite repetir um bloco de código enquanto uma condição for verdadeira. no caso se o cpf a ser consultado existe no banco de dados
	{
		printf("\nEssas são as informações do usuário: ");//achou o arquivo
		printf("%s", conteudo);//mostrando as informações do usuário cadastrado
		printf("\n\n");//espaçamento para melhor organização
	}
	
	system("pause");//pausar paea o usuário ler
}

int deletar()
{
	char cpf[40];//váriavel/string
	
	printf("Digite o CPF do usuário a ser deletado: ");//solicitando qual cpf será excluido
	scanf("%s", cpf);//armazenando a informação
	
	remove(cpf);
	
	FILE *file;//puxando arquivo
	file = fopen(cpf, "r"); //"r" essa string serve para ler o arquivo
	fclose(file);//fechando arquivo
	
	if(file == NULL)//se o cpf não existir
	{
		printf("O usuário não se encontra no sistema!. \n");//não encontrando o usuário no sistema
		system("pause");//pausando para o usuário ler
	}
}


								int main ()
								{
									int opcao=0; //Definindo as variáveis
									int laco=1;
									
									for(laco=1;laco=1;) //atribuindo valor ao laco
									{
									
										system("cls"); //limpa a tela
									
										setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem								
									
										printf("### Cartório da EBAC ###\n\n");									
										printf("Escolha a opção desejada no menu:\n\n"); //Inicio do menu
										printf("\t1 - Registrar nomes\n"); //\t1 irá tabelar as opções
										printf("\t2 - Consultar nomes\n");
										printf("\t3 - Deletar nomes\n\n");
										printf("Opção: "); //Fim do menu
									
										scanf("%d", &opcao); //armazenamento da escolha do usuario sendo %d numero inteiro
									
										system("cls");
										
										
										switch(opcao) //início da seleção do menu
										{
											case 1: 
											registro(); //chamada de funções
											break;										//inicio de seleção
																						
											case 2:
											consulta();
											break;
											
											case 3:
											deletar();
											break;
											
											default:
											printf("Essa opção não está disponível\n"); 
											system("pause");	
											break;
										}//Fim da seleção
									}
								}
