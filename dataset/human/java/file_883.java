import java.util.*;

class Main{
	static public void main(String[] args){
		Scanner sc=new Scanner(System.in);
		int n=sc.nextInt();
		int r=sc.nextInt();
		
		if(n<10){
			n=100*(10-n);
		}
		else{
			n=0;
		}
		
		System.out.println(r+n);
	}
}
