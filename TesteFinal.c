#include <stdio.h>

int main() {
    int codigo[5];
    float preco[5];
    int estoque[5];

    int i;
    int codigoBusca;
    int quantidade;
    int encontrado;
    int opcao;
    int posicao;
    int totalItens;
    int menorEstoque;
    int produtoMenorEstoque;

    float subtotal;
    float totalCompra;

    /* ============================= */
    /* CADASTRO DOS PRODUTOS          */
    /* ============================= */

    printf("========================================\n");
    printf("       CADASTRO DE PRODUTOS\n");
    printf("========================================\n");

    for (i = 0; i < 5; i++) {
        printf("\nProduto %d\n", i + 1);

        printf("Codigo: ");
        scanf("%d", &codigo[i]);

        printf("Preco: R$ ");
        scanf("%f", &preco[i]);

        printf("Quantidade em estoque: ");
        scanf("%d", &estoque[i]);
    }

    /* ============================= */
    /* EXIBICAO DO ESTOQUE            */
    /* ============================= */

    printf("\n========================================\n");
    printf("          ESTOQUE DA LOJA\n");
    printf("========================================\n");
    printf("Codigo    Preco         Estoque\n");

    for (i = 0; i < 5; i++) {
        printf("%-9d R$ %-10.2f %d\n",
               codigo[i], preco[i], estoque[i]);
    }

    /* Inicializacao das variaveis da compra */
    totalCompra = 0.0;
    totalItens = 0;

    /* ============================= */
    /* REALIZACAO DAS VENDAS          */
    /* ============================= */

    opcao = 1;

    while (opcao == 1) {

        printf("\n========================================\n");
        printf("             NOVA VENDA\n");
        printf("========================================\n");

        printf("Digite o codigo do produto: ");
        scanf("%d", &codigoBusca);

        encontrado = 0;
        posicao = -1;

        /* Procura o produto pelo codigo */
        for (i = 0; i < 5; i++) {
            if (codigo[i] == codigoBusca) {
                encontrado = 1;
                posicao = i;
            }
        }

        if (encontrado == 1) {

            printf("\nProduto encontrado!\n");
            printf("Codigo: %d\n", codigo[posicao]);
            printf("Preco: R$ %.2f\n", preco[posicao]);
            printf("Estoque disponivel: %d\n", estoque[posicao]);

            /* Melhoria: impede quantidade menor ou igual a zero */
            do {
                printf("Quantidade desejada: ");
                scanf("%d", &quantidade);

                if (quantidade <= 0) {
                    printf("Quantidade invalida! "
                           "Informe uma quantidade maior que zero.\n");
                }

            } while (quantidade <= 0);

            printf("\nEstoque disponivel: %d\n", estoque[posicao]);
            printf("Quantidade solicitada: %d\n", quantidade);

            /* Verificacao do estoque */
            if (quantidade <= estoque[posicao]) {

                subtotal = preco[posicao] * quantidade;

                printf("\nVenda realizada!\n");
                printf("Preco unitario: R$ %.2f\n", preco[posicao]);
                printf("Quantidade: %d\n", quantidade);
                printf("Subtotal: R$ %.2f\n", subtotal);

                /* Atualiza o estoque */
                estoque[posicao] = estoque[posicao] - quantidade;

                /* Acumula os valores da compra */
                totalCompra = totalCompra + subtotal;
                totalItens = totalItens + quantidade;

                printf("\nEstoque atualizado do produto %d: %d\n",
                       codigo[posicao], estoque[posicao]);

            } else {
                printf("\nEstoque insuficiente!\n");
            }

        } else {
            printf("\nProduto nao encontrado!\n");
        }

        /* Pergunta se deseja continuar */
        printf("\nDeseja comprar outro produto?\n");
        printf("1 - Sim\n");
        printf("0 - Nao\n");
        printf("Opcao: ");
        scanf("%d", &opcao);

        while (opcao != 0 && opcao != 1) {
            printf("Opcao invalida! Digite 1 para Sim ou 0 para Nao: ");
            scanf("%d", &opcao);
        }
    }

    /* ============================= */
    /* NOTA FISCAL SIMPLIFICADA       */
    /* ============================= */

    printf("\n========================================\n");
    printf("       NOTA FISCAL SIMPLIFICADA\n");
    printf("========================================\n");
    printf("Quantidade de itens vendidos: %d\n", totalItens);
    printf("----------------------------------------\n");
    printf("TOTAL DA COMPRA: R$ %.2f\n", totalCompra);
    printf("----------------------------------------\n");
    printf("Obrigado pela compra!\n");

    /* ============================= */
    /* ESTOQUE ATUALIZADO             */
    /* ============================= */

    printf("\n========================================\n");
    printf("          ESTOQUE ATUALIZADO\n");
    printf("========================================\n");
    printf("Codigo    Preco         Estoque\n");

    for (i = 0; i < 5; i++) {
        printf("%-9d R$ %-10.2f %d\n",
               codigo[i], preco[i], estoque[i]);
    }

    /* ============================= */
    /* MELHORIA: MENOR ESTOQUE        */
    /* ============================= */

    menorEstoque = estoque[0];
    produtoMenorEstoque = 0;

    for (i = 1; i < 5; i++) {
        if (estoque[i] < menorEstoque) {
            menorEstoque = estoque[i];
            produtoMenorEstoque = i;
        }
    }

    printf("\n========================================\n");
    printf("        MELHORIA DO SISTEMA\n");
    printf("========================================\n");
    printf("Produto com menor estoque:\n");
    printf("Codigo: %d\n", codigo[produtoMenorEstoque]);
    printf("Estoque: %d unidade(s)\n", menorEstoque);

    return 0;
}
