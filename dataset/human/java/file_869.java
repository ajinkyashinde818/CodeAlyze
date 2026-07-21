import java.util.Scanner;

public class Main {
	public static void main(String[] args){
		Scanner stdIn = new Scanner(System.in);
		int N = stdIn.nextInt();
		int R = stdIn.nextInt();
		int ans = 0;
		if(N >= 10){
			System.out.println(R);
		}
		else{
			ans = 100 * (10 - N);
			System.out.println(R + ans);
		}
		stdIn.close();
	}
}
