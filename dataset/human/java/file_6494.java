import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		atcode();
	}

	public static void atcode() {
		String[] info=new Scanner(System.in).nextLine().split(" ");
		Integer max=Integer.valueOf(info[0]);
		Integer sum=Integer.valueOf(info[1]);
		int count=0;
		for(int x=0;x<=max;x++) {
			for(int y=0;y<=max;y++) {
				int z=sum-x-y;
				if(z>=0&&z<=max)count++;
			}
		}
		System.out.println(count);
	}
}
