import java.util.*;
public class Main{
 public static void main(String[] args){
   Scanner sc = new Scanner(System.in);
 
   String A = sc.next();
   String B = sc.next();
   
   int a = hexToNum(A);
   int b = hexToNum(B);
 
   if(a<b) System.out.println("<");   
   else if(a==b)System.out.println("=");
   else System.out.println(">");
 }
  static int hexToNum(String s)
  {
    if(s.equals("A")) return 10;
    else if(s.equals("B")) return 11;
    else if(s.equals("C")) return 12;
    else if(s.equals("D")) return 13;
    else if(s.equals("E")) return 14;
    else return 15;
  }
}
