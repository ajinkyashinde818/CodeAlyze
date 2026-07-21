import java.util.*;
public class Main {
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
    
		// 文字列の入力
		String x = sc.next();
        String y = sc.next();
        int xValue = Integer.parseInt(x, 16);
        int yValue = Integer.parseInt(y, 16);
        String ans = "";
        if (x.equals(y)) {
          ans = "=";
        } else if (xValue > yValue) {
          ans = ">";
        } else {
          ans = "<";
        }
    
		// 出力
		System.out.println(ans);
	}
}
