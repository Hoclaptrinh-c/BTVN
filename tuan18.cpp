#include <iostream>
using namespace std;
// Ha Noi: 0 ,Hoa Binh: 1,Son Tay: 2,Thai Nguyen: 3,Bac Ninh: 4,Hai Duong: 5,Hung Yen: 6,Phu Ly: 7,Bac Giang :8,Uong Bi: 9,Hai Phong: 10.

struct node {
    int dinh;
    node* next;
};

struct graph {
    int so_dinh;
    int* Ma_tran;
    node* Danh_sach;

    graph(int vertices) {
        so_dinh = vertices;

        Ma_tran = new int[so_dinh * so_dinh];
        for (int i = 0; i < so_dinh * so_dinh; i++) {
            Ma_tran[i] = 0;
        }

 
        Danh_sach = new node[so_dinh];
        for (int i = 0; i < so_dinh; i++) {
            Danh_sach[i].dinh = i;
            Danh_sach[i].next = NULL;
        }
    }

    ~graph() {
        delete[] Ma_tran;
        for (int i = 0; i < so_dinh; i++) {
            node* current = Danh_sach[i].next;
            while (current != NULL) {
                node* temp = current;
                current = current->next;
                delete temp;
            }
        }
        delete[] Danh_sach;
    }

    void addEdgeMatrix(int u, int v) {
        Ma_tran[u * so_dinh + v] = 1;
        Ma_tran[v * so_dinh + u] = 1; 
    }

    void displayMatrix() {
        cout << "Ma tran ke:" << endl;
        for (int i = 0; i < so_dinh; i++) {
            for (int j = 0; j < so_dinh; j++) {
                cout << Ma_tran[i * so_dinh + j] << " ";
            }
            cout << endl;
        }
    }

    void addEdgeList(int u, int v) {
        node* newnode = new node{v, Danh_sach[u].next};
        Danh_sach[u].next = newnode;

        newnode = new node{u, Danh_sach[v].next};
        Danh_sach[v].next = newnode; 
    }

    void displayList() {
        cout << "Danh sach ke:" << endl;
        for (int i = 0; i < so_dinh; i++) {
            cout << i << ": ";
            node* current = Danh_sach[i].next;
            while (current != NULL) {
                cout << current->dinh << " ";
                current = current->next;
            }
            cout << endl;
        }
    }
};

int main() {
    graph g(11); 
//Ma tran ke
    g.addEdgeMatrix(0, 1);
    g.addEdgeMatrix(0, 2);
    g.addEdgeMatrix(0, 3);
    g.addEdgeMatrix(0, 4);
    g.addEdgeMatrix(0, 5);
    g.addEdgeMatrix(0, 7);
    g.addEdgeMatrix(4, 8);
    g.addEdgeMatrix(4, 9);
    g.addEdgeMatrix(5, 6);
    g.addEdgeMatrix(5, 10);
    g.addEdgeMatrix(6, 7);
    g.addEdgeMatrix(8, 9);
    g.addEdgeMatrix(9, 10);
    g.displayMatrix();
//Danh sach ke
    g.addEdgeList(0, 1);
    g.addEdgeList(0, 2);
    g.addEdgeList(0, 3);
    g.addEdgeList(0, 7);
    g.addEdgeList(4, 8);
    g.addEdgeList(4, 9);
    g.addEdgeList(5, 6);
    g.addEdgeList(5, 10);
    g.addEdgeList(6, 7);
    g.addEdgeList(8, 9);
    g.addEdgeList(9, 10);
    g.displayList();

    return 0;
}
