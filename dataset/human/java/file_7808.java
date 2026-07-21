import java.util.*;

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
    	int n = sc.nextInt();
    	long k = sc.nextLong();
    	Map<Integer,Integer> teleport = new HashMap<>();
    	Map<Integer,Long> history = new HashMap<>();
    	for(int i = 1 ; i <= n; i++){
    		teleport.put(i, sc.nextInt());
    	}
    	long i;
    	int now = 1;
    	boolean flag = false;
    	for(i = 0; i <= k; i++){
    		if(history.containsKey(now)){
    			flag = true;
    			break;
    		}
    		history.put(now, i);
    		now = teleport.get(now);
    	}
    	if(flag){
    		long pastTime = history.get(now);
    		k = pastTime + (k - pastTime) % (i - pastTime);
    	}
    	for(int p : history.keySet()){
    		if(history.get(p) == k){
    			System.out.println(p);
    			return;
    		}
    	}
    }
}
