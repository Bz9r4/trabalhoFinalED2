# 3 Avaliação Laboratorio de estruturas 2
# Autores:
Brendo Duarte Bezerra, Guilheme Nunes Araujo, Carlos Henryque de Andrade Soares

Analise o arquivo gerado pela execução do comando anteiror (dados_grafos.txt), armazene o grafo em uma estrutura de matriz. Após isto, responda corretamente,
em função do grafo produzido a partir de dados_grafo.txt, as questões seguintes ou NA (Não se aplica) quando for necessário:

---

# Questões:

O nosso grafo é Não direcional.

## 1: Qual(is) o vértice(s) com maior(es) grau?
   R: É o vertice 0 com grau 7892. Em "calcular_graus", o grau do vértice é encontrado adicionando valores nas linhas correspondentes da matriz de adjacência. O resultado é armazenado no vetor “graus”. Depois, o vetor "graus" é    usado para escrever graus de vértices em um arquivo.
   
## 2: Apresente em um arquivo chamado dados_grafos_graus,txt o número do vértices seguido pelo seu respectivo grau.
   R: O programa abre o arquivo "dados_grafos_graus.txt" no modo de gravação ("w"). Se o arquivo não puder ser aberto, uma mensagem de erro será exibida e o programa será encerrado. O programa passa sobre todos os vértices, escrevendo o número do vértice seguido do grau no arquivo.

## 3: Se existir, quais são os vértices isolados?
   R: Para nosso grafo não existe vertices isoladas. O vetor “isolado” é inicializado com zeros para indicar que nenhum vértice é inicialmente considerado isolado. Durante o cálculo do grau de cada vértice, é feita a soma dos valores nas linhas correspondentes da matriz de adjacência. Se o grau do vértice resultar em zero, isso significa que o vértice está isolado.

## 4: Existe um vértice sumidouro?
   R: Para nosso grafo não existe vertice sumidoura. A função verifica se a soma dos valores em cada linha da matriz de adjacência é igual a zero. Se verdadeiro, o índice da linha (que representa o número do vértice) é retornado como vértice do coletor encontrado. Caso contrário, o valor padrão -1 será retornado para indicar que nenhum vértice do coletor foi encontrado. Se o valor do coletor for diferente de -1, isso significa que um vértice do coletor foi encontrado e seu número será exibido. Caso contrário, será exibida a mensagem “Nenhum vértice de sumidouro encontrado”.

## 5: Existe um vértice fonte?
   R: Para nosso grafo não existe vertice fonte. A função verifica se a soma dos valores em cada coluna da matriz de adjacência é igual a zero. Se verdadeiro, o índice da coluna (que representa o número do vértice) é retornado como vértice de origem encontrado. Caso contrário, o valor padrão -1 será retornado para indicar que nenhum vértice de origem foi encontrado.

## 6: Determine o grau de Emissão e Recepção de cada vértice e os coloque em arquivos chamados de dados_grafos_emissao.txt e dados_grafos_recepcao.txt.
   R: Para calcular o grau de emissão de um vértice, o programa percorre cada linha da matriz de adjacência e soma os valores em cada linha. Esta soma representa o número de arestas que saem do vértice. Para calcular o grau de recepção de um vértice, o programa percorre cada coluna da matriz de adjacência e soma os valores em cada coluna. Esta soma representa o número de arestas que atingem o vértice.

## 7: Apresente um arquivo com o grafo complementar da questão;
   R: O programa passa por cada célula da matriz de adjacência do gráfico original e atribui valor complementar à célula correspondente na matriz do gráfico complementar, basicamente onde tem 0 vai virar 1 e onde tem 1 vai virar 0, você preenche todas arestas que faltavam para ter um grafo completo e remove todas as outras arestas que ja estavam lá.

## 12: Verifique se o primeiro e último vértice estão conectados.
    R: Não estão conectados. O programa verifica se o primeiro e o último vértice estão conectados, verificando se existe uma aresta entre esses dois vértices na matriz de adjacência do grafo. Se o valor na posição (0, tamanho_matriz- 1) for 1, isso significa que há uma aresta entre o primeiro e o último vértices. Se o valor for 1, o programa retornará 1, indicando que os vértices estão conectados. Caso contrário, retorna 0, indicando que não estão conectados.

---

# Documentação do Código

## 1. Introdução
Este programa em C lê uma matriz de um arquivo, realiza diversas operações sobre ela e escreve os resultados em arquivos.

## 2. Estrutura do Código

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
