import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		int a = sc.nextInt();
		int b = sc.nextInt();
        int k = sc.nextInt();
      
        //AとBの小さい方を取得
        int min = Math.min(a, b);
        
        //公約数のリスト
		List<Integer> ary = new ArrayList<>();

        for(int i=1; i <= min; i++) {
        	if(a % i == 0 && b % i ==0) {
        		ary.add(i);
        	}
		}
                
        System.out.print(ary.get(ary.size()-k));
	}
}
