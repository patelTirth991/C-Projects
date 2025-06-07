#include<iostream>
using namespace std;

class timeconv{
	public:
		int h,m,s,ts;
		void stohms(int s){
			h=s/3600;
			m=(s%3600)/60;
			s=(s%3600)%60;
			cout<<"HH:MM:SS :"<<h<<":"<<m<<":"<<s;
		}
		void hmstos(int h,int m,int s){
			ts=h*3600+m*60+s;
			cout<<"Total seconds :"<<ts;
		}
	
};
int main(){
	timeconv t;
	int h,m,s,ts,n;
    cout<<"Press 1 for second to HH:MM:SS\nPress 2 for HH:MM:SS to seconds.";
    cin>>n;
    switch(n){
    	case 1 :
    		cout<<"Enter total seconds :";
	        cin>>s;
	        t.stohms(s);
	        break;
	    case 2:
		    cout<<"Enter hour :\n";
			cin>>h;
			cout<<"Enter minute :\n";
			cin>>m;
			cout<<"Enter second :\n";
			cin>>s;
			t.hmstos(h, m, s);
			break;    
	}
	return 0;
}