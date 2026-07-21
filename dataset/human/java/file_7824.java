import java.util.*;
public class Main{
	public static void main(String args[]){
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		long K = sc.nextLong();
		boolean[] town = new boolean[N];
		long counter = 1;
		int[] A = new int[N];
		for(int i = 0;i < N;i++){
			A[i] = sc.nextInt() - 1;
		}
		int pointer = A[0];
		town[0] = true;
		while(town[pointer] == false){
			town[pointer] = true;
			pointer = A[pointer];
			counter++;
		}
		int ans = pointer;
		int pointer2 = 0;
		long counter2 = 0;
		while(pointer2 != pointer){
			pointer2 = A[pointer2];
			counter2++;
		}
		if(K < counter){
			ans = 0;
			for(long i = 0;i < K;i++){
				ans = A[ans];
			}
		}else if(K > counter2 && counter > counter2){
			long buf = (K - counter2) % (counter - counter2);
			ans = pointer;
			for(long i = 0;i < buf;i++){
				ans = A[ans];
			}
		}
		System.out.println((ans + 1));
	}
}
