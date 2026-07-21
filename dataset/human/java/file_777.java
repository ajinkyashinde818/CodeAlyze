import java.util.*;
class Main{
  public static void main(String[] args){
    Scanner sc = new Scanner(System.in);
    int a = sc.nextInt();
    int b = sc.nextInt();
    int c = 0;
    if(a >= 10){
      System.out.println(b);
    } else {
     c = 100 * (10 - a);
      int d = b + c;
      System.out.println(d);
    }
    
 }
}
