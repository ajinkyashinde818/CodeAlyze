import java.util.Scanner;
public class Main {

	public static void main(String[] args) {
		Scanner stdIn = new Scanner(System.in);
		int K = stdIn.nextInt();
		int S = stdIn.nextInt();
		int count = 0;
		for(int X = 0; X <= K; X++) {
			for(int Y = 0; Y <= K; Y++) {
				if(S-X-Y <= K && S-X-Y >= 0) count++;
			}
		}
		System.out.println(count);

	}

}
