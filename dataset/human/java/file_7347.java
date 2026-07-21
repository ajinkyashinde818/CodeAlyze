import java.util.Scanner;

//提出時にclass Main に書き換え
public class Main {
	public static void main(String[] args)  {
		// 標準入力を受け取る
		Scanner sc = new Scanner(System.in);
		String S = sc.nextLine(); // String Sを受け取る
		sc.close(); // 標準入力を終了

		// 操作で追加できる文字列
		String[] t = {"dream", "dreamer", "erase", "eraser"};
		String[] rt = new String[4];

		// Sを反転
		String rs = new StringBuffer(S).reverse().toString();

		// tを反転
		for(int i = 0; i < t.length; i++) {
			rt[i] = new StringBuffer(t[i]).reverse().toString();
		}


		boolean can = true; // 可能フラグ
	    boolean dis = false; // 発見フラグ

		while(rs.length() > 0 && can) {
			for(int i = 0; i < rt.length; i++) {
				// rsがrt中の文字列で始まるか調査
				if(rs.startsWith(rt[i])) {
					// 見つかった分の文字列を切り取る
					rs = rs.substring(rt[i].length());
					dis = true;
					break; // for処理中断
				}
			}
			// 発見フラグがtrueで無ければ、可能フラグをfalseに
			if(!dis) {
				can = false;
			} else {
				dis = false;
			}
		}

		// 可能フラグがtrueならYESを出力
		if(can) {
			System.out.println("YES");
		} else {
			System.out.println("NO");
		}

	}

}
