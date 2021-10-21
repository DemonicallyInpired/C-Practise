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
//used to store the information much more compactly in certain scenario such as storing a date or something. 
// bitfiled represents the no of the bits required to represent the variable or something. 
// bitfiled data structures can't be addressed since they are not allocated on the regular word boundary. 
// code need to maintain bitfiled usually increases significantlly as compared to the normal data types. 
struct bitfiled{
	bool something: 1; 
	int a: 3; 
	char p: 1; 
};
//unions: Are the way to save some more memory per say and they are often used in such a way that each of their member actually points to the same memory address. And since each of the member points to thte same memory address we can only access one memeber at a time and hte we need to be explicit about the representation of that member. It is practically useful when wrapped around some bettter behaved data structure such as a struct or something as such. For the other parts, the union is rather a failrly simple user-defined type and it can only exisist in cornation to some bounds on it which are as follows: 

// a.) You can intialized atmost one of the memeber variable within the union. 
// b.) User-defined constructor semantics i.e. the copy and the move operation is not allowed for any of such union members, for such members default constructor, copy and move semantics is often deleted.  
// c.) A union cant really have a base calss or something along that line. 
// d.) A Union cant really have a virtual function inside of it. 
// ALl of these restriction im[posed on the union often made it quite hard to use, yet they are most often missued in some of the case for example implictly hacking to convert and int to int* (not a good idea cause they are stored on a completely differnet architectural boundraies.)

union randomthings11{
	int a;  
	float b; 
	const char* somethingrandom; 
	//float b =13;//Not allowed can have atmost one intailized member variable.  
	//complex<int>d1; //not allowed deleted constructor
	//string s; //not allowed delted constructor or having a default constructor
}; 
union fudge{
	int a; 
	int* b; 
};
// Anonymus union: 
class Entry2{
	private: 
		enum class Tag{NUM, STR};
		Tag types; 
	public: 
		union{ //Annonymus union that is a union without any sort of name or something as such
			// An annonymous union usually correponds to an object rather than a type, meaning we can use its members without specifying the object name. 
			int a; 
			string s; //since the string has a user-defined copy and move semantics that are often deleted in the union we need to redefine them to use union members or to initialize the union members. 
		};
		~Entry2(); 
		Entry2& operator =(Entry2& ee); 
		Entry2(const Entry2&); 
		
		int get_number() const; 
		string get_string() const; 
		
		void set_num(int n);
		void set_string(const string& ss);  
		struct Bad_entry{};  
}; 

int Entry2::get_number() const{
	if(types != Tag::STR){throw Bad_entry{};}
	return a; 
}
string Entry2::get_string() const{
	if(types != Tag::NUM){throw Bad_entry{}; }
	return s; 
}

void Entry2::set_num(int n){
	if(types == Tag::STR){
		s.~string(); 
		types = Tag::NUM;
	}
	a = n; 
}
void Entry2::set_string(const string& ss){
	if(types == Tag::STR){
		s = ss; 
	}
	else{
		new(&s)string{ss}; 
		types = Tag::STR; 
	}
}
Entry2& Entry2::operator =(Entry2& ee){
	if(types == Tag::STR && ee.types == Tag::STR){
		s = ee.s; 
		return *this; 
	}
	if(types == Tag::STR){s.~string();}
	switch(ee.types){
		case Tag::NUM: 
			a = ee.a; 
			break; 
		case Tag::STR: 
			new(&s)string{ee.s}; 
			ee.types = Tag::STR; 
			break; 
	}
	return *this; 
}
Entry2::~Entry2(){
	if(types == Tag::STR){s.~string();}
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
	cout << endl; 
	cout << "The size of the bitfiled is:: " << endl; 
	cout << sizeof(bitfiled) << endl; 
	//bitfiled* m1;: error cant address bitfiled.  
	randomthings11 r11; 
	r11.a = 12.33; 
	cout << "Both of the union members have the same address" << endl; 
	cout << &r11.a << endl; 
	cout << &r11.b << endl;  
	cout << sizeof(randomthings11) << endl; //sizeof the union is that of its largest member. 
	cout << *reinterpret_cast<int*>(&r11.b) << endl; //ugly but that the way to use float when its intialized to point to an int. 
	fudge f1; 
	int randomsomething = 12; 
	f1.b = &randomsomething;
	cout << *(f1.b) << endl;
	cout << *(&f1.a) << endl;   
	return 0; 
}
