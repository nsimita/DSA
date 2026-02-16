#include <iostream>
#include <vector>
using namespace std;

class Graph{
    int n;
    vector <vector <int>> w;
    bool directed;
    vector<int> q, key, p;

    public:
    Graph (int n, bool dir): n(n) , directed (dir) { w = vector<vector <int>> (n, vector<int>(n,0));
        // w holo 2d vector adjacency matrix eta. er row ache n ta and col ache n ta. each cell e 0 value set kora
    }
   bool isEdge (int u, int v){
        if(w[u][v]!= 0) return true;
        else return false; 

        //check kore 2 ta vertices er moddhe edge ache kina mane ora connected kina ejonno bool
    }
    void addEdge(int u , int v , int w1){
        w[u][v] = w1 ; // weight set kora holo
        if(!directed) w[v][u] = w1 ; // undirected hole symmetric set kora lagbe
    } // void karon just value update hocche

    int ExtractMin(){
        int m = INT_MAX;
        int idx = -1;
        for(int i = 0; i< n; i++){
            if(q[i] ==1 && key[i]< m){
                m = key[i];
                idx = i;
            }
        }
        return idx;

    }

   void MST(int r){
     q = vector <int> (n,1); // q holo ekta vector jeta n no of vertices , element gulo 1 diye initialize kore mane queue te ache era
     key = vector <int> (n,INT_MAX) ; // key muloto weight value , eta k infinity diye initialize kora holo
      p = vector <int>(n, -1) ; // p muloto parent , -1 diye initialize , ar eta vertext k conncect korbe 
      key[r] =0 ; // root er weight 0

       for (int i=1; i<n; i++){
        int u = ExtractMin(); 
        q[u] =0 ; // u ar queue te nai karon eke select kora hoyeche
        for(int v =0; v<n; v++){
            if(isEdge(u,v)){
                if(q[v]==1 && w[u][v]<key[v]){ // jodi u v er majhe edge thake tahole
                    key[v] = w[u][v];  //v er weight update hobe
                    p[v] = u; // v er parent u mane u ar v k connect kora holo
                }
            }
        }

       }
        cout<<"selected edges: "<<endl;
    int cost =0;
    for(int i=0; i<n; i++){
        if(i==r) continue; // r holo root , r er parent nai
        cout<<"("<<i<<" ,"<<p[i]<<" ,"<<key[i]<<")"<<endl; // i vertex , er parent p[i] , key[i] weight
        cost += key[i];
    }
    cout<<"COST: "<<cost<<endl;
    } // void karon value update and conncet kora hocche
    
   
};

int main (){
    Graph g(5 , false);
    g.addEdge(0,1,2);
    g.addEdge(0, 2, 3);
    g.addEdge(0, 3, 1);
    g.addEdge(1, 3, 5);
    g.addEdge(2, 3, 4);
    g.addEdge(2, 4, 6);
    g.addEdge(3, 4, 9);

    g.MST(0);


} 