import java.util.ArrayList;
import java.util.Scanner;

class Main{
	public static void main(String[] args){
		Scanner insert = new Scanner(System.in);
		ArrayList<String> result = new ArrayList<String>();
		while(true) {
			int n = insert.nextInt();
			if(n==0) {
				break;
			}
			int[] k = new int[n];
			for(int i=0; i<n; i++){
				k[i] = insert.nextInt();
			}	
			String moji = insert.next();
			char eki[] = new char[moji.length()];
			int eki2[] = new int[moji.length()];
			for(int i = 0; i < moji.length(); i++) {
				eki[i] = moji.charAt(i);
				eki2[i] = (int)(eki[i]);		
			}
			for(int i=0; i<eki.length; i++){
				int val = 'a'<=eki[i]&&eki[i]<='z'?eki[i]-'a' : eki[i]-'A'+26;
				val = (val + 52 - k[i%n])%52;
				eki[i] = (char) ((val < 26)? 'a'+val: 'A'+val-26);
			}
			result.add(String.valueOf(eki));
		}
		for(String a:result) {
			System.out.println(a);
		}
	}
	
}
