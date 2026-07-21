import java.util.*;
import java.io.PrintWriter;
public class Main{
	public static void main(String[] args){
		Scanner sc=new Scanner(System.in);
		int n=sc.nextInt();
		int m=sc.nextInt();
		int x=sc.nextInt();
		int[][] ca=new int[n][m+1];
		for(int i=0; i<n; i++){
			int c=sc.nextInt();
			ca[i][0]=c;
			for(int j=0; j<m; j++){
				int a=sc.nextInt();
				ca[i][j+1]=a;
			}
		}
		long ans=Long.MAX_VALUE;
		for(int i=0; i<1<<n; i++){
			long money=0;
			int[] tmp=new int[m];
			for(int j=0; j<n; j++){
				if((i>>j & 1)==1){
					money+=ca[j][0];
					for(int k=1; k<=m; k++){
						tmp[k-1]+=ca[j][k];
					}
				}
			}
			boolean ch=true;
			for(int j=0; j<m; j++){
				if(tmp[j]<x){
					ch=false;
					break;
				}
			}
			if(ch){
				ans=Math.min(ans,money);
			}
		}
		if(ans==Long.MAX_VALUE){
			System.out.println(-1);
		}else{
			System.out.println(ans);
		}
	}
}
