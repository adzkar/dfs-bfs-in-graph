#include "head.h"

int main() {

    graph G = NULL;

    insertNode(G, 10);
    cout << searchNode(G, 10);ln;
    cout << isEmpty(G);ln;
    insertNode(G, 11);
    insertNode(G, 11);ln;
    cout << isEmpty(G);ln;
    insertNode(G, 15);
    readNode(G);ln;
    connect(G,10,15);
    connect(G,10,10);
    ln;
    cout << isConnect(G, 10,10);

    readGraphbyAdjList(G);ln;
    readGraphAdjMatrix(G);

    ln;

    return 0;
}
