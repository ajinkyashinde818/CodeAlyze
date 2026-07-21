public class Main{
  public void run(java.io.InputStream in, java.io.PrintStream out){
    java.util.Scanner sc = new java.util.Scanner(in);
    int i, j, sum, min, x;
    int[] a;
    int[][] l;

    a = new int[8]; l = new int[8][8]; min = 0; x = 0;
    l[0][0] = 1; l[0][1] = 2; l[0][2] = 1; l[0][3] = 2;
    l[0][4] = 1; l[0][5] = 4; l[0][6] = 1; l[0][7] = 4;
    for(i = 0;i < 8;i++)l[1][i] = l[0][(i + 2) % 8];
    for(i = 0;i < 8;i++)l[2][i] = l[0][(i + 6) % 8];
    for(i = 0;i < 8;i++)l[3][i] = l[0][(i + 4) % 8];
    for(j = 4;j < 8;j++)for(i = 0;i < 8;i++)l[j][i] = l[j - 4][(i + 1) % 8];

    for(;sc.hasNext();){
      for(i = 0;i < 8;i++){
        a[i] = sc.nextInt(); min += a[i];
      }
      for(i = 0;i < 8;i++){
        sum = 0;
        for(j = 0;j < 8;j++)if(a[j] > l[i][j])sum += (a[j] - l[i][j]);
        if(min > sum){ min = sum; x = i; }
      }
      for(i = 0;i < 7;i++)out.print(l[x][i] + " ");
      out.println(l[x][i]);
    }

    sc.close();
  }
  public static void main(String[] args){
    (new Main()).run(System.in, System.out);
  }
}
