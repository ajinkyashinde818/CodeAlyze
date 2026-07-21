import java.util.*;
public class Main {
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		// 整数の入力
		int n = sc.nextInt();
		int k = sc.nextInt();
		int s = sc.nextInt();
        if (k > 0){
            System.out.print(s);
        }else{
            if (s < 1000000000){
                System.out.print(s+1);
            }else{
                System.out.print(s-1);
            }
        }
        for (int i=1; i<n; i++){
            if (i < k){
                System.out.print(" " + s);
            }else{
                if (s < 1000000000){
                System.out.print(" " + (s+1));
                }else{
                System.out.print(" " + (s-1));
                }
            }
        }
	}
}
