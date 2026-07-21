import java.util.*;
import java.io.PrintWriter;
public class Main{
	public static void main(String[] args){
		Scanner sc=new Scanner(System.in);
		int k=sc.nextInt();
		int n=sc.nextInt();
		int max=0;
		int a=sc.nextInt();
		int last=0;
		int sum=a;
		for(int i=1; i<n; i++){
			int aa=sc.nextInt();
			if(i==n-1){
				last=aa;
			}
			max=Math.max(max,aa-sum);
			sum=aa;
		}
		System.out.println(k-Math.max(max,a+k-last));
	}
}
