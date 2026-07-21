import java.math.BigInteger;
import java.util.Scanner;

public class Main
{
	public static void main(String[] args)
	{
		Scanner sc = new Scanner(System.in);
		String str = sc.nextLine();
		String[] substr = str.split(" ", 0);
		int n = Integer.parseInt(substr[0]);
		BigInteger k = new BigInteger(substr[1]);
		int [] a = new int[n+1];
		int [] b = new int[n+1];
		int [] c = new int[n+1];
		int [] d = new int[n+1];

		for (int i= 1; i<n+1; i++) {
			a[i] = sc.nextInt();
		}
		sc.close();
		int i = 1;
		int j = 0;
		int count = 0;
		int count0 = 1;
		b[1] = 1;
		while(true) {
			if (b[a[i]] == 2) break;
			if (b[a[i]] == 1) {
				c[j]=a[i];
				b[a[i]] = 2;
				j+=1;
				i = a[i];
				count+=1;
			} else {
				b[a[i]]= 1;
				d[count0]= a[i];
				i= a[i];
				count0+=1;
			}
		}
	    int ans = 0;
		if (k.compareTo(BigInteger.valueOf(count0)) < 0) {
			ans = d[k.intValue()];
			System.out.println(ans);
			return;
		}

		BigInteger index = k.subtract(BigInteger.valueOf(count0)).mod(BigInteger.valueOf(count));
		int ind = index.intValue();

	    ans = c[ind];
		System.out.println(ans);
	}
}
