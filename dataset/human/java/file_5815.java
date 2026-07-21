import java.util.*;
public class Main{
public static void main(String[] args){
Scanner sc = new Scanner(System.in);
  String s = sc.next();
  boolean a = false;
  boolean b = false;
  boolean c = false;
  for(int i = 0;i < 3;i++){
    if(s.charAt(i) == 'a')a = true;
  }
  for(int i = 0;i < 3;i++){
    if(s.charAt(i) == 'b')b = true;
  }
  for(int i = 0;i < 3;i++){
    if(s.charAt(i) == 'c')c = true;
  }
  System.out.println(a && b && c ? "Yes":"No");
}}
