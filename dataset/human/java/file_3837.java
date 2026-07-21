import java.io.IOException;
import java.util.Scanner;

public class Main {

	public static void main(String[] args) throws IOException {
		// TODO 自動生成されたメソッド・スタブ
		Scanner in = new Scanner(System.in);

		String S = in.nextLine();

		int ans = 0;
		int left = 0;
		int right = S.length() - 1;

		while(left < right) {
			if(S.charAt(left) == S.charAt(right)) {
				left++;
				right--;
			}else {
				if(S.charAt(left) == 'x') {
					ans++;
					left++;
				}else if(S.charAt(right) == 'x'){
					ans++;
					right--;
				}else {
					ans = -1;
					break;
				}
			}
		}

		System.out.println(ans);

	}

}
