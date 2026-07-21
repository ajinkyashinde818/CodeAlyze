import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner stdIn = new Scanner(System.in);
		String S = stdIn.nextLine();
		
		StringBuffer sb = new StringBuffer(S);
		
		S = sb.reverse().toString();
		
		String[] word = {"maerd", "remaerd", "esare", "resare"};
		
		boolean canDivide = false;
		for(int i = 0; i < S.length();) {
			for(int j = 0; j < word.length; j ++) {
				canDivide = false;
				if(i + word[j].length() <= S.length()) {
					if(S.substring(i, i + word[j].length()).equals(word[j])) {
						canDivide = true;
						i += word[j].length();
						break;
					}
				}
			}
			if(!canDivide) {
				break;
			}
		}
		
		if(canDivide) {
			System.out.println("YES");
		}else {
			System.out.println("NO");
		}
	}

}
