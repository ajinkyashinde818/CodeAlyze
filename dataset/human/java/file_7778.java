import java.util.*;
import java.io.PrintWriter;
public class Main{
	public static void main(String[] args){
		Scanner sc=new Scanner(System.in);
		int n=sc.nextInt();
		long k=sc.nextLong();
		int[][] dub=new int[n][61];
		int[] a=new int[n];
		for(int i=0; i<n; i++){
			a[i]=sc.nextInt()-1;
			dub[i][0]=a[i];
		}
		for(int i=1; i<=60; i++){
			for(int j=0; j<n; j++){
				dub[j][i]=dub[dub[j][i-1]][i-1];
			}
		}
		int now=0;
		while(k>0){
			for(int i=60; i>=0; i--){
				if(k>=1L<<i){
					k-=1L<<i;
					now=dub[now][i];
				}
			}
		}
		System.out.println(now+1);
	}
}
