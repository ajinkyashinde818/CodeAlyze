import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception {
        Scanner sc=new Scanner(System.in);
        int K=sc.nextInt();
        int N=sc.nextInt();
        int first=sc.nextInt();
        int before=first;
        int haba=-1;
        int next=0;
        
        for(int i=0;i<N-1;i++){
            next=sc.nextInt();
            if(haba<next-before){
                haba=next-before;
            }
            before=next;
        }
        
        if(first+K-next>haba){
            haba=first+K-next;
        }
        
        System.out.println(K-haba);
    }
}
