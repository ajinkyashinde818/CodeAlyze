import java.util.*;

abstract class Elt {

	private int id;
	private Elt parent,left,right;
	
	//Constructor
	public Elt(int id){this.id = id;}
	
	//getter,setter
	public int getId() {return id;}

	public Elt getParent() {return parent;}
	public void setParent(Elt parent) {this.parent = parent;}
	
	public Elt getLeft() {return left;}
	public void setLeft(Elt left) {this.left = left;}
	
	public Elt getRigth() {return right;}
	public void setRigth(Elt rigth) {this.right = rigth;}
}

class Element extends Elt implements Comparable<Element>{

	public int parent,sibling,left,right,degree,height,depth;
	public String type;
	
	public Element(int id){super(id);}

	public String toString(){
		return "node " + getId() + ": parent = " + parent + ", sibling = " + sibling + ", degree = " + degree + ", depth = " + depth +", height = " + height + ", " + type;
	}

	public int compareTo (Element e){
		return this.getId() - e.getId();
	}
}

public class Main {

	public static final int    ROOT      = -1;
	public static final int    EMPTY     = -1;
	public static final String ROOT_TYPE = "root";
	public static final String NODE_TYPE = "internal node";
	public static final String LEAF_TYPE = "leaf";
	
	private static ArrayList<Element> tree = new ArrayList<Element>();

    public static void main(String[] args) {

    	input();

    	//edit
    	set_2();
    	set_3();
    	set_4();
    	set_5();
    	set_7();
    	set_6();
    	
    	//sort by id.
    	Collections.sort(tree);

    	output();
    }

	private static void input() {
    	Scanner sc = new Scanner(System.in).useDelimiter(System.getProperty("line.separator"));
    	int N = sc.nextInt();

    	String[] s = null;
    	Element  e = null;
        for(int i = 0; i < N; i++){
        	s = sc.next().split("\\s");
        	e = new Element(Integer.parseInt(s[0]));
        	e.left  = Integer.parseInt(s[1]);
        	e.right = Integer.parseInt(s[2]);
        	e.height = EMPTY; //?????????
        	tree.add(e);
        }
	}

	private static void set_2(){
		int tree_size = tree.size();
		for(int i = 0; i < tree_size; i++){
			Element child = tree.get(i);
			Element parent = get_parent(child);
			if(parent == null){
				child.parent = ROOT;
				continue;
			}
			child.parent =  parent.getId();
		}
	}

	private static Element get_parent(Element child){
		Element ret   = null;
		for(Element parent:tree){
			if(child.getId() == parent.getId()){continue;}
			if(child.getId() == parent.left || child.getId() == parent.right){
				ret = parent;
			}
		}
		return ret;
	}

	private static void set_3(){
		Element sibling = null;
		int tree_size = tree.size();
		for(int i = 0; i<tree_size; i++){
			sibling = get_sibling(i);
			if(sibling == null){
				tree.get(i).sibling = EMPTY;
				continue;
			}
			tree.get(i).sibling = sibling.getId();
		}
	}

	private static Element get_sibling(int index){
		Element  child = tree.get(index),
		        parent = get_parent(child),
		        ret    = null;

		if(parent == null){return ret;}

		for(Element e:tree){
			if(parent.left  == child.getId() && parent.right == e.getId()){ret = e;}
			if(parent.right == child.getId() && parent.left  == e.getId()){ret = e;}
		}
		return ret;
	}

	private static void set_4(){
		int size = tree.size();
		for(int i=0;i<size;i++){
			set_degree(i);
		}
	}

	private static void set_degree(int index){
		Element e = tree.get(index);
		int cnt = 0;
		if(e.right != EMPTY){cnt++;}
		if(e.left != EMPTY){cnt++;}
		e.degree = cnt;
	}

	private static void set_5(){
		for(int i=0;i<tree.size();i++){
			tree.get(i).depth=calc_depth(i);
		}
	}
	private static int calc_depth(int i){
		int depth = 0;
		Element e = tree.get(i);
		for(int id=e.getId();;depth++){
			id=searchParent(id);
			if(id==-2){System.err.println("parent search error");}
			if(id==ROOT){break;}
		}
		return depth;
	}

	private static int searchParent(int id){
		for(Element e:tree){
			if(id==e.getId()){return e.parent;}
		}
		return -2;
	}

	private static void set_6(){
		for(Element e:tree){
			if(e.right == EMPTY && e.left == EMPTY){
				for(int height = 0;e.height == EMPTY || e.height < height;height++){
					e.height = height;
					e = get_parent(e);
					if(e == null){break;}
				}
			}
		}
	}

	private static void set_7(){
		for(Element e:tree){
			if(e.parent==ROOT){e.type=ROOT_TYPE;}
			if(e.parent!=ROOT && (e.right!=EMPTY || e.left!=EMPTY)){e.type=NODE_TYPE;}
			if(e.parent!=ROOT && (e.right==EMPTY && e.left==EMPTY)){e.type=LEAF_TYPE;}
		}
	}

	private static void output(){
		for(Element e:tree){
			System.out.println(e);
		}
	}
}
