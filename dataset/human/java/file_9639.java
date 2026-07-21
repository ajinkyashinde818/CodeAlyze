import java.util.*; 
import java.lang.*; 


public class Main{
    
	public static void main(String[] args){
		Scanner scan = new Scanner(System.in);
                
                int N = scan.nextInt();
                
                int cnt = 0;
                for(int i=0; i<N; i++){
                    int a = scan.nextInt();
                    int b = scan.nextInt();
                    
                    if(a==b){
                        cnt++;
                    }else{
                        cnt=0;
                    }
                    
                    if(cnt==3){
                        System.out.println("Yes");
                        System.exit(0);
                    }
                }
                
                System.out.println("No");

        }
}
