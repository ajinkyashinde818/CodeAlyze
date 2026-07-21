import java.io.File;
import java.io.IOException;
import java.util.*;
 
public class Main {
 
	public static void main(String[] args) throws IOException {
		//File file = new File("input.txt");
		//Scanner in = new Scanner(file);
		
		Scanner in = new Scanner(System.in);
		
		int n = in.nextInt();
		int m = in.nextInt();
      
		int[][] ab = new int[m][2];
        boolean[] tf = new boolean[n+1];
		
		for(int i = 0; i < m; i++) {
			ab[i][0] = in.nextInt();
            ab[i][1] = in.nextInt();
          if(ab[i][0] == 1) tf[ab[i][1]] = true;
		}
      
        for(int i = 0; i < m; i++) {
			if(tf[ab[i][0]] && ab[i][1] == n){
              System.out.println("POSSIBLE");
              return;
            }
		}
        
		System.out.println("IMPOSSIBLE");
	}
}
