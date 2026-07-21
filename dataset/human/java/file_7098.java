import java.io.*;

public class Main {
  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    
    String[] line1 = br.readLine().split(" ");
    int k = Integer.parseInt(line1[0]);
    int n = Integer.parseInt(line1[1]);
    
    String[] data = br.readLine().split(" ");
    int[] an = new int[n];
    for (int i=0; i<n; i++){
      an[i] = Integer.parseInt(data[i]);
    }
    int maxDistance = k-(an[n-1]-an[0]);
    for (int i=1; i<n; i++){
      int i1 = an[i] - an[i - 1];
      if (maxDistance< i1){
        maxDistance = i1;
      }
    }
    System.out.println(k-maxDistance);
  }
}
