import java.util.*;

public class Main{
  public static void main(String[] args){
    Scanner sc = new Scanner(System.in);
    int n = sc.nextInt();
    int[] array1 = new int[n];
    int[] array2 = new int[n];
    int[] array3 = new int[n-1];
    int satis = 0;
    int pp=0;

    for(int i=0; i<n; i++){
      array1[i] = sc.nextInt();
    }
    for(int i=0; i<n; i++){
      array2[i] = sc.nextInt();
    }
    for(int i=0; i<n-1; i++){
      array3[i] = sc.nextInt();
    }

    for(int i=0; i<n; i++){
      int num = array1[i];
      satis += array2[num-1];
      if(i>0){
        if(array1[i]-array1[i-1]==1){
        pp = array1[i-1];
        satis += array3[pp-1];
        //System.out.println("PASS");
        }
      }
      //System.out.println(satis);
    }
    System.out.println(satis);
  }
}
