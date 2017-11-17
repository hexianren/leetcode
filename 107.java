 public List<List<Integer>> levelOrderBottom(TreeNode root) {
        List<TreeNode> rootList = null;

        if (root != null) {
            rootList = new ArrayList<TreeNode>();
            rootList.add(root);
        }
        List<List<Integer>> result = levelOrder(rootList);
        return result;
    }

    private List<List<Integer>> levelOrder(List<TreeNode> level) {
        List<List<Integer>> result = null;
        List<TreeNode> nextLevel = new ArrayList<TreeNode>();
        if (level == null || level.isEmpty()) {
            result = new ArrayList<List<Integer>>();
            return result;
        }
        for (TreeNode node : level) {
           if (node != null) {
               if (node.left != null) {
                   nextLevel.add(node.left);
               }
               if (node.right != null) {
                   nextLevel.add(node.right);
               }
           }
        }

        result = levelOrder(nextLevel);
        if (result != null) {
            List<Integer> array = new ArrayList<Integer>();
            for (TreeNode node: level) {
                if (node != null) {
                    array.add(node.val);
                }
            }
            result.add(array);
        }
        return  result;
    }