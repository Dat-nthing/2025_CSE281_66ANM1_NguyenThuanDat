#include <iostream>
using namespace std;
/*Cac khai bao */
typedef float Pt;
typedef struct VT {
  int Kt;
  int Max;
  Pt *DS;
} Vec_To;

/*Khai báo các hàm nguyên mau tai dây*/
Vec_To V_KhoiTao(int t); // Xin cap phat bo nho và khoi tao mot vector rong
void V_HuyBo(Vec_To &V); // Xoa bo mot vector, giai phong bo nho
Vec_To
V_SaoChep(Vec_To V); // Tao mot vecto moi có noi dung sao chep tu vector V
bool V_KTRong(
    Vec_To V); // Kiem tra xem vector V co rong (True) hay khong (False)
int V_KichThuoc(Vec_To V);   // Tra lai kich thuoc cua vector V
Pt V_XemPT(Vec_To V, int t); // In ra noi dung cua phan tu thu t cua vector V
void V_CapNhat(
    Vec_To &V, int t,
    Pt X); // Thay gia tri phan tu thu t cua vector V voi noi dung moi la X
void V_MoRongKT(
    Vec_To &V); // Tang kich thuoc toi da Max cua vector V them 1 phan tu moi
void V_ChenPTCuoi(
    Vec_To &V,
    Pt X); // Neu kich thuoc cua vector V day (tran) thi tang khich thuoc cua V
           // them 1. Sau do, chen them phan tu co noi dung X vao cuoi vector V
void V_ChenPT(Vec_To &V, int t,
              Pt X); // Neu kich thuoc cua vector V day (tran) thi tang khich
                     // thuoc cua V them 1. Sau do, chen them phan tu co noi
                     // dung X vao vi tri thu t cua vector V
void V_XoaPTCuoi(
    Vec_To &V, Pt &X); // Neu vector V khong rong thi: lay noi dung phan tu cuoi
                       // cua vector V gui vao X, sau do xoa phan tu cuoi do
void V_XoaPT(
    Vec_To &V, int t,
    Pt &X); // Neu vector V khong rong thi: lay noi dung phan tu vi tri thu t
            // cua vector V gui vao X, sau do xoa phan tu thu t do
//------------------------------------------------------------------------------
void printV(Vec_To V) {
  for (int i = 0; i < V.Kt; i++) {
    cout << V_XemPT(V, i) << " ";
  }
  cout << endl;
}
int main() { // Chuong trinh chinh viet tai day
  int n;
  Pt pt;
  cout << "Nhap vao kich thuoc vector: ";
  cin >> n;
  Vec_To V = V_KhoiTao(n);
  // them phan tu vao vector
  for (int i = 0; i < n; i++) {
    cout << "Nhap phan tu thu " << i + 1 << ": ";
    cin >> pt;
    V_ChenPTCuoi(V, pt);
  }

  // xem phan tu:
  cout << "Cac phan thu cua vector: ";
  printV(V);
  // sao chep
  Vec_To V2 = V_SaoChep(V);
  cout << "Cac phan tu cua vector2: ";
  printV(V2);
  // Kiem tra xem phan tu co phai rong khong
  if (V_KTRong(V)) {
    cout << "Vecto la rong" << endl;
  } else {
    cout << "Vecto khong rong" << endl;
  }

  // xem kich thuoc
  cout << "Kich thuoc cua vector la: " << V_KichThuoc(V) << endl;
  // cap nhat vector
  int k;
  Pt x;

  cout << "Nhap vao vi tri k: ";
  cin >> k;
  cout << "Nhap vao x: ";
  cin >> x;
  V_CapNhat(V, k, x);
  cout << "\nVector sau khi cap nhat la: ";
  printV(V);
  // chen phan tu cuoi;
  Pt ptc;
  cout << "Nhap vao phan tu: ";
  cin >> ptc;
  V_ChenPTCuoi(V, ptc);
  cout << "vector sau khi them phan tu cuoi la: ";
  printV(V);
  // chen phan tu
  Pt cpt;
  cout << "nhap vao vi tri k: ";
  cin >> k;
  cout << "Nhap vao phan tu can chen: ";
  cin >> cpt;
  V_ChenPT(V, k, cpt);
  cout << "Vector sau khi chen la: ";
  printV(V);
  // xoa phan tu cuoi
  Pt X;
  V_XoaPTCuoi(V, X);
  cout << "Vector sau khi xoa cuoi la: ";
  printV(V);
  // xoa phan tu
  Pt X2;
  cout << "Nhap vao vi tri k: ";
  cin >> k;
  V_XoaPT(V, k, X2);
  cout << "Vector sau khi xoa phan tu tai k la: ";
  printV(V);
};

/*Dinh nghia các ham tai day */
Vec_To V_KhoiTao(int t) {
  Vec_To vec;
  vec.Kt = 0;
  vec.Max = t;
  vec.DS = new Pt[vec.Max];
  return vec;
};
void V_HuyBo(Vec_To &V) { delete[] V.DS; };
Vec_To V_SaoChep(Vec_To V) {
  Vec_To V2;
  V2.Kt = V.Kt;
  V2.Max = V.Max;
  V2.DS = new Pt[V2.Max];
  for (int i = 0; i < V.Kt; ++i) {
    V2.DS[i] = V.DS[i];
  }
  return V2;
};
bool V_KTRong(Vec_To V) {
  if (V.Kt != 0)
    return false;
  return true;
};
int V_KichThuoc(Vec_To V) { return V.Kt; };
Pt V_XemPT(Vec_To V, int t) {
  if (t > V.Kt && t < 0) {
    cout << "Wrong pos!";
    return 0;
  }
  return V.DS[t];
};
void V_CapNhat(Vec_To &V, int t, Pt X) {
  if (t >= 0 && t < V.Kt) {
    V.DS[t] = X;
  }
};
void V_MoRongKT(Vec_To &V) {
  V.Max += 1;
  Pt *newV = new Pt[V.Max];
  for (int i = 0; i < V.Kt; ++i) {
    newV[i] = V.DS[i];
  }
  delete[] V.DS;
  V.DS = newV;
};
void V_ChenPTCuoi(Vec_To &V, Pt X) {
  if (V.Kt == V.Max) {
    V_MoRongKT(V);
  }
  V.DS[V.Kt] = X;
  V.Kt++;
};
void V_ChenPT(Vec_To &V, int t, Pt X) {
  if (V.Kt == V.Max)
    V_MoRongKT(V);
  for (int i = V.Kt; i > t; i--) {
    V.DS[i] = V.DS[i - 1];
  }
  V.DS[t] = X;
  V.Kt++;
};
void V_XoaPTCuoi(Vec_To &V, Pt &X) {
  if (!V_KTRong(V)) {
    X = V.DS[V.Kt - 1];
    V.Kt--;
  }
};
void V_XoaPT(Vec_To &V, int t, Pt &X) {
  if (!V_KTRong(V)) {
    if (t < V.Kt || t >= 0) {
      X = V.DS[V.Kt - 1];
      for (int i = t; i < V.Kt; i++) {
        V.DS[i] = V.DS[i + 1];
      }
      V.Kt--;
    }
  }
};
