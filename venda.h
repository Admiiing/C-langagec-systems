#ifndef VENDA_H
#define VENDA_H

#define MAX_VENDAS 200

typedef struct {
    int id;
    int id_produto;
    int quantidade;
    float valor_total;
    char data[11];
    int id_fornecedor;
} Venda;

void registrar_venda();
void imprimir_vendas();

#endif // VENDA_H
