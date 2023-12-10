#include "hash.h"
#include <stdlib.h>
#include <string.h>

// Definição da estrutura interna da tabela hash
struct hash
{
    Student *v[TABSIZE];        // Vetor de ponteiros para estudantes
    HashFunctionPtr hash_func;  // Ponteiro para a função de dispersão
};

// Função para criar uma nova tabela hash
Hash *hsh_create(HashFunctionPtr hash_func)
{
    // Aloca memória para a tabela hash
    Hash *tab = (Hash *)malloc(sizeof(Hash));

    // Inicializa o vetor de ponteiros para estudantes com NULL
    for (int i = 0; i < TABSIZE; i++)
        tab->v[i] = NULL;

    // Define a função de dispersão fornecida pelo usuário
    tab->hash_func = hash_func;

    // Retorna o ponteiro para a tabela hash
    return tab;
}

// Função para liberar a memória alocada para a tabela hash
void hsh_free(Hash *tab)
{
    // Libera a memória alocada para cada estudante na tabela
    for (int i = 0; i < TABSIZE; i++)
    {
        free(tab->v[i]);
    }

    // Libera a memória alocada para a própria tabela hash
    free(tab);
}

// Função para buscar um estudante na tabela hash
Student *hsh_search(Hash *tab, int id)
{
    // Calcula o índice usando a função de dispersão
    int h = tab->hash_func(id);

    // Percorre os elementos na tabela até encontrar o estudante ou encontrar uma posição vazia
    while (tab->v[h] != NULL)
    {
        // Compara as matrículas para encontrar o estudante desejado
        if (st_get_id(tab->v[h]) == id)
            return tab->v[h];

        // Utiliza sondagem linear (linear probing) para tratar colisões
        h = (h + 1) % TABSIZE;
    }

    // Retorna NULL se o estudante não for encontrado
    return NULL;
}

// Função para inserir um estudante na tabela hash
void hsh_insert(Hash *tab, Student *student)
{
    // Calcula o índice usando a função de dispersão
    int h = tab->hash_func(st_get_id(student));

    // Encontra a próxima posição disponível usando sondagem linear
    while (tab->v[h] != NULL)
        h = (h + 1) % TABSIZE;

    // Insere o estudante na posição encontrada
    tab->v[h] = student;
}
