import java.util.Scanner;


class Node{
  Node parent = null;
  Node left = null;
  Node right = null;
  int id;

  void printInfo(){
    System.out.print("node " + id + ": ");
    System.out.print("parent = " + this.getParentID() + ", ");
    System.out.print("sibling = " + this.getSiblingID() + ", ");
    System.out.print("degree = " + this.getDegree() + ", ");
    System.out.print("depth = " + this.getDepth() + ", ");
    System.out.print("height = " + this.getHeight(0) + ", ");
    System.out.println(this.getType());
  }

  int getParentID(){
    if(parent == null)
      return -1;
    else
      return parent.id;
  }

  int getSiblingID(){
    if(parent == null)
      return -1;
    else{
      if(this == parent.left && parent.right != null)
        return parent.right.id;
      else if(this == parent.right && parent.left != null)
        return parent.left.id;
      else
        return -1;
    }
  }

  int getDegree(){
    int deg = 0;
    if(left != null)deg++;
    if(right != null)deg++;
    return deg;
  }

  int getDepth(){
    int depth = 0;
    Node u = this;
    while(u.parent != null){
      depth++;
      u = u.parent;
    }
    return depth;
  }

  int getHeight(int h){
    if(this.left == null && this.right == null)
      return h;
    else{
      int h1 = 0;
      int h2 = 0;
      if(left != null)
        h1 = left.getHeight(h+1);
      if(right != null)
        h2 = right.getHeight(h+1);
      return (h1 > h2) ? h1 : h2;
    }
  }

  String getType(){
    if(parent == null)
      return "root";
    else if(left == null && right == null)
      return "leaf";
    else
      return "internal node";
  }
}

class Main{
  public static void main(String[] args){
    Scanner stdIn = new Scanner(System.in);
    int n = stdIn.nextInt();
    Node[] node = new Node[n];

    for(int i = 0; i < n; i++)
      node[i] = new Node();

    for(int i = 0; i < n; i++){
      int id = stdIn.nextInt();
      int leftid = stdIn.nextInt();
      int rightid = stdIn.nextInt();
      node[id].id = id;
      if(leftid != -1){
        node[id].left = node[leftid];
        node[leftid].parent = node[id];
      }
      if(rightid != -1){
        node[id].right = node[rightid];
        node[rightid].parent = node[id];
      }
    }
    for(int i = 0; i < n; i++)
      node[i].printInfo();
  }
}
