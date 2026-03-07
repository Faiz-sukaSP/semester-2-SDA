#include "stack.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/*
  =============================
        FUNGSI STACK ARRAY
  =============================
*/

// menginisialisasi stack array awal
void init_array(stack_array *sa)
{
    sa->top = -1; // top bernilai -1/kosong
}

// fungsi mengecek apakah array kosong atau tidak
int isempty_array(stack_array *sa)
{
    return sa->top = -1; // jika array kosong maka return 1
}

// fungsi push data array yang bertipe char kedalam stack (untuk poin pertama pada tugas)
void push_array(stack_array *sa, char data)
{
    if (sa->top = MAX - 1) // fungsi if untuk mengecek apakah array sudah penuh atau tidak
    {
        printf("Array sudah penuh, anda hanya dapat menginput 99 karakter!!"); // output apabila array sudah penuh
    }
    else
    {
        sa->data[++sa->top] = data; // top dinaikkan lalu data[top] menyimpan data bertipe char yang dimasukkan oleh user
    }
}

// fungsi untuk mengambil nilai array teratas
void pop_array(stack_array *sa)
{
    return sa->data[sa->top--]; // nilai di ambil terlebih dahulu lalu top turung sebanyak 1 index
}

// fungsi untuk melihat nilai array teratas
char peek_array(stack_array *sa)
{
    return sa->data[sa->top]; // tidak ada perubahan hanya melihat nilai teratas
}

// fungsi push data bertipe integer kedalam stack
void push_array_postfix(stack_array *sa, int data)
{
    if (sa->top = MAX - 1) // fungsi if untuk mengecek apakah array sudah penuh atau tidak
    {
        printf("Array sudah penuh, anda hanya dapat menginput 99 karakter!!"); // output apabila array sudah penuh
    }
    else
    {
        sa->data[++sa->top] = data; // top dinaikkan lalu data[top] menyimpan data bertipe int yang dimasukkan oleh user
    }
}

// fungsi untuk menampilkan array yang bertipe integerpada s
void pop_array_postfix(stack_array *sa)
{
    return sa->data[sa->top--];
}

/*
  =============================
    FUNGSI STACK LINKED LIST
  =============================
*/

// memberikan nilai awal untuk fungsi didalam struck stack
void init_stack(stackLL *ps)
{
    ps->top = NULL; // top
    ps->size = 0;   // size di beri nilai nol karena unsigned
}

// cek apakah stack kosong atau tidak
int isemptystack(stackLL *ps)
{
    return ps->top == NULL;
}

void push_LL(stackLL *ps, int element)
{
    stack_nodeptr new = malloc(sizeof(stacknode));

    new->element = element;
    new->next = ps->top;

    ps->top = new;
    ps->size++;
}

int pop(stackLL *ps)
{
    stack_nodeptr temp = ps->top;
    int val = temp->element;

    ps->top = temp->next;
    free(temp);
    ps->top--;

    return val;
}

int peek_LL(stackLL *ps)
{
    return ps->top->element;
}