import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		// TODO 自動生成されたメソッド・スタブ
		Scanner sc = new Scanner(System.in);

		while(true){
			int n = sc.nextInt();

			if(n == 0){
				break;
			}

			char[][] input = new char[n][];
			for(int i = 0; i < n; i++){
				input[i] = sc.next().toCharArray();
			}

			for(int i = 0; i < n; i++){
				for(int j = input[i].length - 1; j >= 0; j--){
					if(input[i][j] == '.'){
						input[i][j] = '+';
						break;
					}
				}
			}

			//debug
//			for(int i = 0; i < n; i++){
//				System.out.println(input[i]);
//			}

			for(int i = n - 1; i >= 0; i--){
				for(int j = 0; j < input[i].length; j++){
					if(input[i][j] == '+'){
						for(int k = i - 1; k >= 0; k--){
							if(input[k][j] >= 'a' && input[k][j] <= 'z'){
								break;
							}
							if(input[k][j] == '+'){
								for(int l = k + 1; l < i; l++){
									input[l][j] = '|';
								}
								break;
							}
						}

						break;
					}
				}
			}

			for(int i = 0; i < n; i++){
				for(int j = 0; j < input[i].length; j++){
					if(input[i][j] == '.'){
						input[i][j] = ' ';
					}
				}
			}

			for(int i = 0; i < n; i++){
				System.out.println(input[i]);
			}
		}
	}

}
