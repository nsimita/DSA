#include <iostream>
using namespace std;
void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    
    int L[n1], R[n2]; 
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}
void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

int main() {
    int m, n;
    cin >> m;
    cin >> n;
    
    int a[m], b[n];
    cout << "Taking input for array a: ";
    for (int i = 0; i < m; i++) {
        cin >> a[i];
    }
    cout << "Taking input for array b: ";
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    int merged[m + n];
    for (int i = 0; i < m; i++) {
        merged[i] = a[i];
    }

    for (int i = 0; i < n; i++) {
        merged[m + i] = b[i];
    }
    mergeSort(merged, 0, m + n - 1);
    cout << "Sorted Merged Array: ";
    for (int i = 0; i < m + n; i++) {
        cout << merged[i] << " ";
    }
    cout << endl;

    return 0;
}
