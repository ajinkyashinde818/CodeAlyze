import java.io.BufferedReader;
import java.io.InputStreamReader;
 
public class Main {
 
	public static void main(String[] args) throws Exception {
		// TODO 自動生成されたメソッド・スタブ
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		String W = in.readLine();
 
		long N = Long.parseLong(W);
 
		long ans =0;
		if(N%2 == 1){
			//奇数の場合は0
			ans =0;
		}else{
//			ans=N/10;
			for(long i=5;i<=N;i*=5){
				ans+=((N/2)/i);
			}
		}
 
		System.out.println(ans);
 
	}
}
