import java.util.*;
import java.lang.*;

public class Main{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        long n = sc.nextLong();
        if(n<10||n%2==1){
            System.out.println(0);
            return;
        }
        n /= 2;
        long result = 0;
        while(n>0){
            n /= 5;
            result += n;
        }
        System.out.println(result);
        sc.close();
    }
}
