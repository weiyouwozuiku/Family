#include "Tree.h"
#include <cstring>
#include <stdlib.h>
void init(Tree* &pNode){
	menu:
		{
			cout << "\t\tHello, Family!If you want to quit,please input \\q" << endl;
			char flag[4];
			scanf("%s",flag);
			system("cls");
			if(!strcmp(flag,"\q")){
			cout<<"\t===========================================================\n";
			cout<<"\t=              Pretend to be a family tree                =\n";
			cout<<"\t=                                                         =\n";
			cout<<"\t=                                                         =\n";
			cout<<"\t=               1.Create genealogy                        =\n";
			cout<<"\t=                                                         =\n";
			cout<<"\t=               2.Find members by name                    =\n";
			cout<<"\t=                                                         =\n";
			cout<<"\t=               3.Expulsion of genealogy                  =\n";
			cout<<"\t=                                                         =\n";
			cout<<"\t=               4.Strengthen the family                   =\n";
			cout<<"\t=                                                         =\n";
			cout<<"\t=               5.Modify member information               =\n";
			cout<<"\t=                                                         =\n";
			cout<<"\t=               6.Family preview                          =\n";
			cout<<"\t=                                                         =\n";
			cout<<"\t=               7.Exit                                    =\n";
			cout<<"\t=                                                         =\n";
			cout<<"\t===========================================================\n";
			char choose;
			string name;
			Node *currentNode=nullptr,*node=nullptr;
			cin>>choose;
			switch(choose){
				case '1':
				{
					system("cls");
					pNode->insert();
					break;
				}
				case '2':
				{
					cout<<"Please input the name of the member:";
					cin>>name;
					pNode->search(name);
					break;
				}
				case '3':
				{
					cout<<"Please input the name of the member:";
					cin>>name;
					currentNode=pNode->search(name);
					pNode->deleteNode(currentNode);
					break;
				}
				case '4':
				{
					cout<<"Please input the name of the member's parent:";
					cin>>name;
					currentNode=pNode->search(name);
					pNode->_insert(node,currentNode);
					break;
				}
				case '5':
				{
					pNode->modity();
					break;
				}
				case '6':
				{
					pNode->print();
					break;
				}
				default:
				{
					cout<<"Bye!";
					return;
				}
			}
			goto menu;
		}
	}
}

int main() {
	Tree *tmp=new Tree;
	init(tmp);
    return 0;
}