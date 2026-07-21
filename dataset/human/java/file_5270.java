import java.util.Scanner;

public class Main {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		doIt();

	}
	public static void doIt(){
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		while(n != 0){
			int[][] field = new int[n][n];
			boolean bEnd = true;
			for(int i = 0; i < n; i++){
				String s = sc.next();
				for(int j = 0; j < n; j++){
					if(s.charAt(j) == '.'){
						field[i][j] = 1;
						bEnd = false;
					}
				}
			}
			if(bEnd){
				System.out.println(0);
				n = sc.nextInt();
				continue;
			}
			int max = 1;
			//端はやる必要なし
			for(int i = 1; i < n; i++){
				for(int j = 1; j < n; j++){
					if(field[i][j] == 1){
						int min = Math.min(field[i][j - 1], field[i - 1][j]);
						min = Math.min(min, field[i - 1][j - 1]);
						field[i][j] = min + 1;
						if(max < field[i][j]){
							max = field[i][j];
						}
					}
				}
			}
			
			System.out.println(max);
			n = sc.nextInt();
		}
	}
	
	public static void print(int[][] f){
		for(int[] a : f){
			for(int b : a){
				System.out.print(b + " ");
			}
			System.out.println();
		}
	}

}
