import java.util.*;

class Main{
 public static void main(String args[]){
   Scanner scn = new Scanner(System.in);
   int a = scn.nextInt();
   int b = scn.nextInt();
   int max = 0;
   int min = 0;
   if(a<b){
     max = b;
     min = a;
   }else{
     max = a;
     min = b;
   }
   while(max%min!=0){
     int c = min;
     min = max%min;
     max = c;
   }
   long l = (long)(a/min) * (b/min) * min;
   System.out.println(l);
 }
}
