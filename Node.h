//
// Created by king on 17-6-22.
//

#ifndef FAMILY_NODE_H
#define FAMILY_NODE_H

#include <string>
#include <iostream>
#define MAX 20
using std::string;
using std::cin;
using std::cout;
using std::endl;

class Node {
public:
    Node();

    ~Node();

    int getM_iNum() const;

    void setM_iNum(int m_iNum);

    const string &getM_strName() const;

    void setM_strName(const string &m_strName);

    const string &getM_Gender() const;

    void setM_Gender(const string &m_Gender);

private:
    int m_iNum;
    string m_strName;
    string m_Gender;

public:
    Node *pNext[MAX];
    Node *pParent;
};


#endif //FAMILY_NODE_H
