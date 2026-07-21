import java.util.Scanner;

class Main {
  public static void main(String[] args) {
    final Scanner sc = new Scanner(System.in);
    int k = sc.nextInt();
    int n = sc.nextInt();
    int[] dis = new int[n];
    for(int i = 0; i<n; i++){
      dis[i] = sc.nextInt();
    }
    
    int ans = 0;
    int max = dis[0] + k - dis[n-1];
	for(int j = 0; j < n-1; j++){
      if(dis[j+1] - dis[j]>max){
        max = dis[j+1] - dis[j];
      }
    }
    System.out.println(k-max);
  }
}
