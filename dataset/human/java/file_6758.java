import java.util.*;
class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
	int K = sc.nextInt();
    int N = sc.nextInt();
    sc.nextLine();
    int[] houses = Arrays.stream(sc.nextLine().split(" "))
      .mapToInt(Integer::parseInt).toArray();
    int maxDistance = houses[0] + (K-houses[N-1]);
    for (int i = 1; i < N; i++) {
      maxDistance = Math.max(maxDistance, houses[i] - houses[i-1]);
    }
    System.out.println(K - maxDistance);
  }
}
