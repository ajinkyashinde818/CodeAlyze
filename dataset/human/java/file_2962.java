import java.util.*;
import java.lang.Math;

public class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    
	int n = sc.nextInt();
    int m = sc.nextInt();
    int gs[] = new int[m];
    int ts[] = new int[m];
    boolean imp = true;
    List iList = new ArrayList<Integer>();
    
    for(int i = 0; i < m;i++) {
      gs[i] = sc.nextInt();
      ts[i] = sc.nextInt();
      if(gs[i] == 1) iList.add(ts[i]);
      if(ts[i] == n) iList.add(gs[i]);
    }
    Collections.sort(iList);
   	
    for(int i = 0;i < iList.size()-1 && imp;i++){
         if((int)iList.get(i) == (int)iList.get(i+1)) imp = false;
    }

    if(imp) System.out.println("IMPOSSIBLE");
    else System.out.println("POSSIBLE");

  }
}
