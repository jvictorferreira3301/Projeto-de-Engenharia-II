/// @file matrizes.c
/// @page Matrizes.C
#include <stdio.h>
#include <stdlib.h>
#include "matrizes.h"
/**Teste de todas as funções:
 * Executa cada função de teste uma vez
*/
void teste_todos(void)
{	
	printf("\n===============================Teste da Operação Transposta======================\n");
	complexo** c1,**c2; 
	int nlinhas,ncolunas;
    nlinhas=3;
    ncolunas=3;
    //Alocação de memoria para a matriz:
    c1 = allocateComplexMatrix(nlinhas,ncolunas);
	
        for (int l = 0; l < nlinhas; l++)
		{
			for (int c = 0; c < ncolunas; c++)
			{
				c1[l][c].real = (2*l)-c;
				c1[l][c].img = c-1+l;
			}
    }
        printf("\nOperando A:\n");
        for (int l =0 ; l < nlinhas; l++)
		{
			for (int c = 0; c < ncolunas; c++)
			{
				printComplex(c1[l][c]);
			}
        printf("\n");
    }
	int nlinhas_trans = ncolunas;
	int ncolunas_trans = nlinhas;
	
	printf("\nResultado:\n");
    c2 = transposta(c1,nlinhas_trans,ncolunas_trans);
        for (int l =0 ; l < nlinhas_trans; l++)
		{
			for (int c = 0; c < ncolunas_trans; c++)
			{
				printComplex(c2[l][c]);
			}
			printf("\n");
		}
		
	printf("\n===============================Teste da Operação Conjugada===============================\n");
//Kauan (06.05.23)
	complexo **c10, **conj_c10;

	//Alocação de memória. 
	c10 = allocateComplexMatrix(nlinhas, ncolunas);

	//Preenchimento da(s) matriz(es).
	for (int l = 0; l < nlinhas; l++)
	{
		for (int c = 0; c < ncolunas; c++)
		{
			c10[l][c].real = l + c;
			c10[l][c].img = 1 + l + c;
		}
	}

	//Chamada da função conjugada.
	conj_c10 = conjugada(c10, nlinhas, ncolunas);

	printf("\nOperando A:\n");
	//Impressão da Matriz A.
	for (int l = 0; l < nlinhas; l++)
	{
		for (int c = 0; c < ncolunas; c++)
		{
			printComplex(c10[l][c]);
		}
		printf("\n");
	}

	printf("\nResultado:\n");
	//Impressão da(s) matriz(es) conjugada(s)

	for (int l = 0; l < nlinhas; l++)
	{
		for (int c = 0; c < ncolunas; c++)
		{
			printComplex(conj_c10[l][c]);
		}
		printf("\n");
	}


	printf("\n===============================Teste da operação hermitiana===============================\n");

	complexo **mtx_a, **mtx_h;

    mtx_a = allocateComplexMatrix(nlinhas, ncolunas);

    for (int l = 0; l < ncolunas; l++)
    {
        for (int c = 0; c < ncolunas; c++)
        {
            mtx_a[l][c].real = l + c;
            mtx_a[l][c].img = l - 2*c;
        }
    }

    printf("\nOperando A:\n");

    for (int l = 0 ; l < nlinhas; l++)
	{
		for (int c = 0; c < ncolunas; c++)
		{
			printComplex(mtx_a[l][c]);
		}
        printf("\n");
	}

    mtx_h = hermitiana(mtx_a, nlinhas, ncolunas);

	printf("\nResultado:\n");

    for (int l = 0 ; l < nlinhas_trans; l++)
	{
		for (int c = 0; c < ncolunas_trans; c++)
		{
			printComplex(mtx_h[l][c]);
		}
        printf("\n");
	}

	printf("\n\n===============================Teste da Operação Soma===========================\n");
	
	complexo **c3,**c4,**somado1;
    //Alocação de memoria para a matriz:
    c3 = allocateComplexMatrix(nlinhas,ncolunas);
	c4 = allocateComplexMatrix(nlinhas,ncolunas);
	for (int l = 0; l < nlinhas; l++)
		{
			for (int c = 0; c < ncolunas; c++)
			{
				c3[l][c].real = l+1;
				c3[l][c].img = (2*l)-c;
				c4[l][c].real = (5*l)+c;
				c4[l][c].img = l-c;
			}
		}
	printf("\nOperando A:\n");
	for (int l =0 ; l < nlinhas; l++)
	{
			for (int c = 0; c < ncolunas; c++)
			{
				printComplex(c3[l][c]);
			}
		printf("\n");
	}
	printf("\nOperando B:\n");
	for (int l =0 ; l < nlinhas; l++)
	{
		for (int c = 0; c < ncolunas; c++)
		{
			printComplex(c4[l][c]);
		}
		printf("\n");
	}
	printf("\nResultado:\n");
	somado1 = soma(c3,c4,nlinhas,ncolunas);
	for (int l =0 ; l < nlinhas; l++)
	{
		for (int c = 0; c < ncolunas; c++)
		{
			printComplex(somado1[l][c]);
		}
		printf("\n");
	}
	
	printf("\n\n===============================Teste da operação Subtracao===========================\n");
	complexo **c5,**c6,**sub1;
    //Alocação de memoria para a matriz:
    c5 = allocateComplexMatrix(nlinhas,ncolunas);
	c6 = allocateComplexMatrix(nlinhas,ncolunas);
	for (int l = 0; l < nlinhas; l++)
		{
			for (int c = 0; c < ncolunas; c++)
			{
				c5[l][c].real = l-1;
				c5[l][c].img = (3*l)-2*c;
				c6[l][c].real = (4*l)-c;
				c6[l][c].img = -l-c;
			}
    }
	
	printf("\nOperando A:\n");
		for (int l =0 ; l < nlinhas; l++)
		{
				for (int c = 0; c < ncolunas; c++)
				{
					printComplex(c5[l][c]);
				}
			printf("\n");
		}
	printf("\nOperando B:\n");
		for (int l =0 ; l < nlinhas; l++)
			{
				for (int c = 0; c < ncolunas; c++)
				{
					printComplex(c6[l][c]);
				}
			printf("\n");
		}
	printf("\nResultado:\n");
	sub1 = subtracao(c5,c6,nlinhas,ncolunas);
	for (int l =0 ; l < nlinhas; l++)
		{
			for (int c = 0; c < ncolunas; c++)
			{
				printComplex(sub1[l][c]);
			}
        printf("\n");
	}
	
	printf("\n======================Teste do Produto Interno======================\n");
	complexo **c13, **c14;
    int colunasvetor=1;
    c13 = allocateComplexMatrix(nlinhas, colunasvetor);
    c14 = allocateComplexMatrix(nlinhas, colunasvetor);
	
    for (int l=0; l<nlinhas; l++)
    {
        c13[l][0].real=2*l-3;
        c13[l][0].img=3*l+4;
        c14[l][0].real=4*l-5;
        c14[l][0].img=5*l+6;
    }
   
    printf("\nOperando A:\n");
    for (int l=0; l<nlinhas; l++)
    {
        printComplex(c13[l][0]);
        printf("\n");
    }
    printf("\nOperando B:\n");
    for (int l=0; l<nlinhas; l++)
    {
        printComplex(c14[l][0]);
        printf("\n");
    }
    printf("\nResultado:\n");
    printComplex(produto_interno(c13,c14,nlinhas,colunasvetor));
	printf("\n");


	printf("\n===============================Teste da operação Produto Matricial===========================\n");

	complexo **mtx_7, **mtx_8, **mtx_produto;
	
	int nlinhas_7 = 3, ncolunas_7 = 3, nlinhas_8 = 3, ncolunas_8 = 3;
	
	//Alocação de memória.
	mtx_7 = allocateComplexMatrix(nlinhas_7, ncolunas_7);
	mtx_8 = allocateComplexMatrix(nlinhas_8, ncolunas_8);

	//Preenchimento das matrizes operandas.
	for (int l = 0; l < nlinhas_7; l++)
	{
		for (int c = 0; c < ncolunas_7; c++)
		{
 			mtx_7[l][c].real = 1 + l;
			mtx_7[l][c].img = 1 + c;
		}
	}

	for (int l = 0; l < nlinhas_8; l++)
	{
		for (int c = 0; c < ncolunas_8; c++)
		{
			mtx_8[l][c].real = 0;
			mtx_8[l][c].img = 1 + c;
		}
	}
	//Impressão dos Operandos:
	printf("\nOperando A:\n");
	//Impressão da matriz A.
	for (int l = 0 ; l < nlinhas_7; l++)
	{
		for (int c = 0; c < ncolunas_7; c++)
		{
			printComplex(mtx_7[l][c]);
		}
        printf("\n");
	}
	
	printf("\nOperando B:\n");
	//Impressão da matriz B.
	for (int l = 0 ; l < nlinhas_8; l++)
	{
		for (int c = 0; c < ncolunas_8; c++)
		{
			printComplex(mtx_8[l][c]);
		}
        printf("\n");
	}
	//Chamada da função produto_matricial
	mtx_produto = produto_matricial(mtx_7, mtx_8, ncolunas_7, nlinhas_8);
	//Impressão do resultado
	printf("\nResultado:\n");

	for (int l = 0 ; l < nlinhas_7; l++)
	{
		for (int c = 0; c < ncolunas_8; c++)
		{
			printComplex(mtx_produto[l][c]);
		}
        printf("\n");
	}

	//Finalização do teste Hermetiano.
	printf("\n===============================Teste Multiplicação por um escalar===============================\n");
	complexo **mtx_12, **mtx_k12;
	int k = 5;
	//Alocação de memória.
	mtx_12 = allocateComplexMatrix(nlinhas, ncolunas);


	for (int l = 0; l < nlinhas; l++)
	{
		for (int c = 0; c < ncolunas; c++)
		{
			mtx_12[l][c].real = 1 + l + c;
			mtx_12[l][c].img = l*c - 2;
		}
	}
	//Impressão da Matriz A.
	printf("\nOperando A:\n");

	for (int l = 0; l < nlinhas; l++)
	{
		for (int c = 0; c < ncolunas; c++)
		{
			printComplex(mtx_12[l][c]);
		}
		printf("\n");
	}
	
	printf("\nOperando k = %d\n",k);
	//Chamada da função produto_por_escalar.
	mtx_k12 = produto_por_escalar(mtx_12, nlinhas, ncolunas, k); 
	//Impressão do resultado.
	printf("\nResultado de %d*A:\n",k);

	for (int l = 0; l < nlinhas; l++)
	{
		for (int c = 0; c < ncolunas; c++)
		{
			printComplex(mtx_k12[l][c]);
		}
		printf("\n");
	}
}
/**###Função Transporta: 
 * Calcula a matriz transposta de uma matriz A de n linhas e m colunas.
 * @param[in] mtx, linhas, colunas
 * @param[out] mtx_transposta
 * */
complexo **transposta(complexo** mtx,int linhas, int colunas)
{
        complexo** matriz;

        matriz = allocateComplexMatrix(colunas,linhas);
        for (int l = 0; l < linhas; l++)
		{
			for (int c = 0; c < colunas; c++)
			{
				matriz[l][c].real = mtx[c][l].real;
                matriz[l][c].img = mtx[c][l].img;
			}
		}
    return matriz;
}
/**###Função Conjugada:
 * Calcula a matriz conjugada de uma matriz A de n linhas e m colunas.
 * @param[in] mtx, linhas, colunas
 * @param[out] mtx_conjugada
 * */
complexo **conjugada(complexo **mtx, int linhas, int colunas) 
{
    complexo ** matrix;
    //alocação da matriz 
    matrix = allocateComplexMatrix (linhas, colunas);

    for (int l = 0; l < linhas; l++)
    {
        for (int c = 0; c < colunas; c++)
        {
            matrix[l][c].real = mtx[l][c].real;
            matrix[l][c].img = -mtx[l][c].img;
        }
    }

    return matrix;
}
//Função Hermitiana.
complexo **hermitiana(complexo** mtx, int linhas, int colunas)
{
    complexo **matriz, **matriz_h;

    matriz = allocateComplexMatrix(linhas, colunas);
    matriz_h = allocateComplexMatrix(linhas, colunas);

    matriz = conjugada(mtx, linhas, colunas);
    matriz_h = transposta(matriz, linhas, colunas);

    return matriz_h;
}
//Função Soma.
complexo **soma(complexo** mtx_a, complexo** mtx_b, int linhas, int colunas)
{
	complexo** matriz;
	
	matriz = allocateComplexMatrix(linhas,colunas);
		for (int l = 0; l < linhas; l++)
		{
			for (int c = 0; c < colunas; c++)
			{
				matriz[l][c].real = mtx_a[l][c].real + mtx_b[l][c].real;
                matriz[l][c].img = mtx_a[l][c].img + mtx_b[l][c].img;
			}
		}
	return matriz;
}
//Função Subtração.
complexo **subtracao(complexo** mtx_a, complexo** mtx_b, int linhas, int colunas)
{
	complexo** matriz;
	
	matriz = allocateComplexMatrix(linhas,colunas);
		for (int l = 0; l < linhas; l++)
		{
			for (int c = 0; c < colunas; c++)
			{
				matriz[l][c].real = mtx_a[l][c].real - mtx_b[l][c].real;
                matriz[l][c].img = mtx_a[l][c].img - mtx_b[l][c].img;
			}
		}
	return matriz;
}
//Função Produto Interno.
complexo produto_interno(complexo **v1, complexo **v2, int linhas, int colunas)
{
    complexo resultado = {0, 0};
    if(colunas != 1)
	{
		printf("\nErro: O produto não pode ser realizado (incompatibilidade entre vetores)\n");
		exit(1);
	}
    
    for (int l = 0; l< linhas; l++)
    {
        complexo temp = multcomp(v1[l][0], v2[l][0]);
        resultado = soma_complexo(resultado, temp);
    }

    return resultado;

}
//Função Multiplicação Matricial.
complexo **produto_matricial(complexo** mtx_a, complexo **mtx_b, int linhas, int colunas)  
{
	//Validação da operação de multiplicação (colunas_a == linhas_b).
	if(linhas != colunas)
	{
		printf("\nErro: O produto não pode ser realizado (incompatibilidade entre matrizes)\n");
		exit(1);
	}
	//Declaração e alocação de memória.
	complexo** matriz;
	matriz = allocateComplexMatrix(linhas, colunas);
	//O número de linhas da matriz B - à direita - é usado como parâmento na função.
	int linhas_b = colunas;
	//Início da operação. Observer que é necessário um 'acumulador' para guardar o valor da soma dos produtos Aij x Bij que geram um termo Cij.
	for (int l = 0; l < linhas; l++)
	{
		for (int c = 0; c < colunas; c++)
		{
			complexo acumulador;
			acumulador.real = 0;
			acumulador.img = 0;
			for (int i = 0; i < linhas_b; i ++)
			{
				acumulador = soma_complexo(acumulador, multcomp(mtx_a[l][i],mtx_b[i][c]));
			}
			matriz[l][c].real = acumulador.real;
			matriz[l][c].img = acumulador.img;
		}
	}
	return matriz;
}

complexo** produto_por_escalar(complexo **mtx, int linhas, int colunas, int k)
{
	complexo **matriz;

	matriz = allocateComplexMatrix(linhas, colunas);

	for (int l = 0; l < linhas; l++)
	{
		for (int c = 0; c < colunas; c++)
		{
			matriz[l][c].real = k*mtx[l][c].real;
			matriz[l][c].img = k*mtx[l][c].img;
		}
	}
	return matriz;
}
//Teste da função Transposta.
void teste_transposta(void)
{
	complexo** c1,**c2,**c3,**c4;; //matriz complexa a ser transposta
	int nlinhas,ncolunas;
    nlinhas=3;
    ncolunas=3;
    //Alocação de memoria para a matriz:
    c1 = allocateComplexMatrix(nlinhas,ncolunas);
	printf("\n===============================Teste da operação Transposta======================\n");
	
        for (int l = 0; l < nlinhas; l++)
		{
			for (int c = 0; c < ncolunas; c++)
			{
				c1[l][c].real = (3*l)-c;
				c1[l][c].img = c+l;
			}
    }
        printf("\nOperando A:\n");
        for (int l =0 ; l < nlinhas; l++)
		{
			for (int c = 0; c < ncolunas; c++)
			{
				printComplex(c1[l][c]);
			}
        printf("\n");
    }
	int nlinhas_trans = ncolunas;
	int ncolunas_trans = nlinhas;
	
	printf("\nResultado R:\n");
    c2 = transposta(c1,nlinhas_trans,ncolunas_trans);
        for (int l =0 ; l < nlinhas_trans; l++)
		{
			for (int c = 0; c < ncolunas_trans; c++)
			{
				printComplex(c2[l][c]);
			}
        printf("\n");
		}
    //Alocação de memoria para a matriz:
    c3 = allocateComplexMatrix(nlinhas,ncolunas);
	
        for (int l = 0; l < nlinhas; l++)
		{
			for (int c = 0; c < ncolunas; c++)
			{
				c3[l][c].real = (3*l)+c;
				c3[l][c].img = -c+l;
			}
    }
        printf("\nOperando B:\n");
        for (int l =0 ; l < nlinhas; l++)
		{
			for (int c = 0; c < ncolunas; c++)
			{
				printComplex(c3[l][c]);
			}
        printf("\n");
    }
	
	printf("\nResultado R:\n");
    c4 = transposta(c3,nlinhas_trans,ncolunas_trans);
        for (int l =0 ; l < nlinhas_trans; l++)
		{
			for (int c = 0; c < ncolunas_trans; c++)
			{
				printComplex(c4[l][c]);
			}
        printf("\n");
		}
}
//Teste da função Conjugada.
void teste_conjugada(void) //Kauan (06.05.23)
{
	 printf("\n======================Teste da Operação Conjugada======================\n");
	complexo **mtx_a, **mtx_conj_a, **mtx_b, **mtx_conj_b, **mtx_c, **mtx_conj_c;

	int nlinhas = 3, ncolunas = 3;

	//Alocação de memória. 
	mtx_a = allocateComplexMatrix(nlinhas, ncolunas);
	mtx_b = allocateComplexMatrix(nlinhas, ncolunas);
	mtx_c = allocateComplexMatrix(nlinhas, ncolunas);

	//Preenchimento da(s) matriz(es).
	for (int l = 0; l < nlinhas; l++)
	{
		for (int c = 0; c < ncolunas; c++)
		{
			mtx_a[l][c].real = (1+l)*c;
			mtx_a[l][c].img = 4*l - 2*c;

			mtx_b[l][c].real = 2 + l +c; 
			mtx_b[l][c].img = l - 3*c;

			mtx_c[l][c].real = -2*l + 3*c;
			mtx_c[l][c].img = -l - 2*c;
		}
	}

	//Chamada da função conjugada.
	mtx_conj_a = conjugada(mtx_a, nlinhas, ncolunas);
	mtx_conj_b = conjugada(mtx_b, nlinhas, ncolunas);
	mtx_conj_c = conjugada(mtx_c, nlinhas, ncolunas);

	printf("\nOperando A:\n");
	//Impressão da Matriz A.
	for (int l = 0; l < nlinhas; l++)
	{
		for (int c = 0; c < ncolunas; c++)
		{
			printComplex(mtx_a[l][c]);
		}
		printf("\n");
	}
	printf("\nConjugada de A:\n");

	for (int l = 0; l < nlinhas; l++)
	{
		for (int c = 0; c < ncolunas; c++)
		{
			printComplex(mtx_conj_a[l][c]);
		}
		printf("\n");
	}
	printf("\nOperando B:\n");
	//Impressão da Matriz B.
		for (int l = 0; l < nlinhas; l++)
	{
		for (int c = 0; c < ncolunas; c++)
		{
			printComplex(mtx_b[l][c]);
		}
		printf("\n");
	}
	
	printf("\nConjugada de B:\n");

		for (int l = 0; l < nlinhas; l++)
	{
		for (int c = 0; c < ncolunas; c++)
		{
			printComplex(mtx_conj_b[l][c]);
		}
		printf("\n");
	}
	
	printf("\nOperando C:\n");
	//Impressão da Matriz C.
		for (int l = 0; l < nlinhas; l++)
	{
		for (int c = 0; c < ncolunas; c++)
		{
			printComplex(mtx_c[l][c]);
		}
		printf("\n");
	}

	printf("\nConjugada de C:\n");

			for (int l = 0; l < nlinhas; l++)
	{
		for (int c = 0; c < ncolunas; c++)
		{
			printComplex(mtx_conj_c[l][c]);
		}
		printf("\n");
	}
	//Finalização do teste.
}
//Teste da função Hermitiana.
void teste_hermitiana(void)
{
    complexo **mtx_a, **mtx_a_h, **mtx_b, **mtx_b_h, **mtx_c, **mtx_c_h;

    int nlinhas =3, ncolunas = 3;
	int nlinhas_trans = ncolunas;
	int ncolunas_trans = nlinhas;
	//Alocação de memória.
    mtx_a = allocateComplexMatrix(nlinhas, ncolunas);
	mtx_b = allocateComplexMatrix(nlinhas, ncolunas);
	mtx_c = allocateComplexMatrix(nlinhas, ncolunas);
	//Preenchimento da(s) matriz(es).
	printf("\n======================Teste da Operação hermitiana======================\n");
    for (int l = 0; l < ncolunas; l++)
    {
        for (int c = 0; c < ncolunas; c++)
        {
			//Matriz A.
            mtx_a[l][c].real = l + c;
            mtx_a[l][c].img = l - 2*c;
			//Matriz B.
			mtx_b[l][c].real = 1 + l - 3*c;
			mtx_b[l][c].img = 2*l + 4 - c;
			//Matriz C.
			mtx_c[l][c].real = l - 3*c;
			mtx_c[l][c].img = 1 - l + 2*c;
        }
    }
	//Chamada da função hermitiana.
    mtx_a_h = hermitiana(mtx_a, nlinhas, ncolunas);
	mtx_b_h = hermitiana(mtx_b, nlinhas, ncolunas);
	mtx_c_h = hermitiana(mtx_c, nlinhas, ncolunas);
	
	//Impressão da(s) matriz(es).
	printf("\nOperando A:\n");

    for (int l = 0 ; l < nlinhas; l++)
	{
		for (int c = 0; c < ncolunas; c++)
		{
			printComplex(mtx_a[l][c]);
		}
        printf("\n");
	}
	printf("\nMatriz hermitiana de A:\n");

    for (int l = 0 ; l < nlinhas_trans; l++)
	{
		for (int c = 0; c < ncolunas_trans; c++)
		{
			printComplex(mtx_a_h[l][c]);
		}
        printf("\n");
	}
	
	printf("\nOperando B:\n");

    for (int l = 0 ; l < nlinhas; l++)
	{
		for (int c = 0; c < ncolunas; c++)
		{
			printComplex(mtx_b[l][c]);
		}
        printf("\n");
	}
	
	printf("\nMatriz hermitiana de B:\n");

    for (int l = 0 ; l < nlinhas_trans; l++)
	{
		for (int c = 0; c < ncolunas_trans; c++)
		{
			printComplex(mtx_b_h[l][c]);
		}
        printf("\n");
	}
	
	printf("\nOperando C:\n");

    for (int l = 0 ; l < nlinhas; l++)
	{
		for (int c = 0; c < ncolunas; c++)
		{
			printComplex(mtx_c[l][c]);
		}
        printf("\n");
	}	

	printf("\nMatriz hermitiana de C:\n");

    for (int l = 0 ; l < nlinhas_trans; l++)
	{
		for (int c = 0; c < ncolunas_trans; c++)
		{
			printComplex(mtx_c_h[l][c]);
		}
        printf("\n");
	}
	//Fim do teste da função hermitiana.
}
//Teste da função Soma.
void teste_soma(void)
{	

	complexo **c1,**c2,**somado1,**c3,**c4,**somado2;
	int nlinhas,ncolunas;
    nlinhas=3;
    ncolunas=3;
    //Alocação de memoria para a matriz:
    c3 = allocateComplexMatrix(nlinhas,ncolunas);
	c4 = allocateComplexMatrix(nlinhas,ncolunas);
	 for (int l = 0; l < nlinhas; l++)
		{
			for (int c = 0; c < ncolunas; c++)
			{
				c3[l][c].real = l+1;
				c3[l][c].img = (2*l)-c;
				c4[l][c].real = (5*l)+c;
				c4[l][c].img = l-c;
			}
    }
	printf("\n\n===============================Teste da operação Soma===========================\n");
	printf("\nOperando A:\n");
		for (int l =0 ; l < nlinhas; l++)
		{
				for (int c = 0; c < ncolunas; c++)
				{
					printComplex(c3[l][c]);
				}
			printf("\n");
		}
	printf("\nOperando B:\n");
		for (int l =0 ; l < nlinhas; l++)
			{
				for (int c = 0; c < ncolunas; c++)
				{
					printComplex(c4[l][c]);
				}
			printf("\n");
		}
	printf("\nResultado:\n");
	somado1 = soma(c3,c4,nlinhas,ncolunas);
	for (int l =0 ; l < nlinhas; l++)
		{
			for (int c = 0; c < ncolunas; c++)
			{
				printComplex(somado1[l][c]);
			}
        printf("\n");
	}
	c1 = allocateComplexMatrix(nlinhas,ncolunas);
	c2 = allocateComplexMatrix(nlinhas,ncolunas);
	 for (int l = 0; l < nlinhas; l++)
		{
			for (int c = 0; c < ncolunas; c++)
			{
				c1[l][c].real = l-2;
				c1[l][c].img = (2*l)+c;
				c2[l][c].real = (5*l)-c;
				c2[l][c].img = -l-c;
			}
    }
	printf("\nOperando C:\n");
		for (int l =0 ; l < nlinhas; l++)
		{
				for (int c = 0; c < ncolunas; c++)
				{
					printComplex(c1[l][c]);
				}
			printf("\n");
		}
	printf("\nOperando D:\n");
		for (int l =0 ; l < nlinhas; l++)
			{
				for (int c = 0; c < ncolunas; c++)
				{
					printComplex(c2[l][c]);
				}
			printf("\n");
		}
	printf("\nResultado:\n");
	somado2 = soma(c3,c4,nlinhas,ncolunas);
	for (int l =0 ; l < nlinhas; l++)
		{
			for (int c = 0; c < ncolunas; c++)
			{
				printComplex(somado2[l][c]);
			}
        printf("\n");
	}	
}
//Teste da função Subtração.
void teste_subtracao(void)
{
	complexo **c1,**c2,**sub1,**c3,**c4,**sub2;
	int nlinhas,ncolunas;
    nlinhas=3;
    ncolunas=3;
    //Alocação de memoria para a matriz:
    c1 = allocateComplexMatrix(nlinhas,ncolunas);
	c2 = allocateComplexMatrix(nlinhas,ncolunas);
	 for (int l = 0; l < nlinhas; l++)
		{
			for (int c = 0; c < ncolunas; c++)
			{
				c1[l][c].real = l+1;
				c1[l][c].img = (2*l)-c;
				c2[l][c].real = (5*l)+c;
				c2[l][c].img = l-c;
			}
    }
	printf("\n\n===============================Teste da operação Subtracao===========================\n");
	printf("\nOperando A:\n");
		for (int l =0 ; l < nlinhas; l++)
		{
				for (int c = 0; c < ncolunas; c++)
				{
					printComplex(c1[l][c]);
				}
			printf("\n");
		}
	printf("\nOperando B:\n");
		for (int l =0 ; l < nlinhas; l++)
			{
				for (int c = 0; c < ncolunas; c++)
				{
					printComplex(c2[l][c]);
				}
			printf("\n");
		}
	printf("\nResultado:\n");
	sub1 = subtracao(c1,c2,nlinhas,ncolunas);
	for (int l =0 ; l < nlinhas; l++)
		{
			for (int c = 0; c < ncolunas; c++)
			{
				printComplex(sub1[l][c]);
			}
        printf("\n");
	}
	c3 = allocateComplexMatrix(nlinhas,ncolunas);
	c4 = allocateComplexMatrix(nlinhas,ncolunas);
	 for (int l = 0; l < nlinhas; l++)
		{
			for (int c = 0; c < ncolunas; c++)
			{
				c3[l][c].real = l-2;
				c3[l][c].img = (2*l)+c;
				c4[l][c].real = (5*l)-c;
				c4[l][c].img = -l-c;
			}
    }
	printf("\nOperando C:\n");
		for (int l =0 ; l < nlinhas; l++)
		{
				for (int c = 0; c < ncolunas; c++)
				{
					printComplex(c3[l][c]);
				}
			printf("\n");
		}
	printf("\nOperando D:\n");
		for (int l =0 ; l < nlinhas; l++)
			{
				for (int c = 0; c < ncolunas; c++)
				{
					printComplex(c4[l][c]);
				}
			printf("\n");
		}
	printf("\nResultado:\n");
	sub2 = subtracao(c3,c4,nlinhas,ncolunas);
	for (int l =0 ; l < nlinhas; l++)
		{
			for (int c = 0; c < ncolunas; c++)
			{
				printComplex(sub2[l][c]);
			}
        printf("\n");
	}	
}
//Teste da função Produto Interno.
void teste_produto_interno(void)
{
    complexo **v1, **v2,**v3,**v4;
    int linhas=3;
    int colunas=1;
    v1 = allocateComplexMatrix(linhas, colunas);
    v2 = allocateComplexMatrix(linhas, colunas);
    for (int l=0; l<linhas; l++)
    {
        v1[l][0].real=3*l+2;
        v1[l][0].img=2*l+4;
        v2[l][0].real=3*l+1;
        v2[l][0].img=2*l-3;
    }
    printf("\n======================Teste do Produto Interno======================\n");
    printf("\nOperando A:\n");
    for (int l=0; l<linhas; l++)
    {
        printComplex(v1[l][0]);
        printf("\n");
    }
    printf("\nOperando B:\n");
    for (int l=0; l<linhas; l++)
    {
        printComplex(v2[l][0]);
        printf("\n");
    }
    printf("\nResultado:\n");
    printComplex(produto_interno(v1,v2,linhas,colunas));
	printf("\n");
    
    v3 = allocateComplexMatrix(linhas, colunas);
    v4 = allocateComplexMatrix(linhas, colunas);
    for (int l=0; l<linhas; l++)
    {
        v3[l][0].real=-2-l;
        v3[l][0].img=2*l-12;
        v4[l][0].real=3*l+7;
        v4[l][0].img=2*l-4;
    }
    printf("\nOperando C:\n");
    for (int l=0; l<linhas; l++)
    {
        printComplex(v3[l][0]);
        printf("\n");
    }
    printf("\nOperando D:\n");
    for (int l=0; l<linhas; l++)
    {
        printComplex(v4[l][0]);
        printf("\n");
    }
    printf("\nResultado:\n");
    printComplex(produto_interno(v3,v4,linhas,colunas));

}
//Teste da função Produto Matricial.
void teste_produto_matricial(void)
{	
	printf("\n===============================Teste da operação Produto Matricial===========================\n");
	complexo **mtx_a, **mtx_b, **mtx_produto_axb, **mtx_c, **mtx_d, **mtx_produto_cxd, **mtx_e, **mtx_f, **mtx_produto_exf;
	
	int nlinhas_1 = 3, ncolunas_1 = 3, nlinhas_2 = 3, ncolunas_2 = 3;
	
	//Alocação de memória.
	mtx_a = allocateComplexMatrix(nlinhas_1, ncolunas_1);
	mtx_c = allocateComplexMatrix(nlinhas_1, ncolunas_1);
	mtx_e = allocateComplexMatrix(nlinhas_1, ncolunas_1);
	mtx_b = allocateComplexMatrix(nlinhas_2, ncolunas_2);
	mtx_d = allocateComplexMatrix(nlinhas_2, ncolunas_2);
	mtx_f = allocateComplexMatrix(nlinhas_2, ncolunas_2);

	//Preenchimento das matrizes operandas.
	//Matriz A.
	for (int l = 0; l < nlinhas_1; l++)
	{
		for (int c = 0; c < ncolunas_1; c++)
		{
 			mtx_a[l][c].real = 1 + l;
			mtx_a[l][c].img = 1 + c;
		}
	}
	//Matriz B.
	for (int l = 0; l < nlinhas_2; l++)
	{
		for (int c = 0; c < ncolunas_2; c++)
		{
			mtx_b[l][c].real = 0;
			mtx_b[l][c].img = 1 + c;
		}
	}
	//Matriz C.
	for (int l = 0; l < nlinhas_1; l++)
	{
		for (int c = 0; c < ncolunas_1; c++)
		{
 			mtx_c[l][c].real = 1 + 2*l;
			mtx_c[l][c].img = 1 - 2*c;
		}
	}
	//Matriz D.
	for (int l = 0; l < nlinhas_2; l++)
	{
		for (int c = 0; c < ncolunas_2; c++)
		{
			mtx_d[l][c].real = l - c;
			mtx_d[l][c].img = -1 - c;
		}
	}
	//Matriz E.
	for (int l = 0; l < nlinhas_1; l++)
	{
		for (int c = 0; c < ncolunas_1; c++)
		{
 			mtx_e[l][c].real = 2 + l;
			mtx_e[l][c].img = c - 2;
		}
	}
	//Matriz F.
	for (int l = 0; l < nlinhas_2; l++)
	{
		for (int c = 0; c < ncolunas_2; c++)
		{
			mtx_f[l][c].real = 2 + c - l;
			mtx_f[l][c].img = c*l;
		}
	}
	//Primeira Operação.
	
	//Impressão dos Operandos:
	printf("\n\nOperando A:\n");
	//Impressão da matriz A.
	for (int l = 0 ; l < nlinhas_1; l++)
	{
		for (int c = 0; c < ncolunas_1; c++)
		{
			printComplex(mtx_a[l][c]);
		}
        printf("\n");
	}
	
	printf("\n\nOperando B:\n");
	//Impressão da matriz B.
	for (int l = 0 ; l < nlinhas_2; l++)
	{
		for (int c = 0; c < ncolunas_2; c++)
		{
			printComplex(mtx_b[l][c]);
		}
        printf("\n");
	}
	//Chamada da função produto_matricial.
	mtx_produto_axb = produto_matricial(mtx_a, mtx_b, ncolunas_1, nlinhas_2);
	//Impressão do resultado.
	printf("\n\nResultado A x B:\n");

	for (int l = 0 ; l < ncolunas_1; l++)
	{
		for (int c = 0; c < nlinhas_2; c++)
		{
			printComplex(mtx_produto_axb[l][c]);
		}
        printf("\n");
	}

	//Segunda Operação.
	
	//Impressão dos Operandos:
	printf("\n\nOperando C:\n");
	//Impressão da matriz C.
	for (int l = 0 ; l < nlinhas_1; l++)
	{
		for (int c = 0; c < ncolunas_1; c++)
		{
			printComplex(mtx_c[l][c]);
		}
        printf("\n");
	}
	
	printf("\n\nOperando D:\n");
	//Impressão da matriz D.
	for (int l = 0 ; l < nlinhas_2; l++)
	{
		for (int c = 0; c < ncolunas_2; c++)
		{
			printComplex(mtx_d[l][c]);
		}
        printf("\n");
	}
	//Chamada da função produto_matricial
	mtx_produto_cxd = produto_matricial(mtx_c, mtx_d, ncolunas_1, nlinhas_2);
	//Impressão do resultado
	printf("\n\nResultado C x D:\n");

	for (int l = 0 ; l < ncolunas_1; l++)
	{
		for (int c = 0; c < nlinhas_2; c++)
		{
			printComplex(mtx_produto_cxd[l][c]);
		}
        printf("\n");
	}

	//Terceira Operação.

	//Impressão dos Operandos:
	printf("\n\nOperando E:\n");
	//Impressão da matriz E.
	for (int l = 0 ; l < nlinhas_1; l++)
	{
		for (int c = 0; c < ncolunas_1; c++)
		{
			printComplex(mtx_e[l][c]);
		}
        printf("\n");
	}
	
	printf("\n\nOperando F:\n");
	//Impressão da matriz F.
	for (int l = 0 ; l < nlinhas_2; l++)
	{
		for (int c = 0; c < ncolunas_2; c++)
		{
			printComplex(mtx_f[l][c]);
		}
        printf("\n");
	}
	//Chamada da função produto_matricial.
	mtx_produto_exf = produto_matricial(mtx_e, mtx_f, ncolunas_1, nlinhas_2);
	//Impressão do resultado.
	printf("\n\nResultado E x F:\n");

	for (int l = 0 ; l < ncolunas_1; l++)
	{
		for (int c = 0; c < nlinhas_2; c++)
		{
			printComplex(mtx_produto_exf[l][c]);
		}
        printf("\n");
	}
}
//Função: Impressão de um número complexo.
void printComplex(complexo c)
{
    printf("%+.2f %+.2fj ", c.real, c.img);
}
//Função: Alocação de memória para uma matriz complexa.
complexo **allocateComplexMatrix (int linhas, int colunas)
{
    //Declaração.
    complexo** matrix;
	//Alocação das linhas.
    matrix = (complexo **) malloc(linhas*sizeof(complexo*));
	
    if (matrix == NULL)
    {
        printf("Memory alocation failed.");
        exit(1);
    }
    //Alocação de memória para cada linha da matriz
    for (int i = 0; i < linhas; i++)
    {
        matrix[i] = (complexo *) malloc(colunas*sizeof(complexo));
        if (matrix[i] == NULL)
        {
            printf("Memory allocation failed\n");
            exit(1);
        }
    }

    return matrix;
}
//Função: Soma de dois complexos.
complexo soma_complexo(complexo c1, complexo c2)
{
	complexo soma;
	soma.real = c1.real + c2.real;
	soma.img = c1.img + c2.img;
	return soma;
}
//Função: Multiplicação de dois complexos.
complexo multcomp(complexo c1, complexo c2)
{
	complexo multiplicado;
	multiplicado.real = (c1.real*c2.real)-(c1.img*c2.img);
	multiplicado.img = (c1.real*c2.img)+(c1.img*c2.real);
	return multiplicado;
}