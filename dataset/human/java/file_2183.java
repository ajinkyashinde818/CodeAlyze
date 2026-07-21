import java.util.Scanner;

public class Main {
        public static void main(String[] args) {
                Scanner scan = new Scanner(System.in);

                long N = scan.nextLong();
                long rootN = (long)Math.sqrt(N);
                int count = 0;
                int pcount;
                int ncount;
                
                for (long i = 2; i < rootN; i++) {
                	
                	pcount = 0;
                	
                	while (N%i == 0) {
                		pcount++;
                		N /= i;
                	}
                	
                	ncount = 1;
                	
                	while (pcount - ncount >= 0) {
                		pcount -= ncount;
                		count++;
                		ncount++;
                	}
                	
                }
                
                if (N != 1) {
                	count++;
                }
                
                System.out.println(count);
                
        }
}
