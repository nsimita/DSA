#include <iostream>
using namespace std;

struct Task {
    int start;
    int finish;
};

 int getDuration(Task t) {
    return t.finish - t.start;
}

 void sortTasks(Task tasks[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (getDuration(tasks[j]) > getDuration(tasks[j + 1])) {
                 Task temp = tasks[j];
                tasks[j] = tasks[j + 1];
                tasks[j + 1] = temp;
            }
        }
    }
}

 void printTasks(Task tasks[], int n) {
    cout << "[";
    for (int i = 0; i < n; i++) {
        cout << "(" << tasks[i].start << ", " << tasks[i].finish << ")";
        if (i < n - 1) cout << ", ";
    }
    cout << "]" << endl;
}

int main() {
    int n;

     cout << "Enter the number of tasks: ";
    cin >> n;

     Task tasks[n];

     for (int i = 0; i < n; i++) {
        cout << "Task " << i + 1 << ": ";
        cin >> tasks[i].start >> tasks[i].finish;
    }

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (getDuration(tasks[j]) > getDuration(tasks[j + 1])) {
 
                Task temp = tasks[j];
                tasks[j] = tasks[j + 1];
                tasks[j + 1] = temp;
            }
        }
    }
    
    printTasks(tasks, n);

    return 0;
}

