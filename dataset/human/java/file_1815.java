import java.util.*;

public class Main {

  public static void main (String[] args) {

    Scanner sc = new Scanner(System.in);

    int D = sc.nextInt();
    int G = sc.nextInt();
    int[] p = new int[D];
    int[] c = new int[D];

    for (int i = 0; i < D; i++) {
      p[i] = sc.nextInt();
      c[i] = sc.nextInt();
    }

    sc.close();

    int ans = Integer.MAX_VALUE;

    for (int i = 0; i < (1 << D); i++) {

      List<Integer> list = new ArrayList<>();

      for (int j = 0; j < D; j++) {
      
        if ((i >> j & 1) == 1) {
          list.add(c[j]);
        } else {
          list.add(0);
        }
      
      }

      int current = 0;
      int score = 0;
      int line = G;

      for(int j = 0; j < list.size(); j++) {

        int v = list.get(j);

        if (v != 0) {
          int score_ = (j+1) * 100;
          score += p[j] * score_ + v;
          current += p[j];
        }

      }
      line -= score;

      boolean canFinish = true;

      if (line < 0){
        ans = Math.min(ans, current);
      } else {
        int count2_ = D - 1;
        int score2_ = D * 100;
        int limit_ = 0;
        if(list.get(count2_) == 0) {
          limit_ = p[count2_];
        }
        while (0 < line) {
          if (0 < limit_) {
            line -= score2_;
            limit_--;
            current++;
          } else {
            count2_--;
            if (count2_ < 0) {
              line = 0;
              canFinish = false;
            }else {
              if(list.get(count2_) == 0) {
                limit_ = p[count2_];
              }
            }
            score2_ = (count2_+1) * 100;
          }
        }
        if (canFinish == true) {
          ans = Math.min(ans, current);
        }
      }

    }

    System.out.println(ans);

  }

}
