import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		if(br.readLine( ).matches("^((dreamer)|(eraser)|(dream)|(erase))+$") ){
			System.out.println("YES");
		}else{
			System.out.println("NO");
		}
	}
}
