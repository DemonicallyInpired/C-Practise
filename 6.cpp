#include<iostream>
#include<limits>
using namespace std;
// Except for the uninary operator and the assignment all of the expression using the operator with same precedance are usually evaluated from left->right. 
void operator_eval(int a, int b, int c){
	cout << (a == b == c) << endl; //same as right->left precedance expression i.e. (a == (b == c))
	cout << (a - b - c) << endl; //evaluated from left->right i.e. its different from the right to left-evaluation
	cout << (a - (b - c)) << endl; 
}
// Few of the gramamr rules cant really be explained in term of the precedance for isntance the ternary operator generally dont follow the precedance rules. 
bool ternay_operator(int a, int b, int c, int d){
	return a > b ? b == c : c == d; 
}
// Max-Munch rule: It generally tend to choose the longest possible sequence of the character to form a lexical token. For instance && is a single operator rather than two operator corresponding to &, similary
//a+++1 would be treated as (a++) + 1 that is the longest possibel sequence to be considered to form a token here is of course a ++(increment operator); 
void long_sequence_to_consider_for_a_token(int&& a){
	cout << a << endl; 
	cout << (a+++1) << endl;
	cout << ((a++) + 1) << endl;   
}
void bitwise_operators(int a, int b){
	/*Note and equal is not equal to &=, thus if you preffer keyword you must write and_eq*/
	cout << (a&b) << endl; //bitand
	a and_eq b;//and equal
	cout << a << endl;
	cout << (a | b) << endl; //bitor
	a |= b; //or equal
	cout << a << endl; 
	cout << ~a << endl; //compliment
	cout << !a << endl; //not  
	a != b; 
	cout << a << endl; 
	cout << (a ^ b) << endl; //xor
	a ^= b; //xor equal
	cout << a << endl; 
	 
}
// Result of the mixmatch of the operand tpyes involved in a full-expression is that of the largest type meaning if int, float and long are involved in an expression it would caculated with long double //arthematics. Bools and char are generally converted to int in the arthematic expressions. Moreover, wherever logically feasible the result of an operator taking an lval is an lval. 
//Implementation dont really have to check for the overflow and most of them rarely do that for instance in the below example the value of a is increment to the point where it become not fesible for the itegral type to hold it thereby eventually leading to unfortunate conversions as required to represent the value in the integral equivalent. 
void unfortunate_conversion(int a){
	while(true){a += 1; if(a < 0){break;}}
	cout << "A has become negitive with the value" << a << endl; 
}
void results(int& x, float& y, long double& z){
	auto d = x + y + z; 
	cout << "size of the longest operand" << endl; 	
	cout << sizeof(d) << endl; //computation done using long
	int j = x = y; //operator precedence from right to left. meaning the value of j will be assigned after assigning y to x; 
	int* p = &++x; //p stores the address of x not the refernce to the x
	//int* q = &(x++); //q sotres the address of x += 1; 
	int* r = (x > y ? &x : reinterpret_cast<int*>(&y)); //address of greater of x and y; 
	//int& s = (x > y ? x: 1); //error 1 is not an lval; 
	//int& s = (x > y ? d : y); //alright; 
	cout << *p << " " << *r << " "<< '\n'; 
} 
int main(){
	operator_eval(1, 2, 3); 
	long_sequence_to_consider_for_a_token(12); 
	cout << (ternay_operator(2, 1, 1, 0) == 1) << endl; 
	bitwise_operators(12, 13); 
	int x= 12; 
	float y =12.0f; 
	long double z = std::numeric_limits<double>::max();  
	results(x, y, z);  
	int a = 0; 
	unfortunate_conversion(a); 
	return 0; 
}
