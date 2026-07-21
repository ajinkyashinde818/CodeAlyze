import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main{
	public static void main(String[] args)throws IOException{
		InputStreamReader isr = new InputStreamReader(System.in);
		BufferedReader reader = new BufferedReader(isr);
		String string;
		char ch[];
		
		int n, res;
		while(!(string = reader.readLine()).equals("0")){
			n = Integer.valueOf(string);
			
			int map[][] = new int[n][n];
			int sum[][] = new int[n + 1][n + 1];
			ch = reader.readLine().toCharArray();
			for(int i = 0; i < n; i++){
				map[0][i] = (ch[i] == '.' ? 1 : 0);
				
				if(i > 0){
					sum[1][i + 1] = sum[1][i] + map[0][i];
				}else{
					sum[1][i + 1] = map[0][i];
				}
			}
			for(int i = 1; i < n; i++){
				ch = reader.readLine().toCharArray();
				for(int j = 0; j < n; j++){
					map[i][j] = (ch[j] == '.' ? 1 : 0) + map[i - 1][j];
					
					if(j > 0){
						sum[i + 1][j + 1] = sum[i + 1][j] + map[i][j];
					}else{
						sum[i + 1][1] = map[i][0];
					}
				}
			}
			
			if(sum[n][n] == 0){
				System.out.println(0);
				continue;
			}
			res = 1;
			x : for(int w = n + 1; w > 0; w--){
				for(int i = n; i > 0; i--){
					if(i - w < 0) break;
					for(int j = n; j > 0; j--){
						if(j - w < 0) break;
						
						if(sum[i][j] - sum[i - w][j] - sum[i][j - w] + sum[i - w][j - w] == w * w){
							res = w;
							break x;
						}
					}
				}
			}
			System.out.println(res);
		}
		reader.close();
	}
}
