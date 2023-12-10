#include "student.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

// Definição da estrutura interna do estudante
struct student
{
    int id;                // Número de matrícula do estudante
    char name[81];         // Nome do estudante
    char email[43];        // Endereço de e-mail do estudante
    char class;            // Classe do estudante
};

// Função para criar um novo estudante
Student *st_create(int id, const char *name, const char *email, char class)
{
    // Aloca memória para a estrutura do estudante
    Student *student = (Student *)malloc(sizeof(Student));

    // Inicializa os campos da estrutura com os valores fornecidos
    student->id = id;
    strcpy(student->name, name);
    strcpy(student->email, email);
    student->class = class;

    // Retorna o ponteiro para o estudante
    return student;
}

// Função para obter o número de matrícula de um estudante
int st_get_id(Student *student)
{
    // Retorna o número de matrícula do estudante
    return student->id;
}

// Função para obter o nome de um estudante
char *st_get_name(Student *student)
{
    // Retorna o ponteiro para o nome do estudante
    return student->name;
}

// Função para obter o endereço de e-mail de um estudante
char *st_get_email(Student *student)
{
    // Retorna o ponteiro para o endereço de e-mail do estudante
    return student->email;
}

// Função para obter a classe de um estudante
char st_get_class(Student *student)
{
    // Retorna a classe do estudante
    return student->class;
}

// Função para imprimir as informações de um estudante
void st_print(Student *student)
{
    // Imprime as informações formatadas do estudante
    printf("%-10s %-20s (%d) - %c\n", student->name, student->email, student->id, student->class);
}
