import java.util.Scanner;
public class Main{
 public static void main(String[] args) {
   Scanner kbd = new Scanner(System.in);
   int k=kbd.nextInt();
   int n=kbd.nextInt();
   int[] s = new int[n];
   for(int i=0;i<n;i++){
     s[i]=kbd.nextInt();
}
   int a=0;
   a=k-s[n-1]+s[0];
   for(int i=n-1;i>1;i--){
   int b=s[i]-s[i-1];
          if(s[i]-s[i-1]>a){
       a=s[i]-s[i-1];
     }
   }

   System.out.println(k-a);
}
}
