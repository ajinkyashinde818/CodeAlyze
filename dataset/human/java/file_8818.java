import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;

public class Main{
	public static void main(String[] args){
		InputStreamReader ir = new InputStreamReader(System.in);
		BufferedReader br = new BufferedReader(ir);

		String str = null;
		try{
			str = br.readLine();
		}catch(IOException ex){
			ex.printStackTrace();
		}

		String[] input = str.split(" ");
		int a = Integer.parseInt(input[0]);
		int b = Integer.parseInt(input[1]);
		int k = Integer.parseInt(input[2]);

		List<Integer> res = new ArrayList<>();
		for(int i = 1; i <= 100; i++){
			if(a % i == 0 && b % i == 0){
				res.add(i);
			}
		}
		System.out.println(res.get(res.size() - k));
	}
}
