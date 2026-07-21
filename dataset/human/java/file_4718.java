import java.util.Scanner;

public class Main {
  public static void main(String[] args) {
    Scanner scan = new Scanner(System.in);
    String N = scan.next();
    N = "00" + N;
    scan.close();

    int total = 0;
    int kurikoshi = 0;
    for(int i=N.length()-1; i>=0; i--) {
      if(N.charAt(i) - '0' + kurikoshi < 5) {
        total += N.charAt(i) - '0' + kurikoshi;
        kurikoshi = 0;
      }
      else if(N.charAt(i) - '0' + kurikoshi == 5) {
        total += 5;
        if(N.charAt(i-1) - '0' >= 5) {
          kurikoshi = 1;
        }
        else {
          kurikoshi = 0;
        }
      }
      else {
        total += 10 - (N.charAt(i) - '0' + kurikoshi);
        kurikoshi = 1;
      }
    }
    System.out.println(total);
  }
}
