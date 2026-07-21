import java.util.*;
import java.lang.Math;

public class Main {
  
  
  public Main() {
  }
    
  public static void main(String[] args) {
    
    Scanner scan = new Scanner(System.in);
    
    int size = scan.nextInt();
    int[] num = new int[size];
	
    for(int i = 0; i < size; i++) {
      num[i] = scan.nextInt();
    }
    
    long sum = 0;
    boolean hasZero = false;
    boolean even = true;
    int smallest = Math.abs(num[0]);
    
    for(int i = 0; i < size; i++) {
      if(num[i] == 0) {
        hasZero = true;
      }
      
      if(num[i] < 0) {
        even = !even;
      }
      
      smallest = Math.min(Math.abs(num[i]), smallest);
      sum += Math.abs(num[i]);
    }
    
    if (!even && !hasZero)
      sum -= 2*smallest;
    
    System.out.println(sum);
    
  }
}
