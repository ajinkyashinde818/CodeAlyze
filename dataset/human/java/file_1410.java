import java.io.*;
import java.util.*;
public class Main {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int an = in.nextInt();
		int bn = in.nextInt();
		int[][] a = new int[an][an];
		int[][] b = new int[bn][bn];
		for(int i=0;i<an;i++){
			String row = in.next();
			for(int j=0;j<an;j++){
				a[i][j] = row.charAt(j);
			}
		}
		for(int i=0;i<bn;i++){
			String row = in.next();
			for(int j=0;j<bn;j++){
				b[i][j] = row.charAt(j);
			}
		}
		boolean work = false;
		for(int i=0;i<an;i++){
			for(int j=0;j<an;j++){
				if(compare(a,b,i,j)){
					work = true;
					break;
				}
			}
		}
		System.out.println(work ? "Yes" : "No");
	}
	public static boolean compare(int[][] a, int[][] b, int ai, int aj){
		if(ai + b.length > a.length || aj + b.length > a.length) return false;
		for(int i=ai;i<ai+b.length;i++){
			for(int j=aj;j<aj+b.length;j++){
				if(a[i][j] != b[i-ai][j-aj]) return false;
			}
		}
		return true;
	}
}
