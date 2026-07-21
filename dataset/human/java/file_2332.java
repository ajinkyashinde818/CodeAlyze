import java.util.*;


public class Main {

	Scanner sc = new Scanner(System.in);
	public static void main(String[] args) {
		new Main();
	}

	public Main(){
		new A().doIt();
	}
	public class A {
		Scanner sc = new Scanner(System.in);
		String ans(char ctr[],int a[]){
			String alf = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
			char[] alf2 = alf.toCharArray();
			for(int i = 0;i < ctr.length;i++){
				for(int j = 0;j < alf2.length;j++){
					if(ctr[i] == alf2[j]){
						ctr[i] = alf2[((j - a[i % a.length]) + 52) % 52];
						break;
					}
				}
			}
			String result = "";
			for(int i = 0;i < ctr.length;i++){
				result = result + ctr[i];
			}
			return result;
		}
		void doIt(){
			while(true){
				int n = sc.nextInt();
				if(n == 0)break;
				int a[] = new int[n];
				for(int i = 0;i < n;i++)a[i] = sc.nextInt();
				String str = sc.next();
				char ctr[] = str.toCharArray();
				System.out.println(ans(ctr,a));
			}
		}		
	}
}
