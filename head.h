#include <iostream>
#include <vector>
#define ln cout << endl;
using namespace std;

typedef struct node *adrNode;
typedef struct edge *adrEdge;

struct node {
    int info;
    adrNode next;
    adrEdge firstEdge;
};

struct edge {
    adrNode info;
    adrEdge next;
};

typedef adrNode graph;

adrNode createNode(int x) {
    adrNode P = new node;
    P->info = x;
    P->next = NULL;
    P->firstEdge = NULL;
    return P;
};

adrEdge createEdge(adrNode x) {
    adrEdge P = new edge;
    P->info = x;
    P->next = NULL;
    return P;
};

bool isEmpty(graph G) {
    return G == NULL;
};

adrNode searchNode(graph G, int x) {
    if(!isEmpty(G)) {
        adrNode P = G;
        while((P->next != NULL) and (P->info != x)) P = P->next;
        return (P->info == x) ? P : NULL;
    } else return NULL;
};

void insertNode(graph &G, int x) {
    adrNode P = createNode(x);
    if(isEmpty(G)) G = P;
    else {
        adrNode R = searchNode(G, x);
        if(R == NULL) {
            adrNode Q = G;
            while(Q->next != NULL) Q = Q->next;
            Q->next = P;
        } else cout << "Duplicate";
    }
};

void insertLastEdge(adrEdge &E, adrEdge x) {
    if(E == NULL) E = x;
    else {
        adrEdge P = E;
        while(P->next != NULL) P = P->next;
        P->next = x;
    }
}

void connect(graph &G, int x, int y) {
    adrNode P = searchNode(G, x);
    adrNode Q = searchNode(G, y);
    if(P != NULL and Q != NULL) {
        if(x == y) {
            adrEdge R = createEdge(Q);
            insertLastEdge(P->firstEdge, R);
        } else {
            adrEdge r = createEdge(Q);
            adrEdge s = createEdge(P);
            insertLastEdge(P->firstEdge, r);
            insertLastEdge(Q->firstEdge, s);
        }
    }
}

bool isConnect(graph G, int x, int y) {
  bool status = NULL;
  //add this for check the value of node is connecting or not
  if(!isEmpty(G)) {
    adrNode P = searchNode(G, x);
    adrNode Q = searchNode(G, y);
    if(P != NULL && Q != NULL) {
        adrEdge A = P->firstEdge;
        adrEdge B = Q->firstEdge;
        while((B != NULL) && (B->info != P)) B = B->next;
        while((A != NULL) && (A->info != Q)) A = A->next;
        ((A != NULL) && (B != NULL)) ? status = true: status = false;
    }
  }
  return status;
}

void readNode(graph G) {
    if(isEmpty(G)) cout << "Empty Graph";
    else {
        adrNode P = G;
        while(P != NULL) {
            cout << P->info << " ";
            P = P->next;
        }
    }
}

void readGraphbyAdjList(graph G){
  cout << "==========================" << endl
       << "   Read by Adjency List" << endl
       << "==========================" << endl;
  cout << "|| Node    |  neighbors ||" << endl;
  if(isEmpty(G)) cout << "Empty Graph";
  else {
    adrNode P = G;
    while(P != NULL) {
      cout << "   " << P->info << "      |   ";
      adrEdge Q = P->firstEdge;
      while(Q != NULL) {
          cout << (Q->info)->info << " ";
          Q = Q->next;
      }
      ln;
      P = P->next;
    }
  }
}

void readGraphAdjMatrix(graph G) {
  cout << "==========================" << endl
       << "   Read by Matrix List" << endl
       << "==========================" << endl;
  adrNode P = G;
  cout << "   ";
  while(P != NULL) {
    cout << P->info << "   ";
    P = P->next;
  }
  P = G;ln;
  while(P != NULL) {
    cout << P->info << " ";
    adrNode Q = G;
    while(Q != NULL) {
        (isConnect(G, P->info, Q->info)) ? cout << 1:cout << 0;
        cout << "    ";
        Q = Q->next;
    }
    ln;
    P = P->next;
  }
}

bool isMember(vector<int> stacks, int x) {
    if(!stacks.empty()) {
        while(!stacks.empty() && stacks.back() != x) stacks.pop_back();
        return !stacks.empty();
    } else return false;
}

void viewDfs(graph G) {
    if(!isEmpty(G)) {
        vector<int> isVisited;
        vector<int> output;
        int smallest, awal;
        adrNode P = G;
        isVisited.push_back(P->info);
        output.push_back(P->info);
        while(!isVisited.empty()) {
            if(P->firstEdge != NULL) {
                // mencari nilai terkecil dari yang terhubung
                // dengan catatan belum dikunjungi
                adrEdge Q = P->firstEdge;
                smallest = (Q->info)->info;
                awal = smallest;
                while(Q != NULL) {
                    Q = Q->next;
                    if((Q != NULL) && !isMember(isVisited, (Q->info)->info)) smallest = (Q->info)->info;
                }
                // memasukkan nilai nya kedalam output dan isVisited
                if(smallest == awal && isMember(isVisited, smallest)) isVisited.pop_back();
                else {
                    isVisited.push_back(smallest);
                    output.push_back(smallest);
                }
            } else isVisited.pop_back();        
            P = searchNode(G, isVisited.back());
        }
        for(int i = 0;i < output.size();i++) cout << output[i] << " ";
    } else cout << "Empty Graph";
}