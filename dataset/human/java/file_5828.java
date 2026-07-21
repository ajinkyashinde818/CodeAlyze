import java.util.Scanner;

public class Main {

    public static void main(String[] args) {

        int A = 0;
        int B = 0;
        int C = 0;

      Scanner in = new Scanner(System.in);

      String str = in.nextLine();

      char[] c = str.toCharArray();

      for(int cnt=0; cnt <str.length(); cnt++) {
          if(c[cnt] == 'a') {
              A++;
          }
          else if(c[cnt] == 'b') {
              B++;
          }
          else if(c[cnt] == 'c') {
              C++;
          }
      }

      in.close();

      if(A==1 && B==1 && C==1) {
          System.out.println("Yes");
      } else {
          System.out.println("No");
      }
    }

}
