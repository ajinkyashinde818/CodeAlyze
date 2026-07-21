import java.util.Scanner;

public class Main {

	public static void main(String[] args){

		final String DREAM		= "dream";
		final String DREAMER	= "dreamer";
		final String ERASE		= "erase";
		final String ERASER		= "eraser";

		// TODO ABC_049_C
		Scanner sc = new Scanner(System.in);
		// 文字列の入力
		String S = sc.nextLine();
		// Scannerクラスのインスタンスをクローズ
		sc.close();

//		String T = "";
		String res = "YES";

		while(S.length() > 0) {

//			switch(S) {
//				case DREAM:
//					break;
//				case DREAMER:
//					break;
//				case ERASE:
//					break;
//				case ERASER:
//					break;
//			}
			if(S.length() < 5) {
				res = "NO";
				break;
			}
			if(DREAM.equals(S)) {
				break;
			} else if(DREAMER.equals(S)) {
				break;
			} else if(ERASE.equals(S)) {
				break;
			} else if(ERASER.equals(S)) {
				break;
			}

			if(S.substring(0,1).equals("d")) {
				if(S.substring(0,5).equals("dream")) {
					if(S.substring(5,7).equals("er")) {
						if(S.substring(7,8).equals("a")) {
							// dreamerase
							S = S.substring(5);
							continue;
						} else {
							// deramer
							S = S.substring(7);
							continue;
						}
					} else {
						// dream
						S = S.substring(5);
						continue;
					}
				} else {
					res = "NO";
					break;
				}
			}
			else if(S.substring(0,1).equals("e")) {
				if(S.substring(0,5).equals("erase")) {
					if(S.substring(5,6).equals("r")) {
						// eraser
						// deramer
						S = S.substring(6);
						continue;
					} else {
						// erase
						S = S.substring(5);
						continue;
					}
				} else {
					res = "NO";
					break;
				}
			}
			else {
				res = "NO";
				break;
			}

		}

		System.out.println(res);
	}
}
