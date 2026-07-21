import java.util.Scanner;

public class Main {
    static Scanner stdIn = new Scanner(System.in);
    public static void main(String[] args){
		int n = stdIn.nextInt();
		int k = stdIn.nextInt();
		int s = stdIn.nextInt();
		int[] a = new int[n];
		for(int i=0; i<k; i++){
			a[i] = s;
		}
		for(int i=k; i<n; i++){
			a[i] = (s+1)%1000000000;
		}

		for(int i=0; i<n; i++){
			System.out.print(a[i] + " ");
		}
	}
}
