/** EL2008 Praktikum Pemecahan Masalah dengan Pemrograman 2024/2025
 *   Modul               : 2 - Data Manipulation and External Files
 *   Hari dan Tanggal    : Senin, 20 April 2026
 *   Nama (NIM)          : Yozia Gedalya Marcho Ginting (13224001)
 *   Nama File           : soal1.c
 *   Deskripsi           : Program memperbaiki data invalid.
 * 
 */

 /************* LIBRARIES **************/
 #include <stdio.h>
 #include <string.h>
 #include <stdlib.h>

 /************** FUNCTIONS *************/
 // Finds the corrupt data
 int finder(int *data, int size) {
    for (short i = 0; i < size; i++) {
        if (data[i] == -1) {
            return i;
        }
    }
    return -1;
 }

int find_right(int *data, int size, int index) {
    int index_right = -1;
    for (int i = index + 1; i < size; ++i) {
        if (data[i] != -1) {
            index_right = i;
            break;
        }
    }
    return index_right;
}

int find_left(int *data, int size, int index) {
    int index_left = -1;
    for (int i = index - 1; i > -1; --i) {
        if (data[i] != -1) {
            index_left = i;
            break;
        }
    }
    return index_left;
}

 int main() {
    // Read user input
    int size;
    scanf("%d", &size);

    int data[size];
    for (short i = 0; i < size; ++i) {
        scanf("%d", &data[i]);
    }

    while (1) {
        int index_corrupt = finder(data, size);
        int index_left, index_right = -1;
        if (index_corrupt != -1) {
            index_left = find_left(data, size, index_corrupt);
            index_right = find_right(data, size, index_corrupt);
            if (index_left != -1 && index_right != -1) {
                data[index_corrupt] = (data[index_left] + data[index_right]) / 2; // Floored
                if ((data[index_left] + data[index_right] % 2 != 0 && data[index_corrupt] < 0))
                    data[index_corrupt] -= 1;
            } else if (index_left == -1 && index_right != -1) {
                data[index_corrupt] = data[index_right];
            } else if (index_left != -1 && index_right == -1) {
                data[index_corrupt] = data[index_left];
            } else {
                data[index_corrupt] = 0;
            }
        } else
            break;
    }

    int sum = 0;
    printf("RECOVERED");
    for (short i = 0; i < size; ++i) {
        printf(" %d", data[i]);
    }
    printf("\n");
    int max = -9999999;
    int positive = 0;
    for (short i = 0; i < size; ++i) {
        if (data[i] >= 0) {
            sum += data[i];
            positive++;
        }
    }

    if (positive == 0) {
        int max = -9999999;
        for (short i = 0; i < size; ++i) {
            if (data[i] > max) {
                max = data[i];
            }
        sum = max;
        }
    }
    
    printf("MAX_SUM %d", sum);
    return 0;
}
