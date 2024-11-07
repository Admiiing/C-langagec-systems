#include <stdio.h>
#include "registro.h"

extern Produto produtos[MAX_PRODUTOS];
extern Fornecedor fornecedores[MAX_FORNECEDORES];
extern Venda vendas[MAX_VENDAS];
extern int contagem_produtos, contagem_fornecedores, contagem_vendas;
extern int contador_id_produto, contador_id_fornecedor, contador_id_venda;

void salvar_dados() {
    FILE *file;

    file = fopen("produtos.dat", "wb");
    fwrite(&contagem_produtos, sizeof(int), 1, file);
    fwrite(produtos, sizeof(Produto), contagem_produtos, file);
    fclose(file);

    file = fopen("fornecedores.dat", "wb");
    fwrite(&contagem_fornecedores, sizeof(int), 1, file);
    fwrite(fornecedores, sizeof(Fornecedor), contagem_fornecedores, file);
    fclose(file);

    file = fopen("vendas.dat", "wb");
    fwrite(&contagem_vendas, sizeof(int), 1, file);
    fwrite(vendas, sizeof(Venda), contagem_vendas, file);
    fclose(file);

    file = fopen("contadores.dat", "wb");
    fwrite(&contador_id_produto, sizeof(int), 1, file);
    fwrite(&contador_id_fornecedor, sizeof(int), 1, file);
    fwrite(&contador_id_venda, sizeof(int), 1, file);
    fclose(file);
}

void carregar_dados() {
    FILE *file;

    file = fopen("produtos.dat", "rb");
    if (file != NULL) {
        fread(&contagem_produtos, sizeof(int), 1, file);
        fread(produtos, sizeof(Produto), contagem_produtos, file);
        fclose(file);
    }

    file = fopen("fornecedores.dat", "rb");
    if (file != NULL) {
        fread(&contagem_fornecedores, sizeof(int), 1, file);
        fread(fornecedores, sizeof(Fornecedor), contagem_fornecedores, file);
        fclose(file);
    }

    file = fopen("vendas.dat", "rb");
    if (file != NULL) {
        fread(&contagem_vendas, sizeof(int), 1, file);
        fread(vendas, sizeof(Venda), contagem_vendas, file);
        fclose(file);
    }

    file = fopen("contadores.dat", "rb");
    if (file != NULL) {
        fread(&contador_id_produto, sizeof(int), 1, file);
        fread(&contador_id_fornecedor, sizeof(int), 1, file);
        fread(&contador_id_venda, sizeof(int), 1, file);
        fclose(file);
    }
}
