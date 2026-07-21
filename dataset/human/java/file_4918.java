import java.util.Scanner;
public class Main{
 public static void main(String[] args){
   Scanner sc = new Scanner(System.in);
   long A = sc.nextLong();
 
   long ans = 0;
   long tmp = A;
   long t10 = 10;
      for(int i = 1;i<100;i++)
   {
     if(A%2==1) break;
     tmp=A/t10;
     ans+= tmp;
     t10*=5;
 
     if(tmp == 0) break; 
   }
   
   
   System.out.println(ans);
  
 }
}
