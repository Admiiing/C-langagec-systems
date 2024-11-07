#include <stdio.h>
#include "venda.h"

Venda vendas[MAX_VENDAS];
int contagem_vendas = 0;
int contador_id_venda = 1;

void registrar_venda() {
    if (contagem_vendas < MAX_VENDAS) {
        Venda v;
        v.id = contador_id_venda++;

        printf("ID do produto: ");
        scanf("%d", &v.id_produto);
        printf("Quantidade vendida: ");
        scanf("%d", &v.quantidade);
        printf("Valor total da venda: ");
        scanf("%f", &v.valor_total);
        printf("Data da venda (dd/mm/aaaa): ");
        scanf("%s", v.data);
        printf("ID do fornecedor: ");
        scanf("%d", &v.id_fornecedor);

        vendas[contagem_vendas++] = v;
        printf("Venda registrada com sucesso!\n");
    } else {
        printf("Limite de vendas atingido!\n");
    }
}

void imprimir_vendas() {
    printf("\nLista de Vendas:\n");
    for (int i = 0; i < contagem_vendas; i++) {
        Venda v = vendas[i];
        printf("ID: %d | ID Produto: %d | Quantidade: %d | Valor Total: %.2f | Data: %s | ID Fornecedor: %d\n",
               v.id, v.id_produto, v.quantidade, v.valor_total, v.data, v.id_fornecedor);
    }
}
