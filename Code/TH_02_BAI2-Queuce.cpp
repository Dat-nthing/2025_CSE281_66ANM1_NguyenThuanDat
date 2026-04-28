/*Cac khai bao */
typedef float Pt;
typedef struct Nt
  { Pt ND;
    Nt* LK;
  } Nut;
typedef Nut* Hang_Doi;

/*Khai báo các hàm nguyên mau tai dây*/
Hang_Doi Q_KhoiTao(); //Khoi tao mot hang doi rong (nul)
void Q_HuyBo(Hang_Doi &Q); //Xoa bo mot hang doi Q cho truoc: giai phong bo nho
bool Q_KTRong(Hang_Doi Q); //Kiem tra xem hang doi Q co rong (True) hay khong (False)
void Q_DayVao(Hang_Doi &Q, Pt X); //Chen them (day vao) phan tu co noi dung X vao vi tri cuoi cung cua hang doi Q
Pt Q_LayRa(Hang_Doi &Q); //lay noi dung phan tu dau hang doi Q, sau do xoa phan tu do khoi hang doi

int main()
  { //Chuong trinh chinh de thu nghiem cac ham da viet tai day
  };
  
/*Dinh nghia các ham tai day */

