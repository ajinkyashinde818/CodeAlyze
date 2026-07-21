import java.io.FileNotFoundException;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) throws FileNotFoundException {

//    	File file = new File("src/in.txt");

        //コード
//    	Scanner sc = new Scanner(file);
    	Scanner sc = new Scanner(System.in);

    	int N = sc.nextInt();
    	int R = sc.nextInt();

    	if(N>9) {
    		System.out.println(R);
    	} else {
    		System.out.println(R+100*(10-N));
    	}


    }

}
