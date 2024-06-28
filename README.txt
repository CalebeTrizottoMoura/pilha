README - MANIPULACAO DE PILHAS

DESCRICAO
Este codigo implementa uma estrutura de dados do tipo Pilha em C, permitindo 
a manipulacao de palavras. O programa fornece um menu interativo para adicionar, 
desempilhar, limpar e exibir o conteudo da pilha.

ARQUIVOS INCLUSOS
- main.c: Arquivo principal contendo a implementacao das funcoes e a estrutura da pilha.

REQUISITOS
- Compilador C (ex.: GCC);
- Sistema Operacional Windows ou Unix-like.

CARACTERISTICAS PRINCIPAIS
- Estrutura de dados do tipo Pilha com operacoes padrao (push, pop, limpar, exibir);
- Armazenamento e manipulacao de palavras na pilha;
- Menu interativo para realizacao das operacoes.

COMO COMPILAR E EXECUTAR
1. Abra o terminal.
2. Navegue ate o diretorio onde o arquivo main.c esta localizado.
3. Compile o codigo usando o comando:
    gcc -o pilha main.c
4. Execute o programa com o comando:
    ./pilha

FUNCIONALIDADES
1. ADICIONAR PALAVRA NA PILHA
   Permite ao usuario adicionar uma palavra na pilha.

2. DESEMPILHAR ULTIMA PALAVRA
   Remove e exibe a ultima palavra adicionada na pilha.

3. LIMPAR PILHA
   Remove todos os elementos da pilha.

4. EXIBIR TOPO DA PILHA
   Exibe o elemento no topo da pilha sem remove-lo.

5. EXIBIR PILHA COMPLETA
   Exibe todos os elementos atualmente presentes na pilha.

0. SAIR
   Encerra o programa.

OBSERVACOES IMPORTANTES
- O codigo nao utiliza acentos ou cedilhas para maior compatibilidade;
- A funcionalidade de limpar a tela e responsiva a diferentes sistemas 
operacionais (Windows e Unix-like).

ESTRUTURA DO CODIGO
- A estrutura da pilha e definida utilizando um array de caracteres e um 
indice de topo;
- Varias funcoes sao implementadas para manipular a pilha, incluindo 
inicializacao, verificacao de pilha vazia, push, pop, limpar, exibir 
topo e exibir pilha completa;
- O programa principal (main) apresenta um loop que exibe o menu e permite 
ao usuario selecionar e executar diferentes operacoes na pilha.