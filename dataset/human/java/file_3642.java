import java.util.*;
import java.lang.*;
public class Main {
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);

		String x = sc.next();
		String y = sc.next();

                String ret = null;
                try {
                    int convertedX = Integer.parseInt(x, 16);
                    int convertedY = Integer.parseInt(y, 16);
                    if (convertedX > convertedY) {
                        ret = ">";
                    } else if(convertedX < convertedY) {
                        ret = "<";
                    } else if(convertedX == convertedY) {
                        ret = "=";
                    } else {
                        ret = "error!";
                    }
                } catch (NumberFormatException e) {
                    ret = "NumberFormatException";
                }
               
		// 出力
		System.out.println(ret);
	}
}
