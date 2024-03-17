Cara menjalankan program :
1. buka terminal
2. compile kode program dengan compiler C, contoh: gcc -Wall 2208107010021_Simple_Sorting.c -o Simple_Sorting
3. jalankan program tersebut dengan perintah: ./Simple_Sorting

fungsi yang digunakan :
1. bubbleSort(int arr[], int n): Fungsi ini mengimplementasikan algoritma bubble sort untuk mengurutkan array arr dengan n elemen. Algoritma bubble sort membandingkan dua elemen sekaligus dan menukar posisi jika urutannya salah, sehingga elemen terbesar bergerak ke akhir array seperti gelembung naik ke permukaan.
2. selectionSort(int arr[], int n): Fungsi ini mengimplementasikan algoritma selection sort untuk mengurutkan array arr dengan n elemen. Algoritma selection sort memilih elemen terkecil dari array yang belum terurut dan menukar posisinya dengan elemen pertama dari array yang belum terurut.
3. insertionSort(int arr[], int n): Fungsi ini mengimplementasikan algoritma insertion sort untuk mengurutkan array arr dengan n elemen. Algoritma insertion sort membagi array menjadi dua bagian, bagian yang sudah diurutkan dan bagian yang belum. Kemudian, setiap elemen dari bagian yang belum diurutkan dimasukkan ke dalam bagian yang sudah diurutkan sesuai dengan urutan yang benar.
4. main(): Fungsi utama program. Pada bagian ini, program melakukan inisialisasi array, mengisi array dengan bilangan acak, menyimpan bilangan yang belum terurut ke dalam file, melakukan pengurutan dengan ketiga algoritma yang disebutkan di atas, mencatat waktu yang diperlukan untuk setiap pengurutan, dan menyimpan bilangan yang sudah terurut ke dalam file.
