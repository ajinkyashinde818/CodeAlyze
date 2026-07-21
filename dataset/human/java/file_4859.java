import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        long N = sc.nextLong();
        if(N % 2 == 1){
            System.out.println(0);
            return;
        }
        long top = N/2;
        long sum = 0;
        for(long i=1;i<=27;i++){
            long res = pow(5,i);
            sum += top/res;
        }
        System.out.println(sum);
    }

    private static long pow(long a, long b){
        if(b == 0){return 1;}
        return pow(a,b-1)*a;
    }
}
