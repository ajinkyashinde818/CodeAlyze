import java.util.Scanner;

class Main{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int d = sc.nextInt();
        int g = sc.nextInt();
        int[] pi = new int[d];
        int[] ci = new int[d];
        for(int i = 0; i < d; i++){
            pi[i] = sc.nextInt();
            ci[i] = sc.nextInt();
        }
        int min = 1000;
        for(int i = 0; i < (1 << d); i++){
            int csum = 0;
            int cpnsum = 0;
            int n = -1;
            for(int j = 0; j < d; j++){
                if((i >> j & 1) == 1){
                    csum += 100 * (j + 1) * pi[j] + ci[j];
                    cpnsum += pi[j];
                }else{
                    n = j;
                }
            }
            if(csum >= g){
                min = Math.min(min, cpnsum);
            }else{
                for(int j = 1; j <= pi[n] - 1; j++){
                    csum += 100 * (n + 1);
                    cpnsum++;
                    if(csum >= g){
                        min = Math.min(min, cpnsum);
                        break;
                    }
                }
            }
        }
        System.out.println(min);
    }
}
