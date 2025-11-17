# Sistema de Gerenciamento de Produtos em C

Sistema simples em linguagem C para gerenciar produtos utilizando um
arquivo de texto (`produtos.txt`). Permite cadastrar, buscar, listar e
ordenar produtos por preço.

------------------------------------------------------------------------

## Funcionalidades

-   Leitura dos produtos a partir de um arquivo
-   Adição de novos produtos
-   Busca por código
-   Listagem de produtos
-   Ordenação por preço (crescente)
-   Menu interativo

------------------------------------------------------------------------

## Estrutura do Projeto

    Projeto
    ├── main.c          → Código principal
    ├── produtos.txt    → Base de dados
    └── README.md       → Documentação

------------------------------------------------------------------------

## Formato do arquivo `produtos.txt`

Cada linha deve seguir o formato:

    codigo nome preco quantidade

Exemplo:

    101 arroz 6.50 20
    102 feijao 8.20 15
    103 macarrao 4.30 30

Observação: nomes devem ser escritos sem espaço.

------------------------------------------------------------------------

## Como Compilar e Executar

### Compilar (GCC):

    gcc main.c -o programa

### Executar:

Linux / Mac:

    ./programa

Windows:

    programa.exe

------------------------------------------------------------------------

## Descrição das Funções

-   struct Produto: armazena os dados de cada produto
-   lerArquivo(): lê os produtos do arquivo
-   imprimirProdutos(): mostra todos os produtos
-   buscarProduto(): procura por um código específico
-   ordenarPorPreco(): ordena os produtos por preço
-   Menu principal: contém todas as opções de interação
