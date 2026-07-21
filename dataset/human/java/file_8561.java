import java.util.Scanner;
import java.util.Arrays;

public class Main {
        public static void main(String[] args) {
                Scanner scan = new Scanner(System.in);
                int input1 = scan.nextInt();
                int input2 = scan.nextInt();
                int input3 = scan.nextInt();
                int div[] = new int[100];
                Arrays.fill( div, 0 );
                int result1;
                int result2;
                int total = 0;
                int i=0;

                for (i=1; i<=input1; i++) {
                        result1 = input1 % i;
                        result2 = input2 % i;
                        if ( result1 == 0 && result2 == 0 ) {
                                total++;
                                div[total] = i;
                        }
                }

                System.out.println( div[total+1-input3] );
                scan.close();
        }
}
