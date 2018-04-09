#include<iostream>
#include<stack>
using namespace std;
 
class calculator{
	private:
		stack<char> optr;
		stack<double> opnd;
		double value;
		public:
			calculator(){
				
				optr.push('#');
			}
			void run();
			void evaluate();
			void clear();
			private:
				int lp(char op);
				int rp(char op);
				double operate(char theta,double a,double b);
				
				
			
};
double calculator::operate(char theta,double a,double b){
 	double ret;
 	switch(theta){
 		case '+':ret=a+b;break;
		case '-':ret=a-b;break;
		case '*':ret=a*b;break;
		case '/':ret=a/b;break;
			
 		
	 }
	 return ret;
	 
 }
 int calculator::lp(char ch){
 	int ret;
 	switch(ch){
 		case '+':ret=3;break;
		case '-':ret=3;break;
		case '*':ret=5;break;
		case '/':ret=5;break;
		case '(':ret=1;break;
		case ')':ret=6;break;
		case '#':ret=1;break; 		
 		
	 }
 	return ret;
 } 
 int calculator::rp(char ch){
 	int ret;
 	switch(ch){
 		case '+':ret=2;break;
		case '-':ret=2;break;
		case '*':ret=4;break;
		case '/':ret=5;break;
		case '(':ret=6;break;
		case ')':ret=1;break;
		case '#':ret=0;break; 		
 		
	 }
 	return ret;
 }
void calculator::evaluate(){
	char ch,op,theta;
	double val,a,b;
	cin>>ch;
	op='#';
	while((ch!='#')||(op!='#')){
		if(isdigit(ch)){
			cin.putback(ch);
			cin>>val;
			opnd.push(val);
			cin>>ch;
			
		}else if(lp(op)<rp(ch)){
			optr.push(ch);
			cin>>ch;
			
		}else if(lp(op)==rp(ch)){
			optr.pop();
			cin>>ch;
			
		}else{
			if(ch!='#'){
			theta=optr.top();
			optr.pop(); 
			b=opnd.top();
			opnd.pop();
			a=opnd.top();
			opnd.pop();
			opnd.push(operate(theta,a,b));
			}else{
				break; 
			} 
			
			 
		}
		op=optr.top(); 
	}
			
	if(op!='#'){
		cout<<"����"<<endl<<op; 
	}else{
		cout<<'='<<opnd.top()<<endl<<op;
	} 
	
}
int main(){
	calculator c;
	
	c.evaluate();

	

	 
}
 
