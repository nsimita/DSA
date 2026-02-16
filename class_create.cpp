#include <iostream>
using namespace std;

class student{
 
    string name; 
    int id;
    double cgpa;
    //before public, all variables are private by default
    public:
    // after private , all variables are public
   
   /* Student (string name, int id, double c){ //this is one way to initialize class members

        this-> name = name; //why use this? - to differentiate between the class member and the parameter
        this -> id = id;
        cgpa = c; // here cgpa is class member , c is parameter
    } */

    //member initializer list -> this one is better to initialize class members
   student (string name, int id, double c) : name(name), id(id), cgpa(c){

   }
   void display (){
     cout<<"name : "<<name<< " ID: "<<id<< " CGPA: "<<cgpa<<endl;
   }
   //updation
      //s1.name = namjoon - this is not allowed as the members are private
      //s1.cgpa = 4.1 ; - this is not allowed cgpa is also private like name and id
      //if we want to update the cgpa, we can create a public function for that
      void updateCgpa(double newCgpa){
        if(newCgpa <= 4.0){ //giving conditions for valid cgpa
            cgpa = newCgpa; // this will make the cgpa publicly accessible
            
        }
        else{
            cout<<"cgpa update faild"<<endl;
        }
        
      }
};

int main(){
    student s1("Namjoon", 129, 4.0); //creating object for the class student
     s1.display();
     s1.updateCgpa(3.8);
     s1.display();
    student s2 ("Jin", 124, 3.9);
    s2.display();
  
     
}