import java.util.Scanner;

class Main{
	public static void main(String arg[]) {
		Scanner sc = new Scanner(System.in);
		String S = sc.nextLine();
		sc.close();
		
		S = S.replaceAll("eraser",  "-");
        S = S.replaceAll("erase",   "-");
        S = S.replaceAll("dreamer", "-");
        S = S.replaceAll("dream",   "-");
        S = S.replaceAll("-", "");
        if (S.length() == 0) {
        	System.out.println("YES");
        }else {
            System.out.println("NO");
        }
	}
}
