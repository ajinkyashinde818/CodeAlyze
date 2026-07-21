import java.util.*;
import java.math.*;
public class Main{
	public static void main(String[] args){
		Scanner sc=new Scanner(System.in);
		int n=sc.nextInt();
		int k=sc.nextInt();
		int s=sc.nextInt();
		for(int i=0; i<n; i++){
			if(k>0){
				k--;
				System.out.print(s+" ");
			}else{
				if(s==2 || s==1){
					System.out.print(s+1+" ");
				}else{
					System.out.print(s-1+" ");
				}
			}
		}
	}
}
