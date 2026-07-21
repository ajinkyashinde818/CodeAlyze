import java.util.*;
import java.lang.*;


public class Main {
    static int pow(int a, int b){
        int ans = 1;
        for(int i=0; i<b; i++) ans *= a;
        return ans;
    }
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);

        int X = sc.nextInt(16);
        int Y = sc.nextInt(16);

        if(X<Y) System.out.println("<");
        if(X==Y) System.out.println("=");
        if(X>Y) System.out.println(">");


    }
}
