import java.util.Scanner;
public class Main{

	public static void main(String[] args) {
		Scanner stdIn = new Scanner(System.in);
		int k = stdIn.nextInt();
		int s = stdIn.nextInt();
		int cnt = 0;
		for(int i = 0; i <= k; i++) {
			for(int j = 0;j <= k; j++) {
				if(0 <= s-(i+j) && s-(i+j) <= k) {
					cnt++;
				}
			}
		}
		System.out.println(cnt);
		
	}

}
