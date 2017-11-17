#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

char formatanome(char nome[50], char ref[20])
{
	char letra1, letra2;
     	int tam=0, tam_ref=0, i=0, j=0, cont=0, achou=0, pos;
     	tam = strlen(nome);
     	strupr(nome); //transforma todo o nome digitado em letras maiúsculas
    	//retira as palavras de ligação (e, de, do, da, dos, das, la, di, del) e também retira "Junior" e "Neto", se houver
    	while (i<tam)
	{
		if (nome[i]==' ' && nome[i+1]=='E' && nome[i+2]==' ') //se encontrar um "E". Ex: João Silva e Silva
		{
			j = i;
               		while (j<tam)
			{
				nome[j+1]=nome[j+3];
				j++;
			}
               		tam = strlen(nome);
           	}
        
	        if (nome[i]==' ' && nome[i+1]=='D' && (nome[i+2]=='A' || nome[i+2]=='E' || nome[i+2]=='I' || nome[i+2]=='O' || nome[i+2]=='U') && nome[i+3]==' ') //DA, DE, DI, DO, DU
		{
			j=i;
	           	while (j<tam)
			{
				nome[j+1]=nome[j+4];
				j++;
	            	}
	            	tam = strlen(nome);
	        }
	        
	        if (nome[i]==' ' && nome[i+1]=='L' && nome[i+2]=='A' && nome[i+3]==' ') //LA
		{
			j = i;
               		while (j<tam)
			{
	                	nome[j+1]=nome[j+4];
	                	j++;
	           	}
	           	tam = strlen(nome);
	        }
	        
	        if (nome[i]==' ' && nome[i+1]=='D' && (nome[i+2]=='A' || nome[i+2]=='O')&& nome[i+3]=='S' && nome[i+4]==' ') //DAS, DOS
		{
			j=i;
	           	while (j<tam)
			{
				nome[j+1]=nome[j+5];
				j++;
		      	}
		    	tam = strlen(nome);
		}
		    
	        if (nome[i]==' ' && nome[i+1]=='D' && nome[i+2]=='E' && nome[i+3]=='L' && nome[i+4]==' ')//DEL
		{
			j=i;
	           	while (j<tam)
			{
				nome[j+1]=nome[j+5];
				j++;
	            	}
	            	tam = strlen(nome);
	        }
	        
	        if (nome[i]==' ' && nome[i+1]=='J' && (nome[i+2]=='U' || nome[i+2]=='Ú') && nome[i+3]=='N' && nome[i+4]=='I' && nome[i+5]=='O' && nome[i+6]=='R')//JUNIOR
		{
			for (j=0; j<7; j++)
			nome[i+j] = '\0';
			tam = strlen(nome);
	        }
	        
	        if (nome[i]==' ' && nome[i+1]=='N' && nome[i+2]=='E' && nome[i+3]=='T' && nome[i+4]=='O')//NETO
		{
			for (j=0; j<5; j++)
			nome[i+j] = '\0';
			tam = strlen(nome);
	        }
	        i++; //o próximo caractere do nome será analisado 
    	}
    
    	tam=strlen(nome); //tamanho do nome depois da retirada dos sobrenomes de ligação
    
    	while (achou == 0)
	{
		letra1 = nome[i]; // começa a procurar o último sobrenome começando pelo último caracter
      		if (letra1 == ' ')
	  	{ 
        		pos = i;
        		achou = 1;
      		}
		
      		else
	 		i--;
   	}
    
    	for (i=pos+1; i<tam; i++) // coloca o último sobrenome em ref
	{ 
      		ref[cont] = nome[i];
      		cont++;
    	}
	
    	ref[cont] = ','; //seguido por uma vírgula e por um espaço em branco
    	cont++;
    	ref[cont] = ' '; 
    	cont++;
    
	letra2=nome[0]; //letra2 recebe a primeira letra do primeiro nome da pessoa
	for (i=0; i<=pos; i++) //i vai do início de nome até o último caracter antes do último nome
	{
      		letra1 = nome[i]; 
      		if ((letra1 == ' ') || (letra1 == '\0'))
	  	{ 
       			ref[cont] = letra2;
	   		cont++;
	   		ref[cont]='.';
	   		cont++;
	   		letra2 = nome[i+1];
	 	}
    	}
    	cont++;
    	ref[cont]=' ';
    	tam_ref = strlen(ref);
  	return ref[20];
}  

main()
{
	setlocale(LC_ALL, "Portuguese"); //para aceitar caracteres especiais
	printf ("*** PROGRAMA QUE COLOCA NOMES EM REFERENCIA BIBLIOGRAFICA ***");
	int op = 1;
	while (op==1)
	{
		char nome[50], ref[20];
		int x;
		for (x=0; x<21; x++) //zera o vetor
			ref[x]=' ';
		printf("\n\n\nDigite o nome completo a ser formatado: "); 
		fflush(stdin); //limpa o buffer
		gets(nome); //armazena o nome digitado
		formatanome(nome, ref); //chama a função que formata o nome digitado
		printf("Nome em referência bibliográfica: %s\n\n\n", ref);
		printf ("Digite:\n1 para formatar outro nome / qualquer outra tecla para sair\n");
		scanf ("%d", &op);
		if (op!=1) //se for diferente de 1, o programa encerra
		    break;
	}
}
