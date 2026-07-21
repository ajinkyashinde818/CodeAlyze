import java.util.Objects;
import java.util.Scanner;

public class Main{
public static void main(String[] args){

  		Scanner scanner = null;
		try {
			scanner = new Scanner(System.in);
			 
			int ACookieNum = scanner.nextInt();
			int BCookieNum = scanner.nextInt();
			int CCookieNum = scanner.nextInt();
			 
			int poisonRecovery = ACookieNum + BCookieNum;
			 
			if (poisonRecovery >= CCookieNum){
			  System.out.println( BCookieNum + CCookieNum) ;
			} else {
                int canEatNum = ACookieNum + 1;
				if (canEatNum == CCookieNum) {
                  System.out.println(CCookieNum); 
                } else{
                  int remnantNum = CCookieNum - canEatNum;
                  
                  if (remnantNum >= BCookieNum){
                    System.out.println(canEatNum + (BCookieNum * 2));
                  }  else {
                    System.out.println(canEatNum + remnantNum + BCookieNum -1); 
                  }  
                }
			}
			} finally {
				if (!Objects.isNull(scanner)) {
					scanner.close();
				}
			}
		}
}
