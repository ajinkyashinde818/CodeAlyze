import java.util.*;
import java.math.*;

class Main{
public static void main(String args[]){
   Scanner sc = new Scanner(System.in);
   int k = sc.nextInt();
   int n = sc.nextInt();
   int array[] = new int[n+1];
   int ret = 0;
   int maxe = 0;
   for (int i=0;i<n;i++){    
    int temp = sc.nextInt();
    array[i] = temp;
   }
   array[n] = k+array[0];
   for (int i=0;i<n;i++){
     ret += array[i+1]-array[i];
     maxe = Math.max(maxe,array[i+1]-array[i]);
   }
   System.out.println(ret-maxe);
}
}
