#include<iostream>
using namespace std; 
enum class Kind:char{
	name, number, end, 
	plus = '+', minus = '-'. mul = '*', div = '/', print = ';', assign = '=', lp = '(', rp=')'
}
struct Token{
	Kind kind; 
	double number_val; 
	string string_val; 
}; 
class Token_stream{
	private: 
		void close(){if(owns){delete ip;}}
		istream* ip; 
		bool owns; 
		Token ct{Kind::end}; 
	public: 
		Token_stream(istream& is): ip{is}, owns{false}{ }
		Token_stream(istream* is): ip{is}, owns{true}{ }
		~Token_stream(){close(); }
		Token get(); 
		const Token& current(); 
		void set_input(istream& is){close(); ip = &is; owns = false;}
		void set_input(istream* is){close(); ip = is; owns = true;}
}; 
Token Token_stream::get(){
	char ch = 0; 
	*ip>>ch; // Here ch == 0 will indicate the end of the istream. and >>0 doesnt change the input stream. 
	switch(ch): 
		case 0: 
			return ct={Kind::end}; // gotcha assignment is an operator and the return value of that operator is the value of the variable assigned to meaning the given statement indirectly assigned ct to kind::end
		case ';':
		case '*':
		case '/':
		case '+':
		case '-':
		case '(':
		case ')':
		case '=':
			return ct == {static_cast<Kind>(ch)};
		case '\n': 
			return {ct = Kind::print}; 
		case '0': case '1': case '2': case '3': case '4': case '5': case '6': case '7': case '8': case '9': case '.': 
			/*ip->putback(ch); //put the first digit or (.) into the input stream
			*ip>>ct.number_val; //read the number into ct
			ct.kind = Kind::number; 
			return ct;*/
			do{
				if(ip->get(ch)){return ct = {Kind::end};}//it doesn't requires the name to be terminated by the whitespace and doesn't requires the cal expression to always end with; get(ch) returns true if we get ch from the input otherwise false. meaning !get(ch) indicates the last char from the input.
			}while(ch != '\n' && std::isspace(ch)); 
		default: //name, name = or error
			/*if(std::isalpha(ch)){
				ip->putback(ch); //put first char back into input stream
				*ip >> ct.string_value; //read the string into input_stream until the whitespace is required bad can be solved with constant lookup for whitespace using std::isspace, isdigit, isalpha, isalnum. 
				ct.kind = Kind::name;
				return ct; 
			}*/
			if(std::isalpha(ch)){
				string_value = ch; 
				while(ip->get(ch) && isalnum(ch)){string_value += ch;}
				ip->putback(ch); 
				return ct={Kind::print}; 
			}
			std::runtime_error("bad token"); 
			return ct={Kind::print}; 
}
double prim(bool get){
	if(get){ts.get();}
	switch(ts.current().kind){
		case Kind::number:{
			double v = ts.current().number_val; 
			ts.get(); 
			return v; 
		}
		case Kind::name: {
			double &v = table[ts.current().string_val]; 
			if(ts.get().kind == Kind::assign){v = express(true);}
			return v; 
		}
		case Kind::minus: 
			return -prim(true); 
		case Kind::lp : {
			auto e = express(true); 
			if(ts.current().kind != Kind::rp){throw std::rumtime_error("')' expected");}
			ts.get(); 
			return e; 
		}
		default: 
			throw std::rumtime_error("expected a primary"); 
	}
}
// Handling multiplication and divisions
double term(bool get){
	double left = prim(get);
	while(true){
		switch(ts.current().kind){
			case Kind::mul: 
				left *= prim(true); 
				return left; 
			case kind::div: 
				if(auto d = prim(true)){
					left /= d; 
					break; 
				}
				throw std::runtime_error("cant devide by 0"); 
			default: 
				return left; 
			
			}
	} 
}

// Handling the addition and substraction expression or osmething as such
double expresS(bool get){
	double left = term(get); 
	for(;;){
		switch(ts.current().kind){
			case Kind::plus: 
				left += express(true); 
				break; 
			case Kind::minus: 
				left -= express(true); 
				break; 
			default: 
				return left; 
		}
	}
}

int main(){	
	return 0; 
}
