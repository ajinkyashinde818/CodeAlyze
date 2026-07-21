import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int D = sc.nextInt();
        int G = sc.nextInt();
        int[] problemCnt = new int[D];
        int[] perfectScr = new int[D];
        for(int i=0;i<D;i++){
            problemCnt[i] = sc.nextInt();
            perfectScr[i] = sc.nextInt() + ((i+1) * problemCnt[i] * 100);
        }
        sc.close();
        int minCnt = Integer.MAX_VALUE;
        for(int bit=0; bit < 1 << D; bit++){
            int score = 0;
            int count = 0;
            for(int i=0;i<D;i++){
                if((bit & (1 << i)) > 0) continue;
                score += perfectScr[i];
                count += problemCnt[i];
            }
            if(score<G){
                for(int i=D-1;i>=0;i--){
                    if((bit & (1 << i)) == 0) continue;
                    for(int j = 0; j < problemCnt[i]; j++){
                        if(score >= G)break;
                        score += (i+1) * 100;
                        count++;
                    }
                }
            }
            minCnt = Math.min(minCnt, count);
        }
        System.out.println(minCnt);

    }

}
