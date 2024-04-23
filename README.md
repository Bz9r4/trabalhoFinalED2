# 3 Avaliação Laboratorio de estruturas 2
# Autores:
Brendo Duarte Bezerra, Guilheme Nunes Araujo, Carlos Henryque de Andrade Soares

Analise o arquivo gerado pela execução do comando anteiror (dados_grafos.txt), armazene o grafo em uma estrutura de matriz. Após isto, responda corretamente,
em função do grafo produzido a partir de dados_grafo.txt, as questões seguintes ou NA (Não se aplica) quando for necessário:

---

# Documentação do Código

## 1. Introdução
Este programa em C lê uma matriz de um arquivo, realiza diversas operações sobre ela e escreve os resultados em arquivos.

## 2. Estrutura do Código
A estrutura do código pode ser dividida em 7 partes principais:

### 2.1. Inclusão de Bibliotecas 
bibliotecas padrão de entrada e saída e as bibliotecas padrão de alocação de memória.

### 2.2. Definição do tamanho da matriz
Define o tamanho da matriz como 3151. Isso é utilizado em todo o código para definir os limites das iterações e alocar espaço.

### 2.3. Prototipo das funções
Todos os protótipos das funções utilizadas no programa são definidos

### 2.4. Implementação da função principal
 função principal do programa. Ela executa as seguintes operações:

- Aloca memória para as matrizes e vetores necessários.
- Lê a matriz de um arquivo.
- Calcula os graus de cada vértice e identifica os vértices isolados.
- Escreve os graus dos vértices em um arquivo.
- Encontra vértices isolados.
- Verifica a existência de vértice sumidouro.
- Verifica a existência de vértice fonte.
- Calcula o grau de emissão e recepção de cada vértice.
- Escreve o grau de emissão e recepção em um arquivo.
- Calcula o grafo complementar.
- Escreve o grafo gerador em um arquivo.
- Verifica a conexão entre o primeiro e o último vértice.
- Escreve o grafo complementar em um arquivo.
- Libera a memória alocada.

## 3. Problemas no Desenvolvimento

Durante o desenvolvimento do código, foram identificados alguns problemas e foram implementadas soluções para corrigi-los:

- Invez de ler o grafo por vetores, passamos a ler o mesmo por matriz, linha por linha, da outra forma sempre que executavamos o programa ele dava erros de memoria, erros de segmentação.


## 5. Conclusão
Portanto concluimos que este sem duvida foi nosso maior desafio nesta disciplina, trabalhar com grafos e matrizes tão grandes certamente são desafios supreendentes.
---
<p align="center"><img src="http://img.shields.io/static/v1?label=STATUS&message=%20CONCLUIDO&color=GREEN&style=for-the-badge"/></p>
