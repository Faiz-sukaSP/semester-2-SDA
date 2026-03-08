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
void push_array_char(stack_array *sa, char data)
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
char pop_array_char(stack_array *sa)
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
int pop_array_postfix(stack_array *sa)
{
    return sa->data[sa->top--];
}

/*
  =============================
    FUNGSI STACK LINKED LIST
  =============================
*/

// memberikan nilai awal untuk fungsi didalam struck stack
void initLL(stackLL *ps)
{
    ps->top = NULL; // top
    ps->size = 0;   // size di beri nilai nol karena unsigned
}

// fungsi untuk mengecek apakah stack kosong atau tidak
int isemptyLL(stackLL *ps)
{
    return ps->top == NULL;
}

// fungsi untuk menambahkan elemen kedalam stack menggunakan link list
void pushLL(stackLL *ps, int element)
{
    stack_nodeptr new = malloc(sizeof(stacknode)); // new bertipe stack_nodeptr dan memesan memori di heap seukuran dengan stacknode

    new->elemen = element; // element yang akan diinput oleh user disimpan kedalam pointer elemen
    new->next = ps->top;   // node baru menjuki pada top lama
    ps->top = new;         // sekarang top adalah new(node baru)
    ps->size++;            // size bertambah 1 setiap elemen ditambah
}

// fungsi untuk menampilkan elemen dari stack
int popLL(stackLL *ps)
{
    stack_nodeptr temp = ps->top; // temp menyimpan alamat top
    int val = temp->elemen;       // val menyimpan nilai node

    ps->top = temp->next; // top sekarang menyimpan alamat node berikutnya
    free(temp);           // menghapus nilai yang disimpan kedalam temp pada memory
    ps->size--;           // size dikurangi 1 saat data dihapus

    return val;
}

// fungsi untuk menampilkan element ter pada linked list
int peekLL(stackLL *ps)
{
    return ps->top->elemen; // mengembalikan nilai elemen terluar pada stack kepada fungsi peek
}

/*
  ==============================
    FUNGSI CEK KURUNG SEIMBANG
  ==============================
*/

int cek_kurung(char expresi[])
{
    stack_array sa;  // membuat stack array yang diberi nama "sa"
    init_array(&sa); // mengambil alamat memori init_array(salah satu fungsi di awal program)

    // loop untuk membaca setiap karakter hingga akhir string
    for (int i = 0; expresi[i]; i++)
    {
        char c = expresi[i];                  // c menyimpan nilai setiap string
        if (c == '(' || c == '[' || c == '{') // cek apakah c sesuai dengan kondisi if
            push_array(&sa, c);               // jika sesuai maka di push kedalam stack

        else if (c == ')' || c == ']' || c == '}')
        {
            if (isempty_array(&sa)) // jika kurung tutup tidak ada dan tidak sesuai maka program berhenti
                return 0;           // program langsung berhenti

            char top = pop_array_char(&sa); // top menyimpan nilai pop_array_char

            // cek pasangan kurung apakah sesuai atau tidak
            if ((c == ')' && top != '(') ||
                (c == ']' && top != '[') ||
                (c == ' }' && top != '{'))
                return 0;
        }
    }
    return isempty_array(&sa); // jika stack sudah kosong maka akan return 1
}

/*
  =============================
    FUNGSI PRIORITAS OPERATOR
  =============================
*/

int priority(char operation)
{
    if ((operation == '+' || operation == '-'))
        return 1;
    if ((operation == '*' || operation == '/'))
        return 2;

    return 0;
}

/*
  ========================
       INFIX -> POSTFIX
  ========================
*/

void infix_to_postfix(char infix[], char postfix[])
{
    stackLL ps;      // ps menyimpan variabel yang digunakan untuk stackLL
    init_stack(&ps); // memanggi fungsi inisialisasi yang telah dibuat sebelumnya

    // variabel sebagai index array
    int i = 0, j = 0;

    // loop untuk membaca infix hingga ketemu '/0'
    while (infix[i])
    {
        char c = infix[i]; // char c diberi nilai infix pada posisi i

        if (isalnum(c))       // cek apakah sting ke-c adalah alfanumerik atau bukan
            postfix[j++] = c; // jika iya maka postfif awal menampung nilai c

        else if (c == '(')              // jika postfix selain bilangan alfanumerik dan "("
            push_array_postfix(&ps, c); // nilai c akan di push kedalam stack

        else if (c == ')') //// jika postfix selain bilangan alfanumerik dan ")"
        {
            while (!isempty_stack(&ps) && peek_LL(&ps) != '(') // looping selama stack belum kosong dan stack bukan "c"
                postfix[j++] = popLL(&ps);                     // keluarkan operator dari stack ke postfix

            popLL(&ps); // membuang kurung "("
        }

        else // jika operator (+,-,*,/)
        {
            while (!isempty_stack(&ps) && operation(peek_LL(&ps)) >= operation(c)) // loop berjalan apabila stack tidak kosong dan apakah salah satu operasi lebih besar daripada operasi 1 nya
                postfix[j++] = popLL(&ps);                                         // maka operator di stack dipindahkan ke postfix

            pushLL(&ps, c); // operator baru dimasukkan kedalam stack
        }
        i++; // index infix bertambah untuk membaca karakter berikutnya
    }
    while (!isempty_stack(&ps))    // loop apakah masih ada operator di stack
        postfix[j++] = popLL(&ps); // jika ada maka pindahkan ke postfix

    postfix[j] = '\0'; // menambahkan null terminator
}

/*
  ================================
   FUNGSI EVALUASI POSTFIX ARRAY
  ================================
*/

int ev_post_arr(char postfix[]) // mengembalikan nilai integer dengan parameter berupa char string[]
{
    stack_array sa;  // membuat stack array yang diberi nama "sa"
    init_array(&sa); // mengambil alamat memori init_array(salah satu fungsi di awal program)

    for (int i = 0; postfix[i]; i++) // loop untuk membaca postfix hingga ketemu '/0'
    {
        char c = postfix[i]; // char c menerima nilai postfix[i]

        if (isdigit(c))                    // cek apakah c adalah angka
            push_array_char(&sa, c - '0'); /*jika iya maka karakter angka harus diubah terlebih dulu menjadi integer
                                             dengan pengurangan nilai ASCII dan dimasukkan kedalam stack */

        else
        {
            int a = pop_array_char(&sa); // a mengambil elemen pertama dari stack
            int b = pop_array_char(&sa); // b menggambil elemen dibawah elemen pertama dari stack

            switch (c) // menentukan operator apa yang harus digunakan
            {
            case '+':
                push_array_char(&sa, b + a); // jika penjumlahan maka elemen ditambah dan dimasukkan kedalam stack
                break;
            case '-':
                push_array_char(&sa, b - a); // jika penjumlahan maka elemen dikurangi dan dimasukkan kedalam stack
                break;
            case '*':
                push_array_char(&sa, b * a); // jika penjumlahan maka elemen dikalikan dan dimasukkan kedalam stack
                break;
            case '/':
                push_array_char(&sa, b / a); // jika penjumlahan maka elemen ditbagi dan dimasukkan kedalam stack
                break;
            }
        }
    }
    return pop_array_char(&sa); // mengambil nilai terakhir dari stack dan mengembalikan nilainya sebagai hasil fungsi
}

/*
  ========================================
    FUNGSI EVALUASI POSTFIX LINGKED LIST
  ========================================
*/

int ev_postLL(char postfix[]) // mengembalikan nilai integer dengan parameter berupa char string[]
{
    stackLL ps;  // membuat stack array yang diberi nama "ps"
    initLL(&ps); // mengambil alamat memori init_array(salah satu fungsi di awal program)

    for (int i = 0; postfix[i]; i++) // loop untuk membaca postfix hingga ketemu '/0'
    {
        char c = postfix[i]; // char c menerima nilai postfix[i]

        if (isdigit(c))                       // cek apakah c adalah angka
            push_array_postfix(&ps, c - '0'); /*jika iya maka karakter angka harus diubah terlebih dulu menjadi integer
                                             dengan pengurangan nilai ASCII dan dimasukkan kedalam stack */
        // jika "c" bukan angka
        else
        {
            int a = pop_array_postfix(&ps); // a mengambil elemen pertama dari stack
            int b = pop_array_postfix(&ps); // b menggambil elemen dibawah elemen pertama dari stack

            switch (c) // menentukan operator apa yang harus digunakan
            {
            case '+':
                push_array_postfix(&ps, b + a); // jika penjumlahan maka elemen ditambah dan dimasukkan kedalam stack
                break;
            case '-':
                push_array_postfix(&ps, b - a); // jika penjumlahan maka elemen dikurangi dan dimasukkan kedalam stack
                break;
            case '*':
                push_array_postfix(&ps, b * a); // jika penjumlahan maka elemen dikalikan dan dimasukkan kedalam stack
                break;
            case '/':
                push_array_postfix(&ps, b / a); // jika penjumlahan maka elemen ditbagi dan dimasukkan kedalam stack
                break;

            default:
                break;
            }
        }
    }
    return pop_array_postfix(&ps); // mengambil nilai terakhir dari stack dan mengembalikan nilainya sebagai hasil fungsi
}
