import java.util.*;
public class Main{
	static String TemMatch(int p, int q, String[] s, String[] t){
		for(int i=0; i<=p-q; i++){
			for(int j=0; j<=p-q; j++){
				if(s[i].substring(j, j+q).equals(t[0])){
					if(q==1)return "Yes";
					for(int k=1; k<q; k++){
						if(!s[i+k].substring(j,j+q).equals(t[k]))break;
						if(k==q-1)return "Yes";
					}
				}
			}
		}
		return "No";
	}

	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int m = sc.nextInt();
		String[] a = new String[n];
		String[] b = new String[m];
		for(int i=0; i<n; i++){
			a[i] = sc.next();
		}
		for(int i=0; i<m; i++){
			b[i] = sc.next();
		}		
		System.out.println(TemMatch(n, m, a, b));
	}
}
