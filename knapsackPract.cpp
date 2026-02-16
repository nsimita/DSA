#include <iostream>
#include <vector>
#include <algorithm>

class fruit {
  public:
  string name;
  double vol, sugar, unit;
  fruit(string n, double v, double s) : name(n), vol(v), sugar(s), unit(s/v) {} 
};
bool compare (fruit a1, fruit a2){
    return a1.unit < a2.unit;
}
 void knapsack (vector<fruit> a, int n, int W){
    sort(a.begin(), a.end(), compare);
  double suga = 0 ;
    int i = 0;
    cout<<"selected items: "<<endl;
    while (W> 0 && i<n){
        if(a[i].weight >= W){
            suga+= suga;
            cout<<"Name: "<<name<<" , Sugar content : "<<suga<<endl;
            W = W- a[i].weight;
        }
        else{
            double taken= W;
            double p = taken*a[i].unit;
            suga+= suga;
            W=0;
             cout<<"Name: "<<name<<" , Sugar content : "<<suga<<endl;

        }
         i++;
    }
    cout<<"Min sugar: "<<suga<<endl; 

 }
int main (){
 vector <fruit> a = {("Apple", 200, 36),("Orange",300,42),("papaya", 250, 20), ("Mango", 150, 45),("watermelon", 400, 30)};
 int n = a.size();
  int W = 1000;
 knapsack (a, n, W );

}
