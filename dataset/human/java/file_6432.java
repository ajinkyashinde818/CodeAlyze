import java.util.Scanner;




public class Main {

    public static void main(String[] args) {

    	Main main=new Main();

    	main.run();

    }

    void run() {
    	Scanner sc=new Scanner(System.in);

    	int K=sc.nextInt();
    	int S=sc.nextInt();

    	int sum=0;

    	for(int x=0;x<=K;x++) {
    		for(int y=0;y<=K;y++) {
    			int z=S-(x+y);
    			
    			if(z>=0 && z<=K) {
    				sum++;
    			}
    		}
    	}
    	
    	
    	System.out.println(sum);
    }
}
