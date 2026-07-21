import java.util.*;

public class Main{
	public static void main(String[] args){
		Scanner scan = new Scanner(System.in);
		long K = scan.nextLong();
		int N = scan.nextInt();
		long [] house = new long[N + 1];
		long l = 0;

		for(int i=0; i < N; i++){
			house[i] = scan.nextLong();
		}
		house[N] = K + house[0];

		for(int i=0; i < N; i++){
			if (l < (house[i+1] - house[i]) )l = (house[i+1] - house[i]);
		}

		System.out.println(K - l);
	}
}
