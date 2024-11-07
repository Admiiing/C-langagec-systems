#include <stdio.h>
#include <string.h>
#include "fornecedor.h"

#define MAX_FORNECEDORES 50

Fornecedor fornecedores[MAX_FORNECEDORES];
int contagem_fornecedores = 0;
int contador_id_fornecedor = 1;

void adicionar_fornecedor() {
    if (contagem_fornecedores < MAX_FORNECEDORES) {
        Fornecedor f;
        f.id = contador_id_fornecedor++;

        printf("Nome do fornecedor: ");
        fgets(f.nome, sizeof(f.nome), stdin);
        f.nome[strcspn(f.nome, "\n")] = '\0';

        printf("CNPJ: ");
        fgets(f.cnpj, sizeof(f.cnpj), stdin);
        f.cnpj[strcspn(f.cnpj, "\n")] = '\0';

        printf("Endereco: ");
        fgets(f.endereco, sizeof(f.endereco), stdin);
        f.endereco[strcspn(f.endereco, "\n")] = '\0';

        printf("Telefone: ");
        fgets(f.telefone, sizeof(f.telefone), stdin);
        f.telefone[strcspn(f.telefone, "\n")] = '\0';

        printf("Historico de compras: ");
        fgets(f.historico_compras, sizeof(f.historico_compras), stdin);
        f.historico_compras[strcspn(f.historico_compras, "\n")] = '\0';

        fornecedores[contagem_fornecedores++] = f;
        printf("Fornecedor adicionado com sucesso!\n");
    } else {
        printf("Limite de fornecedores atingido!\n");
    }
}

void imprimir_fornecedores() {
    printf("\nLista de Fornecedores:\n");
    for (int i = 0; i < contagem_fornecedores; i++) {
        Fornecedor f = fornecedores[i];
        printf("ID: %d | Nome: %s | CNPJ: %s | Endereco: %s | Telefone: %s | Historico de Compras: %s\n",
               f.id, f.nome, f.cnpj, f.endereco, f.telefone, f.historico_compras);
    }
}

void buscar_fornecedor_por_id() {
    int id;
    printf("Digite o ID do fornecedor: ");
    scanf("%d", &id);

    for (int i = 0; i < contagem_fornecedores; i++) {
        if (fornecedores[i].id == id) {
            Fornecedor f = fornecedores[i];
            printf("ID: %d | Nome: %s | CNPJ: %s | Endereco: %s | Telefone: %s | Historico de Compras: %s\n",
                   f.id, f.nome, f.cnpj, f.endereco, f.telefone, f.historico_compras);
            return;
        }
    }
    printf("Fornecedor com ID %d nao encontrado.\n", id);
}

void editar_fornecedor() {
    int id, opcao;
    printf("Digite o ID do fornecedor que deseja editar: ");
    scanf("%d", &id);
    getchar();  // Limpa o buffer do teclado após o scanf

    for (int i = 0; i < contagem_fornecedores; i++) {
        if (fornecedores[i].id == id) {
            printf("Fornecedor encontrado:\n");
            printf("1. Nome: %s\n", fornecedores[i].nome);
            printf("2. CNPJ: %s\n", fornecedores[i].cnpj);
            printf("3. Endereco: %s\n", fornecedores[i].endereco);
            printf("4. Telefone: %s\n", fornecedores[i].telefone);
            printf("5. Historico de Compras: %s\n", fornecedores[i].historico_compras);
            printf("Digite o numero do campo que deseja editar (ou 0 para sair): ");
            scanf("%d", &opcao);
            getchar();  // Limpa o buffer do teclado após o scanf

            switch (opcao) {
                case 1:
                    printf("Novo nome: ");
                    fgets(fornecedores[i].nome, sizeof(fornecedores[i].nome), stdin);
                    fornecedores[i].nome[strcspn(fornecedores[i].nome, "\n")] = '\0';
                    break;
                case 2:
                    printf("Novo CNPJ: ");
                    fgets(fornecedores[i].cnpj, sizeof(fornecedores[i].cnpj), stdin);
                    fornecedores[i].cnpj[strcspn(fornecedores[i].cnpj, "\n")] = '\0';
                    break;
                case 3:
                    printf("Novo endereco: ");
                    fgets(fornecedores[i].endereco, sizeof(fornecedores[i].endereco), stdin);
                    fornecedores[i].endereco[strcspn(fornecedores[i].endereco, "\n")] = '\0';
                    break;
                case 4:
                    printf("Novo telefone: ");
                    fgets(fornecedores[i].telefone, sizeof(fornecedores[i].telefone), stdin);
                    fornecedores[i].telefone[strcspn(fornecedores[i].telefone, "\n")] = '\0';
                    break;
                case 5:
                    printf("Novo historico de compras: ");
                    fgets(fornecedores[i].historico_compras, sizeof(fornecedores[i].historico_compras), stdin);
                    fornecedores[i].historico_compras[strcspn(fornecedores[i].historico_compras, "\n")] = '\0';
                    break;
                case 0:
                    return;
                default:
                    printf("Opcao invalida.\n");
            }
            printf("Fornecedor atualizado com sucesso!\n");
            return;
        }
    }
    printf("Fornecedor com ID %d nao encontrado.\n", id);
}
