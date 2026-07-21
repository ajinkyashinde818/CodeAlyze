import java.util.Scanner;

public class Main {
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		int k = 0;
		int n = 0;

		k = sc.nextInt();
		n = sc.nextInt();

		int array[] = new int [n];

		for(int i = 0;i<n;i++){
			array[i] = sc.nextInt();
		}

		int ans = Integer.MAX_VALUE;
		for(int i = 0; i < n; i++){
			int  tmp = 0;
			int index = i -1;
			if(index < 0){
				index += n;
			}
			tmp = array[index] - array[i];
			if(tmp <= 0){
				tmp += k;
			}
			ans = Math.min(ans, tmp);
		}
			System.out.println(ans);
	}
}
