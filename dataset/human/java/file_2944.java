import java.util.*;
 
public class Main {
	public static void main(String[] args) throws Exception{
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
        int m = sc.nextInt();
        int[] a = new int[m];
        int[] b = new int[m];
        Set<Integer> mid = new HashSet<>(); 
        Set<Integer> goal = new HashSet<>(); 
        for(int i = 0; i < m; i++){
        	a[i] = sc.nextInt();
            b[i] = sc.nextInt();
            if(a[i] == 1){
            	mid.add(b[i]);
            }else if(b[i] == n){
            	goal.add(a[i]);
            }
        }
        ArrayList<Integer> list = new ArrayList<>();
        for(int x : goal){
        	list.add(x);
        }
        for(int i = 0; i < list.size(); i++){
            if(mid.contains(list.get(i))){
            	System.out.println("POSSIBLE");
                return;
            }
        }
        System.out.println("IMPOSSIBLE");
	}
}
