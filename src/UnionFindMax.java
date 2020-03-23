
public class UnionFindMax {
    private  int[] max = new int[10];  // the max of node tree
    private  int[] roots = new int[10]; //the father node
    private  int[] points = new int[10];    //the node nums of tree

    public UnionFindMax(){
        for (int i = 0; i < roots.length; i++) {
            roots[i] = i;
        }
        for (int i = 0; i < points.length; i++) {
            points[i] = 1;
        }
        for (int i = 0; i < max.length; i++) {
            max[i] = i;
        }
    }

    public  int find(int a){
        return max[root(a)];
    }

    public  void union(int a, int b) {
        int rootA = root(a);
        int rootB = root(b);
        if (root(rootA) != root(rootB)) {
            if (points[rootA] < points[rootB]) {
                roots[rootA] = rootB;
                points[rootB] += points[rootA];
                if(max[rootA]> max[rootB]) max[rootB] = max[rootA];
            }
            if (points[rootB] <= points[rootA]) {
                roots[rootB] = rootA;
                points[rootA] += points[rootB];
                if(max[rootB]> max[rootA]) max[rootA] = max[rootB];
            }
        }
    }

    public  int root(int a) {
        while (roots[a] != a) {
            a = roots[a];
        }
        return a;
    }

    /**
    public static void main(String[] args) {
        UnionFindMax find = new UnionFindMax();
        find.union(1, 2);
        find.union(1, 4);
        find.union(4, 6);
        find.union(5, 2);
        System.out.println(find.find(2));
    }
    */
}
