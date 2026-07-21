import java.util.Scanner;
public class Main {

	public static void main(String[] args) {
		// TODO 自動生成されたメソッド・スタブ
		Scanner scan = new Scanner(System.in);
		int b = scan.nextInt();
        int a = scan.nextInt();
        int ans=0;
        for(int i=0;i<=b;i++){
        	for(int n=0;n<=b;n++){
        		int f= a-i-n;
        		if(f<=b&&f>=0){
        			ans++;
        		}
        	}
        }
        System.out.println(ans);
	}
}
