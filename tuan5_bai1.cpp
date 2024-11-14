//Sắp xếp dãy số
#include <iostream>
using namespace std;
void Sap_xep(int A[],int n){
    for(int i = 1; i < n; i++){
        int x = A[i];
        int j = i -1;
        while(j >= 0 && A[j] > x){
            A[j+1] = A[j];
            j = j-1;}
            A[j+1] = x;
        }
    }
void Nhap_mang(int A[],int n){
    for(int i = 0; i < n; i++){
        cin >> A[i];
    }
}
void In_mang(int A[], int n)
{
    for (int i = 0; i < n; ++i)
        cout << A[i] << " ";
    cout << endl;
}
int main(){
    cout << "Nhap so luong cac doi tuong can sap xep: ";
    int n;
    cin>>n;
    int arr[n];
    cout << "Nhap cac doi tuong (0:do, 1:trang, 2:xanh): ";
    Nhap_mang(arr,n);
    Sap_xep(arr, n);
    cout << "Day cac doi tuong sau khi duoc sap xep : ";
    In_mang(arr, n);
    return 0;
}
