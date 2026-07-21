import java.util.*;
public class Main{
	public static void main(String[] args){
		Scanner sc=new Scanner(System.in);
		int n=sc.nextInt();
		int m=sc.nextInt();
		int[] e=new int[m];
		boolean[] check1=new boolean[n],check2=new boolean[n];
		for(int i=0;i<n;i++){
			check1[i]=true;
			check2[i]=true;
		}
		for(int i=0;i<m;i++){
			e[i]=sc.nextInt();
			check1[e[i]-1]=false;
		}
		for(int i=m-1;i>=0;i--){
			if(check2[e[i]-1]==true){
				System.out.println(e[i]);
				check2[e[i]-1]=false;
			}
		}
		for(int i=0;i<n;i++){
			if(check1[i]==true){
				System.out.println(i+1);
			}
		}
	}
}
