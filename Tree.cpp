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
	  for (int i = 0; i < MAX; i++) {
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
	if (pNode->getM_iNum()==0)
	{
		cout<<"empty";
		return;
	}
    Node *currentNode=pNode->pParent;
    int num=pNode->getM_iNum();
    for (int i = 0; i <num; ++i) {
        deleteNode(pNode->pNext[i]);
    }
	pNode->setM_strName("");
    currentNode->setM_iNum(currentNode->getM_iNum()-1);
}

void Tree::modity(){
	cout<<"Please input the name what you want to modity."<<endl;
	string name;
	cin>>name;
	Node *pNode=search(name);
	cout<<"Secondinput the follow number to choose.";
	cout<<"1.name;2.gender:";
	string newname;
	string newgender;
	int tmp;
	cin>>tmp;
	switch(tmp){
	case 1:
		cout<<"Please input a new name:";
		cin>>newname;
		pNode->setM_strName(newname);
		break;
	case 2:
		cout<<"Please input the gender:";
		cin>>newgender;
		pNode->setM_Gender(newgender);
		break;
	default:
		cout<<"error!bye";
		break;
	}
}

void Tree::_print(Node *pNode){
	Node* currentNode=pNode;
	queue<Node*> q;
	q.push(pNode);
	while(!q.empty()){
		Node* now=q.front();
		q.pop();
		cout<<now->getM_strName()<<' '<<now->getM_Gender()<<'\t';
		for(int i=0;i<MAX;i++){
			if(now->pNext[i]==nullptr||now->pNext[i]->getM_strName()=="")
				continue;
			else{
				q.push(now->pNext[i]);
				//cout<<now->pNext[i]->getM_strName();
			}
		}
	}

}

void Tree::addNode(Node* &pNode){
	if(pNode->getM_iNum()==20){  
		cout<<"Full";
		return;
	}
	Node* tmp=nullptr;
	_insert(tmp,pNode);
	pNode->pNext[pNode->getM_iNum()]=tmp;
	pNode->setM_iNum(pNode->getM_iNum()+1);
}

void Tree::print(){
	cout<<"Output the information of juniors and member£º\n";
	_print(m_pRoot);
}