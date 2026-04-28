/*Cac khai bao */
typedef int T;
struct BinaryNode
  { T elem;
    BinaryNode* left;
    BinaryNode* right;
  };
struct BinarySearchTree
  { BinaryNode * root;
  };

/*Khai báo các hàm nguyên mau tai dây*/
void bstDestroy(BinarySearchTree & t); //Khoi tao mot cay nhi phan rong (nul)
void bstMakeEmpty(BinarySearchTree & t); //Xoa bo mot cay nhi phan t cho truoc: giai phong bo nho
bool bstIsEmpty(BinarySearchTree & t); //Kiem tra xem cay nhi phan t co rong (True) hay khong (False)
void bstMakeEmpty(BinaryNode * & t); //xóa toàn bo các nút c?a cây
BinaryNode * bstFindMin(BinaryNode * t); //Lay ra dia chi nut có gia tri nho nhat - nut trai nhat
T bstFindMin(BinarySearchTree & t);//Lay ra noi dung nut co gia tri be nhat
BinaryNode * bstFindMax(BinaryNode * t);//Lay ra dia chi nut có gia tri lon nhat - nut phai nhat
T bstFindMax(BinarySearchTree & tree);//Lay ra noi dung nut co gia tri lon nhat
bool bstContains(BinaryNode * t, T x); //Kiem tra xem cay nhi phan t co ton tai nut có gia tri x (True) hay khong (False)
void bstInsert(BinarySearchTree & t, T x); //Chen them phan tu co noi dung X vao vi tri phu hop tren cau t
void bstRemove(BinarySearchTree & t, T x); //Xoa nut co noi dung x tren cay t

int main()
  { //Chuong trinh chinh de thu nghiem cac ham da viet tai day
  /*Tu ve ra giay mot cay nhi phan tim kiem, sau do thuc hien viec tao cay va cac thao tac khac*/
  };
  
/*Dinh nghia các ham tai day */

