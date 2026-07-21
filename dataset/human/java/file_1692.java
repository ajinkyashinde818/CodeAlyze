import java.util.Scanner;

public class Main{

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);

		int n = sc.nextInt();
		char[] str = sc.next().toCharArray();

		int alpha[][] = new int[n][26];

		for(int i = n - 2; i >= 0; i--){
			for(int j = 0; j < 26; j++){
				alpha[i][j] = alpha[i + 1][j];
			}

			alpha[i][str[i + 1] - 'a']++;
		}

		//debug
//		for(int i = 0; i < 26; i++){
//			for(int j = 0; j < n; j++){
//				System.out.print(alpha[j][i]+" ");
//			}
//			System.out.println();
//		}

		long result = 0;
		int mod = 1_000_000_007;
		for(int i = 0; i < n; i++){
			long tmp = 1;

			for(int j = 0; j < 26; j++){
				if(alpha[i][j] == 0 || j == str[i] - 'a'){
					continue;
				}

				tmp *= (alpha[i][j] + 1);
				tmp %= mod;
			}

			result += tmp;
			result %= mod;
		}

		System.out.println(result);
	}
}
