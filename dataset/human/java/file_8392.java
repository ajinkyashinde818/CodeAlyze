import java.io.*;
import java.util.*;
import static java.lang.System.in;

public class Main {
    public static void main(String[] args) throws Exception {
        Main main = new Main();
        System.out.println(main.solve());
    }
    long solve(){
        Scanner sc = new Scanner(System.in);
        long a = sc.nextLong(), b = sc.nextLong();
        return getLcm(a,b);
    }
    long gcd(long a, long b){
        if(a<b){
            long c = a;
            a = b; b = c;
        }
        while(a%b!=0){
            long c = a%b;
            a = b; b = c;
        }
        return b;
    }
    long getLcm(long a, long b){
        return a/gcd(a,b)*b;
    }
}
