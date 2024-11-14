#include <iostream>
#include <fstream>

using namespace std;

const int MAX_VERTICES = 100;

int graph[MAX_VERTICES][MAX_VERTICES];
int n, m;

bool isReflexive() {
    for (int u = 0; u < n; u++)
        if (graph[u][u] != 1)
            return false;
    return true;
}

bool isTransitive() {
    for (int u = 0; u < n; u++)
        for (int v = 0; v < n; v++)
            if (graph[u][v] == 1)
                for (int w = 0; w < n; w++)
                    if (graph[v][w] == 1 && graph[u][w] == 0)
                        return false;
    return true;
}

int main() {
    ifstream inputFile("in.txt");

    if (!inputFile) {
        cerr << "Error opening input file!" << endl;
        return 1;
    }

    inputFile >> n >> m;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            graph[i][j] = 0;

    for (int i = 0; i < m; i++) {
        int u, v;
        inputFile >> u >> v;
        u--; v--;
        graph[u][v] = 1;
    }

    inputFile.close();

    if (isReflexive())
        cout << "The relation is reflexive." << endl;
    else
        cout << "The relation is not reflexive." << endl;

    if (isTransitive())
        cout << "The relation is transitive." << endl;
    else
        cout << "The relation is not transitive." << endl;

    return 0;
}