import java.util.*;
public class Main{
 public static void main(String[] args){
   Scanner sc = new Scanner(System.in);
 
   String a = sc.next();
    
   if(a.charAt(0)==a.charAt(1)||a.charAt(1)==a.charAt(2)||a.charAt(2)==a.charAt(0)) System.out.println("No");
   else System.out.println("Yes");
 }
}
