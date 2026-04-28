#include <iostream>
using namespace std;

typedef float Pt;

struct Nt {
    Pt ND;
    Nt* LK_Truoc;
    Nt* LK_Sau;
};

typedef Nt* Danh_Sach;

Danh_Sach L_KhoiTao() {
    return NULL;
}

void L_HuyBo(Danh_Sach &L) {
    while (L != NULL) {
        Nt* temp = L;
        L = L->LK_Sau;
        delete temp;
    }
}

bool L_KTRong(Danh_Sach L) {
    return L == NULL;
}

Pt L_XemPTDau(Danh_Sach L) {
    if (L != NULL) {
        return L->ND;
    }
}

Pt L_XemPTCuoi(Danh_Sach L) {
    if (L == NULL) {
        return -1;
    }
    while (L->LK_Sau != NULL) {
        L = L->LK_Sau;
    }
    return L->ND;
}

void L_ChenPTDau(Danh_Sach &L, Danh_Sach P, Pt X) {
    Nt* newNode = new Nt;
    newNode->ND = X;
    newNode->LK_Truoc = NULL;
    newNode->LK_Sau = NULL;

    if (P == L) {
        newNode->LK_Sau = L;
        if (L != NULL) {
            L->LK_Truoc = newNode;
        }
        L = newNode;
    } else {
        newNode->LK_Sau = P;
        newNode->LK_Truoc = P->LK_Truoc;
        if (P->LK_Truoc != NULL) {
            P->LK_Truoc->LK_Sau = newNode;
        }
        P->LK_Truoc = newNode;
    }
}

Pt L_XoaPTDau(Danh_Sach &L, Danh_Sach P) {
    if (P == NULL) {
        return -1;
    }
    Pt data = P->ND;
    if (P->LK_Truoc != NULL) {
        P->LK_Truoc->LK_Sau = P->LK_Sau;
    } else {
        L = P->LK_Sau;
    }
    if (P->LK_Sau != NULL) {
        P->LK_Sau->LK_Truoc = P->LK_Truoc;
    }
    delete P;
    return data;
}

void L_InDanhSach(Danh_Sach L) {
    while (L != NULL) {
        cout << L->ND << " ";
        L = L->LK_Sau;
    }
}

Danh_Sach L_TimDau(Danh_Sach L) {
    return L;
}

Danh_Sach L_TimCuoi(Danh_Sach L) {
    if (L == NULL) return NULL;
    while (L->LK_Sau != NULL) {
        L = L->LK_Sau;
    }
    return L;
}

int main() {
    Danh_Sach L = L_KhoiTao();

    L_ChenPTDau(L, L, 10.0);
    L_ChenPTDau(L, L, 20.0);
    L_ChenPTDau(L, L, 30.0);

    L_InDanhSach(L);
    cout << L_XemPTDau(L);
    cout << L_XemPTCuoi(L);

    Pt x = L_XoaPTDau(L, L);

    L_InDanhSach(L);

    L_HuyBo(L);
    return 0;
}
