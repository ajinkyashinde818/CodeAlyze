import java.util.*;
public class Main{
    public static void main(String[]args){
        Scanner sc=new Scanner(System.in);
        int K=sc.nextInt();
        int S=sc.nextInt();
        int X=0;
        int Y=0;
        int sum=0;
        for(int i=0;i<=K;i++){
            for(int j=0;j<=K;j++){
                
                    X=i;
                    Y=j;
                    int Z=S-(X+Y);
                    if((Z>=0)&&(Z<=K)){
                        sum=sum+1;
                    

                    }
                }
            }
            System.out.println(sum);
        }
       
        
    }
