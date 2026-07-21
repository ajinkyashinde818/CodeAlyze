import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

class Main {

	public static void main(String[] args) throws IOException{
		BufferedReader in=new BufferedReader(new InputStreamReader(System.in));
		
		StringTokenizer skt=new StringTokenizer(in.readLine());
		
		int k=Integer.parseInt(skt.nextToken());
		int n=Integer.parseInt(skt.nextToken());
		
		skt=new StringTokenizer(in.readLine());
		
		int[] houses=new int[n];
		
		
		for (int i = 0; i < houses.length; i++) {
			houses[i]=Integer.parseInt(skt.nextToken());
		}
		
		int min=Math.min((houses[houses.length-1]-houses[0]), houses[0]+(k-houses[1]));
		for (int i = 1; i < houses.length-1; i++) {
			min=Math.min(Math.min(k-houses[i]+houses[i-1],houses[i]+(k-houses[i+1])), min);
			
		}
		
		System.out.println(min);
		
		

	}

}
