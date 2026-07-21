import java.util.*;
public class Main{
public static void main(String[] args){
Scanner sc = new Scanner(System.in);
  String X = sc.next();
  String Y = sc.next();
  int a = Integer.parseInt(X,16);
  int b = Integer.parseInt(Y,16);
  if(a > b)System.out.println(">");
  else if(a == b)System.out.println("=");
  else System.out.println("<");
}
}
