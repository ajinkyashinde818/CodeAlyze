import java.util.*;

class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int n = Integer.parseInt(sc.next());
    int k = Integer.parseInt(sc.next());
    int s = Integer.parseInt(sc.next());
    int[] a = new int[n];
    int p = 0;

    if(n==k){
      for(int i=0; i<n; i++){
        System.out.print(s);
        System.out.print(" ");
      }
      System.out.print("\n");
      return;
    } else {
      if(s==1){
        for(int i=0; i<n; i++){
          if(i<k){
            System.out.print(1);
            System.out.print(" ");
          } else {
            System.out.print(9);
            System.out.print(" ");
          }
        }
      } else {
        for(int i=0; i<n; i++){
          if(i<=k){
            if(i%2 == 1){
              System.out.print(1);
              System.out.print(" ");
            } else {
              System.out.print(s-1);
              System.out.print(" ");
            }
          } else {
            System.out.print(888888888);
            System.out.print(" ");
          }
        }
      }
      System.out.print("\n");
      return;
    }

  }
}
