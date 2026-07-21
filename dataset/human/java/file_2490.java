import java.util.*;
class Main{
    int d[]={1000,100,10,1};
    char m[]={'m','c','x','i'};
    void run(){
	Scanner sc=new Scanner(System.in);
	int n=sc.nextInt();
	for(int attend=0;attend<n;attend++){
	    System.out.println(toMCXI(toDecimal(sc.next().toCharArray())+toDecimal(sc.next().toCharArray())));
	}
    }
    int toDecimal(char[] mcxi){
	int x=1;
	int decimalVal=0;
	for(int i=0;i<mcxi.length;i++){
	    if(Character.isDigit(mcxi[i]))x=mcxi[i]-'0';
	    else{
		for(int j=0;j<4;j++){
		    if(mcxi[i]==m[j])decimalVal+=x*d[j];
		}
		x=1;
	    }
	}
	//System.out.println(decimalVal);
	return decimalVal;
    }
    String toMCXI(int decimalVal){
	String mcxi=new String();;
	int temp;
           for(int j=0;j<4;j++){
	       temp=decimalVal/d[j];
	       if(temp>1)mcxi+=temp;
	       if(temp>=1)mcxi+=m[j];
	       decimalVal%=d[j];
	   }
	   return mcxi;
    }
    public static void main(String[] args){
	new Main().run();
    }
}
//imitated nanikaka's
