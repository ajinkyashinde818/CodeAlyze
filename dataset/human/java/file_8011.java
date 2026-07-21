import java.util.*;

class Main{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        long a = sc.nextLong();
        long b = sc.nextLong();
        long ans = lcm(a,b);
        System.out.println(ans);
    }

    public static long lcm(long a,long b){
        return a*b / gcd(a,b);
    }
    public static long gcd(long a,long b){
        if(a < b)return gcd(b,a);
        if(b == 0)return a;
        return gcd(b,a%b);
    }
}
