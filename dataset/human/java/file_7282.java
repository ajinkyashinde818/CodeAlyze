//第 4 問: ABC 087 B - Coinsi (200 点)
/*
 * dreamererasereraserdream
erasereraserdream
reraserdream
NO
 */

import java.util.Scanner;

public class Main{

	public static void main(String[] args){

		Scanner scan = new Scanner(System.in);

		String S = scan.next();
		StringBuilder sb = new StringBuilder();
		sb.append(S);

		/*
		String A = "";
		String B = "";
		String C = "";
		*/

		while(true) {

			int counter = sb.length();

			if (counter > 7) {

				if (sb.substring(0,8).equals("dreamera")){

					sb = sb.delete(0,5);

				}
				else if(sb.substring(0,7).equals("dreamer")){

					sb = sb.delete(0,7);

				}
				else if(sb.substring(0,6).equals("eraser")){

					sb = sb.delete(0,6);
					//System.out.println("Err");

				}
				else if ((sb.substring(0,5).equals("dream")) || (sb.substring(0,5).equals("erase"))) {

					sb = sb.delete(0,5);
					//System.out.println("Err2");

				}
				else {
					System.out.println("NO");
					//System.out.println("A");
					break;
				}

			//System.out.println(sb);

			}
			else if (counter == 7) {
				if(sb.toString().equals("dreamer")) {
					System.out.println("YES");
					break;
				}
				else {
					System.out.println("NO");
					//System.out.println("B");
					break;
				}

			}
			else if (counter == 6) {

				if(sb.toString().equals("eraser")) {
					System.out.println("YES");
					break;
				}
				else {
					System.out.println("NO");
					//System.out.println("C");
					break;
				}

			}
			else if (counter == 5) {
				if ((sb.toString().equals("dream")) || (sb.toString().equals("erase"))) {
					System.out.println("YES");
					break;
				}
				else{
					System.out.println("NO");
					//System.out.println("D");
					break;
				}
			}
			else {
				System.out.println("NO");
				//System.out.println("E");
				break;
			}

			//System.out.println(sb);

		}

	}
}
