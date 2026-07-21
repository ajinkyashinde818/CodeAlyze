import java.util.*;

public class Main {
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		int A = sc.nextInt(); // 解毒剤入りの美味しくないクッキー
		int B = sc.nextInt(); // 解毒剤入りの美味しいクッキー
		int C = sc.nextInt(); // 毒入りの美味しいクッキー
		/*
		    なるべくCをたくさん食べたい。
		    ただし、Cを食べられる枚数は、A+B+1枚まで
		*/
		int eatableC = Math.min(A+B+1, C);
		
		int count = B + eatableC;
        
        System.out.println(count);
	}
}
