import  java.util.*;
class Main{
    int s;
    int i;
    int a=0;
    Main(){
	Scanner sc=new Scanner(System.in);
	for(i=1; i<11; i++){
	   s=sc.nextInt();
	   a=a+s;
	}
	System.out.println(a);	    
	  
	

    }

    public static void main(String[] args){
	new Main();
    }
}
