#include <iostream>
using namespace std;

int main(){
 int bottle[] ={3,4,5};
 int minG = 0;
 int i = 0;
 int Max = 6;
 cout<<"Selected drinks : "<<endl;

 while(Max>0){
    if(Max>= bottle[i]){
        int x = Max/bottle[i];
        minG += x;
         Max = Max-x* bottle[i];
         cout<<bottle[i]<<"--> "<< x<< endl;

    }
    i++;
 }

 cout<<"Minimum number of drink: "<<minG<<endl;

}
