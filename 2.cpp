#include<iostream>
#include<vector>
#include<string.h>
using namespace std; 
int f(int a){return a;}
//const int something_there; //error must be intialized; 
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
void warchar_encodings(){
	const char* file_path = R"(C:/home/something)"; //Raw string literal 
	const char* file_path1 = u8"C://home//something"; //UTF8 string literal
	const char* file_path2 = u8R"(C:/home/something)"; //Raw UTF8 string literal 
	const char16_t* file_path3 =  u"C://home//something";//UTF-16 string literal  
	const char32_t* file_path4 = U"C://home//something"; //UTF 32 string literal
	const char32_t* file_path5 = UR"("C:/home/something_else")"; //Raw UTF-32 string literal
	cout << file_path << " " << file_path1 << " " << file_path2 << " " << file_path3 << endl; 
	cout << file_path4 << " " << file_path << endl; 
}
void Pointer_and_Arrays(){
	int arr[]{1, 2, 3}; 
	int* p = arr; //array name implcitly converts to the pointer to the first elements.
	int* q = p+1; //alright but you can't perform any read or write operation on that. 
	//int* r = p-1; //illegal 
	//int *m = p+4; //illegal 
	//Implict conversion of an array to the pointer to the first elements is usually the source of the subtle error and generally leads to losing the size of an array. 
	vector<int>v1{1, 2, 3}; 
	vector<int>v2{v1}; 
	char somethings[]{"something"}; 
	cout << strlen(somethings) << endl;
	const char* something_else = "something"; 
	cout << strlen(something_else) << endl;    
}
void arrays(){
	const int n = 7; 
	// int arr[n]{}; //error array must be const bound sequence of object of given type in the memory, use vector, valarray or simply array. 
	int arr[n]{}; //alrigth statically allocated array; 
	int* q = new int[n]; //alright dynamically allocated array. 
	delete[]q; //Much better if done with some encapsulated resoruce handler such as vector valarray or array. 
	cout << arr[2] << endl; //acess the array index from 0 to n-1; 
	//cout << arr[n+1] << endl;//accessing out of bound index range-checking is not guaranteed and usually expensive. 
	int* r = arr; //array implictly converts to the pointer to the first element. 
	cout << *r << endl;  
	int arr1[n]{1, 2, 3, 4, 5, 6, 7}; //explict intialization; 
	//int arr2[n]{1, 2, 3, 4, 5, 6, 7, 8}; //error: intialization with sulprus elements when the size is provided. 
	int arr3[n]{1, 2, 3}; //alright rest of the elements are appended with zeros. 
	//int arr4[n] = arr1; //error no builtin copy operation cant intialize the array with another array. 
	//cant pass array by value due to implicit conversion rule. 
}
void navigation(int arr[], int size){
	for(int i = 0; i <size; i++){cout << arr[i] << " "; }
	for(int* q = arr; q != &arr[(int)(sizeof(arr)/sizeof(int))]; q++){cout << *q << " "; }
	for(int i = 0; i <size; i++){cout << *(arr+i) << endl; }
}
void string_literal(){
	const char* name = "randomcrap"; 
	//name[2] = 'A'; 
	cout << name << endl; 
	char names[]{"randomcrap"}; 
	names[1] = 'R'; 
	cout << (sizeof(name) == 11) << endl;
	for(auto &i: names){cout << i;}
	const char* name1 = "something"; 
	const char* name2 = "something"; 
	cout << (name1 == name2) << endl; //Check for the equality of the pointers.
	const char* somethings = "abcdefghij"
							 "klmnopqrst";
	const char* randomnames = "random\00something"; 
	cout << randomnames << endl; 
	cout << somethings << endl;
	cout << randomnames << endl;  
}
// String literals are statically allocated so, its safe to return one form the function 
string error_no(int i){if(i){return "out of range error";}else{return "";} }
template<typename T>
int return_bytes(T* p, T* q){
	return reinterpret_cast<char*>(q)- reinterpret_cast<char*>(p); 
}
void Two_D_Traversal(int arr[2][3]){
	for(int i = 0; i <2; i++){
		for(int j = 0; j <3; j++){
			cout << arr[i][j] << " "; 
		}
		cout << endl; 
	}
}
void randomtraversal(int arr[][3], int dim1){
	for(int i= 0; i< dim1; i++){
		for(int j = 0; j< 3; j++){cout << arr[i][j] << " ";}
		cout << endl; 
	}
}
void moresane_Traversal(int* arr, int dim1, int dim2){
	for(int i = 0; i< dim1; i++){
		for(int j = 0; j <dim2; j++){cout << arr[i* dim2 + j] << " "; }
		cout << endl; 
	}
}
void Pointer_and_constant(){
	int a = 12; 
	const int* p = &a; //OK pointer to const int 
	int* const r = &a; //OK const pointer to int
	const int* const rr = &a; //OK const pointer to const int
	//*p = 13; //illegal cant do that 
	*r = 13; //alright; 
	//*rr = 13; //illegal cant modifiy const int. 
	cout << *r << endl; 
	cout << *p << endl; 
	cout << *rr << endl;  
}
int main(){
	pointers(); 
	void* q = return_something(); 
	//cout << *q << endl; //error compiler don't actualy know the type of the object pointed to. 
	cout << *(static_cast<double*>(q)) << endl;//unsafe conversion of int* to double*
	cout << *(static_cast<int*>(q)) << endl; //alright but still ugly 
	nullptrs(); 
	arrays(); 
	string_literal();
	cout << error_no(12) << endl;
	string raw_strings = R"(This is something 		greate \n)"; 
	string someother_raw_strings = R"***("something is there"())***"; 
	cout << someother_raw_strings << endl; 
	cout << raw_strings << endl;
	string otherthings = R"("so, the raw string literals can contain 
	new lines, huh?
	cool!")"; 
	cout << otherthings << endl;    
	warchar_encodings(); 
	Pointer_and_Arrays(); 
	int arr[3]{1, 2, 3}; 
	navigation(arr, 3); 
	int indexing[]{1, 2, 3}; 
	int j = 1; 
	cout << (indexing[j] == *(indexing+j)) << endl; 
	cout << (j[indexing] == *(j + indexing)) << endl; 
	cout << (j[indexing] == indexing[j]) << endl; 
	int randomthings[]{1, 2, 3, 4}; 
	cout << arr << " " << arr+2 << " " << return_bytes(arr, arr+1) << endl; 
	cout << &arr[0] << " " << &arr[3] << " " << return_bytes(&arr[0], arr+3) << endl; 
	int randomarray[2][3]{{1, 2, 3}, {4, 5, 6}}; 
	Two_D_Traversal(randomarray); 
	randomtraversal(randomarray, 2); 
	moresane_Traversal(&randomarray[0][0], 2, 3); 
	Pointer_and_constant(); 
	return 0; 
}
