import java.util.Arrays;
import java.util.Scanner;

public class Main {
public static void main(String[] args) {
		
		Scanner keyboard = new Scanner(System.in); 
		
		String S  = keyboard.next();
		String ans = "YES";
		
		for(int i = 0; i < S.length();) {
			if(S.length() - i >= 5) {
			//ここまでの判定に使った文字の残りが単語の文字数を充足する場合	に処理	
				if(S.substring(i,i+5).equals("dream")){
					if(S.length()-(i+5) >= 3 && S.substring(i+5,i+8).equals("era")) {
						i += 5;
						continue;
					}else if(S.length()-(i+5) >= 2 && S.substring(i+5,i+7).equals("er")) {
						i += 7;
						continue;
					}else {
						i += 5;
						continue;
						}
				}else if(S.substring(i,i+5).equals("erase")){
					if(S.length()-(i+5) >= 1 && S.substring(i+5,i+6).equals("r")) {
						i += 6;
						continue;
					}else {
						i += 5;
						continue;
						}
				//文字列が単語を成さなかった場合
				}else {
					ans = "NO";
					break;
				}
			//文字の残りが単語の文字数を充足しない場合				
			}else{
				ans = "NO";
				break;
			}
		}

		System.out.println(ans);
		keyboard.close();	
	}
}
