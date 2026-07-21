import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;
public class Main {
    public static void main(String[] args){
    
    Scanner sc = new Scanner(System.in);
    int a = sc.nextInt();
    int b = sc.nextInt();
    int k = sc.nextInt();
    ArrayList<Integer>ans  = new ArrayList<>();
    
    for(int i=1; i<=Math.max(a,b); i++) {
    	if(a%i==0 && b%i==0) {
    		ans.add(i);
    	}
    }
    Collections.sort(ans,Collections.reverseOrder());
	System.out.println(ans.get(k-1));
      }
}
