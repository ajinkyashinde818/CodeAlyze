import java.util.Scanner;
public class Main {

	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		int k=scan.nextInt();
		int s=scan.nextInt();
		scan.close();

		int cnt=0;
		for(int i=0;i<=k;i++) {
			for(int j=0;j<=k;j++) {
				//もしZ (s-i-j)が0より大きくて、ZがKよりも小さいなら
				//s=2 i=1 j=1 z=0 〇
				//s=2 i=1 j=2 z=-1 ×
				//s=2 i=1 j=1 z=2 ×
				if(s - i - j >= 0 && s - i - j <= k){
		            cnt++;
		        }
			}
		}

		System.out.println(cnt);

	}
}
