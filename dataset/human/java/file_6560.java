import java.util.*;
public class Main {
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
    
		// 整数の入力
		int k = sc.nextInt();
		int s = sc.nextInt();
        int ans = 0;
       
        aLoop: for(int a = 0; a <= k; a++) {
          bLoop: for(int b = 0; b <= k; b++) {
            int abSum = a + b;
            if (abSum > s) {
              continue aLoop;
            } else if (s - abSum <= k) {
              ans++;
            }
          }
        }
    
		// 出力
		System.out.println(ans);
	}
}
