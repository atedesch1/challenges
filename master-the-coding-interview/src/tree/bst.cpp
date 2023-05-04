#include <iostream>
#include <memory>
#include <string>

template <typename T>
struct BSTNode {
    T value;
    std::unique_ptr<BSTNode<T>> left, right;

    BSTNode(T value) : value(value), left(nullptr), right(nullptr) {}
};

template <typename T>
class BST {
   private:
    std::unique_ptr<BSTNode<T>> root;

   public:
    BST() : root(nullptr) {}

    BST<T>* Insert(T value) {
        auto node = std::make_unique<BSTNode<T>>(value);
        if (root == nullptr) {
            root = std::move(node);
            return this;
        }

        auto p = root.get();
        while (true) {
            if (value < p->value) {
                if (p->left == nullptr) {
                    p->left = std::move(node);
                    break;
                }
                p = p->left.get();
            } else {
                if (p->right == nullptr) {
                    p->right = std::move(node);
                    break;
                }
                p = p->right.get();
            }
        }

        return this;
    }

    BSTNode<T>* Get(T value) {
        auto p = root.get();

        while (p != nullptr) {
            if (value < p->value) {
                p = p->left.get();
            } else {
                if (value == p->value) {
                    return p;
                }
                p = p->right.get();
            }
        }

        return nullptr;
    }

    std::unique_ptr<BSTNode<T>> Remove(T value) {
        if (root == nullptr) return nullptr;

        auto father = root.get();
        auto isLeftChild = true;
        while (father != nullptr) {
            if (father->left->value == value) {
                isLeftChild = true;
                break;
            } else if (father->right->value == value) {
                isLeftChild = false;
                break;
            } else if (value < father->value) {
                father = father->left.get();
            } else {
                father = father->right.get();
            }
        }

        auto removedNode =
            std::move(isLeftChild ? father->left : father->right);
        if (removedNode->right == nullptr) {
            if (isLeftChild) {
                father->left = std::move(removedNode->left);
            } else {
                father->right = std::move(removedNode->left);
            }
            return std::move(removedNode);
        } else if (removedNode->right.get()->left == nullptr) {
            if (isLeftChild) {
                father->left = std::move(removedNode->right);
            } else {
                father->right = std::move(removedNode->right);
            }
        }

        auto fatherOfLeftMostRightChild = removedNode->right.get();
        while (fatherOfLeftMostRightChild->left->left != nullptr) {
            fatherOfLeftMostRightChild = fatherOfLeftMostRightChild->left.get();
        }
        auto replacement = std::move(fatherOfLeftMostRightChild->left);
        fatherOfLeftMostRightChild->left = std::move(replacement->right);

        replacement->right = std::move(removedNode->right);

        if (isLeftChild) {
            father->left = std::move(replacement);
        } else {
            father->right = std::move(replacement);
        }

        return std::move(removedNode);
    }

    void Print() { Print("", root.get(), true); }

   private:
    void Print(std::string prefix, BSTNode<T>* p, bool isLast) {
        if (p == nullptr) return;
        std::cout << prefix + (isLast ? "└── " : "├── ") << p->value
                  << std::endl;

        std::string new_prefix = prefix + std::string(isLast ? "    " : "│   ");

        Print(new_prefix, p->right.get(), false);
        Print(new_prefix, p->left.get(), true);
    }
};

int main() {
    auto bst = BST<int>();
    bst.Insert(3);
    bst.Insert(2);
    bst.Insert(1);
    bst.Insert(5);
    bst.Insert(4);
    bst.Print();
    auto p = bst.Get(5);
    std::cout << "got " << p->value << std::endl;
    bst.Remove(3);
}
