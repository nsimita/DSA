//6
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int a[n];  
    
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    // for ascending order of even index
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1; j++) {
            if (j % 2 == 0 && j + 2 < n && a[j] > a[j + 2]) { 
                int temp = a[j];
                a[j] = a[j + 2];
                a[j + 2] = temp;
            }
        }
    }

    //  for descending order odd index
    for (int i = 0; i < n - 1; i++) {
        for (int j = 1; j < n - 1; j += 2) {  
            if (j + 2 < n && a[j] < a[j + 2]) { 
                int temp = a[j];
                a[j] = a[j + 2];
                a[j + 2] = temp;
            }
        }
    }

 
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;

    
}