import java.util.Scanner;

public class Main {
	
	public static void main(String[] args) {
		
		Scanner in = new Scanner(System.in);
		int count = 0;
		boolean flag = false;
		StringBuilder s = new StringBuilder(in.nextLine());
		StringBuilder front = new StringBuilder("");
		StringBuilder back = new StringBuilder("");
		int q = in.nextInt();
		for(int i=0; i<q; i++) {
			int op = in.nextInt();
			if(op==1) {
				count++;
				flag = !flag;
			}else if(op==2) {
				int position = in.nextInt();
				char c = in.next().charAt(0);
				if(flag) {
					if(position==1) position=2;
					else if(position==2) position=1;
				}
				if(position==1) {
					front.append(c);
				}else if(position==2) {
					back.append(c);
				}
			}
		}
		if(count%2!=0) {
			System.out.print(back.reverse().append(s.reverse()).append(front));
		}else {
		    System.out.print(front.reverse().append(s).append(back));
		}
	}
	
}
