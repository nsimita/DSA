#include <iostream>
#include <vector>
#include <algorithm> //for sort
using namespace std;
//vector is a dynamic array -> works like arraylist in java. it's a part of STL(standard template library)

int main(){
     vector <int> v ; // vector of integer type. v is a vector object.

      //vector <int> v(5) ; // to specify the size of the vector. this will create a vector of size 5 with all elements intialized to 0.
      v.push_back(31); //adding elements to the vector. it adds at the end of the vector
      v.push_back(34); 
      v.push_back(13);
     
      for (int i=0; i<=v.size(); i++){ // that v.size() will give the size of the vector
             cout<<v[i]<<" ";
      }
      v.push_back(44);
      v.push_back(32);
      for(int i:v) { //for each loop to iterate through the vector
            cout<<i<<" "<<endl;
      }
       
        int n = v.size(); 
        cout<<"size: "<<n<<endl;
      //updation
      v[2] =77;
      v[4] = 89; //updating value to a specific index
      // v[6] = 99;   this will give error message as index out of bounds
      for(int i:v) { //for each loop to iterate through the vector
            cout<<i<<" "<<endl;
      }

      vector <int> v2(5); // allocating spaces for v2 vector
      v2.push_back(78); //this will insert at the 5 no index -> appending at the end (0 to 4 will be shown 0)
      for(int i:v2) {  
            cout<<i<<" "<<endl;
      }
     
      cout<<" "<<endl;
      vector <int> v3(4, -2);// this will create a vector of size 4 with all elements initialized to -2
        for(int i:v3) {  
            cout<<i<<" "<<endl;
      }
      cout<<" "<<endl;
      //insert 21 at index 1 
      v3.insert(v3.begin()+1, 21); // v.begin( ) means 1st element and +1 that means 2nd element
      for(int i:v3) {  
            cout<<i<<" "<<endl;
      }
      cout<<" "<<endl;

      //remove element at index 2
      v3.erase(v3.end()-1); // end is the last elemnemt so v.end()-1 -> 4-1 = 3rd index
      for(int i:v3) {  
            cout<<i<<" "<<endl;
      } 

      cout<<"vector sorting"<<endl;
      vector <int> rm = {9, 12, 3 ,10};
       sort(rm.begin(), rm.end()); // sort in ascending order
       cout<<"ascending order: "<<endl;
        for(int i:rm) {  
            cout<<i<<" ";
      }
      cout<<" "<< endl; 
      sort(rm.rbegin(),rm.rend()); // descending order
      cout<<"descending order: "<<endl;
       for(int i:rm) {  
            cout<<i<<" ";
      } 

}