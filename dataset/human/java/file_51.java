import java.util.*;
import java.io.*;

public class Main{
	public static void main(String[] args){
		solve();
	}
	public static void solve(){
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int m = sc.nextInt();
		int[] e = new int[m];
		int[] num =  new int[n+1];
		ArrayList<Integer> list = new ArrayList<Integer>();
		for(int i=0;i<m;i++){
			int x = sc.nextInt();
			num[x] = 1;
			list.add(x);
		}
		for(int i=list.size()-1;i>=0;i--){
			if(num[list.get(i)]==1){
				System.out.println(list.get(i));
				num[list.get(i)] = 2;
			}
		}
		for(int i=1;i<=n;i++){
			if(num[i]==0){
				System.out.println(i);
			}
		}	
	}
}
