import java.util.Scanner;

class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		int D = Integer.parseInt(sc.next());
		int G = Integer.parseInt(sc.next());
		int[][] arr  = new int [D][3];

		for(int i=0;i<D;i++) {
			arr[i][0] = Integer.parseInt(sc.next());
			arr[i][1] = Integer.parseInt(sc.next());
			arr[i][2] = arr[i][0]*100*(i+1) +arr[i][1];
		}
		int totalQueMin = Integer.MAX_VALUE;

		for(int i=0;i<1<<D;i++) {
			int totalQue = 0;
			int totalPoint = 0;
			boolean[] arrFlg = new boolean[D];
			for(boolean a:arrFlg) a = false;
			for(int j=0;j<D;j++) {
				if((1& i>>j) == 1) {
					totalQue += arr[j][0];
					totalPoint += (arr[j][1] + 100*(j+1)*arr[j][0]);
//					System.out.print("1");
					arrFlg[j] = true;
				} else {
//					System.out.print("0");
				}
			}
			label:while(totalPoint < G) {
				for(int m=D; m > 0; m--) {
					if(!arrFlg[m-1]) {
						int aa = m-1;
						for(int n=0;n<arr[aa][0];n++) {
							totalPoint += 100*(m);
							totalQue++;
							if(totalPoint >= G) break label;
						}
						totalPoint += arr[m-1][1];
							if(totalPoint >= G) break label;
					}
				}
			}

//			System.out.println("-----------------");
//			System.out.print(totalQue+ "  ");
//			System.out.println(totalPoint);
			totalQueMin = Math.min(totalQueMin, totalQue);
		}
		System.out.println(totalQueMin);


	}
}
