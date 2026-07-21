import java.util.*;
import java.util.ArrayList;


public class Main{
	public static void main(String args[]){

		// 値取得
		Scanner sc = new Scanner(System.in);
		int total = 0;
		int n = sc.nextInt();
		ArrayList<Integer> a = new ArrayList<>();
		ArrayList<Integer> b = new ArrayList<>();
		ArrayList<Integer> c = new ArrayList<>();

		for(int i = 0;i<n;i++){
			a.add(sc.nextInt());
		}
		for(int j = 0;j<n;j++){
			b.add(sc.nextInt());			
		}
		for(int k = 0;k<n-1;k++){
			c.add(sc.nextInt());			
		}
		c.add(0);

		// b得点
		for(int l =0;l<n;l++){
			total = total + b.get(l);
		}

		// c得点
		for(int m=0; m<a.size()-1;m++){
			if(a.get(m)+1 == a.get(m+1)){
				total = total + c.get(a.get(m)-1);
			}
		}

		System.out.println(total);
	}
}
