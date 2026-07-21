import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		int n = Integer.parseInt(sc.next());
		int k = Integer.parseInt(sc.next());
		int s = Integer.parseInt(sc.next());
		
		int []a = new int [n];
		boolean jdg = false;
			
		if(s == 1000000000) {
			jdg = true;
		}
		
		for(int i = 0 ; i < n ;i++) {
			if(i < k) {
				a[i] = s;
			}
			else {
				a[i] = jdg ? 1 :(s + 1000);
			}
		}
		
		for(int i = 0 ; i < n-1 ;i++) {
			System.out.print(a[i]+" ");
		}
		System.out.print(a[n-1]);
		System.out.println();

	}

}
