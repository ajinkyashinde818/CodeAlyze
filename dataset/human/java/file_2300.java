import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;



public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		List<String> list = new ArrayList<>();
		String b = "";
		char al = 'A';
		for(int i=0;i<52;i++){
			if(i==26) 
				al = 'a';
			list.add(String.valueOf(al));
			al++;
			
		}
		
		while(sc.hasNext()){
			int n = sc.nextInt();
			if(n == 0)break;
			
			int[] k = new int[n+1];
			for(int i=1;i<=n;i++) {
				k[i] = sc.nextInt();
			}
			String str = sc.next();
			char[] s = str.toCharArray();
			StringBuilder sb = new StringBuilder();
			
			int h = 0;
			while(h<str.length()) {
				for(int i=1;i<=n&&h<str.length();i++) {
					if(list.indexOf(String.valueOf(s[h]))-k[i] < 0) {
						b =list.get(52+(list.indexOf(String.valueOf(s[h]))-k[i]));
					}
					else
						b = list.get(list.indexOf(String.valueOf(s[h]))-k[i]);
					sb.append(b);
					h++;
				}
			}
			System.out.println(sb.toString());
		}
	}
}
