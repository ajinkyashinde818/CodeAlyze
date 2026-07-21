import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;


public class Main {
	public static void main(String[] args) throws IOException{


		// 読み込み
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String line;
		String[] temp;

		line=br.readLine();
		temp=line.split(" ");

		int x = Integer.valueOf(temp[0]);

		if(x <1200){
			System.out.println("ABC");
		}else{
			System.out.println("ARC");
		}


	}
}
