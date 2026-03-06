#include "stack.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/*
  =============================
    FUNGSI-FUNGSI STACK ARRAY
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

// fungsi untuk menambahkan data kedalam stack array
void push_array(stack_array *sa, char x)
{
    if (sa->top = MAX - 1) // fungsi if untuk mengecek apakah array sudah penuh atau tidak
    {
        printf("Array sudah penuh, anda hanya dapat menginput 99 karakter!!"); // output apabila array sudah penuh
    }
    else
    {
        sa->data[++sa->top] = x;
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

/*
  =============================
    FUNGSI-FUNGSI STACK ARRAY
  =============================
*/

// memberikan nilai awal untuk fungsi didalam struck stack
void init_stack(stack *ps)
{
    ps->top = NULL; // top
    ps->size = 0;   // size di beri nilai nol karena unsigned
}