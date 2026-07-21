import java.util.ArrayList;
import java.util.Scanner;

public class Main {
	public static void main(String args[]) {
		Scanner stdIn = new Scanner(System.in);
		int N = stdIn.nextInt();
		ArrayList<Integer> D = new ArrayList<Integer>();
		for(int i = 0; i < N * 2; i ++) {
			D.add(stdIn.nextInt());
		}
		
		int keepCnt = 0;
		boolean ans = false;
		for(int i = 0; i < N; i ++) {
			if(D.get(2 * i) == D.get(2 * i + 1)) {
				keepCnt ++;
			}else {
				keepCnt = 0;
			}
			if(keepCnt == 3) {
				ans = true;
				break;
			}
		}
		
		if(ans){
			System.out.println("Yes");
		}else {
			System.out.println("No");
		}
	}
}
