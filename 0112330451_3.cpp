#include <iostream>
#include <vector>

using namespace std;

void RodCut(vector<int> length, vector<int> price, int d, int rodLength) {
    int maxPrice [rodLength+1];
    int b [rodLength+1];
    maxPrice[0] =0;

    for (int l = 1; l <= rodLength; l++) {
        maxPrice[l] = INT_MIN;
        for (int i = 0; i < d; i++) {
            if (l >= length[i]) {
                if (price[i] + maxPrice[l - length[i]] > maxPrice[l]) {
                    maxPrice[l] = price[i] + maxPrice[l - length[i]];
                    b[l] = length[i];  
                }
            }
        }
    }

    cout << "Maximum price: " << maxPrice[rodLength] << endl;
    cout << "Cuts : ";
    int i = rodLength;
    while (i > 0) {
        cout << b[i] << " ";
        i = i - b[i];
    }
    cout << endl;
}

int main() {
    vector<int> length = {1, 2, 3, 4, 5, 7, 8};
    vector<int> price  = {2, 5, 7, 8, 10, 17, 20};
    int rodLength = 5;
    int d = length.size();

    RodCut(length, price, d, rodLength);
}
