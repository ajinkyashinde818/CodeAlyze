import java.util.Scanner;
//import java.util.Arrays;
public class Main{
	public static void main(String[] args){
		Scanner scan = new Scanner(System.in);
		int k = scan.nextInt();
		int s = scan.nextInt();
		int count = 0;
		for(int x=0; x<=k; x++){
			for(int y=0; y<=k; y++){
				if(s - x - y <= k && 0 <= s-x-y){
					count++;
				}
			}
		}
		System.out.println(count);
	}
}
