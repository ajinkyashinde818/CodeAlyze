import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception {
        Scanner sc=new Scanner(System.in);
        
        int k=sc.nextInt();
        int s=sc.nextInt();
        int z;
        int count=0;
        for(int x=0; x<=k; x++){
            for(int y=0; y<=k; y++){
                z=s-x-y;
                if(0<=z && z<=k){
                    count+=1;
                }
            }
        }
        System.out.println(count);
    }
}
