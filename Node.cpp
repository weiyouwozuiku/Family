//
// Created by king on 17-6-22.
//

#include "Node.h"


Node::Node():   m_strName(" "),m_Gender("male"),m_iNum(0) {
    for(int i=0;i<MAX;i++)
        pNext[i]= nullptr;
    pParent=nullptr;
}

Node::~Node() {
    for(int i=0;i<MAX;i++){
        delete pNext[i];
        pNext[i]=nullptr;
    }
    pParent= nullptr;
}

int Node::getM_iNum() const {
    return m_iNum;
}

void Node::setM_iNum(int m_iNum) {
    Node::m_iNum = m_iNum;
}

const string &Node::getM_strName() const {
    return m_strName;
}

void Node::setM_strName(const string &m_strName) {
    Node::m_strName = m_strName;
}

const string &Node::getM_Gender() const {
    return m_Gender;
}

void Node::setM_Gender(const string &m_Gender) {
    Node::m_Gender = m_Gender;
}
