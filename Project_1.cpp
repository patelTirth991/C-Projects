#include<iostream>
using namespace std;

int main(){
	int h,m,ts,n,s,hs,ms;
	cout<<"Press 1 to convetr second to HH:MM:SS\n";
	cout<<"Press 2 to convetr HH:MM:SS to second\n";
	
	cin>>n;
	switch(n)
	{
		case 1:
			cout<<"Enter Total Second: \n";
			cin>>ts;
			h=ts/3600;
			m=(ts%3600)/60;
			s=(ts%3600)%60;
			cout<<"HH:MM:SS =>";
			cout<<h<<":"<<m<<":"<<s;
			break;
		case 2:
			cout<<"Enter hour:\nEnter minute:\nEnter second:\n";
			cin>>h>>m>>s;
			hs=h*3600;
			ms=m*60;
			ts=hs+ms+s;
			cout<<"Total Second: "<<ts;
		    	
	}
	return 0;
}