#include<iostream>
#include<bits/stdc++.h>
#include<stack>
using namespace std;

class Stack{
public:
	stack<int> s;
	int minele;
	
		void getmin();
		void push(int);
		void pop();
		void peek();
		
};
void Stack::getmin(){
	if(s.empty()){
		cout<<"stack is empty"<<endl;
	}
	else{
		cout<<"min element is :"<<minele<<endl;
	}
}
void Stack::peek(){
	int t = s.top();
	
		if(s.empty()){
		cout<<"stack is empty"<<endl;
	      }

		cout<<"peek element is :";
		(t<minele)? cout<<minele: cout<<t;
		cout<<endl;
	
}

void Stack::pop(){
		if(s.empty()){
		cout<<"stack is empty"<<endl;
	      }
	      cout<<"top element is removed .."<<endl;
	      int t = s.top();
	      s.pop();
	      if(t<minele){
	      	cout<<minele<<endl;
	      	minele = 2*minele- t;
		  }
		  else{
		  	cout<<t<<endl;
		  }
}
void Stack::push(int x){
		if(s.empty()){
			minele = x;
			s.push(x);
		cout<<"data inserted"<<endl;
	      }
	      if(x<minele){
	      	s.push( 2*x - minele);
	      	minele = x;
		  }
		  else{
		  	s.push(x);
		  	cout<<"data inserted"<<endl;
		  }
}

int main(){
	Stack s1;
	s1.push(8);
	s1.push(6);
	s1.push(5);
	s1.getmin();
	s1.peek();
	s1.pop();
	s1.getmin();
	s1.push(9);
	s1.getmin();
	s1.peek();
	
	return 0;
}
