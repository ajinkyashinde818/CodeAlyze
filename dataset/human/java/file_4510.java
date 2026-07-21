import java.util.*;
import java.lang.*;
import java.math.*;

public class Main {
    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        
        int a = sc.nextInt(); // bad
        int b = sc.nextInt(); //good
        int c = sc.nextInt(); //good
        if (a + b >= c) {
            System.out.println(b + c); // all ok
        } else {
            System.out.println(b + (b + a) + 1);
        }


        sc.close();
    }
}
