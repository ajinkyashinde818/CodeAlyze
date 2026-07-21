import java.util.Scanner;
import java.util.List;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
class Main{
  public static void main(String[] args){
    Scanner sc = new Scanner(System.in);
	String a = sc.next();
    if (a.substring(0,1).equals(a.substring(1,2)) || a.substring(0,1).equals(a.substring(2)) || a.substring(1,2).equals(a.substring(2))) {
      System.out.println("No");
    } else {
      System.out.println("Yes");
    }
  }
}
