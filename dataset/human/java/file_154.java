import java.util.Scanner;

public class Main {

	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		// 整数の入力
		int input = sc.nextInt();
		long min;
		long n[] = new long [input];
		int countm =  0;
		
		long v = sc.nextInt();
		if(v<0) countm+=1;
		n[0]=Math.abs(v);
		min =n[0];
		
		for (int i=1 ; i<input ; i++ ){
			v = sc.nextInt();
			if(v<0) countm+=1;
			n[i]=Math.abs(v);
			if(min>n[i]){
				min = n[i];
			}
			
		}
		long ans = 0;
		for (int i=0 ; i<input ; i++ ){
			ans += n[i];
		}
		if(countm%2==1){
			ans -=2*min;
		}


		System.out.println(ans);
	}

}
