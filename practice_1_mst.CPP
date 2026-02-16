#include <iostream>
#include <vector>
using namespace std;

class Graph{
    int n;
     bool directed;
     vector <vector <int>> w;
     vector<int> q, p, key;
     public :
     Graph(int n, bool dir): n(n), direction(dir){w= vector <vector <int>> (n, vector<int>(n,0));}

     bool isEdge(){
        if(w[u][v]!=0) return true;
        else false;
     }
     void addEdge(int u, int v, int w1){
         w[u][v] = w1;
         if(!directed) w[v][u] = w1

     }
     int ExtractMin(){
        int m = INT_MAX;
        int idx = -1;
        for(int i=0; i<n; i++){
            if(q[i]==1 && key[i]<m){
                m = key[i];
                i = idx
            }
        }

        return idx;
     }
     void MST(int r){
        q = vector<int> (n,1);
        key = vector<int> (n, INT_MAX);
        p =  vector<int> (n, -1);
        key[r] =0;
        
            int u = ExtractMin();
            q[u]=0;
            for(int v=0; v<n; v++){
                if(isEdge(u,v)){
                    if(q[v]==1 && w[u][v]<key[v]){
                        key[v] = w[u][v];
                        p[v] = u;
                    }  
                }
            }
            cout<<"Selected edges: "<<endl;
            int cost =0;
            
        }
 
     }
};