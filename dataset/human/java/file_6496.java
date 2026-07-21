import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main {

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String line = "";
		int strN = 1; // 文字列を何行受け取るか
		for (int i = 0; i < strN; i++) {
			line += br.readLine() + " ";
		}
		String[] param = line.split(" ");
		AtoZString(param);

	}

	static void AtoZString(String[] param) { //2行、Iで1追加し、Dで1減らす、処理後の最大値を出力[1]
		int K = Integer.parseInt(param[0]);
		int S = Integer.parseInt(param[1]);
		
		int count = 0;
		
		for(int i = 0; i <= K; i++){
			for(int j = 0; j <= K; j++){
				int k = S - (i + j);
				if(k >= 0 && k <= K) count++;
			}
		}
		System.out.println(count);
	}
}
