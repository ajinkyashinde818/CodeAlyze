import java.util.*;

public class Main
{
	public static void main(String[] args)
	{
		Scanner sc = new Scanner(System.in);

		int n = sc.nextInt();
		int k = sc.nextInt();
		int s = sc.nextInt();

		if(s == 1e9){
			for(int i = 0 ; i < n ; i++){
				if(i < k){
					System.out.printf(""+s+" ");
				}else{
					System.out.printf(""+1+" ");
				}
			}
		}else{
			for(int i = 0 ; i < n ; i++){
				if(i < k){
					System.out.printf(""+s+" ");
				}else{
					System.out.printf(""+(int)1e9+" ");
				}
			}
		}

		System.out.println("");
	}

}
