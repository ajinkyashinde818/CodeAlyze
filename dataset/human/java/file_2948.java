import java.util.PriorityQueue;
import java.util.Queue;
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
	    int N = sc.nextInt();
	    int M = sc.nextInt();
	    
	    Queue <Integer> A = new PriorityQueue <Integer>();
	    
	    for (int i=0; i<M; i++){
	    	int ai=sc.nextInt();
	    	int bi=sc.nextInt();
	    	
	    	if (ai==1){
	    		A.add(bi);
	    	}
	    	else if (bi==N){
	    		A.add(ai);
	    	}	
	    }
	    sc.close();
	    
	    
	    int size = A.size();
	    boolean ans = false;
	  
	    if (size>1) {
	    	
	    	for (int i=0; i<size-1; i++){
	    		int temp=A.poll();
	    		if (temp==A.peek()){
	    			ans = true;
	    			break;
	    		}
	    	}
	    }
	    if (ans==false)
	    	System.out.println("IMPOSSIBLE");
	    
	    else if  (ans==true)
	    	System.out.println("POSSIBLE");
	    	
	}

}
