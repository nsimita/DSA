#include<iostream>
#include<vector>  
using namespace std;

void DPcoinChange(vector<int> coin, int d, int M){
    int minCoin [M+1]; //store kore each amount e koyta coin lagbe
    int b[M+1]; //store kore kon coin ta nibo each amount er jonno
    minCoin[0] =0; //0 er jonno value 0 set
    for(int m =1; m<=M ; m++){
        minCoin[m] = INT_MIN ;//initially sob coin infinity
        for(int i=0; i<d; i++){ //avaiable coin gulo check korbe select kora jabe kina
            if(m >= coin[i]){ // jodi amount ta coin theke boro or soman hoy
                if(1 + minCoin[m-coin[i]]< minCoin[m]) { //jodi ei coin total coin theke choto hoy
                  minCoin[m] = 1+minCoin[ m-coin[i] ]; }  //eita k select korbo
                b[m] = coin[i] ; // eta backtrack array teo rakhbo

            }

        }

    }

    cout<<"Selected coins: "<<endl;
    int i = M;
    while(i>0){
        cout<<b[i]<<", ";
        i = i- b[i];
    }
}
int main (){
    vector<int> coin ={1,2,6};
    int M = 11;
    int d = 3;
    DPcoinChange(coin , d , M);
 }