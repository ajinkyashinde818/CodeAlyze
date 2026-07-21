import java.util.*;

class Main {

    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        long A = sc.nextInt();
        long B = sc.nextInt();
        //ここまで入力

        long ans = lcm(A,B);

        System.out.println(ans);
    }
        //AとBの最小公倍数を求める
    static long lcm (long a, long b) {
        long temp;
        long c = a;
        c *= b;
        while((temp = a%b)!=0) {
            a = b;
            b = temp;
        }
        return (long)(c/b);
    }
}
