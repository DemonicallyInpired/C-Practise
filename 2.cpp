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
// A pointer that doesn't points to anything. 
// Usually donted with the nullptr; 
// However, the previous use may involve using macro NULL or the (void*)0 which typically makes it illegal in C++
// 0 can also be used as an overloaded instance of a function where int is to be overloaded with int*
// NULL has different difination in different implementation in C it is usually 0 or 0L however, in C++ it is usually treated as void*(0) which makes it illegal in C++
void nullptrs(){
	int* q = nullptr; //since it doens't point to anything it can be derefernced
	int* r = 0; 
	int* m = NULL; 
	if(q || r || m){cout << "There is one pointer which is not null" << endl;}
	else{cout << "cant derefernce the nullptr" << endl;}
}
int main(){
	pointers(); 
	void* q = return_something(); 
	//cout << *q << endl; //error compiler don't actualy know the type of the object pointed to. 
	cout << *(static_cast<double*>(q)) << endl;//unsafe conversion of int* to double*
	cout << *(static_cast<int*>(q)) << endl; //alright but still ugly 
	nullptrs(); 
	return 0; 
}
