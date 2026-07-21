import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

	public static void main(String[] args) throws IOException{
		InputStreamReader in = new InputStreamReader(System.in);
		BufferedReader br = new BufferedReader(in);
		StringBuilder preSb = new StringBuilder();
		StringBuilder sb = new StringBuilder(br.readLine());
		int q = Integer.parseInt(br.readLine());
		
		boolean reverseFlg = false;
		String line = null;
		for(int i=0;i<q;i++) {
			line = br.readLine();
			char[] arr = line.toCharArray();
			if(arr[0]=='1') {
				reverseFlg = !reverseFlg;
			}else {
				if((arr[2]=='1' && !reverseFlg) || (arr[2]=='2' && reverseFlg)) {
//					sb.insert(0, arr[4]);
					preSb.append(arr[4]);
				} 
				else {
					sb.append(arr[4]);
				}
				
			}
		}
		br.close();
		preSb.reverse();
		preSb.append(sb);
		if(reverseFlg) {
			preSb.reverse();
		}
		System.out.println(preSb.toString());
		
	}
}
