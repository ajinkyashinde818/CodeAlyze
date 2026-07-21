import java.util.HashMap;
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		String S = sc.next();
		sc.close();
		long INF = 1000000007;

		String[][] count = new String[2][26];

		HashMap<String,Integer> map = new HashMap<String,Integer>();

		for(char c = 'a';c < ('a' + 26);c++) {
		    map.put(String.valueOf(c),1);
		}

		for(int i = 0 ; i < S.length(); i++){
				map.put(S.substring(i, i+1),1+map.get(S.substring(i, i+1)));
		}

		long ans = 1;
		for(String key : map.keySet()){
			ans *= map.get(key);
			ans %= INF;
		}
		ans--;
		System.out.println(ans);
	}
}
