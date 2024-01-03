#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <ctype.h>
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;
/**
 * struct cmddata_s - variables -args, file, line content
 * @arg: value
 * @file: pointer to monty file
 * @content: line content
 * @stack queue_flag: flag change stack <-> queue
 * Description: carries values through the program
 */
typedef struct cmddata_s
{
	char *arg;
	FILE *file;
	char *content;
	int stackqueue_flag;
}  cmddata_t;
extern cmddata_t cmddata;

void f_pall(stack_t **head);
void addnode(stack_t **head, int n);
void addqueue(stack_t **head, int n);
void f_push(stack_t **head, unsigned int cont);
int main(int argc, char *argv[]);
int execute(char *content, stack_t **stack, unsigned int cont, FILE *file);

#endif