import java.util.*;
public class Main{
 public static void main(String[] args){
   Scanner sc = new Scanner(System.in);
 
   int N = sc.nextInt();
   int K = sc.nextInt();
   int S = sc.nextInt();
   
   for(int i=0;i<K;i++)
   {
     System.out.print(S+ " ");
   }
   int pr = S-1;
   if(S==1) pr =2; 
   for(int i=K;i<N-1;i++)
   {
     System.out.print(pr + " ");
   }
   if(N!=K) System.out.println(pr);
   else System.out.println();
 }
}
