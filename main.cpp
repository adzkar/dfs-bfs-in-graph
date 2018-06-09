#include "head.h"

int main() {

    graph G = NULL;

    insertNode(G, 10);
    cout << searchNode(G, 10);ln;
    cout << isEmpty(G);ln;
    insertNode(G, 9);
    insertNode(G, 8);ln;
    cout << isEmpty(G);ln;
    insertNode(G, 3);
    insertNode(G, 7);
    insertNode(G, 12);
    readNode(G);ln;
    connect(G, 10, 9);
    connect(G, 10, 8);
    connect(G, 8, 3);
    connect(G, 8, 7);
    connect(G, 3, 7);
    connect(G, 3, 12);
    connect(G, 7, 12);
    readGraphbyAdjList(G);ln;
    readGraphAdjMatrix(G);
    ln;
    viewDfs(G);
    ln;

    return 0;
}
