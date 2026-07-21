import java.util.Scanner;

public class Main{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int a = sc.nextInt();
        int t[] = new int[a];
        
        for(int i = 0; i < a; i++){
            t[i] = sc.nextInt();
        }
        for(int i = a; i> 0;i--){
            
            int count = 0;
            
            for(int j = 0; j<a;j++){   
                if(t[j] >= i){
                    count++;
                }
            }
            
            if(i <= count){
                System.out.println(i);
                break;
            }
                
        }
    }
}
