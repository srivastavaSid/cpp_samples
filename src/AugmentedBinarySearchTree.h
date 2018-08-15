#ifndef augmentedBst_h
#define augmentedBst_h

#include <iostream>

template <typename T>
class augmentedBst {
public:
    augmentedBst()
        : root(nullptr) {}
    augmentedBst(const augmentedBst& rhs)
        : root(nullptr)
    {
        root = cloneBst(rhs.root);
    }
    augmentedBst(augmentedBst&& rhs) noexcept
        : root(std::move(rhs.root))
    {
        rhs.root = nullptr;
    }
    augmentedBst& operator=(const augmentedBst& rhs) {
        augmentedBst temp = rhs;
        std::swap(*this, temp);
        return *this;
    }
    augmentedBst& operator=(augmentedBst&& rhs) noexcept {
        std::swap(root, rhs.root);
        return *this;
    }
    ~augmentedBst() {
        clearTree(root);
        root = nullptr;
    }
    void insert(const T& x) {
        treeNode* temp = new treeNode(x);
        insertUtil(temp);
    }
    void insert(T&& x) {
        treeNode* temp = new treeNode(std::move(x));
        insertUtil(temp);
    }
    void remove (const T& x) {
        bool* pFound = new bool(false);
        root = removeUtil(root, x, pFound);
    }
    T getRank(const int n) {
        treeNode *res(nullptr), *itr(root);
        int rank = n-1;
        while(itr != nullptr) {
            if (itr->leftRank == rank) {
                res = itr;
                break;
            }
            else {
                if (itr->leftRank > rank)
                    itr = itr->left;
                else {
                    rank = rank - 1 - itr->leftRank;
                    itr = itr->right;
                }
            }
        }
        if (res != nullptr)
            return res->data;
        else {
            std::cout << "Rank " << n << " element does not exist" << std::endl;
            return T();
        }
    }
protected:
    struct treeNode {
        T data;
        treeNode* left;
        treeNode* right;
        int leftRank;

        treeNode(const T& x, treeNode* leftChild=nullptr, treeNode* rightChild=nullptr, int lRank=0)
            : data(x), left (leftChild), right(rightChild), leftRank(lRank) {}
        treeNode(T&& x, treeNode* leftChild=nullptr, treeNode* rightChild=nullptr, int lRank=0)
            : data(std::move(x)), left (leftChild), right(rightChild), leftRank(lRank) {}
    };
    treeNode* root;
private:
    treeNode* cloneBst(treeNode* pTrNd) {
        if (pTrNd == nullptr)
            return nullptr;
        return new treeNode(pTrNd->data, cloneBst(pTrNd->left), cloneBst(pTrNd->right), pTrNd->leftRank);
    }
    void clearTree(treeNode* pTrNd) {
        if (pTrNd == nullptr)
            return;
        clearTree(pTrNd->left);
        clearTree(pTrNd->right);
        delete pTrNd;
        pTrNd = nullptr;
    }
    void insertUtil(treeNode* temp) {
        if (root == nullptr) {
            root = temp;
            return;
        }
        treeNode* itr = root;
        while (1) {
            if (itr->data < temp->data) {
                if (itr->right != nullptr)
                    itr = itr->right;
                else {
                    itr->right = temp;
                    break;
                } 
            }
            else {
                itr->leftRank++;
                if (itr->left != nullptr)
                    itr = itr->left;
                else {
                    itr->left = temp;
                    break;
                }    
            }
        }
    }
    treeNode* removeUtil(treeNode* pTrNd, const T& x, bool* pFound) {
        if (pTrNd != nullptr) {
            if (pTrNd->data < x) {
                pTrNd->right = removeUtil(pTrNd->right, x, pFound);
            }
            else if (pTrNd->data > x) {
                pTrNd->left = removeUtil(pTrNd->left, x, pFound);
                if (*pFound == true)
                    pTrNd->leftRank--;
            }
            else {
                *pFound = true;
                if (pTrNd->left == nullptr) {
                    treeNode* temp = pTrNd;
                    pTrNd = pTrNd->right;
                    delete temp;
                }
                else if (pTrNd->right == nullptr) {
                    treeNode* temp = pTrNd;
                    pTrNd = pTrNd->left;
                    delete temp;
                }
                else {
                    T minVal = setMinValTo(pTrNd->right, x);
                    pTrNd->data = minVal;
                    pTrNd->right = removeUtil(pTrNd->right, x, pFound);
                }
            }
        }
        return pTrNd;
    }
    T setMinValTo(treeNode* pTrNd, const T& x) {
        treeNode* temp = pTrNd;
        while(temp->left != nullptr)
            temp = temp->left;
        T ret = temp->data;
        temp->data = x;
        return ret;
    }
};
# endif