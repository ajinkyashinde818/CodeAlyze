import java.util.*;
import java.math.BigDecimal;
public class Main {
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		// 整数の入力
		String x[] = sc.next().split("");
        String y[] = sc.next().split("");
        
        Arrays.sort(x);
        Arrays.sort(y, Collections.reverseOrder());
        String xx = String.join("", x);
        String yy = String.join("", y);
      
        if(xx.compareTo(yy) < 0){
          System.out.println("Yes");
        }else{
          System.out.println("No");
        }
        
        
        
    }
}
