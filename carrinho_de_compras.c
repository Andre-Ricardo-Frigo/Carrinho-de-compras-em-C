#include <stdio.h>

typedef struct
{
    int codigo;
    char nome[20];
    float preco;
} produto;

typedef struct
{
    int codigo;
    int quantidade;
    float subtotal;
} item_carrinho;

int main()
{
    produto produtos[] = {
        {101, "Arroz", 5.5},
        {102, "Feijão", 7.2},
        {103, "Macarrão", 4.0},
        {104, "Farinha", 3.8},
        {105, "Açúcar", 2.5}};

    item_carrinho carrinho[10];
    int indice_carrinho = 0;
    char resposta;

    printf("\nProdutos Disponíveis:\n");
    for (int i = 0; i < 5; i++)
    {
        printf("Código %d => %s => R$ %.2f\n",
               produtos[i].codigo,
               produtos[i].nome,
               produtos[i].preco);
    }

    while (indice_carrinho < 10)
    {
        printf("\nDeseja adicionar item? (s/n): ");
        scanf(" %c", &resposta);

        if (resposta == 'n' || resposta == 'N')
        {
            if (indice_carrinho == 0)
            {
                printf("\nCarrinho vazio.\n");
                return 0;
            }
            break;
        }

        int codigo, quantidade;
        printf("\nDigite o código e a quantidade:\n");
        scanf("%d %d", &codigo, &quantidade);

        if (quantidade <= 0)
        {
            printf("\nQuantidade inválida.\n");
            continue;
        }

        int indice_produto = -1;
        for (int i = 0; i < 5; i++)
        {
            if (produtos[i].codigo == codigo)
            {
                indice_produto = i;
                break;
            }
        }

        if (indice_produto == -1)
        {
            printf("\nCódigo inválido.\n");
            continue;
        }

        carrinho[indice_carrinho].codigo = codigo;
        carrinho[indice_carrinho].quantidade = quantidade;
        carrinho[indice_carrinho].subtotal =
            quantidade * produtos[indice_produto].preco;

        indice_carrinho++;
    }

    float total = 0;

    printf("\nNota Fiscal:\n");
    printf("%-12s %-5s %-10s %-10s\n", "Produto", "Qtd", "Preço", "Subtotal");

    for (int i = 0; i < indice_carrinho; i++)
    {
        int indice_produto = -1;

        for (int j = 0; j < 5; j++)
        {
            if (produtos[j].codigo == carrinho[i].codigo)
            {
                indice_produto = j;
                break;
            }
        }

        printf("%-12s %-5d %-10.2f %-10.2f\n",
               produtos[indice_produto].nome,
               carrinho[i].quantidade,
               produtos[indice_produto].preco,
               carrinho[i].subtotal);

        total += carrinho[i].subtotal;
    }

    printf("\nTotal: R$ %.2f\n", total);

    return 0;
}