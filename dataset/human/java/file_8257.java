import java.util.*;

class Main {
        private static long gcd(long m, long n) {
        if(m < n) return gcd(n, m);
        if(n == 0) return m;
        return gcd(n, m % n);
    }

    public static void main (String[] args){
        Scanner stdIn = new Scanner(System.in);
        long A = stdIn.nextInt();
        long B = stdIn.nextInt();

        long C=0;

        C = A*B / gcd(A,B);
        System.out.print(C);



    }
}
