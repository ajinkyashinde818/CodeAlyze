import java.util.*;
public class Main {
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		
        int n = sc.nextInt();
      	n = 100 * (10 - n);
      	int k = sc.nextInt();
      	if(n > 0) k += n;
      
      	System.out.println(k);      	        
	}
}
