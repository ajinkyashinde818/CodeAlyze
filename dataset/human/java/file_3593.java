import java.util.Scanner;
import java.util.List;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
class Main{
  public static void main(String[] args){
    Scanner sc = new Scanner(System.in);
	String a = sc.next();
    String b = sc.next();
    String[] str = {"A","B","C","D","E","F"};
    int[] num = {10,11,12,13,14,15};
    int c = 0;
    int d = 0;
    for (int i =0; i<str.length;i++){
      if (a.equals(str[i])){
        c=num[i];
      }
      if (b.equals(str[i])){
        d=num[i];
      }
    }
    if (c==d){
      System.out.println("=");
    } else if (c>d) {
      System.out.println(">");
    } else {
      System.out.println("<");
    }
  }
}
