






faizasra@MacBook-Pro-faiz Tugas_2 % leaks --atExit -- ./program

===== Program Stack =====
1. Cek Kurung Seimbang (Arr)
2. Konvert Infix ke Postfix (LL)
3. Menentukan Nilai Akhir Ekspersi Postfix (LL & Arr)
4. Keluar
Masukkan Pilihan Menu: 1

------ Cek Kurung ------
Masukkan Ekspresi Kurung: (({({([[( ) ( )]])})}))
Hasil: Ekspresi "(({({([[( ) ( )]])})}))" Seimbang 

Masukkan Pilihan Menu: ([{({([[( ) ( )]))})}))

------ Cek Kurung ------
Masukkan Ekspresi Kurung: Hasil: Ekspresi "[{({([[( ) ( )]))})}))" Tidak Seimbang 

Masukkan Pilihan Menu: 2

------ Infix -> Postfix ------
Masukkan Ekspresi Infix: (8/2)+3*2
Ekspresi Infix: (8/2)+3*2
Ekspresi Postfix: 82/32*+

Masukkan Pilihan Menu: 3
Ekspresi Postfix  : 82/32*+
Hasil Postfix(Arr): 10
Hasil Postfix(LL): 10

Masukkan Pilihan Menu: 4
Program Selesai, Membersihkan Memori....

Program Selesai, Membersihkan Memori....
Process:         program [8670]
Path:            /Users/USER/Desktop/*/program
Load Address:    0x107306000
Identifier:      program
Version:         ???
Code Type:       X86-64
Platform:        macOS
Parent Process:  leaks [8669]

Date/Time:       2026-03-10 12:20:29.576 +0700
Launch Time:     2026-03-10 12:16:38.375 +0700
OS Version:      macOS 12.7.6 (21H1320)
Report Version:  7
Analysis Tool:   /usr/bin/leaks

Physical footprint:         2052K
Physical footprint (peak):  2052K
----

leaks Report Version: 4.0
Process 8670: 171 nodes malloced for 17 KB
Process 8670: 0 leaks for 0 total leaked bytes.