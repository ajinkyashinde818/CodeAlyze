import java.util.*;
public class Main{
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int[] d1 = new int[n];
		int[] d2 = new int[n];
		for(int i = 0; i < n; i++){
			d1[i] = sc.nextInt();
			d2[i] = sc.nextInt();
		}
		
		int count = 0,max = 0;
		for(int i = 0; i < n; i++){
			if(d1[i] == d2[i]){
				count++;
				max = Math.max(max, count);
			}else{
				count = 0;
			}
		}
		
		if(max >= 3) System.out.println("Yes");
		else System.out.println("No");
	}
}
