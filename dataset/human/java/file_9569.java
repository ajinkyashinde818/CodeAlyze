public class Main {
	public static void main(String[] args) {
		var sc = new java.util.Scanner(System.in);
		var N = sc.nextInt();
		var D = new int[N][];
		for(int i=0;i<N;i++) {
			D[i]=new int[2];
			D[i][0]=sc.nextInt();
			D[i][1]=sc.nextInt();
		}

		var cnt = 0;
		boolean ysFlg=false;
		for(int i=0;i<N;i++) {
			if(isZorome(D[i][0],D[i][1])) {
				cnt++;
			}else {
				cnt=0;
			}
			if(cnt>=3) {
				ysFlg=true;
				break;
			}
		}
		System.out.println((ysFlg)?"Yes":"No");


	}
	private static boolean isZorome(int a,int b) {
		return a==b;
	}
}
