import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {
 
	public static void main(String[] args) {
 
		// 読み込み
		Scanner sc = new Scanner(System.in);
		int K = sc.nextInt();
        int N = sc.nextInt();
      
        List<Integer> A = new ArrayList<>();
        for(int i =0; i < N; i++)
          A.add(sc.nextInt());
       
        int maxD = 0;
        
        for(int i =0; i < N; i++) {
        	int dist = 0;
        	if (i == N-1)
        		dist = K - A.get(i) + A.get(0);
        	else {
        		dist = Math.abs(A.get(i) - A.get(i + 1));
        	}
        	
        	if(dist > maxD) {
        		maxD = dist;
        	}
        	        		
        }
        
         System.out.println(K - maxD);
	}
}
