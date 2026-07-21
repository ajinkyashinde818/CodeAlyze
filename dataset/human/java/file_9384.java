import java.util.*;
public class Main {
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int[][] a = new int[n][2];
		int count  = 0;
		int max = 0;
		for(int i=0;i<n;i++){
			a[i][0] = sc.nextInt();
			a[i][1] = sc.nextInt();
			if( a[i][0] == a[i][1] ){
				count++;
				if( count > max ){
					max = count;
				}
			}else{
				count = 0;
			}
		}
		if( max >= 3 ){
			System.out.println("Yes");
		}else{
			System.out.println("No");
		}
	}
}
