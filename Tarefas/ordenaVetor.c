#include <stdio.h>
#include <stdbool.h>

bool backtrack_sort(int arr[], int n, int current_perm[], bool usado[], int index) {
    if (index == n) {
        for (int i = 0; i < n; i++) {
            arr[i] = current_perm[i];
        }
        return true;
    }

    for (int i = 0; i < n; i++) {
        if (!usado[i]) {
            if (index > 0 && arr[i] < current_perm[index - 1]) {
                continue; 
            }

            usado[i] = true;
            current_perm[index] = arr[i];

            if (backtrack_sort(arr, n, current_perm, usado, index + 1)) {
                return true;
            }

            usado[i] = false;
        }
    }
    return false;
}

void ordenar_backtracking(int arr[], int n) {
    int current_perm[n];
    bool usado[n];
    for (int i = 0; i < n; i++) usado[i] = false;
    
    backtrack_sort(arr, n, current_perm, usado, 0);
}