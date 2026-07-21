import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception {
        
        Scanner scanner = new Scanner(System.in);
        
        long X = scanner.nextLong();
        long Y = scanner.nextLong();
        
        long x = X;
        long y = Y;
        long M = 0;
        
        if(X>Y){
            while(y != 0){
                M = x%y;
                x = y;
                y = M;
            }
            System.out.println(X*Y/x);
        }
        
        if(Y>X){
            while(x != 0){
                M = y%x;
                y = x;
                x = M;
            }
            System.out.println(X*Y/y);
        }
        
    }
}
