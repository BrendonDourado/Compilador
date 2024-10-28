# Compilador
Interpretador BASIC em C++
Este é um interpretador simples para a linguagem BASIC, implementado em C++. Ele pode processar comandos de atribuição e executar operações fundamentais, como soma e subtração, além de exibir variáveis através do comando PRINT.

Funcionalidades
Atribuição de valores a variáveis (ex: A = 100)
Operações aritméticas de soma e subtração entre variáveis (ex: C = A + B)
Exibição de valores com o comando PRINT (ex: PRINT C)
Como usar
1. Compilar o programa
Para compilar o interpretador, execute o seguinte comando no terminal:

g++ -o basic_interpreter basic_interpreter.cpp
Isso irá gerar um executável chamado basic_interpreter.

2. Executar o programa
Para rodar o interpretador, forneça um arquivo de texto com o código BASIC como argumento. Por exemplo:

./basic_interpreter programa.bas
O arquivo programa.bas deve conter as instruções BASIC que você deseja interpretar.

3. Exemplo de arquivo BASIC
Aqui está um exemplo de código BASIC que pode ser inserido no arquivo programa.bas:

A = 5
B = 2
C = A + B
D = A - B
PRINT C
PRINT D
A saída deste programa será:
7
3

4. Erros Comuns
Erro: Variável não encontrada
Erro: Sintaxe de atribuição incorreta: O interpretador espera atribuições simples, como A = 5 ou operações como A = B + C.
Requisitos
Um compilador C++, como o g++, deve estar instalado no sistema.
