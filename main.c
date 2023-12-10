#include "hash.h"
#include <stdio.h>

int hash1(int id)
{
    return id % TABSIZE;
}

int hash2(int id)
{
    return (id * 3 + 7) % TABSIZE;
}

int main()
{
    // Criação de duas tabelas hash usando diferentes funções de dispersão
    Hash *table1 = hsh_create(hash1);
    Hash *table2 = hsh_create(hash2);

    // Crição de alguns estudantes para teste
    Student *student1 = st_create(1, "João Gabriel", "joaogabriel@hotmail.com", 'A');
    Student *student2 = st_create(2, "Sofia Oliveira", "sofiaoliveira@gmail.com", 'B');

    // Inserindo estudantes nas tabelas
    hsh_insert(table1, student1);
    hsh_insert(table2, student2);

    // Buscando estudantes nas tabelas
    Student *foundStudent1 = hsh_search(table1, 1);
    Student *foundStudent2 = hsh_search(table2, 2);

    // Imprimindo informações dos estudantes encontrados
    if (foundStudent1 != NULL)
        st_print(foundStudent1);
    else
        printf("Estudante não encontrado na tabela 1\n");

    if (foundStudent2 != NULL)
        st_print(foundStudent2);
    else
        printf("Estudante não encontrado na tabela 2\n");

    // Liberando memória alocada
    hsh_free(table1);
    hsh_free(table2);

    return 0;
}
