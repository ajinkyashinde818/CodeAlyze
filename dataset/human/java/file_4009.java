import java.util.*;
public class Main{
  public static void main(String[]args){
      Scanner sc = new Scanner(System.in);

      int n = sc.nextInt();
      int[] adata = new int[n];
      int[] bdata = new int[n];
      int[] cdata = new int[n-1];
      int sum = 0;

      for (int i =0 ;i<n ;i++ ) {
        adata[i] = sc.nextInt();
      }
      for (int i =0 ;i<n ;i++ ) {
        bdata[i] = sc.nextInt();
      }
      for (int i =0 ;i<n-1 ;i++ ) {
        cdata[i] = sc.nextInt();
      }

      for (int i =0 ;i<n ;i++ ) {
        sum = sum + bdata[i];
      }


        for (int i =0 ;i<n-1 ;i++ ) {
          if (adata[i]+1==adata[i+1]) {
            sum += cdata[adata[i]-1];
          }
          }



      System.out.println(sum);
}
}
