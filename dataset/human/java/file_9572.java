import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;

public class Main {

      public static void main(String[] args) {

            Scanner sc = new Scanner(System.in);
            int n = sc.nextInt();
            boolean[] isZorome = new boolean[n];
            for (int i = 0;i<n;i++){
                  int d_1 = sc.nextInt();
                  int d_2 = sc.nextInt();
                  isZorome[i] = (d_1 == d_2);
            }
            String ans = "No";
            for (int i = 0;i<n-2;i++){
                  boolean sanren = isZorome[i] && isZorome[i+1] && isZorome[i+2];
                  if (sanren){
                        ans = "Yes";
                  }
            }
            System.out.println(ans);
      }



}
