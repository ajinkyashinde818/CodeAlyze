import java.util.*;
public class Main {
	public static void main(String[] atgs) {
		Scanner scan = new Scanner(System.in);
		int ans = 0;
		int K = scan.nextInt();
		int S = scan.nextInt();
		for(int x = 0; x <= K; x++){
			for(int y = 0; y <= K; y++){
				int z = S - x - y;
				if(0 <= z && z <= K){
					ans = ans + 1;
				}
			}
	    }
		System.out.println(ans);
		scan.close();
	}
}
