import java.util.*;
public class Main{
public static void main(String[]args){
Scanner sc=new Scanner(System.in);
  String n=sc.next();
  int m=sc.nextInt();
  Graph g=new Graph();
  for(int i=0;i<m;i++){
  g.add(sc.next(),sc.next());
  }
  System.out.println(g.isConnect("1",n)?"POSSIBLE":"IMPOSSIBLE");
}

}
class Graph {
	Map<String, ArrayList<String>> edge ;
	Map<String, Integer> vertex ;
	public Graph() {
		edge = new HashMap<String, ArrayList<String>>();
		vertex=new HashMap<String,Integer>();
	}
	public void add(String a, String b) {
		if (edge.containsKey(a)) {
			edge.get(a).add(b);
			vertex.put(a,vertex.get(a)+1);
		} else {
			ArrayList<String>cont=new ArrayList<>();
			cont.add(b);
			edge.put(a, cont);
			vertex.put(a,1);
		}
		if (edge.containsKey(b)) {
			edge.get(b).add(a);
			vertex.put(b,vertex.get(b)+1);
		} else {
			ArrayList<String>cont=new ArrayList<>();
			cont.add(a);
			edge.put(b, cont);
			vertex.put(b,1);
		}
	}
	public boolean isConnect(String a,String b) {
		if(!vertex.containsKey(a)||!vertex.containsKey(b))return false;
		Map<String,Boolean>check=new HashMap<String,Boolean>();
		ArrayList<String>queue=new ArrayList<>();
		check.put(a,false);
        
      ArrayList<String>cont=new ArrayList<>(edge.get(a));
      for(int i=0;i<cont.size();i++)if(!check.containsKey(cont.get(i))) {
					queue.add(cont.get(i));
					check.put(cont.get(i),false);
				}
      
      for(int i=0;i<queue.size();i++){
      	ArrayList<String>cont2=new ArrayList<>(edge.get(queue.get(i)));
        for(int j=0;j<cont2.size();j++)
        	check.put(cont2.get(j),false);
      }
		return check.containsKey(b);
	}
}
