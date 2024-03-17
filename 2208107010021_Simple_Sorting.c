#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Fungsi untuk melakukan pengurutan menggunakan bubble sort
void bubbleSort(int arr[], int n) {
    int i, j, temp;
    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

// Fungsi untuk melakukan pengurutan menggunakan selection sort
void selectionSort(int arr[], int n) {
    int i, j, min_idx, temp;
    for (i = 0; i < n-1; i++) {
        min_idx = i;
        for (j = i+1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
    }
}

// Fungsi untuk melakukan pengurutan menggunakan insertion sort
void insertionSort(int arr[], int n) {
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j+1] = arr[j];
            j = j - 1;
        }
        arr[j+1] = key;
    }
}

int main() {
    // Inisialisasi array
    int *arr = malloc(1000000 * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    // Generate bilangan secara acak
    srand(time(NULL));
    for (int i = 0; i < 1000000; i++) {
        arr[i] = rand();
    }

    // Simpan bilangan yang belum terurut ke dalam file
    FILE *file_unsorted = fopen("unsorted_numbers.txt", "w");
    if (file_unsorted == NULL) {
        printf("Failed to open file for unsorted numbers.\n");
        return 1;
    }
    for (int i = 0; i < 1000000; i++) {
        fprintf(file_unsorted, "%d\n", arr[i]);
    }
    fclose(file_unsorted);

    // Lakukan pengurutan dan catat waktu yang diperlukan
    clock_t start, end;
    double cpu_time_used;

    for (int n = 100000; n <= 1000000; n += 100000) {
        int *arr_copy = malloc(n * sizeof(int));
        if (arr_copy == NULL) {
            printf("Memory allocation failed.\n");
            return 1;
        }
        for (int i = 0; i < n; i++) {
            arr_copy[i] = arr[i];
        }

        start = clock();
        bubbleSort(arr_copy, n);
        end = clock();
        cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
        printf("Bubble Sort - %d numbers: %f seconds\n", n, cpu_time_used);

        start = clock();
        selectionSort(arr_copy, n);
        end = clock();
        cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
        printf("Selection Sort - %d numbers: %f seconds\n", n, cpu_time_used);

        start = clock();
        insertionSort(arr_copy, n);
        end = clock();
        cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
        printf("Insertion Sort - %d numbers: %f seconds\n", n, cpu_time_used);

        // Simpan bilangan yang sudah terurut ke dalam file
        FILE *file_sorted = fopen("sorted_numbers.txt", "a");
        if (file_sorted == NULL) {
            printf("Failed to open file for sorted numbers.\n");
            return 1;
        }
        for (int i = 0; i < n; i++) {
            fprintf(file_sorted, "%d\n", arr_copy[i]);
        }
        fclose(file_sorted);

        free(arr_copy);
    }

    free(arr);
    return 0;
}
