#ifndef binaryTree_h
#define binaryTree_h

#include <iostream>
#include <queue>
#include <stack>

template<typename T>
class binTree {
public:
    binTree ()
        : root(nullptr) {}
    binTree (const binTree& rhs)
        : root(nullptr)
    {
        if (rhs.root != nullptr) {
            root = new treeNode(rhs.root->data, cloneTreeNode(rhs.root->left), cloneTreeNode(rhs.root->right));
        }
    }
    binTree (binTree&& rhs) noexcept
        : root(std::move(rhs.root))
    {
        rhs.root = nullptr;
    }
    binTree& operator= (const binTree& rhs) {
        binTree temp = rhs;
        std::swap(temp, *this);
        return *this;
    }
    binTree& operator= (binTree&& rhs) noexcept {
        std::swap(root, rhs.root);
        return *this;
    }
    virtual ~binTree() {
        clearTree(root);
        root = nullptr;
    }
    bool isEmpty() {
        return (root == nullptr);
    }
    virtual void insert(const T& x) {
        treeNode* temp = new treeNode(x);
        insertUtil(temp);
    }
    virtual void insert(T&& x) {
        treeNode* temp = new treeNode(std::move(x));
        insertUtil(temp);
    }
    // level order traversal
    void printTree() {
        if (root == nullptr)
            return;
        std::queue<treeNode*> tempQ;
        tempQ.push(root);
        tempQ.push(nullptr);
        while(! tempQ.empty()) {
            treeNode* temp = tempQ.front();
            tempQ.pop();
            if (temp != nullptr) {
                std::cout << temp->data << " ";
                if (temp->left != nullptr)
                    tempQ.push(temp->left);
                if (temp->right != nullptr)
                    tempQ.push(temp->right);
            }
            else {
                std::cout << std::endl;
                if (tempQ.size() != 0)
                    tempQ.push(nullptr);
            }
        }
        std::cout << std::endl;
    }
    void inorderTraverse() {
        if (root == nullptr)
            return;
        inorderTraverseUtil(root);
        std::cout << std::endl;
    }
    void inorderTraverseItr() {
        if (root == nullptr)
            return;
        treeNode* temp = nullptr;
        std::stack<treeNode*> tempStk;
        tempStk.push(root);
        while(! tempStk.empty()) {
            temp = tempStk.top();
            if (temp->left != nullptr) {
                tempStk.push(temp->left);
                continue;
            }
            std::cout << temp->data << " ";
            tempStk.pop();
            while (temp->right == nullptr && !tempStk.empty()) {
                temp = tempStk.top();
                std::cout << temp->data << " ";
                tempStk.pop();
            }
            if (temp->right != nullptr)
                tempStk.push(temp->right);
        }
        std::cout << std::endl;
    }
    void preorderTraverse() {
        preorderTraverseUtil(root);
        std::cout << std::endl;
    }
    void preorderTraverseItr() {
        if (root == nullptr)
            return;
        treeNode* temp = nullptr;
        std::stack<treeNode*> tempStk;
        tempStk.push(root);
        while (!tempStk.empty()) {
            // process root
            temp = tempStk.top();
            tempStk.pop();
            std::cout << temp->data << " ";
            // push right first so that it will be processed later
            if (temp->right != nullptr)
                tempStk.push(temp->right);
            if (temp->left != nullptr)
                tempStk.push(temp->left);
        }
        std::cout << std::endl;
    }
    void postorderTraverse() {
        postorderTraverseUtil(root);
        std::cout << std::endl;
    }
    void postorderTraverseItr() {
        if (root == nullptr)
            return;
        std::stack<treeNode*> tempStk;
        std::stack<treeNode*> nodeStk;
        tempStk.push(root);
        treeNode* temp(nullptr);
        while (! tempStk.empty()) {
            temp = tempStk.top();
            tempStk.pop();
            nodeStk.push(temp);
            // push left child first so that it will be processed later
            //      and thus put on top in second stack
            if (temp->left != nullptr)
                tempStk.push(temp->left);
            if (temp->right != nullptr)
                tempStk.push(temp->right);
        }
        while (! nodeStk.empty()) {
            std::cout << nodeStk.top()->data << " ";
            nodeStk.pop();
        }
        std::cout << std::endl;
    }
    void diagonalTraverse() {
        if (root == nullptr)
            return;
        std::queue<treeNode*> tempQ;
        tempQ.push(root);
        treeNode* temp(nullptr);
        while (! tempQ.empty()) {
            temp = tempQ.front();
            tempQ.pop();
            while (temp != nullptr) {
                std::cout << temp->data << " ";
                if (temp->left != nullptr)
                    tempQ.push(temp->left);
                temp = temp->right;
            }
        }
        std::cout << std::endl;
    }
    void density() {
        
    }
    void printAncestor (const T& x) {
        printAncestorUtil(root, x);
    }
    void mirror() {
        mirrorUtil(root);
    }
    int getHeight() {
        return getHeightUtil(root);
    }
    int getDiameter() {
        int treeDia(0);
        getDiameterUtil(root, &treeDia);
        return treeDia;
    }
    virtual void remove(const T& x) {
        if (root == nullptr)
            return;
        std::queue<treeNode*> tempQ;
        tempQ.push(root);
        treeNode *itr(nullptr), *keyNode(nullptr);
        while(! tempQ.empty()) {
            itr = tempQ.front();
            tempQ.pop();
            if (itr->data == x)
                keyNode = itr;
            if (itr->left != nullptr)
                tempQ.push(itr->left);
            if (itr->right != nullptr)
                tempQ.push(itr->right);
        }
        // itr pointing to a leaf and tempQ is empty
        if (keyNode != nullptr) {
            keyNode->data = itr->data;
            if (root == itr) {
                delete itr;
                root = nullptr;
            }
            else {
                tempQ.push(root);
                treeNode* temp(nullptr);
                while(! tempQ.empty()) {
                    temp = tempQ.front();
                    tempQ.pop();
                    if (temp->left != nullptr) {
                        if (temp->left == itr) {
                            temp->left = nullptr;
                            delete itr;
                            break;
                        }
                        else
                            tempQ.push(temp->left);
                    }
                    if (temp->right != nullptr) {
                        if (temp->right == itr) {
                            temp->right = nullptr;
                            delete itr;
                            break;
                        }
                        else
                            tempQ.push(temp->right);
                    }
                }
                while (! tempQ.empty())
                    tempQ.pop();
            }
        }
    }
    /*virtual T lowestCommonAncestor(const T& a, const T& b) {
    }*/
protected:
    struct treeNode {
        treeNode (const T& dt, treeNode* lCh = nullptr, treeNode* rCh = nullptr)
            : data(dt), left(lCh), right(rCh) {}
        treeNode (T&& dt, treeNode* lCh = nullptr, treeNode* rCh = nullptr)
            : data(std::move(dt)), left(lCh), right(rCh) {}
        T data;
        treeNode* left;
        treeNode* right;
    };
    treeNode* root;
private:
    treeNode* cloneTreeNode (const treeNode* pTrNd) {
        treeNode* rtnPtr = nullptr;
        if (pTrNd != nullptr)
            rtnPtr = new treeNode(pTrNd->data, cloneTreeNode(pTrNd->left), cloneTreeNode(pTrNd->right));
        return rtnPtr;
    }
    void clearTree(treeNode*& pTrNd) {
        if (pTrNd != nullptr) {
            clearTree(pTrNd->left);
            clearTree(pTrNd->right);
            delete pTrNd;
        }
    }
    void insertUtil(treeNode* temp) {
        if (root == nullptr) {
            root = temp;
            return;
        }
        std::queue<treeNode*> tempQ;
        tempQ.push(root);
        while(! tempQ.empty()) {
            treeNode* trNd = tempQ.front();
            tempQ.pop();
            if (trNd->left != nullptr)
                tempQ.push(trNd->left);
            else {
                trNd->left = temp;
                break;
            }
            if (trNd->right != nullptr)
                tempQ.push(trNd->right);
            else {
                trNd->right = temp;
                break;
            }
        }
        while (! tempQ.empty())
            tempQ.pop();
    }
    void inorderTraverseUtil(treeNode* pTrNd) {
        if (pTrNd == nullptr)
            return;
        inorderTraverseUtil(pTrNd->left);
        std::cout << pTrNd->data << " ";
        inorderTraverseUtil(pTrNd->right);
    }
    void preorderTraverseUtil(treeNode* pTrNd) {
        if (pTrNd == nullptr)
            return;
        std::cout << pTrNd->data << " ";
        preorderTraverseUtil(pTrNd->left);
        preorderTraverseUtil(pTrNd->right);
    }
    void postorderTraverseUtil(treeNode* pTrNd) {
        if (pTrNd == nullptr)
            return;
        postorderTraverseUtil(pTrNd->left);
        postorderTraverseUtil(pTrNd->right);
        std::cout << pTrNd->data << " ";
    }
    bool printAncestorUtil(treeNode* pTrNd, const T& x) {
        if (pTrNd == nullptr)
            return false;
        if (pTrNd->data == x)
            return true;
        if (printAncestorUtil(pTrNd->left, x) || printAncestorUtil(pTrNd->right, x)) {
            std::cout << pTrNd->data << " ";
            return true;
        }
        else {
            return false;
        }
    }
    void mirrorUtil(treeNode* pTrNd) {
        if (pTrNd == nullptr)
            return;
        mirrorUtil(pTrNd->left);
        mirrorUtil(pTrNd->right);
        treeNode* temp = pTrNd->left;
        pTrNd->left = pTrNd->right;
        pTrNd->right = temp;
        return;
    }
    int getHeightUtil(treeNode* pTrNd) {
        if (pTrNd == nullptr)
            return 0;
        int leftHeight  = getHeightUtil(pTrNd->left);
        int rightHeight = getHeightUtil(pTrNd->right);
        int nodeHeight  = leftHeight > rightHeight ? leftHeight:rightHeight;
        return (nodeHeight+1);
    }
    int getDiameterUtil(treeNode* pTrNd, int* maxDist) {
        if (pTrNd == nullptr)
            return 0;
        int leftHeight  = getDiameterUtil(pTrNd->left, maxDist);
        int rightHeight = getDiameterUtil(pTrNd->right, maxDist);
        int nodeDia = leftHeight + rightHeight + 1;
        if (nodeDia > *maxDist)
            *maxDist = nodeDia;
        int nodeHeight  = leftHeight > rightHeight ? leftHeight:rightHeight;
        return (nodeHeight+1);
    }
};
#endif