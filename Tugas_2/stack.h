// PENCEGAHAN REDEFINITOIN APABILA FILE INI DIPANGGIL OLEH LEBIH DARI 1 FILE.C
#ifndef stack_h
#define stack_h

#define MAX 100

// DEKLARASI STUCK ARRAY
typedef struct
{
    char data[MAX];
    int top;
} stack_array;

// DEKLARASI STRUCT ALAMAT MEMORI PADA AWAL MENGGUNAKAN "nodeptr" SEHINGGA NEXT BUKAN LAGI "STRUCT *NODE"
typedef struct stacknode *stack_nodeptr;

// DEKLARASI STRUCK STACKNODE
typedef struct stacknode
{
    int element;
    stack_nodeptr next; // pointer yang menghubungkan ke alamat seterusnya
} stacknode;

// DEKLARASI STRUCK STACKLL
typedef struct stackLL
{
    stack_nodeptr top; // mendeklarasikan top yang bertipe stack_nodeptr"
    unsigned size;     // mendeklarasikan size yang bertipe unsigned sehingga ukuran selalu dicatat dengan bilangan bulat positif
} stackLL;

// DEKLARASI STRUCK STACK ARRAY
typedef struct
{
    char data[100]; // mendeklarasikan array data berukuran 100
    int top;
} stack_array;

// MENDEKLARASIKAN FUNGSI-FUNGSI YANG AKAN SAYA GUNAKAN
void inisialisasi_awal();

#endif