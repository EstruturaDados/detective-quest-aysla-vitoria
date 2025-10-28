#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estrutura do nó da árvore de busca
typedef struct No {
    char pista[100];
    struct No *esquerda;
    struct No *direita;
} No;

// Função para criar um novo nó
No* criarNo(char* pista) {
    No* novo = (No*)malloc(sizeof(No));
    strcpy(novo->pista, pista);
    novo->esquerda = NULL;
    novo->direita = NULL;
    return novo;
}

// Função para inserir uma pista na árvore de busca
No* inserir(No* raiz, char* pista) {
    if (raiz == NULL) {
        return criarNo(pista);
    }
    if (strcmp(pista, raiz->pista) < 0) {
        raiz->esquerda = inserir(raiz->esquerda, pista);
    } else if (strcmp(pista, raiz->pista) > 0) {
        raiz->direita = inserir(raiz->direita, pista);
    }
    return raiz;
}

// Função para exibir as pistas em ordem alfabética
void emOrdem(No* raiz) {
    if (raiz != NULL) {
        emOrdem(raiz->esquerda);
        printf("Pista: %s\n", raiz->pista);
        emOrdem(raiz->direita);
    }
}

// Simulação de visita a cômodos com pistas
void visitarComodo(char* nomeComodo, No** arvorePistas) {
    printf("Visitando o cômodo: %s\n", nomeComodo);

    // Simulação de pistas encontradas em cômodos específicos
    if (strcmp(nomeComodo, "Biblioteca") == 0) {
        *arvorePistas = inserir(*arvorePistas, "Livro rasgado");
    } else if (strcmp(nomeComodo, "Cozinha") == 0) {
        *arvorePistas = inserir(*arvorePistas, "Faca suja");
    } else if (strcmp(nomeComodo, "Sala de Estar") == 0) {
        *arvorePistas = inserir(*arvorePistas, "Pegada no tapete");
    }
}

int main() {
    No* arvorePistas = NULL;
    int opcao;
    char comodo[50];

    do {
        printf("\nEscolha um cômodo para visitar:\n");
        printf("1. Biblioteca\n");
        printf("2. Cozinha\n");
        printf("3. Sala de Estar\n");
        printf("4. Ver pistas encontradas\n");
        printf("5. Sair\n");
        printf("Opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                visitarComodo("Biblioteca", &arvorePistas);
                break;
            case 2:
                visitarComodo("Cozinha", &arvorePistas);
                break;
            case 3:
                visitarComodo("Sala de Estar", &arvorePistas);
                break;
            case 4:
                printf("\nPistas encontradas:\n");
                emOrdem(arvorePistas);
                break;
            case 5:
                printf("Encerrando investigação...\n");
                break;
            default:
                printf("Opção inválida!\n");
        }
    } while (opcao != 5);

    return 0;
}

