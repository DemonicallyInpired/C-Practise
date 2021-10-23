#include<iostream>
#include<vector>
using namespace std; 
// C++ offers a conventation way of expressing statements, usually all that is interesting and compicated
// is often found in the expression or the declration and statements have a little to do with anything, 
// a declration is an expression, and that an expression becomes a statement as soon as you add a semicolan to the end of it. 
// In that sense, a stament has much to do with the order of the execution rather than something else. 
// Though the statement may being executed in the order in which they are defiend but, sometimes, the compiler may reorder them to certain extent as long as the meaning is preserved. 
// Most of the declration are often treated as the statement, cause a rather well-thought of reason of intializing the variable before using it, make the resulting code more readable and facilitate localizing the errros.

void f(vector<string>&v1, int i, const char* p){
	if(p == nullptr){return;}
	else if(i < 0 || v1.size() <= i){throw std::runtime_error("Bad index"); }
	else{
		string s = v1[i]; 
		if(s == p){cout << "equal" << endl;}
		else{cout << "Not equal or somehting as such" << endl; }
	}
	return; 
} 
// usually, declration while defining an identifier for an const object is for the most of the part providental. 
// However, in other cases, exploting user-defined type, deffering defination of a variable is often promoted and can lead to better performance. 
string s; 
void randomfunction(){
	s = "something is there"; 
	cout << s << endl; 
}
// The most common reason to declare the variable without intialization is that it requires the statement to give it desired value. The input variable, 
// is amongst the most few reasonable examples for that. 
// A branch of the if statement cant be just a declration and if we tend to introduce a name in the branch it must be enclosed within the block. 
void f1(int a){
	//if(a) int x =12; cout << x << endl;  
	if(a){int x =12+a; cout << x << endl;}
}
void initalize_buffer(){
	const int max1 = 10;
	char buff[max1]; 
	int count{}; 
	for(int i; cin >> i;){
		if(i < 0){throw std::runtime_error("cant allow negitive indices");}
		else if(count == max1){throw std::runtime_error("Buffer overflow");}
		else if(count >= max1+1){break;}
		else{buff[count++] = i;}
		}
}
// If-else conditional statement checks for a boolean predicate if that predicate is true, the if clause of statement is executed
// with utmost eclat otherwise, the else is rednered. Usually a type other than boolean in if clause can be implictlly converted to the required boolean type, 
// however, since enum classes are strongly scoped and doesn't allow implict conversion to the boolean variable, it is often not allowed, to be a part of the if clause. 
enum class e1{random, things}; 
void enum_clause(){
	if(static_cast<int>(e1::random) || static_cast<int>(e1::things)){cout << "something is present" << endl;}//no implicit conversion to bool
	//else if(e1){cout << "alright!" << endl;} no implicit conversion to int or bool
	else{cout << "nothing is present" << endl; }
}
// Logical operators such as && and || are lazily evaluated i.e. if their first operand is true they are rendered true without checking the second operand. 
// For choosing between the two alterantives, conditional expression is more direct, for instance: 
int maximum(int a, int b){
	return(a > b) ? a : b; 
}
// switch statements are generally used to select amongst a set of alternatives cases(which may be a const expression, integral or enumerator). 
// A value inside the case-label may not be used more than once. 
// For example: 
void g(int i){
	// A switch statement can thus be alternatively written as a series of if else clases. 
	// However, it is generally more readable and generate more compact-code in the obvious, 
	// cases that requires to check a set of statement against a single value, cause switch statement requires a single jump-table to check its cases rahter than repeadtly checking the conditional branches.  
	switch(i){
		case 0: 
			cout << "even" << endl; 
			break;
		case 1: 
			cout << "odd" << endl; 
			break;
		default: 
			cout << "something" << endl; 
	}
	// beware that the case may be terminated somehow(either with the break statement or the return statement), unless carrying out the execution is intentional in which case, the intention must be commneted to avoid confusion. 
	switch(i){
		case 0: 
			cout << "even" << endl; 
		case 1: 
			cout << "odd" << endl; //intentional fallback
			break; 
		default: 
			cout << "soemthing else" << endl; 
	}
	// default cases are generally used to catch any sort of an error or provide fallbacks, i.e. every valid things are covered by cases. 
	// It is almost always a good idea to provide a default fallback, however, one can't advocate the same in case of the enumerator in case value, 
	// in which case leaving the default case might provide compiler a chance to warn againt a set of values that almost but not quite match against the set of enumerators.
	// for example: 
	e1 v = e1::random; 
	switch(v){
		case e1::random: 
			cout << static_cast<int>(e1::random) << endl; 
			break; 
		case e1::things: 
			cout << static_cast<int>(e1::things) << endl; 
			break;
		/*default: 
			//opps it allows missing enumerator values
			cout << "crap" << endl; */
	} 
	// It is possible and a common practise to declare variable within the switch cases, however, 
	// it is not possible to bypass such variables. 
	/*switch(i){
		case 0: 
			int x; 
			int y = 3; //error declration can be bypassed if i = 1 implictly initialized. 
		case 1: 
			x += 1; //error use of unitialized_variables
			y += 1; 
			break; 
		default: 
			cout << "random crap" << endl; 
	}*/
	// If we want the use of variable within the switch statement, we can limit its scope by enclosing its declration within a block. 
}
int main(){
	vector<string>something{"something", "12"};
	const char* p = "12"; 
	int i{1}; 
	f(something, i, p);
	randomfunction(); 
	cout << s << endl;  
	//initalize_buffer(); 
	enum_clause(); 
	cout << maximum(12, 13); 
	f1(12); 
	g(12); 
	return 0; 
}
