#include <iostream>
#include <string.h>

using namespace std;

struct Node{
    string name;
    int so_tien;
    int so_san_pham_A;
    Node*next;
};
struct queue{
    Node *F = NULL;
    Node *R= NULL;
bool isEmpty(){
    return F == NULL;
}
bool isFULL(){
    Node *temp = new Node;
    if(temp == NULL){
        return true;
    }
    delete temp;
    return false;
}
void enqueue(string name, int amount, int productA){
    if(isFULL()){
        cout<<"hang doi tran"<<endl;
        return;
    } 
    Node* newNode = new Node{name,amount,productA,NULL};
    if(R == NULL){
        F=R= newNode;
    }else{
        R-> next = newNode;
        R= newNode;
    }
}
void dequeue(){
    if(isEmpty()){
        cout<<"hang doi trong"<<endl;
        return;
    }
    Node *p = F;
    F = F-> next;
    if(F == NULL){
        R = NULL;
    }
    cout<<p -> name<<" thanh toan xong"<<endl;
    delete p;
}
float Tong_tien(){
    float tong =0;
    Node *p = F;
    while(p != NULL){
        tong += p -> so_tien;
        p = p->next;
    }
    return tong;
}
int So_san_pham_A(){
    int count =0;
    Node* p = F;
    while(p != NULL){
        count += p-> so_san_pham_A;
        p = p->next;
    }
    return count;
}
void clear() {
        while (!isEmpty()) {
            dequeue();
        }
    }
};
int main(){
    queue queue;
    int n;
     if (queue.isEmpty()) {
        cout << "Hang doi trong"<<endl;
    }
    cout<<"Nhap so khach hang: ";
    cin>>n;
   for (int i = 1; i <= n; i++) {
        string name;
        int amount, productA;
        cout << "Nhap ten khach hang thu " <<i<< ": ";
        cin.ignore(); 
        getline(cin, name);
        cout << "So tien cua khach hang thu " <<i<< ": ";
        cin >> amount;
        cout << "Nhap so luong san pham A cua khach hang thu " <<i<< ": ";
        cin >> productA;
        queue.enqueue(name, amount, productA);
    }
    if (!queue.isEmpty()) {
        cout << "Hang doi khong con trong"<<endl;
    }
    cout<<"So san pham A la: "<<queue.So_san_pham_A()<<endl;
    cout<<"Tong so tien thu duoc la: "<<queue.Tong_tien()<<endl;
    queue.clear(); 
    return 0;
}