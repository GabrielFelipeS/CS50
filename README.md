# CS50
Exercicios do CS50: Introduction to Computer Science

Os exercicios desse repositorio são retirados do curso de Harvard de introdução à ciência da computação- CS50

A pset1 ou semana 1 aborda conceitos de condicionais com desafios interessantes, como o cartão. </br>
Na pset2 ou semana 2 aborda conceitos de vetores e argc e argv. </br>
Na pset3 ou semana 3 aborda conceitos de algoritmo onde possui um dos exercicios mais dificieis do curso, o tideman </br>
Na pset4 ou semana 4 abortam conceitos de memoria, introduzindo o ponteiro </br>
Na pset5 ou semana 5 introduz conceitos de estrutura de dados </br>
 
# Exercicio cartão - Verificador de Cartões de Crédito - pset1

## Descrição

Este programa em C é um verificador simples de números de cartão de crédito. Ele aceita um número de cartão como entrada e determina se o número é válido ou inválido com base em algumas regras comuns associadas aos principais emissores de cartões de crédito.

```C
#include <cs50.h>
#include <stdio.h>

int *numero_para_array(int ptr[], long numero);
int multiplica_array(int ptr[]);
char *calcula_string (int ptr[]);

int main(void)
{
    int cont = 1;
    int digitos[64];
    long card = get_long("Insira o numero do cartão: ");
    if (card < 999999999999 || card > 9999999999999999)
    {
        printf("Invalido\n");
    }
    else
    {
        numero_para_array(digitos, card);
        printf("%s\n", calcula_string(digitos));
    }
}


char *calcula_string(int ptr[])
{
    if(ptr[0] >= 13 && ptr[0] <= 16 && multiplica_array(ptr) == 0)
    {
        if(ptr[ptr[0]] == 4 && (ptr[0] == 13 || ptr[0] == 16))
        {
            return "Visa";
        }
        if(ptr[0] == 15 && ptr[ptr[0]] == 3  && (ptr[ptr[0] - 1] == 4 || ptr[ptr[0] - 1] == 7 ))
        {
            return "America Express";
        }
        if(ptr[0] == 16 && ptr[ptr[0]] == 5  && (ptr[ptr[0] - 1] == 2 || ptr[ptr[0] - 1] == 3 || ptr[ptr[0] - 1] == 4 || ptr[ptr[0] - 1] == 5))
        {
            return "Mastercard";
        }
    }
    return "invald";
}

int *numero_para_array(int ptr[], long numero)
{
    int compr = 0;
    for (int i = 1; numero != 0; i++)
    {
        ptr[i] = numero % 10;
        numero /= 10;
        printf("%i\n%ld\n", ptr[i], numero);
        compr++;
    }

    ptr[0] = compr;
    return ptr;
}

int multiplica_array(int ptr[])
{
    char pular = 'n';
    int soma = 0;
    for (int i = 1;i <= ptr[0]; i++ )
    {
        if (pular == 'n')
        {
            soma += ptr[i];
            pular = 's';
        }
        else
        {
            int mult = ptr[i] * 2;
            if(mult < 10)
            {
                soma += mult;
            }
            else
            {
                while (mult !=0)
                {
                    soma += mult % 10;
                    mult /= 10;
                }
            }
            pular = 'n';
        }
    }
    return (soma % 10);
```


O código possui três funções principais:

1. **numero_para_array:** Converte um número de cartão longo em um array de dígitos, facilitando a manipulação.

2. **multiplica_array:** Realiza a multiplicação de alguns dos dígitos do cartão de acordo com as regras de validação comuns.

3. **calcula_string:** Analisa o array de dígitos resultante e determina o tipo de cartão (Visa, American Express, Mastercard) com base em algumas condições específicas.

## Uso

1. Compile o programa usando um compilador C. Por exemplo, no terminal, você pode usar `gcc`:

    ```bash
    gcc -o cartao cartao.c -lcs50
    ```

2. Execute o programa compilado:

    ```bash
    ./cartao
    ```

3. Insira o número do cartão quando solicitado e o programa indicará se o número do cartão é válido e, se for o caso, qual o tipo de cartão.


# Exercicio caesar - Criptografia de Cifra de César - pset2

```C
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <cs50.h>
#include <ctype.h>


int main(int argc, string argv[])
{
        // Mais de dois argumentos
        if(argc != 2)
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }

    // Verificação se é uma letra
    for(int i = 0; i <= strlen(argv[1]);i++)
    {
        if(isalpha(argv[1][i]))
        {
            printf("Usage: ./caesar key\n ");
            return 1;
        }

    }


        //Chave
        int key = atoi(argv[1])%26;
        // Verificação da chave
        if(key <= 0)
        {
            printf("Usage: ./caesar key\n ");
            return 1;
        }
        //voltar
        int voltar = 26 - key;

        //Pedido do Texto
        string text = get_string("plaintext: ");
        printf("ciphertext: ");

        //Converção ASCII
        int cifra;
        for(int i = 0; text[i] != '\0'; i++)
        {
            cifra = text[i];
            if(isalpha(text[i]))
            {
                if(isupper(text[i]))
                {
                    if(cifra + key > 'Z')
                    {
                        cifra -= key + voltar;
                    }
                    cifra += key;
                }

                //Verifica se é minuscula
                else if(islower(text[i]))
                {
                    if(cifra + key > 'z')
                    {
                        cifra -= key + voltar;
                    }
                    cifra += key;
                }
            }
            printf("%c", cifra);

        }
        printf("\n");
        return 0;
}
```
## Descrição

Este programa em C implementa uma cifra de César simples para criptografar mensagens de texto. A cifra de César é um tipo de cifra de substituição onde cada letra do texto é deslocada por um número fixo de posições no alfabeto.

O código tem as seguintes características:

- Aceita uma chave como argumento de linha de comando para determinar o deslocamento da cifra.
- Verifica se a chave é um número inteiro positivo válido.
- Solicita ao usuário um texto de entrada (plaintext).
- Criptografa o texto de entrada usando a cifra de César e exibe o texto cifrado (ciphertext).

## Uso

1. Compile o programa usando um compilador C. Por exemplo, no terminal, você pode usar `gcc`:

    ```bash
    gcc -o caesar caesar.c -lcs50
    ```

2. Execute o programa compilado, fornecendo a chave como argumento de linha de comando:

    ```bash
    ./caesar [chave]
    ```

   Substitua `[chave]` pelo número inteiro que representa o deslocamento da cifra.

3. Insira o texto de entrada (plaintext) quando solicitado, e o programa exibirá o texto cifrado (ciphertext).

## Exemplos

- Para criptografar o texto "HELLO" com uma chave de 3:

    ```bash
    ./caesar 3
    ```

    A saída será "KHOOR".

# Tideman - Sistema de Votação e Eleição - pset3

## Descrição

Este programa em C implementa um sistema de votação e eleição usando o método de votação de pares (Tideman). O programa aceita votos de eleitores e determina o vencedor da eleição com base nas preferências dos eleitores.

O código inclui as seguintes funcionalidades:

1. **Votação:**
   - Aceita votos de eleitores, permitindo que cada eleitor forneça suas preferências de classificação para os candidatos.

2. **Cálculo de Preferências:**
   - Calcula e armazena as preferências dos eleitores com base nos votos fornecidos.

3. **Geração de Pares:**
   - Gera pares de candidatos com base nas preferências dos eleitores, identificando os candidatos preferidos.

4. **Ordenação de Pares:**
   - Ordena os pares de candidatos em ordem decrescente com base na força da vitória.

5. **Bloqueio de Pares:**
   - Bloqueia os pares de candidatos na representação gráfica do grafo, evitando ciclos e determinando o vencedor da eleição.

6. **Anúncio do Vencedor:**
   - Exibe o candidato vencedor da eleição com base no método de votação de pares (Tideman).

## Funcionamento Interno

O código utiliza uma matriz para armazenar as preferências dos eleitores, gera pares de candidatos com base nessas preferências, bloqueia os pares para evitar ciclos e determina o vencedor com base no grafo resultante.

## Uso

1. Compile o programa usando um compilador C. Por exemplo, no terminal, você pode usar `gcc`:

    ```bash
    gcc -o tideman tideman.c -lcs50
    ```

2. Execute o programa compilado, fornecendo os candidatos como argumentos de linha de comando:

    ```bash
    ./tideman [candidato1] [candidato2] ...
    ```

3. Insira o número de eleitores quando solicitado e forneça as preferências de classificação para cada eleitor.

4. O programa calculará os pares de candidatos, bloqueará os pares para evitar ciclos e anunciará o vencedor da eleição.

## Exemplo

- Para uma eleição com três candidatos (Alice, Bob e Charlie):

    ```bash
    ./tideman Alice Bob Charlie
    ```

# Fileter - Processamento de Imagens - pset4

Este conjunto de funções em C realiza operações de processamento de imagens em uma matriz de pixels representando uma imagem. As funções são parte de um programa mais amplo que manipula imagens, aplicando operações como conversão para escala de cinza, reflexão horizontal, desfoque e detecção de bordas.

## Funções Implementadas

### 1. Conversão para Escala de Cinza (`grayscale`)

A função `grayscale` converte a imagem para escala de cinza. Cada pixel na imagem é ajustado para ter os mesmos valores de intensidade para os componentes vermelho, verde e azul, resultando em uma imagem em tons de cinza.

### 2. Reflexão Horizontal (`reflect`)

A função `reflect` realiza uma reflexão horizontal na imagem, invertendo a ordem dos pixels em cada linha.

### 3. Desfoque (`blur`)

A função `blur` aplica um efeito de desfoque à imagem. Ela calcula a média dos valores de pixel em torno de cada pixel e atribui esse valor ao pixel central. Isso resulta em uma imagem levemente desfocada.

### 4. Detecção de Bordas (`edges`)

A função `edges` realiza a detecção de bordas na imagem usando o operador Sobel. Ela calcula a magnitude do gradiente para cada pixel e ajusta os valores dos pixels na imagem resultante.

## Uso

1. **Incorporação:**
   - Inclua o arquivo de cabeçalho `helpers.h` no seu programa para ter acesso à definição da estrutura `RGBTRIPLE`.

2. **Chamada de Funções:**
   - Chame as funções desejadas no seu programa, fornecendo a altura, largura e a matriz de pixels da imagem como argumentos.

```c
#include "helpers.h"

int main(void)
{
    // Defina a matriz de pixels da imagem (image) e suas dimensões (height e width)

    // Exemplo: Conversão para escala de cinza
    grayscale(height, width, image);

    // Exemplo: Reflexão horizontal
    reflect(height, width, image);

    // Exemplo: Desfoque
    blur(height, width, image);

    // Exemplo: Detecção de bordas
    edges(height, width, image);

    // Restante do seu programa...
    return 0;
}
```

3. **Compilação:**
   - Compile o seu programa, garantindo que o arquivo `helpers.h` esteja disponível.

4. **Execução:**
   - Execute o programa compilado para aplicar as operações desejadas na imagem.
  
- # speller - Dicionário - pset5

Este código implementa funcionalidades básicas de um dicionário usando uma tabela de hash. O programa inclui operações para verificar se uma palavra está no dicionário, calcular o hash de uma palavra, carregar um dicionário em memória, obter o número de palavras no dicionário e descarregar o dicionário da memória.

## Estrutura de Dados

O dicionário utiliza uma tabela de hash com uma lista encadeada para lidar com colisões. A estrutura `node` representa um nó na lista encadeada, armazenando uma palavra e um ponteiro para o próximo nó.

## Funções Implementadas

### 1. Verificar se uma Palavra Está no Dicionário (`check`)

A função `check` recebe uma palavra como entrada e retorna verdadeiro se a palavra estiver no dicionário, caso contrário, retorna falso.

### 2. Calcular o Hash de uma Palavra (`hash`)

A função `hash` calcula um valor de hash para uma palavra dada.

### 3. Carregar um Dicionário em Memória (`load`)

A função `load` recebe o caminho para um arquivo de dicionário como entrada e carrega suas palavras na tabela de hash em memória. Retorna verdadeiro se bem-sucedido, caso contrário, retorna falso.

### 4. Obter o Número de Palavras no Dicionário (`size`)

A função `size` retorna o número de palavras no dicionário.

### 5. Descarregar o Dicionário da Memória (`unload`)

A função `unload` libera a memória alocada para o dicionário, retornando verdadeiro se bem-sucedido, caso contrário, retorna falso.

## Uso

1. **Incorporação:**
   - Inclua o arquivo de cabeçalho `dictionary.h` no seu programa para ter acesso à definição da estrutura `node` e às funções do dicionário.

2. **Definição do Dicionário:**
   - Certifique-se de definir o número de buckets `N` na tabela de hash conforme necessário.

```c
// Número de buckets na tabela de hash
const unsigned int N = 1;
```

3. **Chamada de Funções:**
   - Chame as funções do dicionário conforme necessário no seu programa.

```c
#include "dictionary.h"

int main(void)
{
    // Exemplo: Verificar se uma palavra está no dicionário
    bool isInDictionary = check("example");

    // Exemplo: Calcular o hash de uma palavra
    unsigned int hashValue = hash("example");

    // Exemplo: Carregar um dicionário em memória
    bool loadSuccess = load("dictionary.txt");

    // Exemplo: Obter o número de palavras no dicionário
    unsigned int dictionarySize = size();

    // Exemplo: Descarregar o dicionário da memória
    bool unloadSuccess = unload();

    // Restante do seu programa...
    return 0;
}
```

4. **Compilação:**
   - Compile o seu programa, garantindo que o arquivo `dictionary.h` esteja disponível.

5. **Execução:**
   - Execute o programa compilado para utilizar as operações do dicionário.


<div align="center"> <image src="https://github.com/GabrielFelipeS/Algoritmo-Curso-Em-Video/assets/108304564/8b515a33-5125-407e-91bf-27765e2410d8"></div>
