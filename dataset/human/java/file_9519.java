import java.util.Scanner;

public class Main {

  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int cnt = 0;
    int n = sc.nextInt();
    for(int i = 0; i < n; i++){
      int d1 = sc.nextInt();
      int d2 = sc.nextInt();
      if(d1 == d2) {
        cnt++;
      } else {
        cnt = 0;
      }
      if(cnt >= 3){
        System.out.println("Yes");
        return;
      }
    }
    sc.close();
    System.out.println("No");
  }
}
