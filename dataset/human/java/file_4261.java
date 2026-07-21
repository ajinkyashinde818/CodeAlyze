import java.util.Scanner;

public class Main{
    
    public static void main (String[] args){
        
        Scanner sc = new Scanner (System.in);
        
        int N = sc.nextInt();
        int [] order = new int [N];
        int [] manzoku = new int [N];
        int [] tsuika = new int [N];
        
        for (int index=0; index<N; index++){
            order[index]=sc.nextInt();
        }
        
        for (int index=0; index<N; index++){
            manzoku[index]=sc.nextInt();
        }
        
        for (int index=0; index<N-1; index++){
            tsuika[index]=sc.nextInt();
        }
        
        int total = 0;
        int lastNum = 0;
        
        for (int index=0; index<N; index++){
            int num = order[index]-1;
            total += manzoku [num];
            
            if (index!=0){
                if (lastNum == num-1){
                    total+=tsuika[lastNum];
                }
            }
            lastNum = num;
        }
        
        System.out.println(total);
    }
}
