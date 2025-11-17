#include <stdio.h>

struct Produto { int codigo; char nome[50]; float preco; int quantidade;
};

int lerArquivo(struct Produto produtos[]) { FILE *file =
fopen(“produtos.txt”, “r”); if (file == NULL) { printf(“Erro ao abrir
produtos.txt”); return 0; }

    int i = 0;
    while (fscanf(file, "%d %49s %f %d",
                  &produtos[i].codigo,
                  produtos[i].nome,
                  &produtos[i].preco,
                  &produtos[i].quantidade) == 4) {
        i++;
    }

    fclose(file);
    return i;  

}

void imprimirProdutos(struct Produto produtos[], int qtd) { printf(“—
LISTA DE PRODUTOS —”); for (int i = 0; i < qtd; i++) { printf(“%d %s
%.2f %d”, produtos[i].codigo, produtos[i].nome, produtos[i].preco,
produtos[i].quantidade); } }

int buscarProduto(struct Produto produtos[], int qtd, int codigo) { for
(int i = 0; i < qtd; i++) { if (produtos[i].codigo == codigo) { return
i;
} } return -1; }

void ordenarPorPreco(struct Produto produtos[], int qtd) { for (int i =
0; i < qtd - 1; i++) { for (int j = 0; j < qtd - i - 1; j++) { if
(produtos[j].preco > produtos[j + 1].preco) { struct Produto aux =
produtos[j]; produtos[j] = produtos[j + 1]; produtos[j + 1] = aux; } } }
}

int main() { struct Produto produtos[200]; int qtd = 0; int opcao;

    qtd = lerArquivo(produtos);

    do {
        printf("\n--- MENU ---\n");
        printf("1. Adicionar produto\n");
        printf("2. Buscar produto por código\n");
        printf("3. Imprimir produtos\n");
        printf("4. Ordenar por preço e imprimir\n");
        printf("5. Sair\n");
        printf("Escolha: ");
        scanf("%d", &opcao);

        switch (opcao) {

            case 1:
                printf("Codigo: ");
                scanf("%d", &produtos[qtd].codigo);

                printf("Nome: ");
                scanf(" %49[^\n]", produtos[qtd].nome);

                printf("Preco: ");
                scanf("%f", &produtos[qtd].preco);

                printf("Quantidade: ");
                scanf("%d", &produtos[qtd].quantidade);

                qtd++;
                printf("Produto adicionado!\n");
                break;

            case 2: {
                int codigoBusca;
                printf("Digite o codigo do produto: ");
                scanf("%d", &codigoBusca);

                int pos = buscarProduto(produtos, qtd, codigoBusca);
                if (pos == -1) {
                    printf("Produto nao encontrado!\n");
                } else {
                    printf("\nProduto encontrado:\n");
                    printf("Codigo: %d\n", produtos[pos].codigo);
                    printf("Nome: %s\n", produtos[pos].nome);
                    printf("Preco: %.2f\n", produtos[pos].preco);
                    printf("Quantidade: %d\n", produtos[pos].quantidade);
                }
                break;
            }

            case 3:
                imprimirProdutos(produtos, qtd);
                break;

            case 4:
                ordenarPorPreco(produtos, qtd);
                imprimirProdutos(produtos, qtd);
                break;

            case 5:
                printf("Encerrando...\n");
                break;

            default:
                printf("Opcao invalida!\n");
                break;
        }

    } while (opcao != 5);

    return 0;

}
