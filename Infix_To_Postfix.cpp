#include<iostream>
#include<vector>
#include<string>
using namespace std;
int rank(char a){
	int ranki;
	if(a=='(' || a==')'){
		ranki=0;
	}
	else if(a=='^'){
		ranki=3;
	}
	else if(a=='*' || a=='/'){
		ranki=2;
	}
	else if(a=='+' || a=='-'){
		ranki=1;
	}
	else if(a=='#'){
		ranki=-1;
	}
	return ranki;
}
main(){
	string str;
	char stack[50];
	int top=0;
	stack[0]='#';
	vector<char> polish;
	char next;
	int temp;
	cout<<"Input String : ";
	cin>>str;
	int place[20];
	int p=-1;
	for(int i=0;i<str.length();i++){
		next = str[i];
		temp=str[i];
		if(temp<=129 && temp>=65){
			polish.push_back(next);
		}
		else{
			if(next=='('){
				top=top+1;
				stack[top]=next;
				p+=1;
				place[p]=top;
			}
			else if(next==')'){
				while(top != place[p]){
					polish.push_back(stack[top]);
					top-=1;
				}
				top=top-1;
				p-=1; 
			}
			else{
				while(rank(next) <= rank(stack[top])){
					polish.push_back(stack[top]);
					top=top-1;
				}
				top+=1;
				stack[top]=next;
			}
		}
	}
	while(stack[top]!='#'){
		polish.push_back(stack[top]);
		top-=1;
	}
	vector<char>::iterator it;
	cout<<"Output String : ";
	for(it = polish.begin();it!=polish.end();++it){
		cout<<*it;
	}
	cout<<"\n";
	return 0;
}
