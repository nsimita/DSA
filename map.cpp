#include <iostream>
#include <vector>  // colection of objects
#include <map> // collection of key-value pairs

using namespace std;
int main(){
    vector <int> ar = {5, 1, 21, 6, 5, 16, 21, 5 ,1 };
    map <int , int> num ; // key is unique , value is not unique - here key is element and value is frequency
    for (auto x : ar){ // auto helps the compiler to recognize the type of x
        num[x]++ ; //increment the frequency of x
        //  x is copying the array element and incresing the frequency 
    }
    for(auto y : num){
        cout<<y.first <<"--> " <<y.second <<endl; // y.first is key- array element and y.second is value - frequency
        // it sorts key by default
    }
}