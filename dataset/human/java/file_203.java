import java.util.*;
import java.math.BigDecimal;

public class Main {
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		// 1段目の宝石数
		int n = sc.nextInt();

      	int min = 0;
      	BigDecimal max = new BigDecimal(0);
      	boolean isFirst = true;
      	int minusNum = 0;
		// 2段目の数値
		for (int i=0; i < n; i++) {
          	int  num = sc.nextInt();
			if (num < 0) {
              minusNum++;
            }
          	int tmp = Math.abs(num);
          	if (isFirst || tmp<min) {
              min = tmp;
              isFirst = false;
            }
          	max = max.add(new BigDecimal(tmp)); 

        }
      	
      	if(minusNum % 2 != 0){
          max = max.add(new BigDecimal(min).multiply(new BigDecimal(-2)));
        }

		System.out.println(max.toString());      

 	}
 
}
