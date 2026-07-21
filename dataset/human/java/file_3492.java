public class Main {
 public static void main(String[] args) {
    java.util.Scanner scanner = new java.util.Scanner(System.in);
    char x = scanner.next().charAt(0);
    char y = scanner.next().charAt(0);
    if (x > y) {
      System.out.println(">");
    } else if (x == y) {
      System.out.println("=");
    } else {
      System.out.println("<");
    }
 }
}
