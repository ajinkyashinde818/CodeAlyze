import java.util.Arrays;
import java.util.Collections;
import java.util.Scanner;


	public class Main {

		public static void main(String[] args) {

			Scanner sc = new Scanner(System.in);

			char[] s = sc.next().toCharArray();
			String T = sc.next();
			
			Character[] t = new Character[T.length()];
			
			for(int i=0;i<T.length();i++) {
				t[i] = T.charAt(i);
			}
			
			Arrays.sort(s);
			Arrays.sort(t,Collections.reverseOrder());
			
			char[] tn = new char[T.length()];
			
			for(int i =0;i<T.length();i++) {
				tn[i] = t[i];
			}
			
						
			String Sn = String.valueOf(s);
			String Tn = String.valueOf(tn);
			

			
			if(Sn.compareTo(Tn)<0) {
				System.out.println("Yes");
			}else {
				System.out.println("No");
			}
			
		}



	}
