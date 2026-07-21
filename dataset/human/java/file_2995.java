import java.util.*;
public class Main {
	public static void main(String[] args)  {
		Scanner scan = new Scanner(System.in);
		int n = Integer.parseInt(scan.next());
		int m = Integer.parseInt(scan.next());
		int[] ans = new int[n];
		Arrays.fill(ans, 0);

		int input_a,input_b;
		for (int i = 0;i < m; ++i){
			input_a = Integer.parseInt(scan.next());
			input_b = Integer.parseInt(scan.next());
			if (input_a == 1){
				++ans[input_b];
			}
			if (input_b == n){
				++ans[input_a];
			}
		}

		boolean bool = false;
		for(int i:ans){
			if (i == 2){
				bool = true;
				break;
			}
		}

		System.out.print(bool?"POSSIBLE":"IMPOSSIBLE");
	}
}
//end
