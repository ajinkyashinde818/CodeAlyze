import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		String divide[] = { "dream", "dreamer", "erase", "eraser" };
		Scanner sc = new Scanner(System.in);
		String s = sc.next();

		//すべての文字列を左右反転
		StringBuffer sb = new StringBuffer(s);
		s = sb.reverse().toString();
		//		System.out.println(s);
		for (int i = 0; i < 4; i++) {
			sb = new StringBuffer(divide[i]);
			divide[i] = sb.reverse().toString();
			//			System.out.println(divide[i]);
		}

		//端から切っていく
		boolean flg = true;
		for (int i = 0; i < s.length();) {
			boolean flg2 = false;//4この文字のうち、どれかでdevide出来るか判定
			for (int j = 0; j < 4; j++) {
				String d = divide[j];
//				System.out.println(s.substring(i, i + d.length()));
				if (s.length() >= i + d.length() && s.substring(i, i + d.length()).equals(d)) {//dでdivide出来るか
					flg2 = true;
					i += d.length();//divide出来たらiを進める
				}
			}
			if (!flg2) {//divide出来なかったら
				flg = false;
				break;
			}
		}

		if (flg) {
			System.out.println("YES");
		} else {
			System.out.println("NO");
		}

	}

}
