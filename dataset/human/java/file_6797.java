import java.util.*;

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int K = sc.nextInt();
        int N = sc.nextInt();
      	int temp[];
      	temp = new int[N];
      	int dist[];
      	dist = new int[N];
      	int result = 0;
      	for (int i=0; i<N; i++){
          temp[i] = sc.nextInt();
        }
   		dist[0] = temp[0];
      	for(int i=1; i<N; i++){
          dist[i] = temp[i]-temp[i-1];
        }
      	dist[0] += (K-temp[N-1]);
      	Arrays.sort(dist);
      	// result
      	for(int i=0; i<N-1; i++){
          result += dist[i];
        }
      	System.out.println(result);
    }
}
