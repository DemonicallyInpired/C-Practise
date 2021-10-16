#include<iostream>
using namespace std; 
int f(int a){return a;}
void pointers(){
	//Pointers are one of the adressing machenisms on any given implementation of the machine. 
	int a{12}; 
	int* ptr{&a}; //Pointer to type int, that is the refernce to the address of an object of the type int, and we can refernce this address without having to copy the object.
	cout << *ptr << endl; 
	cout << ptr << endl; 
	int** arr{&ptr}; //pointer to the pointer of type int. 
	cout << *arr << endl; 
	
	int arr1[12]{}; 
	int arr2[3]{1, 2, 3}; 
	int* q = arr1; //name of the array converts to the pointer to its first element on the slightest provocation.
	int (*ptf)(int) = &f; //Pointer to the function that takes in an int arguement and return an int. 
	int* arr3[2]{arr1, arr2}; //arr of int* 
	int* (*arr4)[2] = &arr3; //pointer to array of int*
	cout << **arr4 << endl; 
	cout << ptf(2) << endl; 
}
void* return_something(){//Pointer to object of unkown type about which we aren't allowed to make any assumptions. 
	int a{12}; 
	int* q = &a; 
	return q; 
}
void* allocations(size_t sizes){
	int* newsomething{new int[sizes]};
	return newsomething; 
}
int main(){
	pointers(); 
	void* q = return_something(); 
	//cout << *q << endl; //error compiler don't actualy know the type of the object pointed to. 
	cout << *(static_cast<double*>(q)) << endl;//unsafe conversion of int* to double*
	cout << *(static_cast<int*>(q)) << endl; //alright but still ugly 
	return 0; 
}
