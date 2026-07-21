import java.util.*;
public class Main{
  public static void main (String args[]){
    Scanner sc = new Scanner(System.in);

    int k = sc.nextInt();
    int n = sc.nextInt();
    int ans = 0;
    
    int[] array = new int[n];
    
    for(int i = 0; i < n; i++){
      array[i] = sc.nextInt();
    }
    
    Arrays.sort(array);
    
    int[] gapArray = new int[n];
    
    for(int i = 0; i < n-1; i++){
      int a = i;
      int b = a+1;
      
      gapArray[i] = array[b]-array[a];
    }
    
    gapArray[n-1] = array[0] + k-array[n-1];
    
    Arrays.sort(gapArray);
    
    for(int i = 0; i < n-1; i++){
      ans += gapArray[i];
    }
    
    System.out.println(ans);
  }
}
