#ifndef STUDENT_H
#define STUDENT_H

// Declaração da estrutura do estudante
typedef struct student Student;

// Função para criar um novo estudante
Student *st_create(int id, const char *name, const char *email, char class);

// Função para obter o número de matrícula de um estudante
int st_get_id(Student *student);

// Função para obter o nome de um estudante
char *st_get_name(Student *student);

// Função para obter o endereço de e-mail de um estudante
char *st_get_email(Student *student);

// Função para obter a classe de um estudante
char st_get_class(Student *student);

// Função para imprimir as informações de um estudante
void st_print(Student *student);

#endif
