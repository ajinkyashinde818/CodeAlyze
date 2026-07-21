import java.util.*;
import java.lang.Math;

public class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int k = sc.nextInt();
    int s = sc.nextInt();
    int count = 0;
    int stack;
    
    int start = 0;
    if(s - 2*k > 0) start = s - 2*k;
    
    int end = k;
    if(s < k) end = s;
        
    for(int x = 0; x <= k; x++){
    	stack = s - x;
      	if(stack <= 2*k && stack >= 0){
      		if(stack <= k) count += stack + 1;
      		else count += k - (stack - k) + 1;
        }
    } 
   	
  	System.out.println(count);

  }
}
