import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int k = sc.nextInt(); //総距離
		int n = sc.nextInt(); //n軒
		
      	int[] d = new int[n]; //格家の距離代入
		for(int i = 0;i < n; i++) {
			d[i] = sc.nextInt();
		}
      
      	int maxs =0;  //一番距離が離れている二軒の距離
      	for( int i = 1 ; i < n ; i++){
			int value = d[i] - d[i-1];
			if( maxs <= value ){
				maxs = value;
				}
        }
        
      	int last = k - d[n-1] + d[0];
       	if( maxs <= last ){
				maxs = last;
				}
      
		int ans = 0;//最短移動距離
      	ans = k - maxs ;
     
		System.out.println(ans);

		sc.close();
	}
}
