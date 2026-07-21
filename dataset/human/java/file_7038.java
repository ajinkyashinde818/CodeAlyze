import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) throws IOException {
		Scanner sc = new Scanner(System.in);
		int K = sc.nextInt();
		int N = sc.nextInt();

		int[] a = new int[N];
		int maxDist = 0;
		for(int i = 0; i < N; i++) {
		 a[i] = sc.nextInt();
		 if(i > 0 && (a[i] - a[i-1]) > maxDist)
			 maxDist = a[i] - a[i-1];
		}
		sc.close();

		int tmp = (K-a[N-1]) + a[0];

		if( tmp> maxDist) {
			maxDist = tmp;
		}

		System.out.println(K-maxDist);

	}

}
