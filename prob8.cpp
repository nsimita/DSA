//8
#include <iostream>
using namespace std;

 int countFreq(int arr[], int n, int freqArr[][2]) {
    int count = 0;
    bool found;
    for (int i = 0; i < n; i++) {
        found = false;
         for (int j = 0; j < count; j++) {
            if (freqArr[j][0] == arr[i]) {
                freqArr[j][1]++;      
                found = true;
                break;
            }
        }
        if (!found) {
            freqArr[count][0] = arr[i];   
            freqArr[count][1] = 1;        
            count++;   
        }
    }
    return count;   
}

 
void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

 
void Sort(int f[][2], int count) {
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
             if (f[j][1] < f[j + 1][1]) {
                 swap(f[j][0], f[j + 1][0]);
                swap(f[j][1], f[j + 1][1]);
            }
             else if (f[j][1] == f[j + 1][1] && f[j][0] > f[j + 1][0]) {
                 swap(f[j][0], f[j + 1][0]);
                swap(f[j][1], f[j + 1][1]);
            }
        }
    }
}

 void print(int f[][2], int count) {
    for (int i = 0; i < count; i++) {
         for (int j = 0; j < f[i][1]; j++) {
            cout << f[i][0] << " ";
        }
    }
    cout << endl; 
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    int arr[n];  
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int f[n][2];  
    int count = countFreq(arr, n, f);  

     
    Sort(f, count);

     
    print(f, count);

    return 0;
}