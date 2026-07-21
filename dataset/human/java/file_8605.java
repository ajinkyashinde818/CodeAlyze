import java.util.*;
public class Main{
	public static void main(String args[]){
		Scanner sc = new Scanner(System.in);
		int A = sc.nextInt();
		int B = sc.nextInt();
		int K = sc.nextInt();
		int buf = Math.min(A,B);
		int count = 0;
		int ans = 0;
		for(int i = 0;i < buf;i++){
			if(A % (buf - i) == 0 && B % (buf - i) == 0){
				count++;
			}
			if(count == K){
				ans = buf - i;
				break;
			}
		}
		System.out.println(ans);
	}
}
