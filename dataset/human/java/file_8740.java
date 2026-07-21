import java.util.*;

class Main{
	public static void main(String args[]) {
		Scanner sc=new Scanner(System.in);
		int a=sc.nextInt();
		int b=sc.nextInt();
		int k=sc.nextInt();
		int div=Math.min(a, b);
		int sub[]=new int[div+1];
		int count =0;
		for( int i=div;i>=1;--i) {
			if(a%i==0 && b%i==0) {
				++count;
				sub[count]=i;
			}
		
		}
		System.out.println(sub[k]);

	}
	
}
