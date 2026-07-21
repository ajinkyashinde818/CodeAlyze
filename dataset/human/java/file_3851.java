import java.io.FileInputStream;
import java.io.InputStream;
import java.util.Scanner;

public class Main{
	static Scanner sc;

	public static void main(String[] args) throws Exception {
		//InputStream in = new FileInputStream("src/input.txt");
		InputStream in = System.in;
		//PrintStream out = new PrintStream("src/output.txt");

		//System.setOut(out);

		sc = new Scanner(in);

		String S = sc.next();
		StringBuilder sb = new StringBuilder();
		sb.append(S);
		int answer = 0;


		for(int i = 0; i < Math.ceil(sb.length() / 2.0); i++){
			//System.out.println(i + "\t" + sb.charAt(i) + "\t" + sb.charAt(sb.length() - 1 - i));
			if(sb.charAt(i) != sb.charAt(sb.length() - 1 - i)){
				if(sb.charAt(i) == 'x'){
					sb.insert(sb.length() - i, 'x');
					i--;
					answer++;
				}else if(sb.charAt(sb.length() - 1 - i) == 'x'){
					sb.insert(i, 'x');
					i--;
					answer++;
				}else{
					answer = -1;
					break;
				}
			}

			if(i+1 == Math.ceil(sb.length() / 2.0)){
				if(sb.charAt(i) != sb.charAt(sb.length() - 1 - i)){
					answer = -1;
				}
			}

			//System.out.println(sb);
		}

		System.out.println(answer);

		//out.close();
	}
}
