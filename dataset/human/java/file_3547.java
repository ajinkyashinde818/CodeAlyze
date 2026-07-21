import java.util.Scanner;

class Main {
	public static void main(String[] args) throws Exception{
		Scanner sc = new Scanner(System.in);
		StringBuilder stdout = new StringBuilder();
		String x = sc.next();
		String y = sc.next();
		int flag = Integer.valueOf(x,16).compareTo(Integer.valueOf(y,16));
		switch(flag){
			case -1:
				stdout.append("<");
				break;
			case 0:
				stdout.append("=");
				break;
			case 1:
				stdout.append(">");
				break;
		}
		System.out.println(stdout);
	}
}
