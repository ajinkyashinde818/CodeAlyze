import java.util.Scanner;

public class Main {
    public static void debug(String str) {
        System.out.println(str);
    }

    public static void main(String[] args) {

        int A;
        int B;

        try (Scanner sc = new Scanner(System.in)) {
            A = sc.nextInt();
            B = sc.nextInt();

        }
       
       
        System.out.println(lcm(A,B));
        

    }
    
    //最小公倍数
    static long lcm(long a, long b) {
        long temp;
        long c = a;
        c *= b;
        while ((temp = a % b) != 0) {
            a = b;
            b = temp;
        }
        return (long) (c / b);
    }


}
