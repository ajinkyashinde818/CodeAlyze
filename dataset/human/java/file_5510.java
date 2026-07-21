import java.util.Scanner;

public class Main {

    public static void main(String[] args) {

    	Main main=new Main();

    	main.run();

    }

    void run() {

    	Scanner sc=new Scanner(System.in);

    	int X=sc.nextInt();

    	if(X>=1200) {
    		System.out.println("ARC");
    	}else {
    		System.out.println("ABC");
    	}
    }
}
