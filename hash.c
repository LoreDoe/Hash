#ifndef HASH_H
#define HASH_H

#include "student.h"

// Tamanho da tabela hash (número primo)
#define TABSIZE 101

// Definição da estrutura Hash
typedef struct hash Hash;

// Definição do ponteiro para função de dispersão
typedef int (*HashFunctionPtr)(int);

// Função para criar uma tabela hash
Hash *hsh_create(HashFunctionPtr hash_func);

// Função para liberar a memória alocada para a tabela hash
void hsh_free(Hash *tab);

// Função para buscar um estudante na tabela hash
Student *hsh_search(Hash *tab, int id);

// Função para inserir um estudante na tabela hash
void hsh_insert(Hash *tab, Student *student);

#endif
