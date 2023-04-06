#include <iostream>
#include <cstdio>
#include <ctime>
#include "Tree.h"
using namespace std;


void Tree::recursion_destructor(Node *obj) {
    if(obj->_left)
        recursion_destructor(obj->_left);
    if(obj->_right)
        recursion_destructor(obj->_right);
    delete obj;
    obj = nullptr;
}

void Tree::recursion_copy(const Node *obj) {
    insert(root,obj->_data);
    if(obj->_left)
        recursion_copy(obj->_left);
    if(obj->_right)
        recursion_copy(obj->_right);

}

Node* Tree::insert(struct Node* _root, int key) {
    if(_root== nullptr){
        _root = new Node(key);
        root = _root;
        return _root;
    }
    if(key<_root->_data){
        if(_root->_left== nullptr){
            _root->_left = new Node(key,_root);
            return _root->_left;
        }
        else{
            return insert(_root->_left,key);
        }
    }
    else{
        if(_root->_right== nullptr){
            _root->_right = new Node(key,_root);
            return _root->_right;
        }
        else{
            return insert(_root->_right,key);
        }
    }
}

Node *Tree::return_root() {
    return root;
}

Tree::Tree(const Tree &obj) {
    recursion_destructor(root);
    recursion_copy(obj.root);
}

Tree::Tree() {
    root = nullptr;
}

Tree::~Tree() {
    if(root) {
        recursion_destructor(root);
    }
}

void Tree::print_Tree(const Node * p,int level)const {
    if(p)
    {
        print_Tree(p->_left,level + 1);
        for(int i = 0;i< level;i++) cout<<"   ";
        cout << "("<<p->_data<<")" << endl;
        print_Tree(p->_right,level + 1);
    }
}


Node* Tree::search(int key,const Node* obj) {
    if(obj== nullptr){
        return nullptr;
    }
    if(obj->_data==key){
        return (Node*)obj;
    }
    if(key<obj->_data){
        return search(key,obj->_left);
    }
    else{
        return search(key,obj->_right);
    }
}

bool Tree::contains(int key) {
    if(!root){
        throw "Root not exist";
    }
    if(search(key,root)!= nullptr){
        return true;
    }
    else return false;
}

Node* Tree::erase(int key,Node* obj) {
    if(!root){
        throw "Root not exist";
    }
    if(key<obj->_data){
        obj->_left = erase(key,obj->_left);
    }
    else if(key>obj->_data){
        obj->_right = erase(key,obj->_right);
    }
    else{
        if(obj->_left== nullptr){
            Node* tmp = obj->_right;
            delete obj;
            return tmp;
        }
        else if(obj->_right== nullptr){
            Node* tmp = obj->_left;
            delete obj;
            return tmp;
        }
        Node* tmp = minNode(obj->_right);
        obj->_data = tmp->_data;
        obj->_right = erase(tmp->_data,obj->_right);
    }
    return obj;
}

Node *Tree::minNode(Node *obj) {
    Node* tmp = obj;
    while(tmp && tmp->_left!= nullptr){
        tmp = tmp->_left;
    }
    return tmp;
}

Tree &Tree::operator=(const Tree &obj) {
    if(this==&obj){
        return *this;
    }
    recursion_destructor(root);
    recursion_copy(obj.root);
    return *this;
}










