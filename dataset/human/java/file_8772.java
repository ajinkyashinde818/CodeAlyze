import java.util.ArrayList;
import java.util.Scanner;
public class Main {
	public static void main(String [] args) {
		Scanner in = new Scanner(System.in);
		
		int a = in.nextInt();
		int b = in.nextInt();
		int k = in.nextInt();
		ArrayList<Integer> ks = new ArrayList<>();
		for(int i=1;i<=Math.min(a, b);i++) {
			if(a%i==0&&b%i==0) {
				ks.add(i);
				
				}
			}
		System.out.println(ks.get(ks.size()-k));
		}
	
		
	}
