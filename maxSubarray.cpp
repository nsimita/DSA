#include<iostream>
#include <vector>
using namespace std;

struct Subarray  //everything is public here
{
//why struct ? because we want to return sum, and its start and end index together
    int sum, low, high;
};

Subarray maxcross(vector<int> a, int low, int mid, int high) // function of subarray datatype
{
    int sum=0;
    int left_sum = INT_MIN;
    int l_id = -1;
    for(int i=mid; i>=low; i--)
    {
        sum= a[i];
        if(sum>= left_sum)
        {
            left_sum= sum;
            l_id = i;
        }
    }
    int right_sum = INT_MIN;
    int r_id = -1;
    sum=0;
    for(int j=mid+1; j<=high; j++)
    {
        sum= a[j];
        if(sum>= right_sum)
        {
            right_sum= sum;
            r_id = j;
        }
    }
    Subarray n;
    n.sum =left_sum+right_sum;
    n.low= l_id;
    n.high = r_id;
    return n ;
}
Subarray MaxSubA (vector<int> a, int low, int high)
{
    if(low==high)
    {
        Subarray n;
        n.low = low;
        n.high = high;
        n.sum= a[low];
        return n;
    }
    int mid = (low+high)/2;
    Subarray left = MaxSubA(a, low, mid);
    Subarray right = MaxSubA (a, mid+1, high);
    Subarray cross = maxcross(a, low, mid,  high);
    if(left.sum>=right.sum&& left.sum>=cross.sum ) return left;
    else if(right.sum>=left.sum&& right.sum>=cross.sum ) return right;
    else return cross;


}

int main()
{
    vector<int>  v = {28, 31, 29, 34, 30, 33, 27, 35, 32};
    int n = v.size();
    Subarray s = MaxSubA(v, 0,n-1);

    int sum = s.sum;
    int low = s.low;
    int high = s.high;

    cout<<"Maximum sub array sum: "<<sum<<endl;
    cout<<"maximum sub array : ";
    for(int i=low; i<=high; i++)
    {

        cout<<v[i]<<" "<<endl;
    }
}