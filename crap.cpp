#include<iostream>
using namespace std; 
int b; 
int something(int a){
	return b=a; 
}
int main(){
	something(12); 
	cout << b << endl; 
	return 0; 
}
