import java.util.*;
public class Main{
 public static void main(String[] args){
   Scanner sc = new Scanner(System.in);
 
   int N = sc.nextInt();
   long[] a =new long[N];
   long[] sumar = new long[N];
   
   long sum =0;
   for(int i=0;i<N;i++) 
   {
     a[i]=sc.nextLong();
     sum += a[i];
     sumar[i]= sum;
   }
   long ans =Math.abs(sum-2*sumar[0]);
   for(int i=1;i<N-1;i++)
   {
     if(Math.abs(sum-2*sumar[i])<ans) ans = Math.abs(sum-2*sumar[i]);
   }
   System.out.println(ans);
 }
}
