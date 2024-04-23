#include <stdio.h>
#include <stdlib.h>

// Definindo o tamanho da matriz
#define tamanho_matriz 3151

// Protótipos das funções
void ler_arquivo(char *nome_arquivo, int **matriz);
void calcular_graus(int **matriz, int *graus, int *isolados);
void escrever_graus_no_arquivo(int *graus, int *isolados);
int verificar_vertice_sumidouro(int **matriz);
int verificar_vertice_fonte(int **matriz);
void calcular_grau_emissao_recepcao(int **matriz, int *emissao, int *recepcao);
void escrever_grau_emissao_recepcao_arquivo(int *emissao, int *recepcao);
void encontrar_vertices_isolados(int *isolados);
void calcular_complementar(int **matriz, int **complementar);
void escrever_grafo_gerador(int **matriz);
int verificar_conexao(int **matriz);

// Função principal
int main() {
    // Alocando memória para as matrizes e vetores necessários
    int **matriz = (int **)malloc(tamanho_matriz * sizeof(int *));
    int **complementar = (int **)malloc(tamanho_matriz * sizeof(int *));
    int *graus = (int *)malloc(tamanho_matriz * sizeof(int));
    int *isolados = (int *)malloc(tamanho_matriz * sizeof(int));
    int *emissao = (int *)malloc(tamanho_matriz * sizeof(int));
    int *recepcao = (int *)malloc(tamanho_matriz * sizeof(int));
    int i, j;

    // Alocando memória para cada linha da matriz e inicializando o vetor de vértices isolados
    for (i = 0; i < tamanho_matriz; i++) {
        matriz[i] = (int *)malloc(tamanho_matriz * sizeof(int));
        complementar[i] = (int *)malloc(tamanho_matriz * sizeof(int));
        isolados[i] = 0;
    }

    // Lendo a matriz de um arquivo
    ler_arquivo("dados_matriz.txt", matriz);

    // Calculando os graus de cada vértice e identificando vértices isolados
    calcular_graus(matriz, graus, isolados);

    // Escrevendo os graus dos vértices no arquivo
    escrever_graus_no_arquivo(graus, isolados);

    // Encontrando vértices isolados
    encontrar_vertices_isolados(isolados);

    // Verificando a existência de vértice sumidouro
    int sumidouro = verificar_vertice_sumidouro(matriz);
    if (sumidouro != -1) {
        printf("Vertice sumidouro encontrado: %d\n", sumidouro);
    } else {
        printf("Nenhum vertice sumidouro encontrado.\n");
    }

    // Verificando a existência de vértice fonte
    int fonte = verificar_vertice_fonte(matriz);
    if (fonte != -1) {
        printf("Vertice fonte encontrado: %d\n", fonte);
    } else {
        printf("Nenhum vertice fonte encontrado.\n");
    }

    // Calculando grau de emissão e recepção de cada vértice
    calcular_grau_emissao_recepcao(matriz, emissao, recepcao);

    // Escrevendo o grau de emissão e recepção no arquivo
    escrever_grau_emissao_recepcao_arquivo(emissao, recepcao);
    
    // Calculando o grafo complementar
    calcular_complementar(matriz, complementar);

    // Escrevendo o grafo gerador
    escrever_grafo_gerador(matriz);

    // Verificando a conexão entre o primeiro e o último vértice
    int conexao = verificar_conexao(matriz);
    if (conexao == 1) {
        printf("Primeiro e último vértice conectados.\n");
    } else {
        printf("Primeiro e último vértice não estão conectados.\n");
    }

    // Escrevendo o grafo complementar no arquivo
    FILE *complementar_arquivo;
    complementar_arquivo = fopen("dados_grafo_complementar.txt", "w");

    if (complementar_arquivo == NULL) {
        printf("Erro ao abrir o arquivo dados_grafo_complementar.txt\n");
        exit(1);
    }

    for (i = 0; i < tamanho_matriz; i++) {
        for (j = 0; j < tamanho_matriz; j++) {
            fprintf(complementar_arquivo, "%d ", complementar[i][j]);
        }
        fprintf(complementar_arquivo, "\n");
    }

    fclose(complementar_arquivo);

    // Liberando a memória alocada
    for (i = 0; i < tamanho_matriz; i++) {
        free(matriz[i]);
        free(complementar[i]);
    }
    free(matriz);
    free(complementar);
    free(graus);
    free(isolados);
    free(emissao);
    free(recepcao);

    return 0;
}

// Função para ler a matriz de um arquivo
void ler_arquivo(char *nome_arquivo, int **matriz) {
    FILE *arquivo;
    int i, j;

    arquivo = fopen(nome_arquivo, "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo %s\n", nome_arquivo);
        for (int k = 0; k < tamanho_matriz; k++) {
            free(matriz[k]);
        }
        free(matriz);
        exit(1);
    }

    for (i = 0; i < tamanho_matriz; i++) {
        for (j = 0; j < tamanho_matriz; j++) {
            if (fscanf(arquivo, "%d", &matriz[i][j]) != 1) {
                printf("Erro ao ler o arquivo %s\n", nome_arquivo);
                for (int k = 0; k < tamanho_matriz; k++) {
                    free(matriz[k]);
                }
                free(matriz);
                exit(1);
            }
        }
    }

    fclose(arquivo);
}

// Função para calcular os graus de cada vértice e identificar os vértices isolados
void calcular_graus(int **matriz, int *graus, int *isolados) {
    int i, j;

    for (i = 0; i < tamanho_matriz; i++) {
        graus[i] = 0;
        for (j = 0; j < tamanho_matriz; j++) {
            graus[i] += matriz[i][j];
        }
        if (graus[i] == 0) {
            isolados[i] = 1;
        }
    }
}

// Função para escrever os graus dos vértices no arquivo
void escrever_graus_no_arquivo(int *graus, int *isolados) {
    FILE *arquivo;
    int i;

    arquivo = fopen("dados_grafos_graus.txt", "w");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo dados_grafos_graus.txt\n");
        exit(1);
    }

    for (i = 0; i < tamanho_matriz; i++) {
        fprintf(arquivo, "%d %d\n", i, graus[i]);
        if (isolados[i] == 1) {
            fprintf(arquivo, "%d (isolado)\n", i);
        }
    }

    fclose(arquivo);
}

// Função para verificar se existe vértice sumidouro
int verificar_vertice_sumidouro(int **matriz) {
    int i, j;
    int sumidouro = -1;

    for (i = 0; i < tamanho_matriz; i++) {
        int soma_linha = 0;
        for (j = 0; j < tamanho_matriz; j++) {
            soma_linha += matriz[i][j];
        }
        if (soma_linha == 0) {
            sumidouro = i;
            break;
        }
    }

    return sumidouro;
}

// Função para verificar se existe vértice fonte
int verificar_vertice_fonte(int **matriz) {
    int i, j;
    int fonte = -1;

    for (j = 0; j < tamanho_matriz; j++) {
        int soma_coluna = 0;
        for (i = 0; i < tamanho_matriz; i++) {
            soma_coluna += matriz[i][j];
        }
        if (soma_coluna == 0) {
            fonte = j;
            break;
        }
    }

    return fonte;
}

// Função para calcular o grau de emissão e recepção de cada vértice
void calcular_grau_emissao_recepcao(int **matriz, int *emissao, int *recepcao) {
    int i, j;

    for (i = 0; i < tamanho_matriz; i++) {
        int grau_recepcao = 0;
        int grau_emissao = 0;
        for (j = 0; j < tamanho_matriz; j++) {
            grau_recepcao += matriz[j][i];
            grau_emissao += matriz[i][j];
        }
        recepcao[i] = grau_recepcao;
        emissao[i] = grau_emissao;
    }
}

// Função para escrever o grau de emissão e recepção de cada vértice no arquivo
void escrever_grau_emissao_recepcao_arquivo(int *emissao, int *recepcao) {
    FILE *emissao_arquivo, *recepcao_arquivo;
    int i;

    emissao_arquivo = fopen("dados_grafos_emissao.txt", "w");
    recepcao_arquivo = fopen("dados_grafos_recepcao.txt", "w");

    if (emissao_arquivo == NULL || recepcao_arquivo == NULL) {
        printf("Erro ao abrir os arquivos de emissão e recepção.\n");
        exit(1);
    }

    for (i = 0; i < tamanho_matriz; i++) {
        fprintf(emissao_arquivo, "%d %d\n", i, emissao[i]);
        fprintf(recepcao_arquivo, "%d %d\n", i, recepcao[i]);
    }

    fclose(emissao_arquivo);
    fclose(recepcao_arquivo);
}

// Função para encontrar os vértices isolados
void encontrar_vertices_isolados(int *isolados) {
    int i;
    int tem_isolado = 0;

    printf("Vértice(s) isolado(s):\n");
    for (i = 1; i < tamanho_matriz; i++) {
        if (isolados[i] == 1) {
            printf("%d\n", i);
            tem_isolado = 1;
        }
    }
    if (!tem_isolado) {
        printf("Não há vértices isolados.\n");
    }
}

// Função para calcular o grafo complementar
void calcular_complementar(int **matriz, int **complementar) {
    int i, j;

    for (i = 0; i < tamanho_matriz; i++) {
        for (j = 0; j < tamanho_matriz; j++) {
            complementar[i][j] = !matriz[i][j];
        }
    }
}

// Função para escrever o grafo gerador no arquivo
void escrever_grafo_gerador(int **matriz) {
    FILE *gerador_arquivo;
    int i, j;

    gerador_arquivo = fopen("dados_grafo_gerador.txt", "w");

    if (gerador_arquivo == NULL) {
        printf("Erro ao abrir o arquivo dados_grafo_gerador.txt\n");
        exit(1);
    }

    for (i = 0; i < tamanho_matriz; i++) {
        if (i % 5 == 0) {
            for (j = 0; j < tamanho_matriz; j++) {
                fprintf(gerador_arquivo, "%d ", matriz[i][j]);
            }
            fprintf(gerador_arquivo, "\n");
        }
    }

    fclose(gerador_arquivo);
}

// Função para verificar se o primeiro e o último vértice estão conectados
int verificar_conexao(int **matriz) {
    if (matriz[0][tamanho_matriz - 1] == 1)
        return 1;
    else
        return 0;
}
