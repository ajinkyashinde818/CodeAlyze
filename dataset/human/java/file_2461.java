import java.util.*;

public class Main {
	public Scanner sc = new Scanner(System.in);
	public static void main(String[] args) {
		new Main();
	}
	public Main() {
		new aoj1137().doIt();
	}
	class aoj1137{
		char keta[] = {'i','x','c','m'};
		char keta2[] = {'2','3','4','5','6','7','8','9'};
		int number(char ctr[]){
			int result = 0;
			int num2 = 1;
			int num = 1;
			for(int i = 0;i < ctr.length;i++){
				for(int j = 0;j < 4;j++){
					if(keta[j] == ctr[i]){
						result = result + (num * num2);
						num2 = 1;
						break;
					}
					num = num * 10;
				}
				num = 1;
				for(int j = 0;j < 8;j++){
					if(keta2[j] == ctr[i])num2 = num2 * (j+2);
				}
			}
			return result;
 		}
		void doIt() {
			int n = sc.nextInt();
			for(int i = 0;i < n;i++){
				String a = sc.next();
				String b = sc.next();
				char ctra[] = a.toCharArray();
				char ctrb[] = b.toCharArray();
				int sum = number(ctra) + number(ctrb);
				int m = 1000;
				for(int j = 3;j >= 0;j--){
					int ans = sum / m;
					if(ans > 1){
						System.out.print(ans);
						System.out.print(keta[j]);
					}else if(ans == 1){
						System.out.print(keta[j]);
					}
					sum = sum % m;
					m = m / 10;
				}
				System.out.println();
			}
		}
	}
}
