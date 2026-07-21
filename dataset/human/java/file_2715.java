import java.io.IOException;
import java.util.Arrays;
import java.util.Scanner;

public class Main {

	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);

		char[] s = sc.next().toCharArray();
		char[] t = sc.next().toCharArray();

		Arrays.sort(s);
		Arrays.sort(t);

		for(int i = 0; i < s.length; i++){
			for(int j = i; j < t.length; j++){
				if(s[i] < t[j]){
					System.out.println("Yes");
					return;
				}
			}
		}

		if(new String(t).contains(new String(s)) && s.length < t.length){
			System.out.println("Yes");
		}
		else {
			System.out.println("No");
		}

	}
}
