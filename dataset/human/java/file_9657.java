import java.util.*;
public class Main {

	public static void main(String[] args) {
		// TODO 自動生成されたメソッド・スタブ
		Scanner sc= new Scanner(System.in);
		
		int N= sc.nextInt();
		
		int cnt= 0;
		for(int i=0;i<N;i++){
			
			int a= sc.nextInt();
			int b= sc.nextInt();
			
			if(a == b){
				cnt++;
				if(cnt == 3){
					System.out.println("Yes");
					break;
				}
			}
			else cnt=0;
			
			if(i == N-1)System.out.println("No");
			
		}
		
		
		sc.close();
	}
	
	
	

}
