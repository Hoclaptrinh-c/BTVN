#include <iostream>

using namespace std;

struct Node{
    float heso;
    int somu;
    Node * next;
};

Node * head = nullptr;
void add (float heso, int somu){
    if (heso == 0) return;

    Node* newNode = new Node{heso, somu, nullptr};

    if (!head || head ->somu < somu){
        newNode->next = head;
        head = newNode;
    } 
    else {
     Node* current = head;
     Node* previous = nullptr;
     while (current && current->somu > somu){
        previous = current;
        current = current->next;
     }
     if (current && current->somu == somu){
        current->heso += heso;
        delete newNode;
        if (current->heso == 0){
            if (previous){
                previous->next = current->next;
            }
            else{
                head = current->next;
            }
            delete current;
        }
     }
     else{
        newNode->next = current;
        if (previous){
            previous->next = newNode;
        }
        else {
            head = newNode;
        }
     }
    }
}
void print(){
    if(!head){
        cout << "0" << endl;
        return;
    }
    Node* current = head;
    bool first = true;

 while (current){
    if (!first && current->heso > 0 ){
        cout << "+";
    }
    if (current->heso < 0){
        cout << "-";
    }else if (!first){
        cout << " ";
    }
    cout << abs(current->heso);
    if (current->somu > 0){
        cout << "x";
        if (current->somu > 1){
            cout << "^" << current->somu;
        }
    }
    first = false;
    current = current->next;
 }
}
void Giaiphong(){
    Node* current = head;
    while (current){
        Node*temp = current;
        current = current->next;
        delete temp;
    }
    head = nullptr;
}
int main(){
    int hs, sm;
    cout << "Nhap he so va so mu cua cac phan tu (Nhap 0 de dung lai)\n";

    while (true){
        cout << "He so: ";
        cin >> hs;
        if (hs == 0) break;

        cout <<"Bac: ";
        cin >> sm;
        add(hs,sm);
    }
    cout <<"Da thuc da nhap: ";
    print();
    Giaiphong();
return 0;
}