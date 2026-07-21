import java.util.*;

public class Main{
      public static void main(String[] args) {
            Scanner sc = new Scanner(System.in);
            String x = sc.next();
            String y = sc.next();
            //compareToで比較xとyを比較してxが大きいと1が小さいと-1が返ってくる
            if(x.compareTo(y) > 0){
              System.out.println(">");
            } else if(x.compareTo(y) == 0){
              System.out.println("=");
            } else {
              System.out.println("<");
            }
          }
}
