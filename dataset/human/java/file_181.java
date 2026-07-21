import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();

        long val = 0;
        int[] V=new int[N];
        int negCount = 0;
        int absMin = Integer.MAX_VALUE;
        for (int i = 0; i < N; i++) {
            V[i]=sc.nextInt();
            if(V[i]<0){
                negCount++;
            }
            absMin=Math.min(absMin,Math.abs(V[i]));
            val +=Math.abs(V[i]);
        }

        if(negCount%2==0){
            System.out.println(val);
        }else{
            System.out.println(val - absMin*2);
        }

    }

}
