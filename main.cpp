#include "Tree.h"
#include <cstring>
#include <stdio.h>
#include <stdlib.h>
void init(Tree* &pNode){
	menu:
		{
			system("cls");
			cout << "\t\tHello, Family!If you want to quit,please input q" << endl;
			char flag;
			scanf("%c",&flag);
			system("cls");
			if(flag!='q'){
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
			Node *currentNode=nullptr;
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
					system("cls");
					cout<<"Please input the name of the member:";
					cin>>name;
					pNode->_print(pNode->search(name));
					fflush(stdin);
					getchar();
					break;
				}
				case '3':
				{
					system("cls");
					cout<<"Please input the name of the member:";
					cin>>name;
					currentNode=pNode->search(name);
					pNode->deleteNode(currentNode);
					break;
				}
				case '4':
				{
					system("cls");
					cout<<"Please input the name of the member's parent:";
					cin>>name;
					currentNode=pNode->search(name);
					pNode->addNode(currentNode);
					break;
				}
				case '5':
				{
					system("cls");
					pNode->modity();
					break;
				}
				case '6':
				{
					system("cls");
					pNode->print();
					cout<<endl;
					fflush(stdin);
					getchar();
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
	delete tmp;
    return 0;
}