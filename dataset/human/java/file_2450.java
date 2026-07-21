import java.util.Scanner;
public class Main{
	public static void main(String[] args){
        new Main().run();
    }
	public void run(){
		Scanner scan = new Scanner(System.in);
		char[] ch = {'m','c','x','i'};
		while(scan.hasNext()){
			int n = scan.nextInt();
			for(int i = 0;i < n;i++){
				String str = scan.next() + scan.next();
				int a = 1;
				int[] sum = new int[4];
				int t;
				for(int j = 0;j < str.length();j++){
					t = str.charAt(j) - '0';
					if(t < 10){
						a = t;
					}else if(t == 61){
						sum[0] += a;
						a = 1;
					}else if(t == 51){
						sum[1] += a;
						a = 1;
					}else if(t == 72){
						sum[2] += a;
						a = 1;
					}else if(t == 57){
						sum[3] += a;
						a = 1;
					}
				}
				if(sum[3] > 9){
					sum[2]++;
					sum[3] -= 10;
				}
				if(sum[2] > 9){
					sum[1]++;
					sum[2] -= 10;
				}
				if(sum[1] > 9){
					sum[0]++;
					sum[1] -= 10;
				}
				str = "";
				for(int j = 0;j < 4;j++){
					if(sum[j] > 1){
						str += sum[j] + "" + ch[j];
					}else if(sum[j] > 0){
						str += ch[j];
					}
				}
				System.out.println(str);
			}
		}
	}
}
