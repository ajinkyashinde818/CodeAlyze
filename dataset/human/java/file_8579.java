import java.util.*;

class Main{
    public static void main(String[] args){

        Scanner sc = new Scanner(System.in);

        int A = sc.nextInt();
        int B = sc.nextInt();
        int n = sc.nextInt();

        int s = 0;
        int k= 0;
            for(int i=100;i>=0;i--){
                if((A%i==0)&&(B%i==0)){
                    s=i;     
                    k++;        
                    if(k==n){   
                        break;
                    }
                }
            }
            System.out.println(s); 
     }
}
