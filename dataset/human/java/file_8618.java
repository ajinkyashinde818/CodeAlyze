import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
    	
    	//入力値の格納
        Scanner sc = new Scanner(System.in);

        int A = sc.nextInt();
        int B = sc.nextInt();
        int K = sc.nextInt();

        sc.close();

        //A<BとおいてAの数だけAとBの約数を求める
        ArrayList<Integer> factoringA = new ArrayList<>();
        ArrayList<Integer> factoringB = new ArrayList<>();

        if (A > B) {int temp = A; A=B; B = temp;}

        for(int n = 1; n < A+1 ; n++) {

            if(A % n == 0) {

                factoringA.add(n);
            }

            if(B % n == 0) {

                factoringB.add(n);
            }
        }

        //AとBの公約数のリスト
        List<Integer> commonDivisorList = new ArrayList<>();

        //Aの約数の数だけループさせる
        for (int a = 0; a < factoringA.size(); a++ ) {
        	
        	//上で求めたBの約数の数だけループさせる
            for (int b = 0; b < factoringB.size(); b++) {
            	
            	//a番目のAの約数がBの約数の内に存在するか総当りで求める、見つかったらcontinue
                if (factoringA.get(a).equals(factoringB.get(b))) {

                    commonDivisorList.add(factoringA.get(a));
                    continue;
                }
            }
        }
        //commonDivisorListは昇順 => -(-commonDivisorListの要素数 + K)番目が最大公約数からK番目に大きい数
        System.out.println(commonDivisorList.get(commonDivisorList.size() - K));

    }
}
