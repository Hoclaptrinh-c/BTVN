#include <iostream>
#include <string.h>

using namespace std;

struct Node{
    string data;
    Node* L;
    Node* R;
};
Node* Tao_node(string x){
    Node* newnode = new Node;
    newnode->data = x;
    newnode->L = NULL;
    newnode->R = NULL;
    return newnode;
}
bool isEmty(Node* root){
    return root == NULL;
}
Node* Tao_cay(string Cay[], int& p, int n) {
    if (p >= n) return NULL;
    Node* node = Tao_node(Cay[p]);
    p++;
    if (node->data == "+" || node->data == "-" || node->data == "*" || node->data == "/" || node->data == "^") {
        node->L = Tao_cay(Cay, p, n);
        node->R = Tao_cay(Cay, p, n);
    }

    return node;
}
void LNR(Node* root) {
    if (!isEmty(root)) {
        if (root->L != NULL || root->R != NULL) cout << "("; 
        LNR(root->L);
        cout << root->data << " ";
        LNR(root->R);
        if (root->L != NULL || root->R != NULL) cout << ")"; 
    }
}
void NLR(Node* root){
    if(!isEmty(root)){
        cout<<root->data<<" ";
        NLR(root->L);
        NLR(root->R);
    }
}
void LRN(Node* root){
    if(!isEmty(root)){
        LRN(root->L);
        LRN(root->R);
        cout<<root->data<<" ";
    }
}
int main(){
    Node* root = NULL;
    int n;
    string Phan_tu[] = {"+", "-", "*", "a", "5", "/", "*", "b", "^", "c", "6", "5", "*", "-", "h", "f", "^", "e", "1/2"};
    n = sizeof(Phan_tu) / sizeof(Phan_tu[0]);
    int x = 0;
    root = Tao_cay(Phan_tu,x,n);
    LNR(root);
    cout<<endl;
    LRN(root);
    cout<<endl;
    NLR(root);
    cout<<endl;
    return 0;
}