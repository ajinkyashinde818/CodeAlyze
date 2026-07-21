import java.util.*;

class Main{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int a = sc.nextInt();
        int b = sc.nextInt();
        int k = sc.nextInt();
        int maxAB = Math.max(a,b);
        int count = 0;
        int arrayCountAB = 0;

        for(int i = 1; i <= maxAB; i++){
            if(a % i == 0 && b % i == 0){
                count++;
            }
        }

        Integer[] divisorAB = new Integer[count];

        for(int i = 1; i <= maxAB; i++){
            if(a % i == 0 && b % i == 0){
                divisorAB[arrayCountAB] = i;
                arrayCountAB++;
            }
        }

        Arrays.sort(divisorAB,Collections.reverseOrder());

        System.out.println(divisorAB[k-1]);

    }
}
