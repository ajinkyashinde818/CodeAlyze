import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		// 整数の入力
		int n = sc.nextInt();
		boolean bl1 = false;
		boolean bl2 = false;
		boolean bl3 = false;

		for (int i = 0; i < n; i++) {
			int a = sc.nextInt();
			int b = sc.nextInt();

			//値が同じ場合
			if(a == b){
				//1度目のヒット
				if(!bl1){
					bl1 = true;
				}else{
					//2度目のヒット
					if(!bl2){
						bl2 = true;
					}else{
						//3度目のヒット
						bl3 = true;
					}
				}
			}else{
				//3度未達の場合
				if(!bl3){
					//違う場合全部リセット
					bl1 = false;
					bl2 = false;
					bl3 = false;
				}
			}
		}

		if(bl3){
			System.out.println("Yes");
		}else{
			System.out.println("No");
		}

		sc.close();
	}
}
