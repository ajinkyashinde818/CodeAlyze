import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		String s = sc.next();
		
		StringBuilder sb = new StringBuilder();
		
		String t = sb.append(s).reverse().toString();
		
		
		t = t.replaceAll("resare", "1");
		t = t.replaceAll("esare", "1");
		t = t.replaceAll("remaerd", "1");
		t = t.replaceAll("maerd", "1");
		t = t.replaceAll("1", "");
		
		
		if(t.equals("")){
			System.out.println("YES");
		}
		else {
			System.out.println("NO");
		}
	}

}
