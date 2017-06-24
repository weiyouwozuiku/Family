//
// Created by king on 17-6-22.
//

#include "Tree.h"

Tree::Tree(){
    m_pRoot= nullptr;
}

Tree::~Tree() {

}

void Tree::insert(){
	_insert(m_pRoot,nullptr);
}

void Tree::_insert(Node* &member,Node *parent){
    if (member==nullptr) {
      int num;
      string name,gender;
      member=new Node();
      member->pParent=parent;
      cout<<"Please input your name:";
      cin>>name;
      member->setM_strName(name);
      cout<<"Please input your gender:";
      cin>>gender;
      member->setM_Gender(gender);
      cout<<"Please input the number of your family without yourself:";
      cin>>num;
      member->setM_iNum(num);
      if (num==0) {
        return;
      }
      else{
        for (int i = 0 ;i < num ;i++) {
          _insert((member->pNext[i]),member);
        }
      }
    }
}

Node *Tree::_search(Node *pNode,string name){
  Node *currentNode=pNode;
  if (currentNode!=nullptr) {
	  if (currentNode->getM_strName()==name) {
      return currentNode;
    }
	  for (int i = 0; i < currentNode->getM_iNum(); i++) {
      if(_search(currentNode->pNext[i],name)!=nullptr)
        return _search(currentNode->pNext[i],name);
    }
  }
  return nullptr;
}

Node *Tree::search(string name){
  return _search(m_pRoot,name);
}

void Tree::deleteNode(Node* &pNode) {
    Node *currentNode=pNode->pParent;
    int num=pNode->getM_iNum();
    for (int i = 0; i <num; ++i) {
        deleteNode(pNode->pNext[i]);
    }
    delete pNode;
    pNode=nullptr;
    currentNode->setM_iNum(currentNode->getM_iNum()-1);
}