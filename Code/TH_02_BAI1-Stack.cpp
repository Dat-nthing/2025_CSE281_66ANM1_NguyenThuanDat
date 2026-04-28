/*Cac khai bao */
typedef float Pt;
typedef struct Nt
  { Pt ND;
    Nt* LK;
  } Nut;
typedef Nut* Ngan_Xep;

/*Khai báo các hàm nguyên mau tai dây*/
Ngan_Xep S_KhoiTao(); //Khoi tao mot ngan xep rong (nul)
void V_HuyBo(Ngan_Xep &S); //Xoa bo mot ngan xep S cho truoc: giai phong bo nho
bool S_KTRong(Ngan_Xep S); //Kiem tra xem ngan xep S co rong (True) hay khong (False)
void S_DayVao(Ngan_Xep &S, Pt X); //Chen them (day vao) phan tu co noi dung X vao vi tri dinh cua ngan xep S
Pt S_LayRa(Ngan_Xep &S); //lay noi dung phan tu tren dinh cua ngan xep S, sau do xoa phan tu do khoi ngan xep

int main()
  { //Chuong trinh chinh dethu nghiem cac ham da viet tai day
  };
  
/*Dinh nghia các ham tai day */

