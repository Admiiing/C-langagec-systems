#ifndef FORNECEDOR_H
#define FORNECEDOR_H

#define MAX_FORNECEDORES 50

typedef struct {
    int id;
    char nome[50];
    char cnpj[20];
    char endereco[100];
    char telefone[15];
    char historico_compras[200];
} Fornecedor;

void adicionar_fornecedor();
void imprimir_fornecedores();
void buscar_fornecedor_por_id();

#endif // FORNECEDOR_H
