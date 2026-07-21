import java.util.Scanner;

public class Main {

    public static void main(String[] args) throws Exception {

//    	File file = new File("test.txt");
//    	Scanner sc = new Scanner(file);
    	Scanner sc = new Scanner(System.in);
    	int X = sc.nextInt();
    	int Y = sc.nextInt();
    	int Z = sc.nextInt();
    	sc.close();
    	int[] ary = new int[Z];
    	int min = X <= Y ? X : Y;
    	for(int i = min; i > 0; i--){
    		if(X % i == 0 && Y % i == 0){
    			ary[Z-1] = i;
    			Z--;
    		}
    		if(Z <= 0) break;
    	}
    	System.out.println(ary[0]);
    }
}
