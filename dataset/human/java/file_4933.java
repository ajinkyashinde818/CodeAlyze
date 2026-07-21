import java.util.*;
import java.io.*;
 
public class Main {
    public static void main (final String[] args) {
        final Scanner sc = new Scanner(System.in);
        long n = sc.nextLong();
      	long result = 0;
      	boolean flag = true;
      	long temp = 10;
      	if(n%2 == 1 || n < 10) System.out.println(0);
      	else {
          while(n/temp > 0) {
            result += n / temp;
            if(flag) temp *= 5;
            else temp *= 2;
          }
          System.out.println(result);
        }
    }
}
