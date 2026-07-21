import java.util.*;
class Main{
    Scanner sc=new Scanner(System.in);
    void main(){
	int sum=0;
	for(int i=0;i<10;i++){
	    sum+=sc.nextInt();
	}
	System.out.println(sum);
	
    }
    public static void main(String[]ag){
	new Main().main();
    }
}
