import java.util.Arrays;
import java.util.Scanner;

class Main{
	public static void main(String[] arg) {
		Scanner sc=new Scanner(System.in);
		int ninzu=sc.nextInt();
		int[] teamscore=new int[ninzu+1];

		for(int i=0; i<ninzu; i++) {
			teamscore[i]=sc.nextInt();
		}
		teamscore[ninzu]=0;

		Arrays.sort(teamscore);

		int tmp=0;

		for(int h=100; h>=1; h--) {
			tmp=0;
			for(int i=1; i<=ninzu; i++) {
				if(teamscore[i]>=h) {
					tmp++;
				}
			}
			if(tmp>=h) {
				System.out.println(h);
				break;
			}
		}
	}
}
