import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main{
	public static void main(String[] args)throws IOException{
		InputStreamReader isr = new InputStreamReader(System.in);
		BufferedReader reader = new BufferedReader(isr);
		StringBuilder sb = new StringBuilder();
		String string, str[];
		
		int min, sum, tmp, hoge;
		int jen[] = new int[]{4, 1, 4, 1, 2, 1, 2, 1};
		while((string = reader.readLine()) != null){
			str = string.split(" ");
			min = hoge = 2 << 29;
			
			int ary[] = new int[8];
			for(int i = 0; i < 8; i++){
				ary[i] = Integer.valueOf(str[i]);
			}
			
			for(int i = 0; i < 8; i++){
				sum = 0;
				for(int j = 0; j < 8; j++){
					tmp = (i + j) % 8;
					if(jen[tmp] < ary[j]){
						sum += ary[j] - jen[tmp];
					}
				}
				if(min > sum){
					min = sum;
					
					sb.setLength(0);
					for(int j = 0; j < 8; j++){
						sb.append(String.valueOf(jen[(i + j) % 8]));
					}
					hoge = Integer.valueOf(sb.toString());
				}else if(min == sum){
					sb.setLength(0);
					for(int j = 0; j < 8; j++){
						sb.append(String.valueOf(jen[(i + j) % 8]));
					}
					if(Integer.valueOf(sb.toString()) < hoge){
						hoge = Integer.valueOf(sb.toString());
					}
				}
			}
			
			String res = String.valueOf(hoge);
			for(int i = 0; i < 8; i++){
				if(i == 7){
					System.out.println(res.charAt(i));
				}else{
					System.out.print(res.charAt(i) + " ");
				}
			}
		}
		reader.close();
	}
}
