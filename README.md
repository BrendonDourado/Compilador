# Interpretador BASIC em C++

Este é um interpretador simples para a linguagem BASIC, implementado em C++. Ele pode processar comandos de atribuição e executar operações fundamentais, como soma e subtração, além de exibir variáveis através do comando `PRINT`.

## Funcionalidades
- Atribuição de valores a variáveis (ex: `A = 5`)
- Operações aritméticas de soma e subtração entre variáveis (ex: `C = A + B`)
- Exibição de valores com o comando `PRINT` (ex: `PRINT C`)

## Como usar

### 1. Compilar o programa
Para compilar o interpretador, execute o seguinte comando no terminal:

```bash
g++ -o B_interpreter B_interpreter.cpp

Executar o programa passando um arquivo BASIC:
./soma_interpreter soma.bas

