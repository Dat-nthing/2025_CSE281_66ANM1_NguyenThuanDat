
// Thuc hanh Vector

#include <iostream>
using namespace std;
typedef int T;
struct Vector {
    int size;
    int capacity;
    T * array;
};

// Khoi tao vector
void vecInit(Vector & vec, int initCapacity = 16);

// Huy vector
void vecDestroy(Vector & vec);

// Sao chep vector
void vecCopy(Vector & vec, Vector & vec2);

// Lay kich thuoc vector
int  vecGetSize(Vector & vec);

// Kiem tra vector rong
bool vecIsEmpty(Vector & vec);

// Lay phan tu
T vecGetElem(Vector & vec, int index);

// Cap nhat phan tu
void vecSetElem(Vector & vec, int index, T newValue);

// Tang dung luong vector
void vecExpand(Vector & vec, int newCapacity);

// Chen vao cuoi vector
void vecPushBack(Vector & vec, T newElement);

// Chen vao giua vector
void vecInsert(Vector & vec, int pos, T newElement);

// Xoa phan tu cuoi vector
void vecPopBack(Vector & vec);

// Xoa tat ca cac phan tu
void vecClear(Vector & vec);

// Xoa phan tu o giua vector
void vecErase(Vector & vec, int pos);

// YEU CAU THUC HANH
//   Khai bao cac ham thuc hien cac viec sau:
//     1. Lay dung luong cua vector
//     2. Cat bo phan dung luong du thua cua vector
//     3. In tat ca cac phan tu cua vector len man hinh
//     4. Tim kiem tuan tu tren vector
//     5. Tim kiem nhi phan tren vector (gia su vector da sap xep tang dan)
//     6. Xoa cac phan tu nam o cac vi tri tu pos1 den pos2 tren vector

// VIET CODE CUA BAN O DAY...
//1. Lay dung luong
int vecCapacity(Vector &vec);
//2. Cat dung luong thua
//3. In phan tu
//4. Tim kiem tuan tu
//5. Tim kiem nhi phan
//6. Xoa phan tu

int main()
{
	// Khai bao bien vector
	Vector vec;	

	// Khoi tao vector
	vecInit(vec);

	// Chen mot so phan tu vao cuoi vector
	vecPushBack(vec, 4); // 4
	vecPushBack(vec, 8); // 4 8
	vecPushBack(vec, 3); // 4 8 3
	vecPushBack(vec, 9); // 4 8 3 9
	vecPushBack(vec, 5); // 4 8 3 9 5
	
	// YEU CAU THUC HANH
	//   Viet code goi cac ham da viet de lam cac viec sau:
	//     1. In dung luong cua vector len man hinh
    //     2. Cat bo phan dung luong du thua cua vector
    //     3. In kich thuoc va dung luong cua vector xem co bang nhau hay khong
    //     4. In tat ca cac phan tu cua vector len man hinh
    //     5. Tim kiem tuan tu tren vector
    //     6. Tim kiem nhi phan tren vector (hay tao mot vector khac
	//        chua cac phan tu sap xep tang dan)
	//     7. Xoa cac phan tu nam o cac vi tri tu pos1 den pos2 tren vector
	
	// VIET CODE CUA BAN O DAY...
//1. In dung luong
	cout << "Dung luong ban dau: " << vecCapacity(vec);
//2. Cat bo 
	vecCut(vec);
//3. In kich thuoc va dung luong
	cout << "Kich thuoc: " << vecGetSize(vec) << "\nDung luong: " << vecCapacity(vec);
//4. In tat ca cac phan tu
	cout << "Cac phan tu cua vector: ";
	vecPrint(vec);
//5. Tim kiem tuan tu
	int value1 = 9;
    int index1 = vecSearch(vec, value1);
    if (index1 != -1)
        cout << "Tim thay " << value1 << " tai vi tri: " << index1;
    else
        cout << value1 << " khong co trong vector.";
//6. Tim kiem nhi phan
    Vector sortedVec;
    vecInit(sortedVec);
    vecPushBack(sortedVec, 1);
    vecPushBack(sortedVec, 3);
    vecPushBack(sortedVec, 5);
    vecPushBack(sortedVec, 7);
    vecPushBack(sortedVec, 9);

    int value2 = 5;
    int index2 = vecBinarySearch(sortedVec, value2);
    if (index2 != -1)
        cout << "Tim thay " << value2 << " tai vi tri " << index2;
    else
        cout << value2 << " khong co trong vector";
//7. Xoa phan tu
    int pos1 = 1;
    int pos2 = 3;
    vecEraseRange(vec, pos1, pos2);
    cout << "Vector sau khi xoa tu vi tri " << pos1 << " den " << pos2 << ": ";
    vecPrint(vec);
	// Huy vector
	vecDestroy(vec);
	
	return 0;
}

void vecInit(Vector & vec, int initCapacity) {
    vec.size = 0;
    vec.capacity = initCapacity;
    vec.array = new T[vec.capacity];
}

void vecDestroy(Vector & vec) {
    delete[] vec.array;
}

void vecCopy(Vector & vec, Vector & vec2) {
    if (&vec != &vec2) {
        vec.size = vec2.size;
        vec.capacity = vec2.capacity;
        delete[] vec.array;
        vec.array = new T[vec.capacity];
    
        for (int i = 0; i < vec.size; i++)
            vec.array[i] = vec2.array[i];
    }
}

int vecGetSize(Vector & vec) {
    return vec.size;
}

bool vecIsEmpty(Vector & vec) {
    return (vec.size == 0);
}

T vecGetElem(Vector & vec, int index) {
    return vec.array[index];
}

void vecSetElem(Vector & vec, int index, T newValue) {
    vec.array[index] = newValue;
}

void vecExpand(Vector & vec, int newCapacity) { 
    if (newCapacity <= vec.size)
        return;
    
    T * old = vec.array;
    vec.array = new T[newCapacity];
    for (int i = 0; i < vec.size; i++)
        vec.array[i] = old[i];
    
    delete[] old;
    
    vec.capacity = newCapacity;
}

void vecPushBack(Vector & vec, T newElement) {
    if (vec.size == vec.capacity)
        vecExpand(vec, 2 * vec.capacity);
    
    vec.array[vec.size] = newElement;

    vec.size++;
}

void vecInsert(Vector & vec, int pos, T newElement) {
    if (vec.size == vec.capacity)
        vecExpand(vec, 2 * vec.capacity);

    for (int i = vec.size; i > pos; i--)
        vec.array[i] = vec.array[i - 1];

    vec.array[pos] = newElement;

    vec.size++;
}

void vecPopBack(Vector & vec) {
    vec.size--;
}

void vecClear(Vector & vec) {
    vec.size = 0;
}

void vecErase(Vector & vec, int pos) {
    for (int i = pos; i < vec.size - 1; i++)
        vec.array[i] = vec.array[i + 1];

    vec.size--;
}

// YEU CAU THUC HANH
//   Dinh nghia cac ham thuc hien cac viec sau:
//     1. Lay dung luong cua vector
//     2. Cat bo phan dung luong du thua cua vector
//     3. In tat ca cac phan tu cua vector len man hinh
//     4. Tim kiem tuan tu tren vector
//     5. Tim kiem nhi phan tren vector (gia su vector da sap xep tang dan)
//     6. Xoa cac phan tu nam o cac vi tri tu pos1 den pos2 tren vector

// VIET CODE CUA BAN O DAY...
int vecCapacity(Vector &vec){
	return vec.capacity;
}
void vecCut(Vector &vec){
	if(vec.capacity > vec.size){
		T * newArray = new T[vec.size];
		for(int i=0;i<vec.size;++i){
			newArray[i] = vec.array[i];
		}
	}
	delete[] vec.array;
	vec.array = newArray;
	vec.capacity = vec.size;
}
void vecPrint(Vector &vec){
	for(int i=0;i<vec.size;++i){
		cout << vec.array[i] << " ";
	}
}
int vecSearch(Vector &vec, T value){
	for (int i=0;i<vec.size;++i){
		if(vec.array[i] == value){
			return i;
		}
	}
	return -1;
}
int vecBinarySearch(Vector &vec, T value){
	int left = 0;
    int right = vec.size - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (vec.array[mid] == value)
            return mid;
        else if (vec.array[mid] < value)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}
int vecDelete(Vector &vec, int pos1, int pos2){
	if (pos1 < 0) pos1 = 0;
    if (pos2 >= vec.size) pos2 = vec.size - 1;
    if (pos1 > pos2) 
	return;
    int Count = pos2 - pos1 + 1;
    for (int i = pos2 + 1; i < vec.size; ++i) {
        vec.array[i - Count] = vec.array[i];
    }
    vec.size -= Count;
}
