import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		//List<String> list=new ArrayList<String>(Arrays.asList(s.split("")));
		//List<String> list=new ArrayList<String>();
		//int[] array = new int[1000000000*2];
		int n = sc.nextInt();
		int r = sc.nextInt();
		if(n>=10) {
			System.out.println(r);
		}
		else {
			int a = r+100*(10-n);
			System.out.println(a);
		}
	}
}
