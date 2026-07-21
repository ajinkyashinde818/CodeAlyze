import java.util.Scanner;

public class Main {
	public static void main(String args[]){
		Scanner scanner = new Scanner(System.in);
		
		int n = scanner.nextInt();
		int sum = scanner.nextInt();
		int count = 0;
		
		int i = 0 , j = 0 , k = 0; 
		for(i = 0; i<=n ; i++){
			for(j = 0 ; j<=n ; j++){
				for(k = 0 ; k<=n ; k++){
					if(i+j+k<=sum){
						k = Math.min(n, sum-i-j);
						if(i+j+k<=sum){
							j = Math.min(n, sum-i-k);
							if(i+j+k<=sum){
								i = Math.min(n, sum-j-k);
							}
						}
					}else{
						break;
					}
					
					if( (i+j+k)==sum ) count++;
					//System.out.println("i="+i+" ,j="+j+" ,k="+k+" ,count="+count);
				}
			}
		}
		
		System.out.println(count);
	}
}
