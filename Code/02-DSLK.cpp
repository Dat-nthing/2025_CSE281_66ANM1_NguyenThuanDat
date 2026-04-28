
// Thuc hanh danh sach lien ket don

#include <iostream>

using namespace std;

// Kieu phan tu
typedef int T;

// Kieu cua cac nut
struct Node
{
    T elem;      // Phan tu
    Node * next; // Con tro toi nut tiep theo
};

// Kieu danh sach lien ket don
struct List
{
    Node * head; // Con tro toi nut dau danh sach
};

// Khoi tao danh sach
void listInit(List & list);

// Huy danh sach
void listDestroy(List & list);

// Kiem tra danh sach rong
bool listIsEmpty(List & list);

// Lay phan tu dau danh sach
T listFront(List & list);

// Chen vao dau danh sach
void listPushFront(List & list, T e);

// Xoa phan tu dau danh sach
void listPopFront(List & list);

// YEU CAU THUC HANH
//   Khai bao cac ham thuc hien cac viec sau:
//     1. Tra ve kich thuoc cua danh sach
//     2. In cac phan tu trong danh sach len man hinh
//     3. Tra ve phan tu o vi tri k trong danh sach (vi tri bat dau tu 0)
//     4. Kiem tra xem mot gia tri x co mat trong danh sach hay khong
//     5. Chen mot phan tu moi vao truoc x (neu x ton tai trong danh sach)
//     6. Xoa phan tu x (neu x ton tai trong danh sach)
//     7. Chen mot phan tu moi vao cuoi danh sach

// VIET CODE CUA BAN O DAY...

int main()
{
	// Khai bao bien danh sach
	List list;	

	// Khoi tao danh sach
	listInit(list);	

	// Chen mot so phan tu vao dau danh sach
	listPushFront(list, 4); // 4
	listPushFront(list, 8); // 8 -> 4
	listPushFront(list, 3); // 3 -> 8 -> 4
	listPushFront(list, 9); // 9 -> 3 -> 8 -> 4
	listPushFront(list, 5); // 5 -> 9 -> 3 -> 8 -> 4

    // YEU CAU THUC HANH
	//   Viet code goi cac ham da viet de chay thu
	
	// VIET CODE CUA BAN O DAY...
	
	// Huy danh sach
	listDestroy(list);
	
	return 0;
}

void listInit(List & list)
{
    list.head = NULL;
}

void listDestroy(List & list)
{
    while (!listIsEmpty(list))
        listPopFront(list);
}

bool listIsEmpty(List & list)
{
    return (list.head == NULL);
}

T listFront(List & list)
{
    return list.head->elem;
}

void listPushFront(List & list, T e)
{
    Node * v = new Node;
    v->elem = e;
    v->next = list.head;
    list.head = v;
}

void listPopFront(List & list)
{
    Node * old = list.head;
    list.head = list.head->next;
    delete old;
}

// YEU CAU THUC HANH
//   Dinh nghia cac ham thuc hien cac viec sau:
//     1. Tra ve kich thuoc cua danh sach
//     2. In cac phan tu trong danh sach len man hinh
//     3. Tra ve phan tu o vi tri k trong danh sach (vi tri bat dau tu 0)
//     4. Kiem tra xem mot gia tri x co mat trong danh sach hay khong
//     5. Chen mot phan tu moi vao truoc x (neu x ton tai trong danh sach)
//     6. Xoa phan tu x (neu x ton tai trong danh sach)
//     7. Chen mot phan tu moi vao cuoi danh sach

// VIET CODE CUA BAN O DAY...
