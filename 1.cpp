#include<iostream>
#include<limits>
#include<math.h>
#include<cstddef>
#include<vector>
using namespace std; 
using Pchar = char*; 
using PTOF = int(*)(int); 
typedef unsigned int uintr; 

const int sizes = 12; //global scope
int randomc; //declreation without setting aside the memory or something as such!
auto kk = 12; //declration that is also a defination meaining that it sets aside the memory or something as such
const double pi{3.143}; 

const char* name = "something"; 
const char* names[]{"someting", "has", "been", "there"}; 
vector<string>people{"Random", "crap"}; 

struct something; 
struct something{int a; float b; char c;};
struct Date{int day; int month; int year;}; 
int day(Date* d1){return d1->day; }
constexpr int fact(int n){return(n < 2) ? 1: n* fact(n-1);}

enum class Random{RANDOM, CRAP, THAT, HAS, BEEN, THERE}; 
void implementation_defined(){
	int a{12}; //well-defined
	int b = 259; //implementation defined casuse the no of the bits in the char is implementation defiend. 
	cout << a << " " << b << endl; 
	cout << numeric_limits<int>::max() << " " << numeric_limits<int>::min() << endl; 
	cout << pow(2, 32)/2 << endl; 
	//static_assert(sizeof(int) < 3, "size of int is too samll or something"); 
}
struct HolesForInprovements{
	int a; //4 bytets
	char b; //5 bytes
	float c; //structural padding of 3 bytes + 4 bytes = 12;
};  
void undefined_behaviors(){
	int arr[sizes]{};
	arr[sizes+sizes] = 'B';  
	cout << arr[sizes + sizes] << endl; 
}
void ASCII(){
	for(char a = 'a'; a < 'z'; a++){
		cout << static_cast<int>(a) << endl; 
		cout << (char)((int)a) << endl; 
	}
	for(char c; cin >> c;){
		if(c == 'Z'){break;}
		cout << static_cast<int>(c) << endl;
	}
}
bool Booleans(int a, int b){
	return(a == b) ? true : false; 
}
bool isvalid_pointer(int* p){if(p){cout << *p << endl; return true;}else{cout << "cant derefernce the nullptr" << endl; return false; }}
void operation_bools(){
	bool a = 12; 
	bool b = 0; 
	bool c = true; 
	bool d = false; 
	bool e{12!=0}; 
	cout << (a || b) << endl; 
	cout << (a  && b) << endl; 
	cout << (a + c) << endl; 
	cout << (a - e) << endl; 
	cout << e << endl; 
}
void char_are_integrals(){
	for(int i = 0; i< 12; i++){
		cout << (char)('A' + i) << endl; 
	}
}
void char_types_are_distict(char ch, unsigned char uc, signed char sc){
	char* p = &ch; 
	unsigned char* p1{&uc}; 
	signed char* p2{&sc}; 
	//char* p3 = &uc; //not well-defiend for the given construct cause cant assign the type char* to unsigned char*
}
void g(char c, unsigned char uc, signed char sc){
	c = 255; //implementation defined if plain char are signed and have 8 bits. 
	c = uc; //implementation-defined if plain char is signed and uc is too large. 
	c = sc; //OK
	uc = c; //Implementation-defined if plain char is signed and too small. 
	uc = sc; //implementation defiend. 
	sc = c; //alright. 
	sc = uc; //OK conversion to unsinged.  
	cout << c << " " << uc << " " << sc << endl; 
}
void char_literals(){
	char a = 'A'; 
	char b = 'B'; 
	cout << a << " " << b << endl; 
	cout << a << '\n' << b << endl; 
	cout << a << '\b' << b << endl; 
	cout << a << '\v' << b << endl; 
	cout << a << '\f' << b << endl; 
	cout << a << '\r' << b << endl; 
	cout << a << '\a' << b << endl; 
	cout << a << '\t' << b << endl; 
	cout << a << '\\' << b << endl; 
	cout << a << '\?' << b << endl; 
	cout << a << '\"' << b << endl; 
	cout << a << '\'' << b << endl; 
	string somesequence = "a\12\1h"; 
	for(auto &i: somesequence){cout << int(i) << endl; }
	//char a1 = U'\UDEADDEAD'; 
	//char b1 = u'\uDEAD'; 
	//char c1 = u'\x123'; 
	//cout << a1 << b1 << c1 << endl; 
}
void integral_types(){
	int a{12}; 
	int b = 0xffff; 
	int c = 012; 
	cout << a << " " << b << " " << c << endl; 
	long int k{123}; 
	long long int k1 = 12LL; 
	cout << k << k1 << endl; 
	short int m = 1; 
	cout << m << endl; 
}
void sizes1(){
	cout << (sizeof(char) <= sizeof(bool) <= sizeof(short) <= sizeof(int)) << endl; 
	cout << (sizeof(float) <= sizeof(double) <= sizeof(long long) <= sizeof(long double)) << endl; 
	cout << (sizeof(int) == sizeof(signed int) == sizeof(unsigned int)) << endl; 
	cout << (sizeof(char) <= sizeof(bool) <= sizeof(short) <= sizeof(int) <= sizeof(float) <= sizeof(long) <= sizeof(long long) <= sizeof(int*) <= sizeof(double) <= sizeof(long double)) << endl; 
	int32_t a{123}; 
	cout << a << endl; 
	int64_t b{123123123}; 
	cout << b << endl; 
	int_least16_t c = 13; 
	cout << c << endl; 
	int_fast16_t f = 123; 
	cout << f << endl; 
	int arr[3]{1, 2, 3}; 
	ptrdiff_t r = &arr[sizeof(arr)/sizeof(int)]-arr; 
	cout << r << endl; 
}
template<class T>
void* allocate(size_t sizet){
	void* p = malloc(sizeof(T)); 
	return p; 
}
int* unitialized_copy(vector<int>::iterator it1, vector<int>::iterator it2, int* buffer){
	int count = 0; 
	for(auto p = it1; p!= it2; p++){
		buffer[count] = *p; 
		count += 1; 
	}
	return buffer; 
}
void user(vector<int>&v1){
	constexpr int buffmax = 1024; 
	alignas(int) int buffer[buffmax]; 
	const int maximum = min(v1.size(), buffmax/sizeof(int)); 
	auto p = unitialized_copy(v1.begin(), v1.begin()+maximum, buffer); 
	for(int i = 0; i < sizeof(p)/sizeof(int); i++){cout << p[i] << endl;}
}
alignas(32) struct People{
	int a; 
	char b; 
	float c; 
}; 
void local_names(){
	int a; //local name
	float b; //local name
	char c; //local name also called as the function scoped name
}
class Person{
	private: 
		int x, y; //class scope. 
	public: 
		Person(int x1, int y1): x{x1}, y{y1}{cout << x << y << endl; }
		Person(): x{}, y{}{cout << x << y << endl;}
		int return_1(){return 1;}//class scope; 
};
namespace somethingrandom{
	int randomcrap = 12; //namespace scope; 
}; 
void print_vector(vector<int>&v1){
	for(int i = 0; i < v1.size(); i++){cout << v1[i] << endl;}
	for(vector<int>::iterator it = v1.begin(); it != v1.end(); it++){cout << *it << endl;}
	for(auto &i: v1){cout << i << endl;}
}
int x1; 
void shadowing(){
	int x1 = 12; 
	{
		int x1 = 13; 
		cout << x1 << endl; 
	}
	cout << x1 << endl; 
	cout << ::x1 << endl; 
}
void badPractise(){
	int x1 =x1; 
}
void intialization(){
	int a{12}; //type deduced to be intializer_list<int> not int
	vector<int>v1(12); //intialized with default int type for 12 elements, should not be confused with the default function call.
	vector<int>v2{}; //v2 is an empty vector 
	string s4; //has default construct so intialized to ""
	char* p1{}; //p1 intialized to nullptr; 
	static int i; //intialized to 0
	cout << a << s4 << i << endl; 
}
void freestore(){
	int* p = new int{}; 
	int* q{new int[12]}; 
	cout << *p << endl; 
	cout << *q << endl; 
	int randomcraps{}; 
	string* s1{new string{}}; 
	string s2; 
	delete p; 
	delete[] q; 
	delete s1; 
}
void autos(){
	vector<int>v1(100); 
	for(vector<int>::iterator it = v1.begin(); it != v1.end(); it++){
		cout << *it << " "; 
	}
	for(auto &i: v1){cout << i << " "; }
}
/*template<class T, class U>
auto operator+(const Matrix<T>&m1, const Matrix<U>m2)->Matrix<decltype(T{}+U{})>{
	Matrix<decltype(T{}+U{})>res; 
	for(int i = 0; i != m1.rows(); i++){
		for(int j = 0; j != m1.cols; j++){
			res(i, j) = m1(i, j) + m2(i, j); 
		}
	}
	return res; 
}*/
template<class T>
void swapping(T& a, T& b){
	T temp = static_cast<T&&>(a); 
	a = static_cast<T&&>(b); 
	b = temp; 
}
template<class T>
void swapping1(T& a, T& b){
	T temp = std::move(a); 
	a = std::move(b); 
	b = temp; 
}
int returning(int a){return a;}
int main(){
	implementation_defined(); 
	//undefined_behaviors(); 
	ASCII(); 
	isvalid_pointer(nullptr);
	operation_bools();  
	char_are_integrals(); 
	char_types_are_distict('A','B','C'); 
	g('A', 'B', 'C'); 
	char_literals(); 
	integral_types(); 
	sizes1(); 
	cout << sizeof(HolesForInprovements) << endl; 
	vector<int>v1{1, 2, 3, 4};
	user(v1);  
	cout << sizeof(People) << endl; 
	Person p1{1, 2}; 
	cout << p1.return_1() << endl; 
	cout << somethingrandom::randomcrap << endl; 
	print_vector(v1); 
	shadowing();
	badPractise();
	freestore();  
	autos(); 
	vector<int>v11{1, 2, 3, 4}; 
	vector<int>v12{4, 3, 2, 1}; 
	swapping(v11, v12); 
	for(auto &i: v11){cout << i << " "; }
	cout << endl; 
	for(auto &i: v12){cout << i << " "; }
	swapping1(v11, v12); 
	cout << endl; 
	for(auto &i: v1){cout << i << " "; }
	cout << endl; 
	for(auto &i: v12){cout << i << " "; }
	PTOF pf{&returning}; 
	cout << pf(2) << endl; 
	uintr p = 12;
	cout << p << endl; 
	return 0; 
}
