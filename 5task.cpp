#include <iostream>

struct Node {
    int value;
    Node* left;
    Node* right;

    Node(int val) : value(val), left(nullptr), right(nullptr) {}
};

class BinarySearchTree {
private:
    Node* root;

    // Вспомогательный метод для добавления узла
    Node* addNode(Node* node, int value) {
        if (node == nullptr) {
            return new Node(value);
        }
        if (value < node->value) {
            node->left = addNode(node->left, value);
        } else if (value > node->value) {
            node->right = addNode(node->right, value);
        }
        return node;
    }

    // Вспомогательный метод для вывода листьев дерева в порядке возрастания
    void collectLeaves(Node* node) const {
        if (node == nullptr) return;

        // Рекурсивно идем по левому и правому поддереву
        collectLeaves(node->left);

        // Если узел — лист, выводим его значение
        if (node->left == nullptr && node->right == nullptr) {
            std::cout << node->value << " ";
        }

        collectLeaves(node->right);
    }

public:
    BinarySearchTree() : root(nullptr) {}

    // Метод для добавления элемента
    void add(int value) {
        root = addNode(root, value);
    }

    // Метод для вывода листьев в порядке возрастания
    void printLeavesInOrder() const {
        std::cout << "Leaves in ascending order: ";
        collectLeaves(root);
        std::cout << std::endl;
    }
};

int main() {
    BinarySearchTree bst;
    int value;

    std::cout << "Enter numbers to add to the tree (end with a non-integer): ";
    while (std::cin >> value) {
        bst.add(value);
    }

    // Выводим листья в порядке возрастания
    bst.printLeavesInOrder();

    return 0;
}
