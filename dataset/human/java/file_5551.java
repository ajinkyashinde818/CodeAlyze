import java.util.Arrays;
import java.util.Scanner;
public class Main {

	public static void main(String[] args) {
		Scanner stdIn = new Scanner(System.in);
		
		int n = stdIn.nextInt(); //数列の数
		int k = stdIn.nextInt(); //個数
		int s = stdIn.nextInt(); //条件
		
		int[] a = new int[n];
		Arrays.fill(a, s);
		
		if(s == (int)1e9) {
			for(int i = 0; i < k; i++) {
				System.out.print(s+" ");
			}
			for(int i = 0; i < n-k; i++) {
				System.out.print(s-1+" ");
			}
			
		}else {
			
			for(int i = 0; i < k; i++) {
				System.out.print(s+" ");
			}
			for(int i = 0; i < n-k; i++) {
				System.out.print(s+1+" ");
			}
			
			
			
		}
		
		
		
	}

}
