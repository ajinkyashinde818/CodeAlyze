import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		// TODO 自動生成されたメソッド・スタブ
		Scanner sc = new Scanner(System.in);
		String sline = sc.next();
		int n = sline.length();
		sc.close();
		StringBuffer sb = new StringBuffer(sline);
		String reversed = sb.reverse().toString();
		
		boolean ans = true;
		String[] words = {"maerd", "remaerd", "esare", "resare"};
		for (int i = 0; i < n;) {
			boolean can = false;
			for(String w: words){
				int end = w.length();
				if (i + end > n) continue;
				if (reversed.substring(i, i + end) .equals(w)) {
					i += end;
					can = true;
				}
			}
			if (can == false) {
				ans = false;
				break;
			}
		}
		if (ans){
			System.out.println("YES");
		} else {
			System.out.println("NO");
		}
		
	}

}
