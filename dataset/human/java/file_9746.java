import java.util.*;
import java.io.*;
import java.lang.*;
class Main{
  public static void main(String args[]){
    int id, l, r,root=0;
    StringBuilder build = new StringBuilder();
    Scanner sc = new Scanner(System.in);
    int n = sc.nextInt();
    Node node[] = new Node[n];

    for(int i = 0; i<n; i++){
      node[i] = new Node();
    }

    for(int i = 0; i<n; i++){
      id = sc.nextInt();
      l = sc.nextInt();
      r =  sc.nextInt();
      node[id].left = l;
      node[id].right = r;
      if(l != -1)node[l].parent = id;
      if(r != -1)node[r].parent = id;
    }

    for(int i = 0;i<n; i++){
      if(node[i].parent==-1)root = i;
    }
    setDepth(root,0,node);

    for(int i = 0 ; i < n; i++){
      build.append("node ").append(i).append(": parent = ").append(node[i].parent).append(", sibling = ").append(getSibling(i,node)).append(", degree = ").append(getDegree(i,node)).append(", depth = ").append(node[i].depth).append(", height = ").append(getHeight(i, node));
      if(node[i].parent==-1)build.append(", root\n");
      else if(node[i].right == -1 && node[i].left == -1)build.append(", leaf\n");
      else build.append(", internal node\n");
    }

    System.out.print(build);

  }

  static int getHeight(int u, Node node[]){
    int h1 = 0;
    int h2 = 0;
    if(node[u].right != -1)h1 = getHeight(node[u].right, node) +1;
    if(node[u].left != -1)h2 = getHeight(node[u].left, node) +1;

    return Math.max(h1,h2);
  }

  static void setDepth(int u,int d,Node node_d[]){
    if( u == -1)return;
    node_d[u].depth = d;
    setDepth(node_d[u].right,node_d[u].depth+1, node_d);
    setDepth(node_d[u].left, node_d[u].depth+1, node_d);
  }

  static int getSibling(int u, Node node[]){
    if(node[u].parent == -1)return (-1);
    if(node[node[u].parent].left != u && node[node[u].parent].left!=-1)return node[node[u].parent].left;
    if(node[node[u].parent].right != u && node[node[u].parent].right!=-1)return node[node[u].parent].right;
    return (-1);
  }

  static int getDegree(int u, Node node[]){
    int count=0;
    if(node[u].left != -1)count++;
    if(node[u].right != -1)count++;
    return count;
  }
}

class Node{
  int parent = -1;
  int left = -1;
  int right = -1;
  int depth = 0;
}
