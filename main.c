#include <stdio.h>
#include "registro.h"
#include "produto.h"
#include "fornecedor.h"
#include "venda.h"

void menu();

int main() {
    carregar_dados();  // Carrega os dados salvos

    menu();

    salvar_dados();  // Salva os dados ao sair
    return 0;
}

void menu() {
    int escolha;
    do {
        printf("\n\tSistema de Gestao Hortifruti Arauto do Vale\n");
        printf("\n01. Adicionar Produto\n");
        printf("02. Adicionar Fornecedor\n");
        printf("03. Registrar Venda\n");
        printf("04. Imprimir Produtos\n");
        printf("05. Imprimir Fornecedores\n");
        printf("06. Imprimir Vendas\n");
        printf("07. Buscar Produto por ID\n");
        printf("08. Buscar Fornecedor por ID\n");
        printf("09. Editar Produto\n");
        printf("10. Editar Fornecedor\n");
        printf("11. Sair\n");
        printf("\nDigite sua escolha: ");
        scanf("%d", &escolha);
        switch (escolha) {
            case 1:
                adicionar_produto();
                break;
            case 2:
                adicionar_fornecedor();
                break;
            case 3:
                registrar_venda();
                break;
            case 4:
                imprimir_produtos();
                break;
            case 5:
                imprimir_fornecedores();
                break;
            case 6:
                imprimir_vendas();
                break;
            case 7:
                buscar_produto_por_id();
                break;
            case 8:
                buscar_fornecedor_por_id();
                break;
            case 9:
                editar_produto();
                break;
            case 10:
                editar_fornecedor();
                break;
            case 11:
                printf("Saindo...\n");
                break;
            default:
                printf("Escolha invalida! Por favor, tente novamente.\n");
        }
    } while (escolha != 10);
}
