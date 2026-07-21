import java.util.Scanner;
public class Main {
	public static void main(String[] args){
		Scanner as = new Scanner(System.in);
		int n = as.nextInt();
		int[] a;
		a = new int[n];
		long t = 0;
		for(int i=0;i<n;i++){
			a[i] = Integer.parseInt(as.next());
			t+=a[i];
		}
		long l=0;
		boolean asa = true;
		if(t%((n+1)*(long)n/2)==0){
			long k=t/((n+1)*(long)n/2);
			for(int i=0;i<n;i++){
				l = a[(i+1)%n]-a[i];
				if(l>k||(k-l)%n!=0){
					asa = false;
					break;
				}
			}
		}else{
			asa = false;
		}
		if(asa){
			System.out.println("YES");
		}else{
			System.out.println("NO");
		}
	}
}
