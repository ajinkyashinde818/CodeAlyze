import java.util.*;
public class Main {
public static void main(String args[]) {
Scanner sc = new Scanner(System.in);
  String s = sc.next();
  s = s.replace("eraser","*");
  s = s.replace("erase","*");
  s = s.replace("dreamer","*");
  s = s.replace("dream","*");
  s = s.replace("*","");
  System.out.println(s.equals("") ? "YES":"NO");
}}
