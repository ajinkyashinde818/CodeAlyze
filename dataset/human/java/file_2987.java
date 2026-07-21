import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;


	public class Main {
		

		public static void main(String[] args) {

			Scanner sc = new Scanner(System.in);
	        
			int n = sc.nextInt();
			int m = sc.nextInt();
			int[] a = new int[m];
			int[] b = new int[m];
			int na = 0;
			int nb = 0;
			Set<Integer> c = new HashSet<Integer>();
			
			for(int i=0;i<m;i++) {
				a[i]=sc.nextInt();
				b[i]=sc.nextInt();
				if(a[i]==1) {
					c.add(b[i]);
					na++;
				}
				if(b[i]==n) {
					c.add(a[i]);
					nb++;
				}
			}
			
			if(na+nb==c.size()) {
				System.out.println("IMPOSSIBLE");
			}else {
				System.out.println("POSSIBLE");
			}
		}
		
	}
