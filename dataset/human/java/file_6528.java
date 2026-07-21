import java.util.*;

public class Main {
	  public static void main(String args[]){
      		Scanner scan = new Scanner(System.in);
            
            int K = scan.nextInt();
            int S = scan.nextInt();
            
            int x, y, z;
            int ans = 0;
            
            for( x = 0 ; x <= K ; x++ ){
            	for( y = 0 ; y <= K ; y++ ){
                	z = S - x - y;
                    if( z >= 0 && z <= K )ans++;
                }
            }
      
		    System.out.println(ans);
		  }
}
