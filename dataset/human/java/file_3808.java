import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;


public class Main {
	
	public static void main(String[] args) throws IOException {
		Main m = new Main();
		m.input();
		m.solve();
		m.output();
	}
	
	BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	//	InputUtil in = new InputUtil();
	PrintWriter out = new PrintWriter(System.out);

	String S = null;
	int ans = 0;
	
	public void input() throws IOException {
		S = br.readLine();
	}

	public void solve() throws IOException {
		int slen = S.length();
		char[] snx = new char[slen];
		int ptrSnx = 0;
		for(int i=0; i<slen; i++){
			char c = S.charAt(i);
			if(c != 'x')
				snx[ptrSnx++] = c;
		}
		
		for(int i=0; i<ptrSnx/2; i++){
			if(snx[i]!=snx[ptrSnx-1-i]){
				ans = -1;
				return;
			}
		}
		
		int ptr1=0;
		int ptr2=slen-1;
		
		while(ptr1<ptr2){
			char c1 = S.charAt(ptr1);
			char c2 = S.charAt(ptr2);
			if(c1 == c2){
				ptr1++;
				ptr2--;
			}else{
				if(c1=='x'){
					ptr1++;
					ans ++;
				}else{
					ptr2--;
					ans ++;
				}
			}
		}
	}
	
	
	public void output() {
		out.println(ans);
		out.flush();
		
	}
}
