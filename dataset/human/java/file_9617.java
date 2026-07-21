import java.util.Scanner;

public class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int num = sc.nextInt();

    int cnt = 0;
    boolean judge = false;

    for (int i = 0; i < num ;i++) {
      int a1 = sc.nextInt();
      int a2 = sc.nextInt();
      if (a1 == a2) {
        cnt++; 
      } else {
        cnt = 0;
      }
      if(cnt == 3){
        judge = true;
      }

    }
    if(judge){
      System.out.println("Yes");
    } else {
      System.out.println("No");
    }
    sc.close();


  }
}
