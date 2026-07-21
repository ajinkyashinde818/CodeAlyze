import java.util.*;
public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int A =sc.nextInt();
		int B =sc.nextInt();
		int K =sc.nextInt();
		int count =0;
		if(A<B){
			for(int i=A;i>=1;i--) {
				if(A%i==0&&B%i==0) {
					count++;
					if(count==K){
						System.out.println(i);
					}
				}
			}
		}
		else if(A>B){
			for(int i=B;i>=1;i--) {
				if(A%i==0&&B%i==0) {
					count++;
					if(count==K){
						System.out.println(i);
					}
				}
			}
		}
		else if(A==B){
			for(int i=A;i>=1;i--) {
				if(A%i==0&&B%i==0) {
					count++;
					if(count==K){
						System.out.println(i);
					}
				}
			}
		}
	}
}
