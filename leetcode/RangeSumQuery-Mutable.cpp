class NumArray {
    
    private:
    struct TreeNode {
        int val;
        int start;
        int end;
        TreeNode(int v, int s, int e): val(v), start(s), end(e){}
        TreeNode(){}
    };
    
    int n;
    vector<int> nums;
    TreeNode *tree;
    
    int get_sum(int i, int j, int k) {

      if (k >= n*4) {
        return 0;
      }

      TreeNode root = tree[k];

      if (i <= root.start && root.end <= j) {
        return root.val;
      }
      
      int li = 2*k;
      int ri = 2*k + 1;
      
      int leftSum = 0;
      if (li < 4*n) {
          if (tree[li].end >= i) {
             leftSum = get_sum(i,j, 2*k);
          }
      }
      
      int rightSum = 0;
      if (ri < 4*n) {
          if (tree[ri].start <= j) {
              rightSum = get_sum(i,j,2*k +1);
          }
      }
      
      return leftSum + rightSum;
    }
public:

    NumArray(vector<int> &nums) {
        this->nums = vector<int>(nums);
        n = (int)nums.size();
        
        if (n != 0){
            tree = new TreeNode[4*n];
            build_tree(1, 0, n-1);
            if (n < 15)
                print_tree();
        }
    }

    void build_tree(int k, int start, int end) {
        if (k >= 4*n) {
            return;
        }
        
      if (start == end) {
        tree[k].val = nums[start];
        tree[k].start = start;
        tree[k].end = end;
      } else {
        int mid = floor((start + end) /2);
        build_tree(2*k, start, mid);
        build_tree(2*k + 1, mid+1, end);
        tree[k].val = tree[2*k].val + tree[2*k+1].val;
        tree[k].start = tree[2*k].start;
        tree[k].end = tree[2*k+1].end;
      }
    }

    void print_tree() {
        for (int i = 1; i < 4*n; ++i) {
          cout << "["<< i << "] " << tree[i].val << "(" << tree[i].start << "," << tree[i].end << ")" << endl;
        }
    }
    
    void update_internal(int k, int start, int end, int i, int val) {
        if (k >= 4*n) {
            return;
        }
        
        if (start == end) {
            tree[k].val = val;
        } else {
            int mid = floor((start + end) /2);
            if (i <= mid) {
                update_internal(2*k, start, mid, i, val);
            } else {
                update_internal(2*k+1, mid+1, end, i, val);
            }
            tree[k].val = tree[2*k].val + tree[2*k+1].val;
        }
    }
    void update(int i, int val) {
        update_internal(1, 0, n-1, i, val);
    }

    int sumRange(int i, int j) {
       return get_sum(i, j, 1);
    }
};