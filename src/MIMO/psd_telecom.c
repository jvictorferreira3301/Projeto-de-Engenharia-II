#include <stdio.h>
#include <stdlib.h>
#include "../matrizes/matrizes.h"
#include <gsl/gsl_linalg.h>
#include <time.h>

int * tx_data_read(FILE *fp, long int numBytes){

    int *s = (int *)malloc(numBytes * 4 * sizeof(int));
    if (s == NULL) {
        printf("Erro na alocação de memória\n");
        fclose(fp);
        return (int *)1;
    }
    
    for (int i = 0; i < numBytes; i++) {
        char byte;
        fread(&byte, sizeof(byte), 1, fp);

        for (int j = 0; j <= 7; j=j+2) {
            int bit = (byte >> j) & 3;
            s[(i*4) + (j/2)]= bit;
        }
        
    }
    return s;
}
int * tx_data_pedding(int*s,long int numBytes, int Nstream){
    if(numBytes%Nstream==0){
        return s;
    }
    else{
        int *resized_s = (int*)realloc(s,((numBytes*4)+(numBytes%Nstream))*sizeof(int));

        for(long int i = numBytes*4; i<(numBytes*4)+(numBytes%Nstream); i++){
            resized_s[i]=0;
        }
        return s;
    }     
}


complexo* tx_qam_mapper(int *s, long int numBytes){
    complexo *c1 = (complexo *)malloc(numBytes * 4 * sizeof(complexo));   
    for(int i= 0; i<numBytes*4;i++){
        if(s[i]==0){
            c1[i].real = -1;
            c1[i].img = 1;
        }
        else if (s[i]==1){
            c1[i].real = -1;
            c1[i].img = -1;
        }
        else if (s[i]==2){
            c1[i].real = 1;
            c1[i].img = 1;
        }
        else {
            c1[i].real = 1;
            c1[i].img = -1;
        }
    }
    return c1;
}

/// @brief 
/// @param v 
/// @param Nstream 
/// @param numBytes 
/// @return Matriz complexa 
complexo ** tx_layer_mapper(complexo *v, int Nstream, long int numBytes){
    complexo **mtx_stream;
    mtx_stream = (complexo**) malloc(Nstream*numBytes*sizeof(complexo*));

    for(int i = 0; i < Nstream; i++){
        mtx_stream[i] = (complexo *) malloc(numBytes*Nstream*sizeof(complexo));
    }
    for (int i = 0; i < numBytes*4; i++){
        mtx_stream[i%Nstream][i/Nstream] = v[i];
    }
    return mtx_stream;
}

complexo* rx_layer_demapper(complexo** mtx_stream, int Nstream, long int numBytes) {
    complexo* v = (complexo*) malloc(numBytes * 4 * sizeof(complexo));
    if (v == NULL) {
        printf("Erro na alocação de memória.\n");
        return NULL;
    }

    for (int i = 0; i < numBytes * 4; i++) {
        v[i] = mtx_stream[i % Nstream][i / Nstream];
    }

    return v;
}

int* rx_qam_demapper(complexo * map, long int numBytes){

    int *vetor = (int *)malloc(numBytes * 4 * sizeof(int));
      if (vetor == NULL) {
        printf("Erro na alocação de memória\n");
        return (int *)1;
    }   
    for(int i= 0; i<numBytes*4;i++){
        if(map[i].real== -1 && map[i].img == 1){
            vetor[i]=0;
        }
        else if (map[i].real== -1 && map[i].img == -1){
            vetor[i]=1;
        }
        else if (map[i].real== 1 && map[i].img == 1){
            vetor[i]=2;
        }
        else {
            vetor[i]=3;
        }
    }
    return vetor;
}
void rx_data_write(int* s, long int numBytes, char* fileName) {
    FILE* out = fopen(fileName, "wb");
    if (out == NULL) {
        printf("Erro ao abrir o arquivo %s para escrita.\n", fileName);
        return;
    } else {
        printf("Arquivo %s criado com sucesso.\n", fileName);
    }

    for (int i = 0; i < numBytes; i++) {
        unsigned char byte = 0;
        for (int j = 0; j < 4; j++) {
            unsigned int bit = s[(i * 4) + j];
            byte |= (bit << (2 * j));
        }
        fwrite(&byte, sizeof(byte), 1, out);
    }

    fclose(out);
}


float ** channel_gen(int Nr, int Nt, float minValue, float maxValue){
    float** H;
	
    H = (float **) malloc(Nr*sizeof(float*));
	
    if (H == NULL)
    {
        printf("Memory alocation failed.");
        exit(1);
    }
    //Alocação de memória para cada linha da matriz
    for (int i = 0; i < Nr; i++)
    {
        H[i] = (float *) malloc(Nt*sizeof(float));
        if (H[i] == NULL)
        {
            printf("Memory allocation failed\n");
            exit(1);
        }
    }
    srand(time(NULL));
    for (int i = 0; i < Nr; i++) {
        for (int j = 0; j < Nt; j++) {
            H[i][j] = ((float)rand() / RAND_MAX) * (maxValue - minValue) + minValue;
        }
    }
    return H;
}



int main() {
    FILE* fp = fopen("teste", "w");

    if (fp == NULL) {
        printf("Erro ao abrir o arquivo\n");
        return 1;
    }

    // Solicitar ao usuário que escreva a mensagem
    printf("Digite a mensagem que quer enviar:\n");
    char mensagem[1000];
    fgets(mensagem, sizeof(mensagem), stdin);

    // Escrever a mensagem no arquivo
    fprintf(fp, "%s", mensagem);

    // Fechar o arquivo
    fclose(fp);

    // Abrir o arquivo para leitura em binario
    fp = fopen("teste", "rb");

    if (fp == NULL) {
        printf("Impossivel abrir o arquivo\n");
        return 1; // Encerra o programa se a abertura do arquivo falhar
    }

    printf("Arquivo criado com sucesso\n");
    fseek(fp, 0, SEEK_END);
    long int numBytes = ftell(fp);
    fseek(fp, 0, SEEK_SET);
    
    int Nr; // Número de antenas recpetoras
    int Nt; // Número de antenas transmissoras
    int num_teste = 16; // Numero de testes necessarios
    
    for(int teste = 1; teste<=num_teste; teste++){
        
        printf("\n=====================Teste %d===================\n\n", teste);
        
        if(teste<=4){
            Nr = 2;
            Nt = 4;
            
        }
        else if (teste>4 && teste<=8){
            Nr = 8;
            Nt = 8;
        }
        else if (teste>8 && teste<=12){
            Nr = 8;
            Nt = 32;
        }
        else if (teste>12 && teste <=16){
            Nr = 16;
            Nt = 32;
        }

        int Nstream = Nr;
        printf("Numero de antenas recpetoras: %d // Numero de antenas Transmissoras: %d // Numero de fluxos: %d\n",Nr,Nt,Nstream);
        // Leitura do arquivo
        printf("Realizando leitura do Arquivo...\n");
        int *s=tx_data_read(fp,numBytes);
        
        //Preenchimento por meio do data_pedding
        printf("Data pedding...\n");
        int *d=tx_data_pedding(s,numBytes,Nstream);

        // Mapeamento dos bits do arquivo
        printf("Realizando Mapeamento dos Bits do Arquivo...\n");
        complexo *map = tx_qam_mapper(d,numBytes);

        // Criação do Canal H com range entre -1 e 1
        printf("Criação do Canal de transferencia de Dados...\n");
        float ** H = channel_gen(Nr,Nt,-1,1);
        int ruido;
        if(teste == 1 || teste == 5 || teste == 9 || teste == 13){
            float **Rd=channel_gen(Nr,Nt,-1,1);
            ruido = 1;
        }
        else if(teste == 2 || teste == 6 || teste == 10 || teste == 14){
            float **Rd=channel_gen(Nr,Nt,-0.5,0.5);
            ruido = 2;
        }
        else if(teste == 3 || teste == 7 || teste == 11 || teste == 15){
            float **Rd=channel_gen(Nr,Nt,-0.1,0.1);
            ruido = 3;
        }
        else if(teste == 4 || teste == 8 || teste == 12 || teste == 16){
            float **Rd=channel_gen(Nr,Nt,-0.01,0.01);
            ruido = 4;
        }

        //Transformando o vetor complexo do mapaeamento para uma matriz complexa
        complexo **mtx= tx_layer_mapper(map, Nstream, numBytes);

        complexo *v=rx_layer_demapper(mtx,Nstream,numBytes);

        // Desmapeamento dos bits do arquivo
        printf("Realizando Desmapeamento dos Bits do Arquivo...\n");
        int *a=rx_qam_demapper(v,numBytes);

        // Leitura Final dos Dados
        printf("Salvando arquivo com a mensagem enviada no arquivo test_Nr%d_Nt%d_Rd%d\n",Nr,Nt,ruido);
        
        char fileName[100];
        sprintf(fileName, "Teste_Nr%d_Nt%d_Rd%d", Nr,Nt,ruido); // Formata o nome do arquivo com base no valor de i
        rx_data_write(s, numBytes, fileName);
    }

    fclose(fp);
    return 0;
}