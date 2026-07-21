import java.util.Scanner;

public class Main {

	// 末尾に追加可能な文字列を反転した文字列
	private static final String REVERSE_DREAM = new StringBuilder("dream").reverse().toString();
	private static final String REVERSE_DREAMER = new StringBuilder("dreamer").reverse().toString();
	private static final String REVERSE_ERASE = new StringBuilder("erase").reverse().toString();
	private static final String REVERSE_ERASER = new StringBuilder("eraser").reverse().toString();

	public static void main(String[] args) {

		// 処理対象文字列の入力
		Scanner sc = new Scanner(System.in);

		// 最後尾から追加可能な文字列を検索するため、処理対象の文字列を反転させる
		StringBuilder targetString = new StringBuilder(sc.next()).reverse();
		sc.close();

		int bak = 0;
		// 処理対象の文字列の最後尾から、追加可能である文字列を可能な限り削除する処理を繰り返す
		// ※効率化のため文字列は反転して処理
		while(bak != targetString.length()) {
			bak = targetString.length();
			targetString = checkTopString(targetString);
		}

		// 出力
		if(targetString.length() == 0) {
			System.out.println("YES");
		}else{
			System.out.println("NO");
		}

	}

	// 処理対象の文字列の最後尾に追加可能な文字列があるなら削除する関数(効率化のため処理は反転して行う)
	static StringBuilder checkTopString(StringBuilder targetString){
		if(targetString.indexOf(REVERSE_DREAM) == 0){
			return targetString.delete(0,REVERSE_DREAM.length());
		}

		if(targetString.indexOf(REVERSE_DREAMER) == 0){
			return targetString.delete(0,REVERSE_DREAMER.length());
		}

		if(targetString.indexOf(REVERSE_ERASE) == 0){
			return targetString.delete(0,REVERSE_ERASE.length());
		}

		if(targetString.indexOf(REVERSE_ERASER) == 0){
			return targetString.delete(0,REVERSE_ERASER.length());
		}

		return targetString;

	}

}
