import java.util.*;
public class Main{
public static void main(String[] args){
Scanner sc = new Scanner(System.in);
  String s = sc.next();
  String t = sc.next();
  char[] c1 = s.toCharArray();
  char[] c2 = t.toCharArray();
  Arrays.sort(c1);
  Arrays.sort(c2);
  c2[0] = c2[c2.length - 1];
  String S = String.valueOf(c1);
  String T = String.valueOf(c2);
  if(S.compareTo(T) < 0)System.out.println("Yes");
  else System.out.println("No");
}}
