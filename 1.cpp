#include<iostream>
#include<limits>
#include<math.h>
const int sizes = 12; 
using namespace std; 
void implementation_defined(){
	int a{12}; //well-defined
	int b = 259; //implementation defined casuse the no of the bits in the char is implementation defiend. 
	cout << a << " " << b << endl; 
	cout << numeric_limits<int>::max() << " " << numeric_limits<int>::min() << endl; 
	cout << pow(2, 32)/2 << endl; 
	//static_assert(sizeof(int) < 3, "size of int is too samll or something"); 
}
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
	return 0; 
}
