#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100
#define MAX_VET 20

// Declaracao da estrutura e das funcoes
struct Pilha {
    char itens[MAX_SIZE];
    int topo;
};

void inicializar(struct Pilha *p);
int vazia(struct Pilha *p);
void limparBuffer();
void aguardar_entrada();
void limpar_tela();
void push(struct Pilha *p, int desempilhar_palavra[]);
char pop(struct Pilha *p, int desempilhar_palavra[]);
void topo(struct Pilha *p);
void limpar(struct Pilha *p, int desempilhar_palavra[]);
void exibir_pilha(struct Pilha *p);
void menu();
void default_switch();
int filtro_opcao();
void adicionar_valor(int vetor[]);

// Funcao principal
int main() {
    struct Pilha p;
    int desempilhar_palavra[MAX_VET];
    
    inicializar(&p);
    adicionar_valor(desempilhar_palavra);

    while (1) {
        int opcao = filtro_opcao();

        switch (opcao) {
            case 1: {
                push(&p, desempilhar_palavra);
                break;
            }

            case 2: {
                pop(&p, desempilhar_palavra);
                break;
            }

            case 3: {
                limpar(&p, desempilhar_palavra);
                break;
            }

            case 4: {
                topo(&p);
                break;
            }

            case 5: {
                exibir_pilha(&p);
                break;
            }

            case 0: {
                return 0;
            }

            default: {
                default_switch();
            }
        }
    }

    return 0;
}

// Implementacao das funcoes
void inicializar(struct Pilha *p) {
    p->topo = -1;
}

int vazia(struct Pilha *p) {
    return p->topo == -1;
}

void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}

void aguardar_entrada() {
    printf("Pressione Enter para continuar...");
    limparBuffer();
}

void limpar_tela() {
#ifndef _WIN32
    printf("\033[2J\033[1;1H");
#else
    system("cls");
#endif
}

void push(struct Pilha *p, int desempilhar_palavra[]) {
    char palavra[MAX_SIZE];

    limpar_tela();
    printf("=============== ADICIONAR PALAVRA ===============\n");
    printf("Digite a palavra a ser adicionada: ");
    scanf("%s", palavra);
    limparBuffer();
    
    int total = strlen(palavra) + p->topo + 1;

    if (MAX_SIZE < total) {
        printf("A pilha atingiu o seu tamanho maximo.\n");
    } else {
        for (int i = 0; i < strlen(palavra); i ++) {
            if (palavra[i] == '\n') {
                palavra[i] = '\0';
            } else {
                p->topo ++;
                p->itens[p->topo] = palavra[i];
            }
        }
        
        for (int i = 0; i < MAX_VET; i ++) {
            if (desempilhar_palavra[i] == -1) {
                desempilhar_palavra[i] = p->topo + 1;
                i = MAX_VET;
            }
        }
        
        printf("Palavra '%s' adicionada a pilha.\n", palavra);
    }

    aguardar_entrada();
}

char pop(struct Pilha *p, int desempilhar_palavra[]) {
    char palavra[MAX_SIZE], letra;
    int indice = 0, controle = 0, iterar = 0, j = MAX_VET - 1;

    while (controle == 0 && !vazia(p)) {
        if (desempilhar_palavra[j] != -1) {
            if (j == 0) {
                iterar = desempilhar_palavra[j];
            } else {
                iterar = desempilhar_palavra[j] - desempilhar_palavra[j - 1];
            }

            for (int i = iterar - 1; i >= 0; i --) {
                letra = p->itens[p->topo];
                p->itens[p->topo] = '\0';
                palavra[indice ++] = letra;
                p->topo --;
            }

            desempilhar_palavra[j] = -1;
            controle = 1;
        } else if (j < 0) {
            controle = 1;
        } else {
            j --;
        }
    }

    palavra[indice] = '\0';

    limpar_tela();
    printf("=============== DESEMPILHAR ===============\n");

    if (indice > 0) {
        int tamanho_palavra = strlen(palavra), j = 0;
        char palavra_ordenada[tamanho_palavra];

        palavra_ordenada[indice] = '\0';

        for (int i = tamanho_palavra - 1; i >= 0; i --) {
            palavra_ordenada[j] = palavra[i];
            j ++;
        }

        printf("Palavra desempilhada: '%s'\n", palavra_ordenada);
        printf("Sequencia de desempilhamento: '%s'\n", palavra);
    } else {
        printf("Pilha vazia. Nenhum elemento para mostrar.\n");
    }

    aguardar_entrada();
}

void topo(struct Pilha *p) {
    limpar_tela();
    printf("=============== TOPO DA PILHA ===============\n");

    if (p->topo == -1) {
        printf("Pilha vazia. Nenhum elemento para mostrar.\n");
    } else {
        printf("Elemento no topo da pilha: %c\n", p->itens[p->topo]);
    }
    
    aguardar_entrada();
}

void limpar(struct Pilha *p, int desempilhar_palavra[]) {
    limpar_tela();
    printf("=============== LIMPANDO PILHA ===============\n");

    if (p->topo > -1) {
        for (int i = 0; i <= p->topo; i ++) {
            p->itens[i] = '\0';
        }

        for (int i = 0; i < MAX_VET; i++){
            if (desempilhar_palavra[i] != -1) {
                desempilhar_palavra[i] = -1;
            } else {
                i = MAX_VET;
            }
        }

        p->topo = -1;

        printf("Pilha limpa.\n");
    } else {
        printf("Nao e necessario limpar a pilha, uma vez que ja se encontra vazia.\n");
    }

    aguardar_entrada();
}

void exibir_pilha(struct Pilha *p) {  
    limpar_tela();
    printf("=============== EXIBIR PILHA ===============\n");

    if (vazia(p)) {
        printf("Pilha vazia. Nenhum elemento para mostrar.\n");
    } else {
        printf("Indice: [");

        for (int i = 0; i <= p->topo; i ++) {
            if (i == p->topo) {
                printf("%d", i);
            } else {
                printf("%d, ", i);
            }
        }

        printf("]");
        printf("\nDados:  [");

        int maior_nove = 0;

        for (int i = 0; i <= p->topo; i ++) {
            if (i == p->topo) {
                printf("%c", p->itens[i]);
            } else if (i > 9) {
                printf("%c,  ", p->itens[i]);
                maior_nove ++;
            } else {
                printf("%c, ", p->itens[i]);
            }
        }

        if (maior_nove == 0) {
            printf("]\n");
        } else {
            printf(" ]\n");
        }
    }

    aguardar_entrada();
}

void menu() {
    limpar_tela();
    printf("=============== MENU DE OPCOES ===============\n");
    printf("1 - Adicionar uma palavra na pilha\n");
    printf("2 - Desempilhar a ultima palavra\n");
    printf("3 - Limpar a pilha\n");
    printf("4 - Exibir o topo da pilha\n");
    printf("5 - Exibir pilha completa\n");
    printf("0 - Sair\n");
    printf("\nDigite o numero da sua opcao: ");
}

void default_switch() {
    limpar_tela();
    printf("=============== OPCAO INVALIDA ===============\n");
    printf("Digite 1, 2, 3, 4, 5 ou 0.\n");
    aguardar_entrada();
}

int filtro_opcao() {
    int controle = 0, opcao = -1;

    while (controle == 0) {
        menu();
        scanf("%d", &opcao);
        limparBuffer();

        if (opcao >= 0) {
            controle ++;
        } else {
            default_switch();
        }
    }

    return opcao;
}

void adicionar_valor(int vetor[]) {
    for (int i = 0; i < MAX_VET; i ++) {
        vetor[i] = -1;
    }
}