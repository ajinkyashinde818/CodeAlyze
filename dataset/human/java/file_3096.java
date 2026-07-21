import java.util.*;

public class Main {
	public static void main(String[] args) throws Exception{
		Scanner scn = new Scanner(System.in);
		int n = scn.nextInt();
      	int m = scn.nextInt();
		int[] a = new int[m];
      	int[] b = new int[m];
		for(int i=0; i<m; i++){
			a[i] = scn.nextInt();
          	b[i] = scn.nextInt();
		}
      	ArrayList<Integer> list = new ArrayList<>();
      	for(int i=0; i<m; i++){
			if(a[i]==1) list.add(b[i]);
          	if(b[i]==n) list.add(a[i]);
		}
      	Collections.sort(list);
      	String ans = "IMPOSSIBLE";
      	for(int i=0; i<list.size()-1; i++){
          if((int)list.get(i) == (int)list.get(i+1)){
            ans = "POSSIBLE";
            break;
          }
        }
      	System.out.println(ans);
	}
}
