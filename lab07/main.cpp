#include <iostream>

template<class T>
struct Node {
    T data;
    Node<T> *children[10];
    int count;
};

template<class T>
class Tree {
private:
    void treeCleanup(Node<T> *node) {
        std::cout << node->data << "\n";
        if (node->count == 0) delete node;
        else for (int i = 0; i < node->count; i++) {
            treeCleanup(node->children[i]);
        }
    }

    Node<T> *findRecurs(Node<T> *node, T value, bool (*f)(T x, T y)) {
        if (f(value, node->data)) return node;
        else if (node->count == 0) return nullptr;
        else for (int i = 0; i < node->count; i++) {
            Node<T> *aux = findRecurs(node->children[i], value, f);
            if (aux) return aux;
        }
        return nullptr;
    }

    void sortRecur(Node<T> *node, int (*cmp)(T, T)) {
        for (int i = 0; i < node->count; i++) {
            sortRecur(node->children[i], cmp);
        }
        for (int i = 0; i < node->count-1; i++) {
            for (int j = i; j < node->count; j++) {
                if (cmp) {
                    if (cmp(node->children[i]->data, node->children[j]->data) > 0) {
                        Node<T> *aux = node->children[i];
                        node->children[i] = node->children[j];
                        node->children[j] = aux;
                    }
                }
                else {
                    if (node->children[j]->data < node->children[i]->data) {
                        Node<T> *aux = node->children[i];
                        node->children[i] = node->children[j];
                        node->children[j] = aux;
                    }
                }
            }
        }
    }

public:
    Node<T> *root;

    Node<T> *add_node(Node<T> *parent, T data) {
        if (parent == nullptr) {
            this->root = new Node<T>;
            this->root->data = data;
            this->root->count = 0;
            return this->root;
        }
        else {
            parent->children[parent->count] = new Node<T>;
            parent->children[parent->count]->data = data;
            parent->children[parent->count]->count = 0;
            parent->count++;
            return parent->children[parent->count-1];
        }
    }
    Node<T> *insert(Node<T> *parent, T data) {return add_node(parent, data);}

    void sort(int (*cmp)(T, T)) {
        sortRecur(this->root, cmp);
    }

    Node<T> *find(T value, bool (*f)(T x, T y)) {
        return findRecurs(root, value, f);
    }
    int count(Node<T> *node) {
        int sum = 0;
        for (int i = 0; i < node->count; i++) {
            sum += count(node->children[i]);
        }
        return sum+1;
    }
    ~Tree() {
        treeCleanup(this->root);
    }
};

bool isEqual(int a, int b) {
    return a == b;
}

int cmp(int a, int b) {
    if (a > b) return 1;
    else if (a < b) return -1;
    return 0;
}

int main() {
    Tree<int> t;
    Node<int> *root = t.add_node(nullptr, 3);
    t.add_node(root, 6);
    Node<int> *n1 = t.add_node(root, 5);
    t.add_node(n1, 11);
    t.add_node(n1, 12);
    t.add_node(n1, 10);
    t.add_node(root, 4);
    t.sort(cmp);
    Node<int> *x = t.find(11, isEqual);
    Node<int> *y = t.find(123, isEqual);
    if (x) std::cout << "found x with value " << x->data << "\n";
    else std::cout << "x not found\n";

    if (y) std::cout << "found y with value " << y->data << "\n";
    else std::cout << "y not found\n";

    std::cout << "there are " << t.count(root) << " nodes from root\n";
    std::cout << "there are " << t.count(n1) << " nodes from n1\n";
    return 0;
}
