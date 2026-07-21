import java.util.*;
 
public class Main {
	
    public static void main(String[] args) {
    	Scanner sc = new Scanner(System.in);
    	int N = sc.nextInt();
    	int M = sc.nextInt();
    	int X = sc.nextInt();
    	List<int[]> list = new ArrayList<>();
    	for (int i = 0; i < N; i++) {
    		int[] ar = new int[M + 1];
    		for (int j = 0; j < ar.length; j++) {
    			ar[j] = sc.nextInt();
    		}
    		list.add(ar);
    	}
    	List<List<int[]>> ptn = new ArrayList<>();
    	for (int i = 1; i < Math.pow(2, N); i++) {
    		List<int[]> p = new ArrayList<>();
    		for (int j = 0; j < N; j++) {
    			if ((1&(i>>j)) == 1) {
    				int[] array = list.get(j);
    				p.add(array);
    			}
    		}
    		ptn.add(p);
    	}
    	long cost = Long.MAX_VALUE;
    	boolean isEx = false;
    	for (List<int[]> p : ptn) {
    		int[] cont = new int[M + 1];
    		for (int[] a : p) {
    			for (int i = 0; i < a.length; i++) {
    				cont[i] += a[i];
    			}
    		}
    		boolean key = true;
    		for (int i = 1; i < cont.length; i++) {
    			if (cont[i] < X) {
    				key = false;
    			}
    		}
    		if (key && (cont[0] < cost)) {
    			cost = cont[0];
    			isEx = true;
    		}
    	}
    	System.out.println(isEx ? cost : -1);
    	
    }
}
