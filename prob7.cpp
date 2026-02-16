//7 
#include <iostream>
using namespace std;

int main() {
    int n;
    cin>>n;
    
    int a[n];
    for(int i=0; i<n; i++){
        cin>> a[i];
    }
    for (int i = 1; i < n; i++) {
        int temp = a[i];
        int j = i - 1;

        while (j >= 0 && a[j] > temp) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = temp;
    }

     int l = 1;   
    int current = 1;

    for (int i = 1; i < n; i++) {
        if (a[i] == a[i - 1] + 1) {  
            current++;
        } else if (a[i] != a[i - 1]) {   
            if (current > l) {  
                l = current;
            }
            current = 1;   
        }
    }

     if (current > l) {
        l = current;
    }

     cout <<  l << endl;

    return 0;
}