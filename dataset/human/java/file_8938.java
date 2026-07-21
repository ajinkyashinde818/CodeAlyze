import java.util.Scanner;
public class Main{
 public static void main(String[] args){
   Scanner sc = new Scanner(System.in);
   int A = sc.nextInt();
   int B = sc.nextInt();
   int K = sc.nextInt();

   if(B>A)
   {
    int s =B;
    B = A;
    A = s;
   }
   
   int count =0;
   int ans=0;
   int cd = B;
   while(count<K)
   {
     if(A%cd==0 && B%cd ==0) 
     {
       count++;
       ans = cd;
     }
     cd--;
   }
   System.out.println(ans);
 }
}
