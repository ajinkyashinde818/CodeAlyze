import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;


public class Main {

	public static void main(String[] args) {
		Main main = new Main();
		main.pointCount();
		return;
	}
	
	private void pointCount() {
		
		BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in)); //標準入力
		
		try {
			
			int point = 0;
			
			for (int i = 0; i < 10; i++) {
				String inputStr = bufferedReader.readLine();
				int num = Integer.parseInt(inputStr);
				point += num;
			}
			
			System.out.println(point);
			
		} catch (IOException e) {
			// TODO 自動生成された catch ブロック
			e.printStackTrace();
		}
		
	}
}
