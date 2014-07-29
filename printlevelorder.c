

void printLevelOrder(BinaryTree *root) {
  if (!root) return;
  queue<BinaryTree*> currentLevel, nextLevel;
  currentLevel.push(root);
  while (!currentLevel.empty()) {
    BinaryTree *currNode = currentLevel.front();
    currentLevel.pop();
    if (currNode) {
      cout << currNode->data << " ";
      nextLevel.push(currNode->left);
      nextLevel.push(currNode->right);
    }
    if (currentLevel.empty()) {
      cout << endl;
      swap(currentLevel, nextLevel);
    }
  }
}
