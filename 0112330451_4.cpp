#include <iostream>
#include <vector>
using namespace std;

struct temp {
    int sum, low, high;  
};

temp Crossp(vector<int> a , int low, int mid, int high){
    temp n = {0, -1, -1};

     
    if(mid-1 >= low && mid+1 <= high){
        n.sum = a[mid-1] + a[mid] + a[mid+1];
        n.low = mid-1;
        n.high = mid+1;
    }
    return n;
}

temp Max(vector<int> a, int low, int high){
  
    if(high - low + 1 < 3) return {0, -1, -1};

     
    if(high - low + 1 == 3){
        int total = a[low] + a[low+1] + a[high];
        temp n;
        return {total, low, high};
    }

    int mid = (low + high)/2;

  temp left  = Max(a, low, mid);
    temp right = Max(a, mid+1, high);
    temp cross = Crossp(a, low, mid, high);

    if(left.sum >= right.sum && left.sum >= cross.sum) return left;
    else if(right.sum >= left.sum && right.sum >= cross.sum) return right;
    else return cross;
}

int main (){
    vector<int> a = {28, 31, 29, 34, 30, 33, 27, 35, 32};
    int n = a.size();
    temp p = Max(a, 0, n-1);

    cout << "Maximum 3-day temperature sum = " << p.sum << endl;
    cout << "3-day subarray: ";
    int low = p.low;
    int high = p.high;
    for(int i =low; i <= high; i++){
        cout << a[i] << " ";
    }
     
}
