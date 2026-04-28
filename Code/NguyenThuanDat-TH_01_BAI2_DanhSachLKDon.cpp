#include <iostream>
using namespace std; 
typedef float Pt;
typedef struct Nut{ 
    Pt ND;
    Nut* LK;
  } Nut;
typedef Nut* Danh_Sach;

Danh_Sach L_KhoiTao() {
    return NULL;
}

void L_HuyBo(Danh_Sach &L) {
    while (L != NULL) {
        Nut* temp = L;
        L = L->LK;
        delete temp;
    }
}

bool L_KTRong(Danh_Sach L) {
    return L == NULL;
}

Pt L_XemPT(Danh_Sach L) {
    if (L != NULL) {
        return L->ND;
    }
}

void L_ChenPTDau(Danh_Sach &L, Pt X) {
    Nut* newNode = new Nut;
    newNode->ND = X;
    newNode->LK = L;
    L = newNode;
}

void L_XoaPTDau(Danh_Sach &L, Pt &X) {
    if (L != NULL) {
        Nut* temp = L;
        X = L->ND;
        L = L->LK;
        delete temp;
    }
}

void L_InDanhSach(Danh_Sach L) {
    while (L != NULL) {
        cout << L->ND << " ";
        L = L->LK;
    }
}

int main(){
    Danh_Sach L = L_KhoiTao();

    L_ChenPTDau(L, 10.5);
    L_ChenPTDau(L, 20.3);
    L_ChenPTDau(L, 30.7);

    L_InDanhSach(L);

    Pt x;
    L_XoaPTDau(L, x);

    L_InDanhSach(L);

    if (!L_KTRong(L)) {
        cout << L_XemPT(L);
    }
    L_HuyBo(L);
    return 0;
}
