#include "Tree.h"
int main() {
	cout << "Hello, Family!" << endl;
    Tree tmp;
    tmp.insert();
	Node* temp= tmp.search("c");
    tmp.deleteNode(temp);
	tmp.print();
    
    return 0;
}