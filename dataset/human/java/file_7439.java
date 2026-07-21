import java.util.Scanner;


public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		String S = sc.next();
		boolean result = false;
      	String test[] = {"dream", "dreamer", "erase", "eraser"};
		int index = S.length();

		loop: for (int i = 0; i < 20001; i++) {
          	if (index == 0) {
				result = true;
				break;
			}
          	for (int j = 0; j < test.length; j++) {
              	if (index - test[j].length() >= 0
                	&& test[j].equals(S.substring(index - test[j].length(), index))) {
                	index -= test[j].length();
                	continue loop;
                }
            }
			break;
		}

		System.out.println(result ? "YES" : "NO");
	}
}
