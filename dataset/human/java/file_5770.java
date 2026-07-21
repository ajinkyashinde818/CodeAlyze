import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader buff = null;
		buff = new BufferedReader(new InputStreamReader(System.in));

		String[] box = buff.readLine().split("");
		int ans = 0;
		for(int i = 0; i < 3; ++i){
			if(box[i].equals("a")){
				ans += 4;
			} else if (box[i].equals("b")){
				ans += 2;
			} else if(box[i].equals("c")){
				ans += 1;
			}
		}

		if(ans == 7){
			System.out.println("Yes");
		} else {
			System.out.println("No");
		}

	}

}
