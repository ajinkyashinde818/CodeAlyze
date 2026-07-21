import java.util.*;
public class Main{
 public static void main(String[] args){
   Scanner sc = new Scanner(System.in);
   int s1 = sc.nextInt();

   if(s1/10==9||s1%10==9)System.out.println("Yes");
   else System.out.println("No");
 }
}
