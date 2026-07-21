import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		String s = scanner.next();
		String t = scanner.next();

		List<String> Slist = new ArrayList<>();
		List<String> Tlist = new ArrayList<>();
		//文字列を1文字ずつリストに入れる
		for (int i = 0; i < s.length(); i++) {
			Slist.add(s.substring(i, i+1));
		}
		for (int i = 0; i < t.length(); i++) {
			Tlist.add(t.substring(i, i+1));
		}

		//Slistを昇順に並び替え
		Collections.sort(Slist);
		String S = "";
		for (String str : Slist) {
			S += str;
		}

		//Tlistを降順に並び替え
		Collections.sort(Tlist, Collections.reverseOrder());
		String T = "";
		for (String str : Tlist) {
			T += str;
		}

		//System.out.println("S：" + S);
		//System.out.println("T：" + T);

		String judge = "No";
		//文字列の大小を比較
		//辞書的にSがTより大きい時：1、SがTより小さい時：-1、SとTが等しい時：0
		if (S.compareTo(T) < 0) {
			judge = "Yes";
		}
		System.out.println(judge);

	}
}
