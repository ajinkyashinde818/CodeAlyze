import java.util.*;

public class Main{
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int k=sc.nextInt();
		int n=sc.nextInt();
		int[] a=new int[n];
		int sum=0;
		ArrayList<Integer> aa = new ArrayList<>();
		
		for(int i=0;i<n;i++) {
			int w =sc.nextInt();
			aa.add(w);
		}

		for(int i=0;i<n-1;i++) {
			a[i]=aa.get(i+1)-aa.get(i);
		}
		a[a.length-1]=aa.get(0)+k-aa.get(aa.size()-1);
		Arrays.sort(a);
		
		for(int i=0;i<n-1;i++) {
			sum+=a[i];
		}
		
		System.out.println(sum);
		sc.close();
	}
}
