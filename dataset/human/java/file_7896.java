import java.io.IOException;
import java.util.HashMap;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.List;
import java.util.Map;
import java.util.Scanner;
 
 
public class Main{
	
	public static class Exec{
		int pos, val;

		public Exec(int pos, int val) {
			super();
			this.pos = pos;
			this.val = val;
		}
	}
	
    public static void main(String[] args) throws IOException {
    	Scanner sc = new Scanner(System.in);
    	
    	final int n = sc.nextInt();
    	
    	Map<String, Integer> map = new HashMap<String, Integer>();
    	
    	int[] next = new int[n];
    	for(int i = 0; i < n; i++){
    		next[i] = i + 1;
    	}
    	
    	String[][] input = new String[n][2];
    	
    	for(int i = 0; i < n; i++){
    		String ops = sc.next();
    		
    		input[i][0] = ops;
    		
    		if("goto".equals(ops)){
    			String jump = sc.next();
    			input[i][1] = jump.substring(0, jump.length() - 1);
    		}else{
    			map.put(ops.substring(0, ops.length() - 1), i);
    		}
    	}
    	
    	for(int i = 0; i < n; i++){
    		if("goto".equals(input[i][0])){
    			//System.out.println(input[i][1]);
    			next[i] = map.get(input[i][1]);
    		}
    	}
    	
    	boolean[][] visited = new boolean[n][n];
    	LinkedList<Exec> queue = new LinkedList<Exec>();
    	queue.add(new Exec(0, 0));
    	
    	while(!queue.isEmpty()){
    		Exec e = queue.poll();
    		
    		//System.out.println(e.pos + " " + e.val);
    		
    		if(e.pos == n){
    			System.out.println(e.val);
    			return;
    		}
    		
    		if(visited[e.pos][e.val]){
    			continue;
    		}else{
    			visited[e.pos][e.val] = true;
    		}
    		
    		
    		
    		queue.addFirst(new Exec(next[e.pos], e.val));
    		if(next[e.pos] != e.pos + 1){
    			queue.addLast(new Exec(e.pos + 1, e.val + 1));
    		}
    	}
    	
    	
    }
     
}
