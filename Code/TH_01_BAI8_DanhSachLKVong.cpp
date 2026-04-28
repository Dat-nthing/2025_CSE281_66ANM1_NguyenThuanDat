#include <iostream>
using namespace std;

typedef float Pt;

struct Nt {
    Pt ND;
    Nt* LK;
};

typedef Nt* Danh_Sach;

Danh_Sach L_KhoiTao() {
    return NULL;
}

void L_HuyBo(Danh_Sach &L) {
    if (L == NULL) return;

    Nt* start = L;
    Nt* temp = NULL;
    do {
        temp = L->LK;
        delete L;
        L = temp;
    } while (L != start);
    L = NULL;
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
    Nt* newNode = new Nt;
    newNode->ND = X;
    if (L == NULL) {
        newNode->LK = newNode;
        L = newNode;
    } else {
        newNode->LK = L->LK;
        L->LK = newNode;
    }
}

void L_XoaPTDau(Danh_Sach &L, Pt &X) {
    if (L == NULL) {
        return;
    }
    Nt* p = L->LK;
    X = p->ND;
    if (p == L) {
        delete p;
        L = NULL;
    } else {
        L->LK = p->LK;
        delete p;
    }
}

void L_InDanhSach(Danh_Sach L) {
    if (L == NULL) {
        return;
    }
    Nt* p = L->LK;
    do {
        cout << p->ND << " ";
        p = p->LK;
    } while (p != L->LK);
}

int main() {
    Danh_Sach L = L_KhoiTao();

    L_ChenPTDau(L, 10);
    L_ChenPTDau(L, 20);
    L_ChenPTDau(L, 30);

    L_InDanhSach(L);

    Pt x;
    L_XoaPTDau(L, x);

    L_InDanhSach(L);
    cout << L_XemPT(L);

    L_HuyBo(L);
    return 0;
}
