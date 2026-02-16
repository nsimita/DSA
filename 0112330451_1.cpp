#include <iostream>
#include <vector>


using namespace std;

class Graph {
    int n;
    vector<vector<int>> w;
    bool directed;
    vector<int> q, d, p;

public:
    Graph(int n, bool dir) : n(n), directed(dir) {
        w = vector<vector<int>>(n, vector<int>(n, 0));
    }

    void addEdge(int u, int v, int w1) {
        w[u][v] = w1;
        if (!directed)
            w[v][u] = w1;
    }

    bool isEdge(int u, int v) {
        return w[u][v] != 0;
    }

    int ExtractMin() {
        int m = INT_MAX;
        int idx = -1;
        for (int i = 0; i < n; i++) {
            if (q[i] == 1 && d[i] < m) {
                m = d[i];
                idx = i;
            }
        }
        return idx;
    }

    void Dijkstra(int src) {
        q = vector<int>(n, 1);
        d = vector<int>(n, INT_MAX);
        p = vector<int>(n, -1);
        d[src] = 0;

        for (int i = 0; i < n; i++) {
            int u = ExtractMin();
            if (u == -1)
                break;
            q[u] = 0;
            for (int v = 0; v < n; v++) {
                if (isEdge(u, v)) {
                    if (d[u] + w[u][v] < d[v]) {
                        d[v] = d[u] + w[u][v];
                        p[v] = u;
                    }
                }
            }
        }
    }

    void printPath(int dest) {
        if (dest == -1) return;
        if (p[dest] != -1)
            printPath(p[dest]);
        cout << dest << " ";
    }

  
    int findPath(int s, int dest) {
        Dijkstra(s);
        cout << "Shortest time from " << s << " to " << dest << ": " << d[dest] << endl;
        cout << "Path: ";
        printPath(dest);
        cout << endl;
        return d[dest];
    }
};

int main() {
    Graph g(5, true);

    g.addEdge(0, 1, 5);
    g.addEdge(0, 2, 2);
    g.addEdge(1, 3, 4);
    g.addEdge(1, 4, 2);
    g.addEdge(2, 1, 1);
    g.addEdge(2, 3, 3);
    g.addEdge(3, 4, 6);

    cout << "Direct:" << endl;
    int directTime = g.findPath(0, 3);

    cout << "Via Gas Station:" << endl;
    int timeToGas = g.findPath(0, 1);
    int timeGasToDest = g.findPath(1, 3);

    int timeViaGas = timeToGas + timeGasToDest;
    int timeSaved = timeViaGas - directTime;

    cout << "Time saved by going directly: " << timeSaved << endl;

   
}
