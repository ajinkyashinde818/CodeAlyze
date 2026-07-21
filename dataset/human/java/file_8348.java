import java.math.BigInteger;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int A  =sc.nextInt();
        int B = sc.nextInt();
        BigInteger big = new BigInteger(String.valueOf(A));
        big = big.multiply(new BigInteger(String.valueOf(B)));
        int r;
        while (A%B!=0){
            r = A%B;
            A=B;
            B = r;
        }


        big = big.divide(new BigInteger(String.valueOf(B)));
        System.out.println(big);


    }
}
