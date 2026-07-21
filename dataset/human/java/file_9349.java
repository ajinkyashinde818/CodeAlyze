import java.util.*;
import java.math.RoundingMode;
import java.math.BigDecimal;
 
 
public class Main{
	public static void main (String[] args){
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int[][] d = new int[n][2];
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < 2; j++) {
				d[i][j] = sc.nextInt();
			}
		}
		int num = 0;
		boolean cont = false;
		for(int i = 0; i < n; i++) {
			if(d[i][0]==d[i][1]) {
				cont = true;
				num++;
			}
			else{
				cont = false;
				num=0;
			}
			if(num>=3) break;
		}
		if(num<3)cont=false;
		System.out.println(cont? "Yes":"No");
	}
}
