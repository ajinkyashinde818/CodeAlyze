import java.util.Scanner;

public class Main {

    public static void main(String[] args) throws Exception {

//    	File file = new File("test.txt");
//    	Scanner sc = new Scanner(file);
    	Scanner sc = new Scanner(System.in);
    	int n = sc.nextInt();
    	int r = sc.nextInt();
    	sc.close();
    	if(10 <= n){
    		System.out.println(r);
    	}else{
    		System.out.println(r + (100*(10-n)));
    	}
    }
}
