import java.util.Scanner;

class Main{

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);			//文字の入力
		int A = sc.nextInt();
		int B = sc.nextInt();
		int C = sc.nextInt();
		
		int count = 0;
		int small = Math.min(A, B);
		for(int i = small;i >= 1;i--){
			if(A%i == 0 && B%i == 0){
			count++;
				if(count == C){
					System.out.println(i);
					return;
				}
			}
		}

		
	}
	
	
}
