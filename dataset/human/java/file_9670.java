import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

  public static void main(String[] args) {
    
    new Main().run();
  }

  public void run() {

    try(BufferedReader br = new BufferedReader(new InputStreamReader(System.in))) {

      int n = Integer.parseInt(br.readLine());
      int id,left,right;
      String[] words;
      Tree tree = new Tree(n);

      for(int i=0,k=0; i<n; i++,k=0){
        words = br.readLine().split(" ");
        id = Integer.parseInt(words[k++]);
        left  = Integer.parseInt(words[k++]);
        right = Integer.parseInt(words[k++]);

        tree.nodeInit(id,left,right);
      }
      tree.treeInit();

      System.out.print(tree.dispTreeNode());
    }
    catch(IOException e) {
      System.out.println("IOException!");
    }
  }
}

class Tree {

  static final int NIL = -1;
  BTreeNode[] node;

  public Tree(int size) {
    node = new BTreeNode[size];
    for (int i=0; i < size; i++) {
      node[i] = new BTreeNode();
    }
  }

  void nodeInit(int id, int left, int right) {
    node[id].id = id;
    node[id].left = left;
    node[id].right = right;
    node[id].setDegree();
    setParent(id);
  }
  void treeInit() {
    int root=0;

    for (BTreeNode e : node) {
      setSibling(e.id);
      if(e.parent == Tree.NIL)
        root = e.id;
    }
    setDepth(root, 0);
    setHeight(root);
  }
  void setParent(int id) {
    if(node[id].left != Tree.NIL)
      node[ node[id].left ].parent = id;
    if(node[id].right != Tree.NIL)
      node[ node[id].right ].parent = id;
  }
  void setSibling(int id) {
    int p = node[id].parent;
    if( p != Tree.NIL) {
      node[id].sibling =
        node[p].left != node[id].id ? node[p].left : node[p].right;
    }
  }
  void setDepth(int u, int p) {
    node[u].setDepth(p);

    if( node[u].left != Tree.NIL )
      setDepth(node[u].left, p+1);
    if( node[u].right != Tree.NIL )
      setDepth(node[u].right, p+1);
  }
  int setHeight(int u) {
    int lH=0, rH=0;

    if( node[u].left != NIL )
      lH = setHeight(node[u].left ) + 1;
    if( node[u].right != NIL )
      rH = setHeight(node[u].right) + 1;
    node[u].setHeight( Math.max(lH, rH) );

    return node[u].getHeight() ;
  }

  public String dispTreeNode() {
    StringBuilder s = new StringBuilder();

    for (BTreeNode n : node)
      s.append(n).append("\n");

    return s.toString();
  }
}

class BTreeNode {
  int id,degree,parent,sibling;
  private int depth,height,type;
  int left,right;

  public BTreeNode() {
    this.id =
    this.degree =
    this.parent =
    this.sibling =
    this.left =
    this.right = Tree.NIL;
  }

  public int getHeight() {
    return height;
  }
  public String getType() {
    switch(type) {
      case 0:
        return "root";
      case 1:
        return "internal node";
      default:
        return "leaf";
    }
  }

  public void setDepth(int d) {
    depth = d;
    if(depth > 0) {
      if(degree > 0)
        setType(1);
      else
        setType(2);
    }
  }
  public void setDegree() {
    if( left == right )
      this.degree = 0;
    else if ((left == Tree.NIL) || (right == Tree.NIL))
      this.degree = 1;
    else
      this.degree = 2;
  }
  public void setHeight(int height) {
    this.height = height;
  }
  public void setType(int t) {
    this.type = t;
  }

  @Override
  public String toString() {
    return "node " + id + ": parent = " + parent + ", sibling = " + sibling
      + ", degree = " + degree + ", depth = " + depth + ", height = " + height +
      ", " + getType();
  }
}
