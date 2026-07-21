import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        long A = sc.nextLong();
        long B = sc.nextLong();
        System.out.println(A*B/LCM(A,B));

    }
    private static long LCM(long a, long b){
        if(a < b){
            long tmp = a;
            a = b;
            b = tmp;
        }
        if(a % b == 0){return b;}
        return LCM(b, a%b);
    }
}
