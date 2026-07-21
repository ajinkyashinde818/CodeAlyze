import java.io.*;

public class Main {
	public static void main(String[] args) {
		BufferedReader r = new BufferedReader(new InputStreamReader(System.in));       
		try {
			String line;
			while((line=r.readLine())!=null){
				/* input from here */
				int n = Integer.parseInt(line);
				/* input till here */
				if(n==1||n==2){
					System.out.println(n);
					continue;
				}
				/* processing from here */
				int size=0,weight=4;
				if(n%2==1){
					size = 1;
					for(int i=3;i<=n;i+=2){
						size += weight;
						weight*= 3;
					}
				} else {
					size = 2;
					weight = 6;
					for(int i=4;i<=n;i+=2){
						size += weight;
						weight*= 3;
					}
				}
				/* processing till here */
				/* output */
				System.out.println(size);
			}
		} catch (IOException e) {
			e.printStackTrace();
		}
	}
}
