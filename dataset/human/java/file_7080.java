import java.util.Scanner;

public class Main{
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		int k = Integer.parseInt(sc.next());
		
		int n = Integer.parseInt(sc.next());
		
		int []a = new int [n];
		
		for(int i = 0 ; i < n ;i++) {
			a[i] = Integer.parseInt(sc.next());
		
		}
	
		int max = k-a[n-1]+ a[0];
		for(int i = 1 ;i < n ;i++) {
			max= Math.max(a[i] -a[i-1],max);	
		}
		

		System.out.println(k - max);
	}		
	}
