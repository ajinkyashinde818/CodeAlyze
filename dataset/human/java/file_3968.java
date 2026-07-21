import java.util.ArrayList;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
    	
		Scanner sc = new Scanner(System.in);
		// 整数の入力
		int N = sc.nextInt();
//		int A = sc.nextInt();
//		int B = sc.nextInt();
//		int C = sc.nextInt();
		
		ArrayList<Integer> list_a = new ArrayList<Integer>();//モンスター
		ArrayList<Integer> list_b = new ArrayList<Integer>();//討伐数
		ArrayList<Integer> list_c = new ArrayList<Integer>();//討伐数


		int ans = 0;

		for(int i = 0 ;i < N;i++){
			list_a.add(sc.nextInt());
		}

		for(int i = 0 ;i < N;i++){
			int w = sc.nextInt();
			list_b.add(w);
			ans = ans + w;
		}

		for(int i = 0 ;i < N-1;i++){
			list_c.add(sc.nextInt());
		}

		for(int i = 0;i < N-1;i++) {
			if(list_a.get(i+1) - list_a.get(i) == 1) {
				ans = ans + list_c.get(list_a.get(i)-1);
			}
		}
	
		System.out.println(ans);

   		sc.close();
        return ;

    }
    
}
