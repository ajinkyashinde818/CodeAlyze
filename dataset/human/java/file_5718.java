import java.util.*;

public class Main{
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		String a = sc.next();
		char[] n = new char[3];
		int counterA = 0;
		int counterB = 0;
		int counterC = 0;

		for(int i = 0; i < 3; i++){
			n[i] = a.charAt(i);
		}

		for(int j = 0; j < 3; j++){
			if(n[j] == 'a'){
				counterA++;
			}else if(n[j] == 'b'){
				counterB++;
			}else if(n[j] == 'c'){
				counterC++;
			}
		}

		if(counterA == 1 && counterB == 1 && counterC == 1){
			System.out.println("Yes");
		}else{
			System.out.println("No");
		}
	}
}
