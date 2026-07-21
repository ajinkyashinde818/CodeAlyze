import java.util.*;
import java.io.*;
public class Main {

	public static void main(String[] args) throws java.lang.Exception{
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n=Integer.parseInt(br.readLine());
		String ans="";
		for(int i=0; i<n; i++) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			int a=Integer.parseInt(st.nextToken()),b=Integer.parseInt(st.nextToken());
			if(a==b) ans+="1";
			else  ans+="0";
		}
		int c=0;
		for(int i=0; i<ans.length(); i++) {
			if(ans.charAt(i)=='0') {
				if(c>=3) {
					System.out.println("Yes");
					return;
				}
				c=0;
				continue;
			}
			++c;
		}
		System.out.println(c>=3?"Yes":"No");
	}

}
