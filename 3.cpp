#include<iostream>
#include<vector>
#include<ostream>
#include<cstring>
using namespace std; 
// Can be thought of the user define type or sort of a datastructure to store element of arbitary types and can apply structural padding to improve memory layout, unlike array which is a fixed sequence of objects in the memory. 
// You can thought of structure as a class where all the member are public by default, thus you can define constructor for it, member function or even an overloaded operator. 
//we can thus sor the structural elements in the ascending order of the size of the elements of the structure to save the space consumed for its representation. 
struct Address{
	int phone; //4
	const char* name;//4+4+8(siszeof(char*) is 8 on my architecture or something as such!) 
	char zip[4]; //20
	float sal; //24
	char something;//25 + 3 = 28 
	bool operator==(Address& A1){
		if(A1.phone == phone && A1.name == name && A1.zip == zip && A1.sal == sal && A1.something == something){return true;}
		else{return false;}
	}
}; 
struct Address1{
	char something; //1
	int phone; //1+3+4 = 8
	float sal; //4+4 = 8
	char state[4]; //12
	const char* name; //20
	bool operator==(Address1& A1){
		if(A1.phone == phone && A1.sal == sal && A1.state == state && A1.name == name && A1.something == something){return true;}
		else{return false;}
	}
}; 
// structure memeber could be accessed with the pointer, ref or just a copy operation. 
void structral_access_with_copy(Address A1){cout << A1.phone << " " << A1.name << " " << A1.zip[0] << " " << A1.zip[1] << " " << A1.zip[2] << " " << A1.zip[3] << " " << A1.sal << endl;}
void structural_access_with_pointer(Address* A1){cout << A1->phone << " " << A1->name << " " << A1->zip[0] << " " << A1->zip[1] << " " << A1->zip[2] << " " << A1->zip[3] << " " << A1->sal << endl;}
void structural_acess_with_ref(Address& A1){cout << A1.phone << " " << A1.name << " " << A1.zip[0] << " " << A1.zip[1] << " " << A1.zip[2] << " " << A1.zip[3] << " " << A1.sal << endl;}
//structure can be asigned through and return from a function 
Address return_current(Address prev){
	Address current = prev; 
	return current; 
}
// The name of the struct become available as soon as we declare it however, it cant be use until its complete declration casuse compilter might need to know the size of the struct to set aside the memory 
//for its use, mearning you can declare types for the given struct unless its being completely defined. 
struct Link; 
void structural_names(){	
	Link* head; //alright can declare pointer cause it doesn't directly use struct. 
	Link* prev; 
	Link* next; 
	int data; 
};
struct Link{
	int x; 
	int y; 
};
struct S; 
extern S a; //alright; 
S f(); //alright dont use S in any way yet; 
void g(S);//alright dont use s in any way yet
S* h(S* a){return a;}//alright dont use S in any way yet
S* K(S* p){
	//S a; //error can declare object of incomplete type
	//f(); //error dont know the size of S
	//g(a);error dont know the size of s yet
	//p->x = 12; //error cant use object of type S yet. 
	h(p); //alright dont need to know the size of s; 
}
//You can use structure and other variable with same name with the disambiguation being the struct keyword itself. For instance, we can do the following: 
// However one should avoid such confusing overloads. 
struct something1{int x; int y;};
int something = 13; 	

//Since the struct are just like classes where the members are public by defualt you can defined constructor for the struct in particular you can also have member function and destructor. 
//constructor are not only used to assign the member variables in order they are mostly used to reorder arguments, valudata them and to establish invariants. 

struct randomthings{
	int x, y; 
	randomthings(): x{}, y{}{cout << x << " " << y << endl;}//defualt constructor
	randomthings(int x1, int y1): x{x1}, y{y1}{if(x <y){throw std::runtime_error("cant have x > y");}else{cout << x << " " << y << endl;}}
	void addition(int x1, int y1){cout << '{' << x+x1 << ',' << y+y1 << '}' << endl;}
};
struct Point{
	int x, y;  
}; 
struct ArraysEx{
	Point p1[3]; 
};
struct Arrays{
	vector<Point>p; 
	Arrays(Point p1){p.push_back(p1);} 
	Arrays(Point p1, Point p2){p.push_back(p1); p.push_back(p2); } 
}; 
ArraysEx shift(ArraysEx e1, ArraysEx e2){ 
	for(int i = 0; i< 3; i++){
		if(sizeof(e1) && sizeof(e2)){
			e1.p1[i].x += e2.p1[i].x;
			e1.p1[i].y += e2.p1[i].y;
		}
		else{throw std::runtime_error("cant have empty arrays");}
	}
	return e1; 
}
// One of the distadventage of using std::array over the array is that we cant deduce the no of elements form the intializer itself as in case of fhe array with no given elements. 
template<typename T, size_t N>
struct StdArrays{	 
	public: 
		T elem[N]; 
		T* begin() noexcept{return &elem[0];}
		T* end() noexcept{return &elem[0] + N;}
		const T* end() const noexcept{return &elem[0]+N;}		
		T& operator[](const int& i){return elem[i];}
		//const T& operator[](const int& i)const{return elem[i];}
}; 
// Two struct are different type even when they have the identiacal defination as such we can really intialize two different isntance of the struct cause thety are used to define different user-defined types. 

//A Plain odd data could be considereed just as dataa without having to worry about other runtime polymorphisms things such as it being having a default construct, move semantics, copy seamntics, etc. One of the reason to consider
// the plain odd data is to facilate inexpensive copy operation as a block of memeory such as memcpy rather than copy constructor call to move the data around. So a plain odd data can be considered just as data without having to worry
// about user-defined seamantics for construction and copy operations. 
// To check wheter somtehing is a pod which is a standard library type predicate defined in the <type_traits> allowing us to ascertain wheter something is a pod or not for instance.
template<class T>
void mycopy(T* to, T* form, int count){
	if(std::is_pod<T>::value){
		memcpy(to, form, sizeof(T)*count); 
	}
	else{
		for(int i= 0; i< count; i++){
			to[i] = form[i]; 
		}
	}
}
int main(){
	Address A1{123, "something", {'A', 'B', 'C', 'D'}, 123.3f, 'R'}; 
	Address* A2 = &A1; 
	structral_access_with_copy(A1); 
	structural_access_with_pointer(A2); 
	structural_acess_with_ref(A1); 
	Address current = return_current(A1); 
	cout << current.phone << " " << current.name << " " << current.sal << endl; 
	bool equals = A1 == A1;
	cout << equals << endl;
	cout << sizeof(Address) << endl;  
	cout << sizeof(Address1) << endl; 
	randomthings r1 = randomthings{2, 1}; 
	r1.addition(2, 2); 
	Point p1{1, 2}; 
	Point p2{2, 2}; 
	Arrays a1{p1, p2}; 
	for(int i= 0; i < a1.p.size(); i++){cout << a1.p[i].x << " " << a1.p[i].y << endl;}
	// Array of struct or something man!!
	Point points[3]{{1, 2}, {2, 3}, {4, 5}}; 
	for(int i= 0; i< 3; i++){cout << points[i].x << " " << points[i].y << endl;}
	ArraysEx randomarrays{{{1, 2}, {3, 4}, {5, 6}}}; 
	for(int i = 0; i< 3; i++){cout << randomarrays.p1[i].x << " " << randomarrays.p1[i].y << endl;}
	ArraysEx randomthings1 = randomarrays; //since its is being treated as an object we can do assignment to that!! Hurray one problem solved with arrays, right?
	for(int i= 0; i< 3; i++){cout << randomthings1.p1[i].x << " " << randomthings1.p1[i].y << endl;}
	ArraysEx shifted = shift(randomthings1, randomarrays); 
	for(int i = 0; i< 3; i++){cout << shifted.p1[i].x << " " << shifted.p1[i].y << endl;}
	StdArrays<Point, 3>stdArrays{{{1, 2}, {3, 4}, {4, 5}}}; 
	Point pp{5,6}; 
	
	int arr[3]{1, 2, 3}; 
	int arr1[3]{};
	mycopy(arr1, arr, 2); 
	for(int i = 0; i < 3; i++){cout << arr1[i] << " "; }
	return 0; 
}
