#ifndef _MONTY_H_
#define _MONTY_H_

/* c standard libraries */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <ctype.h>
#include <limits.h>

/* macros */

#define LIFO 1
#define FIFO 0
#define TRUE (1 == 1)
#define FALSE (!TRUE)

/* errors */

#define ERROR_MALLOC 0
#define ERROR_USAGE_FILE 1
#define ERROR_OPEN_FILE 2
#define ERROR_UKNOWN 3
#define ERROR_PUSH 4
#define ERROR_PINT 5
#define ERROR_POP 6
#define ERROR_SWAP 7
#define ERROR_ADD 8
#define ERROR_SUB 9
#define ERROR_DIV 10
#define ERROR_DIV_ZERO 11
#define ERROR_MUL 12
#define ERROR_MOD 13
#define ERROR_STACK_EMPTY 14
#define ERROR_PCHAR_RANGE 15

/* structs */

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
 * struct inventory_s - struct that points to all other structs in the project
 * @filename: filename from argv[1]
 * @stack: pointer to stack
 * @line: line input from getline
 * @input: lines of files parsed into separate elements
 * @line_num: line number
 * @file: input file
 * @order: FIFO, LIFO, stack or queue
 */
typedef struct inventory_s
{
	char *filename;
	stack_t *stack;
	char *line;
	char **input;
	unsigned int line_num;
	FILE *file;
	int order;
} inventory_t;

/* global variables */
extern inventory_t *inventory;
inventory_t *inventory;

int inventory_structure(void);
int are_digits(char *str);
int dprintf(int fd, const char *format, ...);
ssize_t getline(char **lineptr, size_t *n, FILE *stream);

/* stack methods */
void add_node_order_LIFO(stack_t **stack, stack_t *new);
void add_node_order_FIFO(stack_t **stack, stack_t *new);
void _push(stack_t **stack, unsigned int line_num);
void _pall(stack_t **stack, unsigned int line_num);
void _pint(stack_t **stack, unsigned int line_num);
void _pop(stack_t **stack, unsigned int line_num);
void _swap(stack_t **stack, unsigned int line_num);
void _add(stack_t **stack, unsigned int line_num);
void _nop(stack_t **stack, unsigned int line_num);
void _sub(stack_t **stack, unsigned int line_num);
void _div(stack_t **stack, unsigned int line_num);
void _mul(stack_t **stack, unsigned int line_num);
void _mod(stack_t **stack, unsigned int line_num);
void _pchar(stack_t **stack, unsigned int line_num);
void _pstr(stack_t **stack, unsigned int line_num);
void _rotl(stack_t **stack, unsigned int line_num);
void _rotr(stack_t **stack, unsigned int line_num);
void _stack(stack_t **stack, unsigned int line_num);
void _queue(stack_t **stack, unsigned int line_num);

/* error handling and freeing memory*/
void handle_errors(int e);
void free_stack(void);
void free_all(void);

void (*handle_opcode(void))(stack_t **stack, unsigned int line_num);
int parse_l(char *line);

#endif /* _MONTY_H_ */
