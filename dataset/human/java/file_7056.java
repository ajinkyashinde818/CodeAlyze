import java.util.Scanner;

public class Main {
    public static void main(String[] args) {

        // 入力
        Scanner sc = new Scanner(System.in);
        int wayLength = sc.nextInt();
        int houseCnt = sc.nextInt();


        int[] place = new int[houseCnt];

        for(int index=0;index<houseCnt;index++){
            place[index] = sc.nextInt();
        }
        sc.close();
        // max計算
        int[] distance = new int[houseCnt];
        for(int i=0;i<houseCnt-1;i++){
            distance[i] = place[i+1] - place[i];
        }
        distance[houseCnt-1] = place[0] + (wayLength-place[houseCnt-1]);

        int max = distance[0];
        for (int ind=0;ind<houseCnt;ind++){
            if(max < distance[ind]){
                max = distance[ind];
            }
        }

        System.out.println(wayLength-max);
    }
}
