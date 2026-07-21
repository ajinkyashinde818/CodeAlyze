import java.util.*;
class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int D = sc.nextInt();
        int G = sc.nextInt();
        int min = Integer.MAX_VALUE;
        int[] p = new int[D];
        int[] c = new int[D];

        for(int i = 0; i<D; i++) {
            p[i] =sc.nextInt();
            c[i] =sc.nextInt();
        }

        for(int i = 0; i<Math.pow(2,D); i++) {
            int maxIndex = 0;
            int num = i;
            int cnt = 0;
            int val = 0;
            int tmp = 0;
            while(cnt<D) {
                if(num % 2 == 1) {
                    val = val + p[cnt]*(cnt+1)*100+c[cnt];
                    tmp += p[cnt];
                }else {
                    maxIndex++;
                }
                num /= 2;
                cnt++;
            }
            maxIndex--;
            //System.out.println(i+ " " + val + " " +tmp+ " maxIndex " + maxIndex);
            if(val<G) {
                for(int j = 0; j<p[maxIndex]-1; j++) {
                    val += (maxIndex+1)*100;
                    tmp++;
                    //if(i==24) System.out.println(val+" " + tmp);
                    if(val>=G) break;
                }

            }

            if(val<G) continue;
            //System.out.println(i+ " " + val +" " +tmp +" " + min);
            min = Math.min(tmp, min);
        }

        System.out.println(min);
    }
}
