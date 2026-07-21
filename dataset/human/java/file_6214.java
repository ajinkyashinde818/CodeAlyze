import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		// TODO 自動生成されたメソッド・スタブ
		Scanner sc = new Scanner(System.in);
		int K = sc.nextInt();
		int S = sc.nextInt();
		sc.close();
		System.out.println(three(K, S));

	}

	private static int one(int K, int S)
	{
		return 0 <= S && S <= K ? 1 : 0; 
	}
	
	private static int two(int K, int S)
	{
		int result = 0;
		for (int i = 0; i <= K; i++){
			result += one(K, S - i);
		}
		return result;
	}
	
	private static int three(int K, int S)
	{
		int result = 0;
		for (int i = 0; i <= K; i++){
			result += two(K, S - i);
		}
		return result;
	}
}
