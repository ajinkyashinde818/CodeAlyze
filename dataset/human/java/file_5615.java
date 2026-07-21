import java.util.*;
 
public class Main {
	
    public static void main(String[] args) {
    	Scanner sc = new Scanner(System.in);
    	int n = Integer.parseInt(sc.next());
    	int k = Integer.parseInt(sc.next());
    	long s = Long.parseLong(sc.next());
    	if(s < 1000000000) {
        	for(int i=0; i<k; i++) {
        	    System.out.print(s+" ");
        	}
        	for(int i=k; i<n; i++) {
        	    if(i < n-1) System.out.print(s+1+" ");
        	    else System.out.println(s+1);
        	}
    	}else {
    	    for(int i=0; i<k; i++) {
        	    System.out.print(s+" ");
        	}
        	for(int i=k; i<n; i++) {
        	    if(i < n-1) System.out.print(1+" ");
        	    else System.out.println(1);
        	}
    	}
    }
}
