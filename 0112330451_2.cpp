#include <iostream>
#include <vector>
using namespace std;

class Graph{
    int n;
    bool directed;
    vector <int> q , key, p;
    vector <vector <int> > w;
    public:
    Graph (int n, bool dir) : n(n) , directed (dir) { w = vector <vector <int>> (n, vector<int>(n,0)); }

    bool isEdge(int u , int v){
        if(w[u][v] != 0) return true;
        else return false;
    }
    void addEdge(int u, int v,int w1){
        w [u][v] = w1;
        if(!directed) w[v][u] = w1;
    }
     int ExtractMin(){
        int m = INT_MAX;
        int idx = -1;
        for(int i =0; i<n; i++){
            if(q[i] ==1 && key[i] <m){
                m= key[i] ;
                idx =i;
            }
        }
        return idx;
     }
     void MST(int r){
          q = vector<int> (n,1);
         key = vector<int> (n, INT_MAX);
          p = vector<int> (n, -1);
        key[r] =0;
        for(int i=1 ; i<n; i++){
           int u = ExtractMin();
            q[u]= 0;
            for(int v = 0; v<n ; v++){
                if(isEdge(u,v))
                if(q[v]==1 && w[u][v] < key[v]){
                    key[v] = w[u][v];
                    p[v] = u;
                }
            }
        }
        cout <<"The following bridges should be built: "<<endl;
        int cost = 0;
        for(int i=0; i<n; i++){
            if(i==r) continue;
            cout<<char('A'+i)<<"->"<<char('A'+p[i])<<": "<<key[i]<<endl;
            cost+=key[i];
        }
        cout<<"Minimum cost to connect islands: "<<cost<<endl;
     }

};
int main(){
    Graph g (6, false);
    g.addEdge(0,1,3);
    g.addEdge(0,2,7);
    g.addEdge(0,3,6);
    g.addEdge(0,5,8);
    g.addEdge(1,3,7);
    g.addEdge(1,4,5);
    g.addEdge(1,5,7);
    g.addEdge(2,3,2);
    g.addEdge(2,4,3);
    g.addEdge(3,4,1);
    g.addEdge(4,5,4);

g.MST(0);

}