import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int K = sc.nextInt();
		int S = sc.nextInt();
		int count =0;
		int start,end;
		if (S<K) {
			end = S;
		} else {
			end = K;
		}
		if (S-2*K>0) {
			start = S-2*K;
		} else {
			start =0;
		}
		for (int x=start;x<=end;x++) {
			int temp = S-x;
			if (temp >K) {
				count += 2*K-temp+1;
			} else {
				count +=temp+1;
			}
		}
		System.out.println(count);
	}
}
