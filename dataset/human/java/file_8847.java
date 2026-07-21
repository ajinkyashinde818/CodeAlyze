import java.util.*;
public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int a = sc.nextInt();
		int b = sc.nextInt();
		int k = sc.nextInt();
		int[] commondivisor = new int[a+1];
		int number = 0;
		int kthnumber = 0;
		for(int i = a; i >= 1; i--) {
			if(a % i == 0 && b % i == 0) {
				commondivisor[i] = i;
			}
		}
		for(int i = a; i >= 1;i--) {
			if(commondivisor[i] != 0) {
				number += 1;
			}
			if(number == k) {
				kthnumber = i;
				break;
			}
		}
		System.out.println(commondivisor[kthnumber]);
	}

}
