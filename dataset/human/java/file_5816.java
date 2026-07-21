import java.util.Scanner;

public class Main {

  static Scanner sc = new Scanner(System.in);


  public static void main(String[] args) {
    String a = sc.next();
    if(a.contains("a")&&a.contains("b")&&a.contains("c")){
      System.out.println("Yes");
    }else{
      System.out.println("No");
    }
  }
}
