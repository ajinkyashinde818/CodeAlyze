import java.util.*;

public class Main {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        System.out.println(lcm(sc.nextInt(),sc.nextInt()));
    }
    static long gcd(long x,long y){
        if (y==0)return x;
        else return gcd(y,x%y);
    }
    static long lcm(long x,long y){
        return x/gcd(x,y)*y;
    }
}
