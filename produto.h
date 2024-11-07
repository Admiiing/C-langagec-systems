#ifndef PRODUTO_H
#define PRODUTO_H

#define MAX_PRODUTOS 100

typedef struct {
    int id;
    char nome[50];
    char validade[11];
    int codigo;
    char categoria[30];
    float preco;
    char unidade[10];
    int quantidade;
    int id_fornecedor;
} Produto;

void adicionar_produto();
void imprimir_produtos();
void buscar_produto_por_id();
void editar_produto();

#endif // PRODUTO_H
