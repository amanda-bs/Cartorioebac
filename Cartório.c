#include <stdio.h> // Biblioteca de comunica��o com o usu�rio
#include <stdlib.h> // Biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> // Biblioteca de aloca��es de texto por regi�o
#include <string.h> // Biblioteca respons�vel por cuidar das string

int registro() // Fun��o respons�vel por cadastrar os usu�rios no sistmea
{
	//In�cio da cria��o de vari�veis/string
	char arquivo [40];
	char cpf[40];
	char nome [40];
	char sobrenome [40];
	char cargo[40];
	//final da cria��o de vari�veis
	
	printf("Digite o CPF a ser cadastrado:"); //Coletando informa��es do usu�rio
	scanf ("%s", cpf); //%s refere-se a string

	strcpy(arquivo, cpf); //Respons�vel por copiar os valores das string
	
	FILE *file;//cria o arquivo
	file= fopen(arquivo,"w");//cria o arquivo e o "w" significa escrever
	fprintf(file,cpf);//salvo o valor da vari�vel
	fclose(file);//fecha o arquivo
	
	file = fopen(arquivo,"a"); // Cria o arquivo
	fprintf(file,","); //Espa�o na linha
	fclose(file); // Fecha o arquivo
	
	printf("Digite o nome a ser cadastrado:"); // Coletando informa��es do usu�rio
	scanf("%s",nome); //%s refere-se a string
	
	file = fopen(arquivo, "a"); // Cria o arquivo
	fprintf(file,nome); //Informa��o a ser recebida
	fclose(file);//Fecha o arquivo
	
	file = fopen(arquivo,"a");//Cria o arquivo
	fprintf(file,",");//Espa�o na linha
	fclose(file);//Fecha o arquivo
	
	printf("Digite o sobrenome a ser cadastrado:");//Coletando informa��es do usu�rio
	scanf("%s",sobrenome);//%s refere-se a string
	
	file = fopen(arquivo,"a");//Cria o arquivo
	fprintf(file,sobrenome); //Informa��o a ser recebida
	fclose(file); //Fecha arquivo
	
	file = fopen(arquivo,"a");//Colentando ingorma��es do usu�rio
	fprintf(file,",");//Espa�o na linha
	fclose(file);//Fecha arquivo
	
	printf("Digite o cargo a ser cadastrado:");//Coletando informa��es do usu�rio
	scanf("%s",cargo); //%s refere-se a string
	
	file = fopen(arquivo, "a"); //Coletando informa��es do usu�rio
	fclose(file); //Fecha o arquivo
	
	system("pause"); // Pausa para o usu�rio ler o conte�do
	
}

int consulta ()
{
	setlocale(LC_ALL, "Portuguese"); // Definindo a linguagem
	
	char cpf [40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado:  ");
	scanf("%s",cpf);

	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
		printf("N�o foi poss�vel abrir o arquivo, n�o localizado!.\n");
		
	}
	
	while(fgets(conteudo, 200, file) != NULL)
{
	printf("\n Essas s�o as informa��es do usu�rio: ");
	printf("%s", conteudo);
	printf("\n\n");
}

	system("pause");
}
	

int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF do usu�rio a ser deletado: ");
	scanf("%s", cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file== NULL)
	{
		printf("O usu�rio n�o se encontra no sistema!. \n");
		system("pause");
		
	}
}

int main()
{
	int opcao=0; // Definindo vari�veis
	int laco=1;
	
	for(laco=1;laco=1;)
	{

		system("cls");
	
 		setlocale(LC_ALL, "Portuguese"); // Definindo a linguagem
	
		printf("### Cart�rio da EBAC ###\n\n");
		printf("Escolha a op��o desejada do menu:\n\n"); //Inicio do menu
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n\n");
  		printf("Op��o:"); // Fim do menu
	
		scanf ("%d",&opcao); //Armazenando a escolha do usu�rio

		system("cls"); //Respons�vel por limpar a tela
		
		switch (opcao) //In�cio da sele��o do menu
		{
			case 1:
			registro();//Chamada de fun��es
			break;
			
			case 2:
			consulta();//Chamada de fun��es
			break;
			
			case 3:
			deletar();// Chamada de fun��es
			break;
			
			
			default:
			printf("Essa op��o n�o est� dispon�vel!\n");
			system("pause");
			break;
		} //fim da sele��o

  	}
}
