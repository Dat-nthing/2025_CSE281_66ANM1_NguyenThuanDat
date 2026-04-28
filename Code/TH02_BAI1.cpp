#include <iostream>
using namespace std;

typedef int T;

struct Vector {
  int capacity, size;
  T *array;
};

void vecInit(Vector &vec, int initCapacity = 16) {
  vec.capacity = initCapacity;
  vec.size = 0;
  vec.array = new T[vec.capacity];
}

void vecDestroy(Vector &vec) { 
	delete[] vec.array;
}

void vecCoPy(Vector &vecA, Vector &vecB) {
	if (&vecA != &vecB) {
    	vecA.capacity = vecB.capacity;
    	vecA.size = vecB.size;
    	delete[] vecA.array;
    	vecA.array = new T[vecA.capacity];

    	for (int i = 0; i < vecA.size; i++)
    		vecA.array[i] = vecB.array[i];
  }
}

int vecGetSize(Vector &vec){ 
	return vec.size;
}

bool vecIsEmpty(Vector &vec){
	return (vec.size == 0);
}

T vecGetElem(Vector &vec, int Index){
	return vec.array[Index];
}

void vecSetElem(Vector &vec, int index, T newValue){
  vec.array[index] = newValue;
  vec.size++;
}

void vecExpand(Vector &vec, int newCapacity){
	if (newCapacity <= vec.size){
		return;
 	}
  	T *old = vec.array;
  	vec.array = new T[newCapacity];

  	for (int i = 0; i < vec.size; i++) {
    vec.array[i] = old[i];
  	}
  	delete[] old;
  	vec.capacity = newCapacity;
}

void vecPushBack(Vector &vec, T newElement){
  	if (vec.capacity <= vec.size) {
   		vecExpand(vec, 2 * vec.capacity);
  	}
  	vec.array[vec.size] = newElement;
  	vec.size++;
}

void vecInsert(Vector &vec, int pos, T newElement){
  	if (vec.capacity <= vec.size) {
    	vecExpand(vec, 2 * vec.capacity);
  	}
 	 vec.size++;
  	for (int i = vec.size; i > pos; i--)
    	vec.array[i + 1] = vec.array[i];
  	vec.array[pos] = newElement;
}

void vecPopBack(Vector &vec){
	vec.size--;
}

void veClear(Vector &vec){
	vec.size = 0;
}

void vecErase(Vector &vec, int pos){
  	for (int i = pos; i < vec.size; i++) {
    	vec.array[i] = vec.array[i + 1];
  	}
  	vec.size--;
}

void vecPrint(const Vector &vec) {
  cout << "Vector (" << vec.size << "/" << vec.capacity << "): ";
  for (int i = 0; i < vec.size; ++i)
    cout << vec.array[i] << " ";
  cout << endl;
}

int main() {
  Vector vector;
  vecInit(vector);
  // Thêm phần tử
  vecPushBack(vector, 10);
  vecPushBack(vector, 20);
  vecPushBack(vector, 30);
  vecPrint(vector);

  // Chèn phần tử
  vecInsert(vector, 1, 15);
  vecPrint(vector);

  // Cập nhật phần tử
  vecSetElem(vector, 0, 99);
  vecPrint(vector);

  // Xóa phần tử
  vecErase(vector, 2);
  vecPrint(vector);

  // Xóa phần tử cuối
  vecPopBack(vector);
  vecPrint(vector);

  vecDestroy(vector);
  return 0;

}
