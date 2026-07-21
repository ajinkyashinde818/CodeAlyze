import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;
public class Main{
  public static void main(String[] args){
    Scanner sc = new Scanner(System.in);
    int n=sc.nextInt(),m=sc.nextInt();
    Set<Integer> set = new HashSet<>();
    int[] a= new int[m],b=new int[m];
    for(int i=0;i<m;i++) {
    	a[i]=sc.nextInt();
    	b[i]=sc.nextInt();
    	if(a[i]==1)set.add(b[i]);
    }
    for(int i=0;i<m;i++) {
    	if(b[i]==n) {
    		if(!set.add(a[i])) {
    			 System.out.println("POSSIBLE");
    			 System.exit(0);
    		}
    	}
    }
    System.out.println("IMPOSSIBLE");
  }
}
