# 📚 Catatan Belajar Algoritma & Pemrograman

> Dokumentasi pribadi perjalanan belajar pemrograman dari dasar hingga struktur data lanjutan.
> Ditulis dalam sudut pandang sendiri, dilengkapi analogi kehidupan nyata agar mudah dipahami kembali.

**Bahasa:** C & C++
**Tools:** VS Code, GCC/G++ Compiler

---

## 📋 Daftar Isi

1. [Variabel & Tipe Data](#1-variabel--tipe-data)
2. [Operator](#2-operator)
3. [Selection (Percabangan)](#3-selection-percabangan)
4. [Repetition (Perulangan)](#4-repetition-perulangan)
5. [Pointer & Struct](#5-pointer--struct)
6. [Linked List](#6-linked-list)
7. [Stack & Queue](#7-stack--queue)
8. [Hash Table](#8-hash-table)
9. [Binary Tree & BST](#9-binary-tree--bst)
10. [AVL Tree](#10-avl-tree)

---

## 1. Variabel & Tipe Data

### 📌 Sudut Pandang Saya
Variabel itu seperti **kotak** yang punya nama dan bisa menyimpan sesuatu di dalamnya. Tipe data menentukan **jenis isi** kotak itu — apakah angka, huruf, atau bilangan desimal.

### 🏠 Analogi
> Bayangkan kamu punya rak di kamar:
> - Rak berlabel **"uang"** → hanya boleh isi uang (int)
> - Rak berlabel **"nama"** → hanya boleh isi nama (char)
> - Rak berlabel **"nilai"** → hanya boleh isi angka desimal (float)
>
> Kamu tidak bisa taruh nama di rak uang — itulah gunanya tipe data!

### 💻 Contoh Kode
```cpp
#include <stdio.h>

int main() {
    int umur = 20;           // bilangan bulat
    float nilai = 95.5;      // bilangan desimal
    char huruf = 'A';        // satu karakter
    char nama[50] = "Budi";  // kumpulan karakter (string)

    printf("Umur  : %d\n", umur);
    printf("Nilai : %.2f\n", nilai);
    printf("Huruf : %c\n", huruf);
    printf("Nama  : %s\n", nama);

    return 0;
}
```

### 📊 Tabel Tipe Data

| Tipe | Ukuran | Isi | Format |
|------|--------|-----|--------|
| `int` | 4 byte | Bilangan bulat | `%d` |
| `float` | 4 byte | Bilangan desimal | `%f` |
| `double` | 8 byte | Desimal presisi tinggi | `%lf` |
| `char` | 1 byte | Satu karakter | `%c` |
| `char[]` | n byte | Kumpulan karakter | `%s` |

---

## 2. Operator

### 📌 Sudut Pandang Saya
Operator adalah **alat** untuk melakukan sesuatu terhadap variabel — bisa menghitung, membandingkan, atau menggabungkan kondisi.

### 🏠 Analogi
> Operator itu seperti **tombol kalkulator**:
> - Tombol `+` untuk tambah
> - Tombol `>` untuk bandingkan
> - Tombol `&&` seperti syarat "dan" — dua-duanya harus terpenuhi

### 💻 Contoh Kode
```cpp
#include <stdio.h>

int main() {
    int a = 10, b = 3;

    // Operator Aritmatika
    printf("a + b = %d\n", a + b);   // 13
    printf("a - b = %d\n", a - b);   // 7
    printf("a * b = %d\n", a * b);   // 30
    printf("a / b = %d\n", a / b);   // 3
    printf("a %% b = %d\n", a % b);  // 1 (sisa bagi)

    // Operator Perbandingan
    printf("a > b  : %d\n", a > b);   // 1 (true)
    printf("a == b : %d\n", a == b);  // 0 (false)

    // Operator Logika
    printf("a>5 && b>5 : %d\n", a > 5 && b > 5); // 0
    printf("a>5 || b>5 : %d\n", a > 5 || b > 5); // 1

    return 0;
}
```

### 📊 Tabel Operator

| Jenis | Operator | Fungsi |
|-------|----------|--------|
| Aritmatika | `+ - * / %` | Hitung matematika |
| Perbandingan | `== != > < >= <=` | Bandingkan nilai |
| Logika | `&& \|\| !` | Gabungkan kondisi |
| Assignment | `= += -= *=` | Simpan nilai |

---

## 3. Selection (Percabangan)

### 📌 Sudut Pandang Saya
Selection adalah cara program untuk **mengambil keputusan** — mirip seperti kita memilih jalan yang berbeda berdasarkan kondisi tertentu.

### 🏠 Analogi
> Bayangkan kamu di persimpangan jalan:
> - Lampu **hijau** → jalan terus (`if`)
> - Lampu **merah** → berhenti (`else`)
> - Ada **3 persimpangan** → pilih salah satu (`else if` / `switch`)

### 💻 Contoh Kode
```cpp
#include <stdio.h>

int main() {
    int nilai = 85;

    // if - else if - else
    if (nilai >= 90) {
        printf("Grade A\n");
    } else if (nilai >= 80) {
        printf("Grade B\n");  // ini yang dijalankan
    } else if (nilai >= 70) {
        printf("Grade C\n");
    } else {
        printf("Grade D\n");
    }

    // switch case
    int hari = 1;
    switch (hari) {
        case 1: printf("Senin\n");   break;
        case 2: printf("Selasa\n");  break;
        case 3: printf("Rabu\n");    break;
        default: printf("Hari lain\n"); break;
    }

    return 0;
}
```

### ⚠️ Catatan Penting
```
if      → cek satu kondisi
else if → cek kondisi lain jika if gagal
else    → dijalankan jika semua kondisi gagal
switch  → pilih dari banyak kondisi berdasarkan nilai
```

---

## 4. Repetition (Perulangan)

### 📌 Sudut Pandang Saya
Repetition adalah cara program untuk **mengulangi sesuatu** tanpa harus menulis kode yang sama berkali-kali. Ada 3 jenis: `for`, `while`, dan `do while`.

### 🏠 Analogi
> - **for** → seperti tugas "lari 10 putaran" — sudah tahu berapa kali
> - **while** → seperti "makan sampai kenyang" — tidak tahu berapa kali, cek dulu baru lakukan
> - **do while** → seperti "coba makanan dulu, kalau enak lanjut" — lakukan dulu baru cek

### 💻 Contoh Kode
```cpp
#include <stdio.h>

int main() {
    // FOR → tahu berapa kali
    for (int i = 1; i <= 5; i++) {
        printf("for ke-%d\n", i);
    }

    // WHILE → cek dulu baru lakukan
    int j = 1;
    while (j <= 5) {
        printf("while ke-%d\n", j);
        j++;
    }

    // DO WHILE → lakukan dulu baru cek
    int k = 1;
    do {
        printf("do while ke-%d\n", k);
        k++;
    } while (k <= 5);

    return 0;
}
```

### 📊 Perbandingan

| | `for` | `while` | `do while` |
|--|-------|---------|------------|
| Cek kondisi | Sebelum | Sebelum | Sesudah |
| Minimal jalan | 0 kali | 0 kali | 1 kali |
| Cocok untuk | Tahu berapa kali | Tidak tahu berapa kali | Harus jalan minimal 1x |

---

## 5. Pointer & Struct

### 📌 Sudut Pandang Saya
**Pointer** bukan menyimpan nilai, tapi menyimpan **alamat** dari nilai. **Struct** adalah cara menggabungkan beberapa variabel berbeda tipe menjadi satu kesatuan data.

### 🏠 Analogi
> **Pointer** → seperti alamat rumah. Kamu tidak punya rumahnya, tapi kamu tahu **dimana rumah itu berada**. Dengan alamat itu kamu bisa pergi ke sana dan mengubah isinya.
>
> **Struct** → seperti **formulir data diri** yang punya banyak kolom: nama, umur, alamat — semuanya satu paket untuk satu orang.

### 💻 Contoh Kode
```cpp
#include <stdio.h>
#include <string.h>

// STRUCT
struct Mahasiswa {
    char nama[50];
    int umur;
    float ipk;
};

int main() {
    // POINTER
    int nilai = 100;
    int *ptr = &nilai;  // ptr menyimpan ALAMAT nilai

    printf("Nilai       : %d\n", nilai);   // 100
    printf("Alamat      : %p\n", &nilai);  // alamat memori
    printf("Via pointer : %d\n", *ptr);    // 100

    *ptr = 200;  // ubah nilai lewat pointer
    printf("Setelah diubah : %d\n", nilai); // 200

    // STRUCT
    struct Mahasiswa mhs;
    strcpy(mhs.nama, "Budi");
    mhs.umur = 20;
    mhs.ipk  = 3.75;

    printf("Nama : %s\n", mhs.nama);
    printf("Umur : %d\n", mhs.umur);
    printf("IPK  : %.2f\n", mhs.ipk);

    // STRUCT + POINTER (dynamic memory)
    struct Mahasiswa *mhs2 = (Mahasiswa*) malloc(sizeof(Mahasiswa));
    strcpy(mhs2->nama, "Ani");
    mhs2->umur = 19;
    free(mhs2);

    return 0;
}
```

### ⚠️ Catatan Penting
```
&variabel → ambil ALAMAT variabel
*pointer  → ambil NILAI dari alamat yang ditunjuk
->        → akses field struct lewat pointer
.         → akses field struct langsung
malloc    → alokasi memori dinamis
free      → bebaskan memori yang sudah tidak dipakai
```

---

## 6. Linked List

### 📌 Sudut Pandang Saya
Linked List adalah struktur data berbentuk **rantai** — setiap node menyimpan data dan **alamat node berikutnya**. Berbeda dengan array, ukurannya bisa bertambah dan berkurang secara dinamis.

### 🏠 Analogi
> Bayangkan **kereta api**:
> - Setiap gerbong = satu node (punya isi + sambungan ke gerbong berikutnya)
> - Lokomotif = head (gerbong paling depan)
> - Gerbong terakhir = tail (tidak punya sambungan lagi / NULL)
> - Mau tambah gerbong? Tinggal sambungkan di depan atau belakang!

### 💻 Contoh Kode
```cpp
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    char nama[50];
    Node *next;
    Node *prev;  // untuk Double Linked List
}*head = NULL, *tail = NULL;

// Push (tambah di belakang)
void push(char nama[]) {
    Node *curr = (Node*) malloc(sizeof(Node));
    strcpy(curr->nama, nama);
    curr->next = NULL;
    curr->prev = NULL;

    if (head == NULL) {
        head = tail = curr;
    } else {
        tail->next = curr;
        curr->prev = tail;
        tail = curr;
    }
}

// Pop (hapus berdasarkan nama)
void pop(char nama[]) {
    Node *prev = NULL;
    Node *curr = head;

    while (curr != NULL && strcmp(nama, curr->nama) != 0) {
        prev = curr;
        curr = curr->next;
    }

    if (curr == NULL) { printf("Tidak ditemukan!\n"); return; }
    if (prev == NULL) head = curr->next;
    else prev->next = curr->next;
    if (curr == tail) tail = prev;

    free(curr);
}

// View
void view() {
    Node *curr = head;
    while (curr != NULL) {
        printf("%s -> ", curr->nama);
        curr = curr->next;
    }
    printf("NULL\n");
}
```

### 📊 Jenis Linked List

| Jenis | Pointer | Arah |
|-------|---------|------|
| Single | `*next` | Satu arah → |
| Double | `*next, *prev` | Dua arah ↔ |
| Circular | `*next` (tail→head) | Melingkar ↺ |

---

## 7. Stack & Queue

### 📌 Sudut Pandang Saya
**Stack** dan **Queue** sebenarnya adalah Linked List dengan **aturan khusus** tentang dari mana data masuk dan keluar.

### 🏠 Analogi
> **Stack (LIFO)** → seperti **tumpukan piring**:
> Piring terakhir ditaruh = piring pertama diambil.
> Masuk dan keluar dari tempat yang SAMA (atas).
>
> **Queue (FIFO)** → seperti **antrian kasir**:
> Yang duluan antri = yang duluan dilayani.
> Masuk dari BELAKANG, keluar dari DEPAN.

### 💻 Contoh Kode
```cpp
// STACK (LIFO - Last In First Out)
void push_stack(int nilai) {
    Node *curr = (Node*) malloc(sizeof(Node));
    curr->nilai = nilai;
    curr->next  = head;  // masuk dari depan (atas)
    head = curr;
}

int pop_stack() {
    Node *temp = head;
    int nilai  = head->nilai;
    head = head->next;   // keluar dari depan (atas)
    free(temp);
    return nilai;
}

// QUEUE (FIFO - First In First Out)
void enqueue(int nilai) {
    Node *curr = (Node*) malloc(sizeof(Node));
    curr->nilai = nilai;
    curr->next  = NULL;
    tail->next  = curr;  // masuk dari belakang
    tail = curr;
}

int dequeue() {
    Node *temp = head;
    int nilai  = head->nilai;
    head = head->next;   // keluar dari depan
    free(temp);
    return nilai;
}
```

### 📊 Perbandingan Stack vs Queue

| | Stack | Queue |
|--|-------|-------|
| Konsep | LIFO | FIFO |
| Masuk | Dari atas (push) | Dari belakang (enqueue) |
| Keluar | Dari atas (pop) | Dari depan (dequeue) |
| Analogi | Tumpukan piring | Antrian kasir |
| Contoh nyata | Ctrl+Z, back browser | Antrian printer |

---

## 8. Hash Table

### 📌 Sudut Pandang Saya
Hash Table adalah struktur data yang menggunakan **fungsi hash** untuk menentukan posisi data. Tujuannya agar pencarian data menjadi sangat cepat — tidak perlu cek satu per satu.

### 🏠 Analogi
> Bayangkan **lemari arsip dengan 26 laci (A-Z)**:
> - Mau simpan data "Ani" → huruf pertama A → masuk laci A
> - Mau simpan data "Budi" → huruf pertama B → masuk laci B
> - Mau cari "Ani"? → langsung buka laci A → tidak perlu buka semua laci!
>
> Fungsi hash = **aturan yang menentukan data masuk ke laci mana**.

### 💻 Contoh Kode
```cpp
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    char nama[50];
    Node *next;
}*head[26] = {NULL};

// Fungsi Hash (berdasarkan huruf pertama)
int hash(char nama[]) {
    int idx = nama[0];
    if (idx >= 65 && idx <= 90)  return idx - 65;  // A-Z
    if (idx >= 97 && idx <= 122) return idx - 97;  // a-z
    return 0;
}

// Push
void push(char nama[]) {
    int idx  = hash(nama);
    Node *curr = (Node*) malloc(sizeof(Node));
    strcpy(curr->nama, nama);
    curr->next = NULL;

    if (head[idx] == NULL) {
        head[idx] = curr;
    } else {
        Node *temp = head[idx];
        while (temp->next != NULL) temp = temp->next;
        temp->next = curr;
    }
}

// View
void view() {
    for (int i = 0; i < 26; i++) {
        printf("%c : ", 'A' + i);
        Node *curr = head[i];
        while (curr != NULL) {
            printf("%s -> ", curr->nama);
            curr = curr->next;
        }
        printf("NULL\n");
    }
}
```

### 📊 Hash Table + BST (Versi Lanjutan)
```
Hash Table biasa    → tiap bucket pakai Linked List
Hash Table + BST    → tiap bucket pakai BST
                    → pencarian dalam bucket lebih cepat!
                    → data dalam bucket otomatis terurut!
```

---

## 9. Binary Tree & BST

### 📌 Sudut Pandang Saya
**Binary Tree** adalah struktur data berbentuk pohon dimana setiap node maksimal punya 2 anak. **BST (Binary Search Tree)** adalah Binary Tree dengan aturan tambahan: **kiri selalu lebih kecil, kanan selalu lebih besar** dari parent.

### 🏠 Analogi
> **BST** seperti **kamus yang terurut A-Z**:
> - Cari kata "Meja"? Langsung buka tengah
> - Meja > kata di tengah? Cari di bagian kanan
> - Meja < kata di tengah? Cari di bagian kiri
> - Tidak perlu baca dari halaman 1!
>
> **Root** = pintu masuk utama. Tanpa root, seluruh tree tidak bisa diakses — seperti pohon tanpa batang utama.

### 💻 Contoh Kode
```cpp
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int number;
    Node *left, *right;
}*root = NULL;

// Insert
Node *insert(Node *node, int number) {
    if (node == NULL) {
        Node *curr = (Node*) malloc(sizeof(Node));
        curr->number = number;
        curr->left = curr->right = NULL;
        return curr;
    }
    if (number < node->number)
        node->left  = insert(node->left,  number);
    else if (number > node->number)
        node->right = insert(node->right, number);
    return node;
}

// Cari nilai terkecil (untuk delete 2 anak)
Node *findMin(Node *node) {
    while (node->left != NULL)
        node = node->left;
    return node;
}

// Delete
Node *pop(Node *node, int number) {
    if (node == NULL) return NULL;
    if (number < node->number)
        node->left  = pop(node->left,  number);
    else if (number > node->number)
        node->right = pop(node->right, number);
    else {
        if (node->left == NULL && node->right == NULL) {
            free(node); return NULL;                    // Kondisi 1: Leaf
        } else if (node->left == NULL) {
            Node *temp = node->right;
            free(node); return temp;                   // Kondisi 2a: 1 anak kanan
        } else if (node->right == NULL) {
            Node *temp = node->left;
            free(node); return temp;                   // Kondisi 2b: 1 anak kiri
        } else {
            Node *temp  = findMin(node->right);        // Kondisi 3: 2 anak
            node->number = temp->number;
            node->right  = pop(node->right, temp->number);
        }
    }
    return node;
}

// Traversal
void preOrder(Node *node) {  // Tengah → Kiri → Kanan
    if (node == NULL) return;
    printf("%d -> ", node->number);
    preOrder(node->left);
    preOrder(node->right);
}

void inOrder(Node *node) {   // Kiri → Tengah → Kanan (URUT!)
    if (node == NULL) return;
    inOrder(node->left);
    printf("%d -> ", node->number);
    inOrder(node->right);
}

void postOrder(Node *node) { // Kiri → Kanan → Tengah
    if (node == NULL) return;
    postOrder(node->left);
    postOrder(node->right);
    printf("%d -> ", node->number);
}
```

### 📊 3 Kondisi Delete BST

| Kondisi | Ciri | Solusi |
|---------|------|--------|
| Leaf | Tidak punya anak | Langsung hapus |
| 1 Anak | Hanya kiri atau kanan | Anak naik menggantikan |
| 2 Anak | Punya kiri dan kanan | findMin(kanan) jadi pengganti |

### 📊 Traversal

| Traversal | Urutan | Kegunaan |
|-----------|--------|----------|
| PreOrder | Tengah→Kiri→Kanan | Salin struktur tree |
| InOrder | Kiri→Tengah→Kanan | Hasil selalu URUT! |
| PostOrder | Kiri→Kanan→Tengah | Hapus tree |

---

## 10. AVL Tree

### 📌 Sudut Pandang Saya
AVL Tree adalah BST yang bisa **menyeimbangkan dirinya sendiri** secara otomatis. Masalah BST biasa adalah jika data dimasukkan secara urut, tree jadi miring seperti Linked List dan pencarian melambat. AVL Tree mengatasi ini dengan **rotasi otomatis**.

### 🏠 Analogi
> **BST biasa** → seperti tumpukan buku yang ditaruh sembarangan — lama-lama miring ke satu sisi!
>
> **AVL Tree** → seperti tumpukan buku dengan **penyangga otomatis** — setiap kali miring, langsung diluruskan kembali!
>
> **Balance Factor** → sensor kemiringan. Kalau kemiringan > 1 atau < -1, langsung diperbaiki dengan rotasi.

### 💻 Konsep Balance Factor
```
Balance Factor = Tinggi Kiri - Tinggi Kanan

-1, 0, 1  → Seimbang ✅ tidak perlu rotasi
> 1       → Terlalu berat KIRI ❌ harus rotasi
< -1      → Terlalu berat KANAN ❌ harus rotasi
```

### 💻 Contoh Kode
```cpp
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int value;
    int height;  // ← TAMBAHAN dari BST!
    Node *left, *right;
}*root = NULL;

int getHeight(Node *curr) {
    if (curr == NULL) return 0;
    return curr->height;
}

int getMax(int a, int b) { return a > b ? a : b; }

int balanceFactor(Node *curr) {
    if (curr == NULL) return 0;
    return getHeight(curr->left) - getHeight(curr->right);
}

// Rotasi Kanan (untuk LL Case)
Node *rightRotation(Node *curr) {
    Node *child      = curr->left;
    Node *grandChild = child->right;
    child->right = curr;
    curr->left   = grandChild;
    curr->height  = getMax(getHeight(curr->left),  getHeight(curr->right))  + 1;
    child->height = getMax(getHeight(child->left), getHeight(child->right)) + 1;
    return child;
}

// Rotasi Kiri (untuk RR Case)
Node *leftRotation(Node *curr) {
    Node *child      = curr->right;
    Node *grandChild = child->left;
    child->left  = curr;
    curr->right  = grandChild;
    curr->height  = getMax(getHeight(curr->left),  getHeight(curr->right))  + 1;
    child->height = getMax(getHeight(child->left), getHeight(child->right)) + 1;
    return child;
}

// Insert
Node *insertNode(Node *curr, int value) {
    if (curr == NULL) {
        Node *n  = (Node*) malloc(sizeof(Node));
        n->value  = value;
        n->height = 1;
        n->left = n->right = NULL;
        return n;
    }
    if (value < curr->value)
        curr->left  = insertNode(curr->left,  value);
    else if (value > curr->value)
        curr->right = insertNode(curr->right, value);

    curr->height = getMax(getHeight(curr->left), getHeight(curr->right)) + 1;
    int bf = balanceFactor(curr);

    if (bf > 1  && value < curr->left->value)                           // LL
        return rightRotation(curr);
    else if (bf > 1  && value > curr->left->value) {                    // LR
        curr->left = leftRotation(curr->left);
        return rightRotation(curr);
    }
    else if (bf < -1 && value > curr->right->value)                     // RR
        return leftRotation(curr);
    else if (bf < -1 && value < curr->right->value) {                   // RL
        curr->right = rightRotation(curr->right);
        return leftRotation(curr);
    }
    return curr;
}
```

### 📊 4 Case Rotasi AVL

| Case | Kondisi | Rotasi | Contoh Insert |
|------|---------|--------|---------------|
| LL (Left Left) | bf > 1, value < left | Kanan | 10, 5, 3 |
| RR (Right Right) | bf < -1, value > right | Kiri | 3, 5, 10 |
| LR (Left Right) | bf > 1, value > left | Kiri + Kanan | 10, 3, 5 |
| RL (Right Left) | bf < -1, value < right | Kanan + Kiri | 3, 10, 5 |

### 📊 Perbedaan BST vs AVL

| Aspek | BST | AVL |
|-------|-----|-----|
| Keseimbangan | Tidak terjamin | Selalu seimbang |
| Struct tambahan | Tidak ada | `int height` |
| Insert/Delete | Rekursif biasa | Rekursif + rotasi |
| Kompleksitas | O(n) worst case | O(log n) selalu |

---

## 📊 Ringkasan Semua Materi

| No | Materi | Konsep Kunci | Kompleksitas |
|----|--------|-------------|--------------|
| 1 | Variabel | Kotak penyimpan data | - |
| 2 | Operator | Alat hitung & bandingkan | - |
| 3 | Selection | Ambil keputusan | - |
| 4 | Repetition | Ulangi instruksi | - |
| 5 | Pointer & Struct | Alamat memori & paket data | - |
| 6 | Linked List | Rantai node dinamis | O(n) |
| 7 | Stack & Queue | LIFO & FIFO | O(1) |
| 8 | Hash Table | Index berdasarkan fungsi hash | O(1) avg |
| 9 | BST | Tree terurut kiri < root < kanan | O(log n) avg |
| 10 | AVL Tree | BST + seimbang otomatis | O(log n) selalu |

---

## 🗺️ Roadmap Belajar

```
Variabel & Tipe Data
        ↓
Operator
        ↓
Selection & Repetition
        ↓
Pointer & Struct
        ↓
Linked List (Single → Double → Circular)
        ↓
Stack & Queue
        ↓
Hash Table
        ↓
Binary Tree & BST
        ↓
AVL Tree  ← posisi sekarang!
        ↓
Graph (selanjutnya!)
```

---

> 💡 **Catatan:** Dokumentasi ini ditulis berdasarkan pemahaman pribadi selama proses belajar. Setiap materi dilengkapi analogi kehidupan nyata agar lebih mudah diingat dan dipahami kembali di kemudian hari.
