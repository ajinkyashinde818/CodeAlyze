import java.util.*;
public class Main{
  public static void main(String[]args){
      Scanner sc = new Scanner(System.in);


      String a1 = sc.next();
      String b1 = sc.next();

      char a =a1.charAt(0);
      char b =b1.charAt(0);

      if((int)a<(int)b){
        System.out.println("<");
      }
      if((int)a>(int)b){
        System.out.println(">");
      }
      if((int)a==(int)b){
        System.out.println("=");
      }

  }
}
