import java.util.Scanner;
public class Main{
 public static void main(String[] args){
   Scanner sc = new Scanner(System.in);
   int max = sc.nextInt();
   int[] a = new int[max];
   int count = 0;
   for(int i=0;i<max;i++){
   int c = sc.nextInt();
     if(c<0){
     count++;
     c = -c;
     }
   a[i] = c;
   }
   long sum =0;
   if(count%2 == 1){
     int min = a[0];
     for(int i = 0;i<a.length;i++)
     {
       if(min > a[i]) min = a[i];
       sum += a[i];
     }
     sum = sum - 2*min;
   }else{
     for(int i =0;i<a.length;i++)
     {
       sum +=a[i]; 
     }
   }
    System.out.print(sum);
   
   
 }
}
