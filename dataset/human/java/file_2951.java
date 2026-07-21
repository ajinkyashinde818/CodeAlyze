import java.util.*;

class Main{
  public static void main(String[] args){
    Scanner sc=new Scanner(System.in);
    int n=sc.nextInt();
    int m=sc.nextInt();
    List<Integer>[] graph=new List[n];
    for(int i=0;i<n;i++){
      graph[i]=new LinkedList<Integer>();
    }
    for(int i=0;i<m;i++){
      int a=sc.nextInt()-1;
      int b=sc.nextInt()-1;
      graph[a].add(b);
      graph[b].add(a);
    }
    Deque<Integer> dq=new ArrayDeque<>();
    int[] dist=new int[n];
    Arrays.fill(dist,-1);
    dist[0]=0;
    dq.add(0);
    while(!dq.isEmpty()){
      int here=dq.pollFirst();
      for(int next:graph[here]){
        if(dist[next]==-1){
          dist[next]=dist[here]+1;
          if(dist[next]<2){
            dq.add(next);
          }
        }
      }
    }
    if(dist[n-1]==2){
      System.out.println("POSSIBLE");
    }else{
      System.out.println("IMPOSSIBLE");
    }
  }
}
