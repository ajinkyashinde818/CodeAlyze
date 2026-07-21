#include <iostream>
#include <string>

using namespace std;

class Num{

	//string s0;
	//int inum;
	int N0;
	//int icase;
	int icount;
	int* pn;
	int isign;
	int isign0;
	long long itotal;
	int imin;
	
	
public:
	Num(int);
	Num();
	
	void output() const;
	void input();
	
	int checksign();
	
	int getsign0() const;
	int getN0() const;
	void sort0();
	void test() const;
	int add(int);
	long long add0();
	long long add1();
	void subs0();
	long long getitotal();
	void checkmin(int);
	
	~Num();
};



Num::Num(int itemp){N0=itemp;pn=new int[N0];}
Num::Num(){}


void Num::input(){
	//cout<<"inum?"<<endl;
	//cin>>inum;
	for(icount=0;icount<N0;icount++){

	//cout<<"icount="<<icount<<endl;
	cin>>pn[icount];
}

}

void Num::output() const{
	for(int icount1=0;icount1<N0;icount1++){

	//itemp=pn[icount].output();
	//cout<<"itemp="<<itemp<<endl;
	cout<<"pn["<<icount1<<"]="<<pn[icount1]<<endl;
}
	//return inum;

}	

int Num::checksign(){
	isign=0;
	isign0=0;
	itotal=0;
	imin=abs(pn[0]);
	for(icount=0;icount<N0;icount++){
		checkmin(pn[icount]);
if(pn[icount]<0){
			isign++;
			itotal=itotal-pn[icount];
			pn[icount]=-pn[icount];
			}
		else if(pn[icount]==0){isign0++;}
		else {itotal=itotal+pn[icount];}
									}
	return isign;
}

void Num::test() const{cout<<"hogehoge"<<endl;}

void Num::sort0(){
				bool b0=1;
			while(b0==1){
				b0=0;
				//cout<<"ho0ge"<<endl;
				for(icount=0;icount<N0-1;icount++){
					if((pn[icount])>(pn[icount+1])){
												int itemp0=pn[icount];
												pn[icount]=pn[icount+1];
												pn[icount+1]=itemp0;
												b0=1;
												
												
												}
					else{}
					
				}//end for
				
				//output();
				//cout<<"b0="<<b0<<endl;
				//cout<<"-----"<<endl;
				
				}//end while
					//return 0;
					}//end function
					
					
int Num::add(int itemp){
				itotal=0;
				for(icount=itemp;icount<N0;icount++){
				
						itotal=itotal+(pn[icount]);
						//cout<<"hoge"<<endl;
				}
				return itotal;

}

long long Num::add0(){
				itotal=0;
				for(icount=0;icount<N0;icount++){
				
						itotal=itotal+(pn[icount]);
						//cout<<"hoge"<<endl;
				}
				return itotal;

}//end add0

long long Num::add1(){
				itotal=0;
				for(icount=1;icount<N0;icount++){
				
						itotal=itotal-(pn[icount]);
						//cout<<"hoge"<<endl;
				}
				itotal=itotal+(pn[0]);
				return itotal;

}//end add1

void Num::subs0(){
				
				itotal=itotal-2*imin;
				//return itotal;
				
}//end add1

long long Num::getitotal(){return itotal;}



int Num::getsign0() const{return isign0; }
int Num::getN0() const{return N0; }		

void Num::checkmin(int itempa) {
			//cout<<"itempa,imin="<<itempa<<","<<imin<<endl;
			
			if(abs(itempa)<imin){
						imin=abs(itempa);
								}

					}

Num::~Num(){delete [] pn;}




int main(){
	//int i0=12;
	int N0;
	//int icount;
	//int itemp;
	int isign,isign0;
	long long itotal0;
	//int isign0;
	
	
	//cout<<"N0?"<<endl;
	cin>>N0;
	
	Num n0(N0);
	n0.input();
	//n0.output();
	isign=n0.checksign();
	//isign0=n0.getsign0();
	//isign0=n0.checksign0();
	
	//cout<<"isign="<<isign<<endl;
	//cout<<"isign0="<<isign0<<endl;
	//cout<<"N0="<<n0.getN0()<<endl;



	//n0.sort0();
	//n0.test();
	//n0.output();
	
if(isign%2==1){

				n0.subs0();
}





			//cout<<"itotal="<<itotal0<<endl;
			cout<<n0.getitotal()<<endl;
			
			return 0;
}
