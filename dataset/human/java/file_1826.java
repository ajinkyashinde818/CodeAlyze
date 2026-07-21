import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int d = Integer.parseInt(sc.next());
        int g = Integer.parseInt(sc.next());
        int[] p = new int[d];
        int[] c = new int[d];
        for(int i=0;i<d;i++){
            p[i] = Integer.parseInt(sc.next());
            c[i] = Integer.parseInt(sc.next());
        }
        sc.close();
        int sum;
        int minval = Integer.MAX_VALUE;
        int count,index = -1;
        for(int i=0;i<1<<d;i++){
            sum = count = 0;
            index = -1;
            for(int j=0;j<d;j++){
                if(((i>>d-1-j)&1)==1){
                    sum+=p[j]*100*(j+1)+c[j];
                    count+=p[j];
                }else{
                    index = j;
                }
            }
            if(sum<g && index>=0){
                int point = 100*(index+1);
                int need = (g-sum+point-1)/point;
                if(need >= p[index]){
                    continue;
                }else{
                    count+=need;
                }
            }
            minval = Math.min(count,minval);
        }
        System.out.println(minval);
    }

}
