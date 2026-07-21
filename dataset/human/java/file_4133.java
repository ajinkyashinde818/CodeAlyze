import java.util.Scanner;
import java.util.*;

public class Main {
        public static void main(String[] args) {
                Scanner scan = new Scanner(System.in);
                int h = scan.nextInt();

                int[] a = new int[h];
                int[] b = new int[h];
                int[] c = new int[h-1];

                for(int i = 0; i < h; i++){
                  a[i] = scan.nextInt();

                  
                // System.out.println(a[i]);
                }

                for(int i = 0; i < h; i++){
                  b[i] = scan.nextInt();
                }

                for(int i = 0; i < h - 1; i++){
                  c[i] = scan.nextInt();
                }

                int sum = 0;
               
               sum = b[a[0] - 1]; 
                for(int i = 1; i < h; i++){
                  sum += b[a[i] - 1];
                  if(a[i - 1] + 1 == a[i]){
                    sum += c[a[i - 1] - 1];
                  }
                }

                System.out.println(sum);
    }
}
