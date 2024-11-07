#include <stdio.h>
#include <string.h>
#include "produto.h"

Produto produtos[MAX_PRODUTOS];
int contagem_produtos = 0;
int contador_id_produto = 1;

void adicionar_produto() {
    if (contagem_produtos < MAX_PRODUTOS) {
        Produto p;
        p.id = contador_id_produto++;

        printf("Nome do produto: ");
        scanf("%s", p.nome);
        printf("Validade (dd/mm/aaaa): ");
        scanf("%s", p.validade);
        printf("Codigo do produto: ");
        scanf("%d", &p.codigo);
        printf("Categoria: ");
        scanf("%s", p.categoria);
        printf("Preco: ");
        scanf("%f", &p.preco);
        printf("Unidade: ");
        scanf("%s", p.unidade);
        printf("Quantidade: ");
        scanf("%d", &p.quantidade);
        printf("ID do Fornecedor: ");
        scanf("%d", &p.id_fornecedor);

        produtos[contagem_produtos++] = p;
        printf("Produto adicionado com sucesso!\n");
    } else {
        printf("Limite de produtos atingido!\n");
    }
}

void imprimir_produtos() {
    printf("\nLista de Produtos:\n");
    for (int i = 0; i < contagem_produtos; i++) {
        Produto p = produtos[i];
        printf("ID: %d | Nome: %s | Validade: %s | Codigo: %d | Categoria: %s | Preco: %.2f | Unidade: %s | Quantidade: %d | ID Fornecedor: %d\n",
               p.id, p.nome, p.validade, p.codigo, p.categoria, p.preco, p.unidade, p.quantidade, p.id_fornecedor);
    }
}

void buscar_produto_por_id() {
    int id;
    printf("Digite o ID do produto: ");
    scanf("%d", &id);

    for (int i = 0; i < contagem_produtos; i++) {
        if (produtos[i].id == id) {
            Produto p = produtos[i];
            printf("ID: %d | Nome: %s | Validade: %s | Codigo: %d | Categoria: %s | Preco: %.2f | Unidade: %s | Quantidade: %d | ID Fornecedor: %d\n",
                   p.id, p.nome, p.validade, p.codigo, p.categoria, p.preco, p.unidade, p.quantidade, p.id_fornecedor);
            return;
        }
    }
    printf("Produto com ID %d nao encontrado.\n", id);
}

void editar_produto() {
    int id;
    printf("Digite o ID do produto para editar: ");
    scanf("%d", &id);

    for (int i = 0; i < contagem_produtos; i++) {
        if (produtos[i].id == id) {
            printf("Novo nome do produto: ");
            scanf("%s", produtos[i].nome);
            printf("Nova validade (dd/mm/aaaa): ");
            scanf("%s", produtos[i].validade);
            printf("Novo codigo do produto: ");
            scanf("%d", &produtos[i].codigo);
            printf("Nova categoria: ");
            scanf("%s", produtos[i].categoria);
            printf("Novo preco: ");
            scanf("%f", &produtos[i].preco);
            printf("Nova unidade: ");
            scanf("%s", produtos[i].unidade);
            printf("Nova quantidade: ");
            scanf("%d", &produtos[i].quantidade);
            printf("Novo ID do Fornecedor: ");
            scanf("%d", &produtos[i].id_fornecedor);
            printf("Produto editado com sucesso!\n");
            return;
        }
    }
    printf("Produto com ID %d nao encontrado.\n", id);
}
