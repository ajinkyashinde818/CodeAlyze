import java.util.Scanner;

public class Main{
    public static void main(String[] args){
	Scanner sc = new Scanner(System.in);
	long A = sc.nextLong();
	long B = sc.nextLong();
        
	for(int i=1;i<=B;i++){
	    if((i*A)%B==0){
		System.out.print(i*A);
		break;
	    }
	}
    }
}
