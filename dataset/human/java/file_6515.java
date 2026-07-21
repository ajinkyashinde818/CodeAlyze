import java.io.File;
import java.io.IOException;
import java.util.*;
 
public class Main {
 
	public static void main(String[] args) throws IOException {
		//File file = new File("input.txt");
		//Scanner sc = new Scanner(file);
		
		Scanner sc = new Scanner(System.in);
		
		int K = sc.nextInt();
		int S = sc.nextInt();
		int ans = 0;
		
		for(int x = 0; x <= K; x++){
			for(int y = 0; y <= K; y++){
				int z = S - x - y;
				if(z >= 0 && z <= K) ans++;
			}
		}
		
		System.out.println(ans);
	}
}
