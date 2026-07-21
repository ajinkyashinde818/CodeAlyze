import java.util.Scanner;

public class Main {
	public static void main(String args[]){
		Scanner sc = new Scanner(System.in);
		int i,s,k;
		k=0;
		for(i=0; i<10; i++) {
			s = sc.nextInt();
			k = k+s;
			}
		System.out.println(k);
		}
	}
