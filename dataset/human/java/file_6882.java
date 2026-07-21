import java.util.*;
import java.util.Scanner;
public class Main {
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		
		int k = scan.nextInt();
		int n = scan.nextInt();
		int a[] = new int[n];
		int dis[] = new int[n];
		int ans = 0;
		for(int i=0;i<n;i++) {
			a[i] = scan.nextInt();
		}
		
		for(int i=0;i<n;i++) {
			if(i!=n-1) {
				dis[i] = a[i+1]-a[i];
			}else {
				dis[i] = a[0]+k-a[i];
			}
		}
		
		Arrays.sort(dis);
		
		for(int i=0;i<n-1;i++) {
			ans += dis[i];
		}
		
		System.out.println(ans);
	}	
	
	
	//最小公約数
	/*
	static int gcd (int a, int b) {
		int temp;
		while((temp = a%b)!=0) {
			a = b;
			b = temp;
		}
		return b;
	}
	*/
	
	//入れ替え
	/*
	static int swap (int a, int b) {
		int swap_arr[] = new int[2];
		
		swap[0] = b;
		swap[1] = a;
		
		return swap_arr;
	}
	*/
	
}
