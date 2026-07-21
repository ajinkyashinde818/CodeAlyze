import java.util.*;
import java.text.DecimalFormat;

public class Main {
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
        int a = sc.nextInt();
        int b = sc.nextInt();
 
        int max = 1;
        for (int i = 2; i <= a; i++) {
            if (a % i == 0 && b % i == 0) {
                max = i;
            }
        }
		DecimalFormat decimalFormat = new DecimalFormat("###");
      	Double result=new Double(a)*new Double(b);
        System.out.println(decimalFormat.format(result/max));
	}
}
