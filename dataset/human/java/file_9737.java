import java.util.*;


public class Main{ 

	public static void main(String args[]){
		Scanner scan = new Scanner(System.in);
		//int numNode = scan.nextInt();
		TreeNodeData data = new TreeNodeData(scan.nextInt());
		//scan.nextLine();
		data.readNodeData(scan);
		AbstractNode root = data.getNodeList();
		ArrayList<AbstractNode> tree = root.connectTree();
		Collections.sort(tree);
		for(int i=0; i<tree.size();i++)
			System.out.println(tree.get(i));

	}

}
enum NODETYPE{
	ROOT,INTERNAL,LEAF,LEFTCHILD,RIGHTCHILD
}
class NodeData{
	private int leftID;
	private int rightID;
	private ArrayList<Integer> children;
	private NODETYPE nodeType;
	public NodeData(int l, int r){
		leftID= l;
		rightID = r;
		if(l != -1 && r != -1)
			nodeType = NODETYPE.INTERNAL;
		else if(l == -1 && r == -1)
			nodeType = NODETYPE.LEAF;
		else if(r==-1)
			nodeType = NODETYPE.LEFTCHILD;
		else
			nodeType = NODETYPE.RIGHTCHILD;
	}
	public NODETYPE getType(){
		return nodeType;
	}
	public int getLeftID(){
		return leftID;
	}
	public int getRightID(){
		return rightID;
	}
	@Override
	public String toString(){
		StringBuilder temp = new StringBuilder();
		temp.append(leftID+", ");
		temp.append(rightID+", ");
		temp.append(nodeType+", ");
		return new String(temp);
	}
}

class TreeNodeData{
	int numNode;
	private HashMap<Integer, NodeData> nodeData = new HashMap<Integer, NodeData>();
	public TreeNodeData(int n){
		this.numNode = n;	
	}

	public void readNodeData(Scanner scan){
		for(int i=0; i<numNode; i++){
			int id = scan.nextInt();
			int left = scan.nextInt();
			int right = scan.nextInt();
			NodeData data = new NodeData(left, right);
			nodeData.put(id, data);
			///System.out.println(data);
		}
	}
	private int rootID(){
		ArrayList<Integer> notParent = new ArrayList<Integer>();
		for(int i=0; i<numNode; i++){
			notParent.add(nodeData.get(i).getLeftID());
			notParent.add(nodeData.get(i).getRightID());
		}
		for(int i=0; i<numNode; i++)
			if(!notParent.contains(i))
				return i;
		return -1;
	}
	public AbstractNode getNodeList(){
		return new AbstractNode(rootID(), nodeData);	
	}
}


// class Leaf extends AbstractNode{
// 	public Leaf(int n, HashMap<Integer, NodeData> nodeData){
// 		super(n, nodeData);
// 	}

// 	@Override 
// 	String getType(){
// 			return "leaf";
// 	}
// 	@Override 
// 	public int getDepth(){//(AbstractNode n){
// 			return parent.getDepth()+1;
// 	}
// 	@Override 
// 	public int getParentID(){
// 		return parent.getID();
// 	}
// }
// class Root extends AbstractNode{
// 	public Root(int n, HashMap<Integer, NodeData> nodeData){
// 		super(n, nodeData);
// 	}
// 	@Override 
// 	public int getDepth(){
// 		return 0;
// 	}
// 	@Override 
// 	String getType(){
// 			return "root";
// 	}
// 	@Override 
// 	public int getParentID(){
// 		return -1;
// 	}
// }
// class InternalNode extends AbstractNode{
// 	public InternalNode(int n, HashMap<Integer, NodeData> nodeData){
// 		super(n, nodeData);
// 	}

// 	@Override 
// 	int getDepth(){//(AbstractNode n){
// 			return parent.getDepth()+1;
// 	}
// 	@Override 
// 	String getType(){
// 			return "internal node";
// 	}
// 	@Override 
// 	public int getParentID(){
// 		return parent.getID();
// 	}
// }

// class NodeFactory{	
// 	static AbstractNode getInstance(int id, HashMap<Integer, NodeData> nodeData){
// 		NODETYPE t = nodeData.get(id).getType();
// 		if(t==NODETYPE.LEAF)
// 			return new Leaf(id ,nodeData);
// 		return new InternalNode(id ,nodeData);
// 	}
// }
class AbstractNode implements Comparable<AbstractNode>{
	protected int id;
	protected AbstractNode parent=null;
	protected ArrayList<AbstractNode> children = new ArrayList<AbstractNode>();
	protected AbstractNode LeftChild=null;
	protected AbstractNode RightChild=null;

	public AbstractNode(int id, HashMap<Integer, NodeData> nodeData){
		this.id = id;
		NodeData self = nodeData.get(id);
		if(self.getType()==NODETYPE.LEAF)
			return;
		if(self.getType()!=NODETYPE.RIGHTCHILD){
			AbstractNode temp = new AbstractNode(self.getLeftID(), nodeData);
			temp.setParent(this);
			this.LeftChild = temp;
		}
		if(self.getType()!=NODETYPE.LEFTCHILD){
			AbstractNode temp = new AbstractNode(self.getRightID(), nodeData);
			temp.setParent(this);
			this.RightChild = temp;
		}

	}
	int getDepth(){
		if(parent == null)
			return 0;
		return parent.getDepth()+1;
	}
	String getType(){
		if(parent == null)
			return "root";
		if(LeftChild==null && RightChild==null)
			return "leaf";
		else return "internal node";
	};
	public int getParentID(){
		if(parent == null)
			return -1;
		else
			return parent.getID();
	}
	public void addChild(AbstractNode c){
		children.add(c);
	}
	public int getID(){
		return id;
	}
	public void setParent(AbstractNode p){
		this.parent = p;
	}
	String childrenID(){
		StringBuilder temp = new StringBuilder();
		temp.append("[");
		if(children.size()>0)
		for(int i=0; ; i++){
			temp.append(children.get(i).getID());
			if( i == children.size() - 1 )
				break;
			temp.append(", ");
		}
		temp.append("]");
		return new String(temp);
	}
	public int getHeight(){
		int leftHeight=0;
		int rightHeight=0;
		if(LeftChild==null && RightChild==null)
			return 0;
		if(LeftChild!=null)
			leftHeight = LeftChild.getHeight();
		if(RightChild!=null)
			rightHeight = RightChild.getHeight();
		return Math.max(leftHeight, rightHeight) +1;

	}
	int getDegree(){
		int countDegree = 0;
		if(LeftChild!=null)
			countDegree++;
		if(RightChild!=null)
			countDegree++;	
		return countDegree;
	}
	public int getSiblingID(){
		if(parent!=null)
			return parent.getAnotherChild(this.id);
		return -1;
	}
	public int getAnotherChild(int id){
		if(LeftChild!=null && LeftChild.getID() == id)
			if(RightChild!=null)
				return RightChild.getID();
		if(RightChild!=null && RightChild.getID() == id)
			if(LeftChild!=null)
				return LeftChild.getID();
		return -1;
	}
	public void nodeInfomation(){
		System.out.println(this);
		for(int i=0; i< children.size();i++)
			children.get(i).nodeInfomation();
	}
	public ArrayList<AbstractNode> connectTree(){
		ArrayList<AbstractNode> temp = new ArrayList<AbstractNode>();
		temp.add(this);
		if(LeftChild!=null)
			temp.addAll(LeftChild.connectTree());
		if(RightChild!=null)
			temp.addAll(RightChild.connectTree());
		return 	temp;
	}
	@Override
	public String toString(){
		StringBuilder temp = new StringBuilder();
		temp.append("node " + this.id);
		temp.append(": parent = " + getParentID());
		temp.append(", sibling = " + getSiblingID());
		temp.append(", degree = " + getDegree());
		temp.append(", depth = " + getDepth());
		temp.append(", height = " + getHeight());
		temp.append(", "  + getType());
		//temp.append(", "   + childrenID());
		return new String(temp);
	}
	@Override
 	public int compareTo(AbstractNode temp) {
		return this.id - temp.getID();
	}
}
