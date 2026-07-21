import java.util.*;
class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int a = Integer.parseInt(sc.next(), 16);
	int b = Integer.parseInt(sc.next(), 16);
    String ret = "=";
	if (a > b) {
      ret = ">";
    } else if (a < b) {
      ret = "<";
    }
    System.out.println(ret);
  }
}
