import java.util.Scanner;
import java.util.Arrays;

public class Main{
  public static void main(String args[]){
    Scanner sc = new Scanner(System.in);
    int a = sc.nextInt();
    int b = sc.nextInt();
    int[] ax = new int[a];
    int[] bx = new int[b];
    int ay = 0;
    int by = 0;
    int az = a;
    int bz = b;
    for(int i = 2;i <=a;i++){
      if(az % i == 0){
   //     System.out.println(i);
 //       System.out.println(a);        
        az = az / i;
        ax[ay] = i;
        i--;
        ay++;
      }
    }
    for(int j = 2;j <= b;j++){
      if(bz % j == 0){
    //    System.out.println(bz);
  //      System.out.println(j);        
        bz = bz / j;
        bx[by] = j;
        j--;
        by++;
      }      
    }
// System.out.println(Arrays.toString(ax));
//  System.out.println(Arrays.toString(bx));    
    for(int c = 0;c < ay;c++){
      for(int d = 0;d < by;d++){
        if(ax[c] == bx[d] && bx[d] != 1){
          bx[d] = 1;
          break;
        }
      }
    }
    long ans = 1;
    for(int e = 0;e < ay;e++){
      ans *= ax[e];
    }
    for(int f = 0;f < by;f++){
      ans *= bx[f];      
    }
    System.out.println(ans);
   // System.out.println(Arrays.toString(ax));
 //   System.out.println(Arrays.toString(bx)); 
//    System.out.println(by);
  }
}
