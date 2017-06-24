#include "Tree.h"
int main() {
    Tree tmp;
    tmp.insert();
	Node* temp= tmp.search("e");
    tmp.deleteNode(temp);
    std::cout << "Hello, World!" << std::endl;
    return 0;
}