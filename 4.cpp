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
int main(){
	vector<string>something{"something", "12"};
	const char* p = "12"; 
	int i{1}; 
	f(something, i, p);
	randomfunction(); 
	cout << s << endl;  
	initalize_buffer(); 
	return 0; 
}
