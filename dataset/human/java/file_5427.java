import java.util.Scanner;

class Main {
  public static void main(String[] args) {
    Scanner s = new Scanner(System.in);
    int x = s.nextInt();
    if (x < 1200) {
      System.out.println("ABC");
    } else {
      System.out.println("ARC");
    }
  }
}
