//
// Created by king on 17-6-22.
//

#ifndef FAMILY_TREE_H
#define FAMILY_TREE_H

#include "Node.h"

class Tree {
public:
    Tree();
    virtual ~Tree();
	void _insert(Node* &member,Node *parent);
	void insert();
  	Node *search(string name);
  	Node *_search(Node *pNode,string name);
	void
private:
    Node *m_pRoot;
};


#endif //FAMILY_TREE_H
