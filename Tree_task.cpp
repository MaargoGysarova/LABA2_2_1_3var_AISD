
#include "Tree_task1.h"
using namespace std;

template<typename T>
void Tree_task1<T>::recursion_destructor(Node_1<T> *obj) {
    if(obj->_left)
        recursion_destructor(obj->_left);
    if(obj->_right)
        recursion_destructor(obj->_right);
    delete obj;
    obj = nullptr;
}

template<typename T>
void Tree_task1<T>::recursion_copy(const Node_1<T> *obj) {
    insert(root,obj->_data);
    if(obj->_left)
        recursion_copy(obj->_left);
    if(obj->_right)
        recursion_copy(obj->_right);
}

template<typename T>
Node_1<T> *Tree_task1<T>::insert(Node_1<T> *_root, int key) {
    //добавление элемента в дерево с повторяющимися элементами
    if (_root == nullptr) {
        _root = new Node_1<T>(key);
        root = _root;
        return _root;
    }
    if (key < _root->_data) {
        if (_root->_right->_data == root->_data) {
            insert(_root->_right, key);
        }
        if (_root->_left == nullptr) {
            _root->_left = new Node_1<T>(key, _root);
            return _root->_left;
        } else {
            return insert(_root->_left, key);
        }
    }
    if (key > _root->_data) {
        if (_root->_right->_data == root->_data) {
            insert(_root->_right, key);
            if (_root->_right == nullptr) {
                _root->_right = new Node_1<T>(key, _root);
                return _root->_right;
            } else {
                return insert(_root->_right, key);
            }
        }
        if (key == _root->_data) {
            if (_root->_right == nullptr) {
                _root->_right = new Node_1<T>(key, _root);
                _root->_left = nullptr;
                return _root->_right;
            } else {
                _root->_left = nullptr;
                return insert(_root->_right, key);
            }
        }
    }
}

template<typename T>
Node_1<T> *Tree_task1<T>::return_root() {
    return root;
}

template<typename T>
Tree_task1<T>::Tree_task1 (const Tree &obj) {
    recursion_destructor(root);
    recursion_copy(obj.root);
}

template<typename T>
Tree_task1<T>::Tree_task1() {
    root = nullptr;
}

template<typename T>
Tree_task1<T>::~Tree_task1() {
    if(root) {
        recursion_destructor(root);
    }
}

template<typename T>
void Tree_task1<T>::print_Tree(const Node_1<T> * p,int level)const {
    if(p)
    {
        print_Tree(p->_left,level + 1);
        for(int i = 0;i< level;i++) cout <<"   ";
        cout << "("<<p->_data<<")" << endl;
        print_Tree(p->_right,level + 1);
    }
}


template<typename T>
Node_1<T>* Tree_task1<T>::search(int key,const Node_1<T>* obj) {
    if(obj== nullptr){
        return nullptr;
    }
    if(obj->_data==key){
        return (Node_1<T>*)obj;
    }
    if(key<obj->_data){
        return search(key,obj->_left);
    }
    else{
        return search(key,obj->_right);
    }
}

template<typename T>
bool Tree_task1<T>::contains(int key) {
    if(!root){
        throw "Root not exist";
    }
    if(search(key,root)!= nullptr){
        return true;
    }
    else return false;
}

template<typename T>
Node_1<T>* Tree_task1<T>::erase(int key,Node_1<T>* obj) {
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
            Node_1<T>* tmp = obj->_right;
            delete obj;
            return tmp;
        }
        else if(obj->_right== nullptr){
            Node_1<T>* tmp = obj->_left;
            delete obj;
            return tmp;
        }
        Node_1<T>* tmp = minNode(obj->_right);
        obj->_data = tmp->_data;
        obj->_right = erase(tmp->_data,obj->_right);
    }
    return obj;
}

template<typename T>
Node_1<T> *Tree_task1<T>::minNode(Node_1<T> *obj) {
    Node_1<T>* tmp = obj;
    while(tmp && tmp->_left!= nullptr){
        tmp = tmp->_left;
    }
    return tmp;
}

template<typename T>
Tree_task1<T> &Tree_task1<T>::operator=(const Tree_task1<T> &obj) {
    if(this==&obj){
        return *this;
    }
    recursion_destructor(root);
    recursion_copy(obj.root);
    return *this;
}

template<typename T>
size_t Tree_task1<T>::count(int x, Node_1<T> *obj) {
    if(obj== nullptr){
        return 0;
    }
    if(obj->_data==x){
        return 1+count(x,obj->_right);
    }
    else{
        return count(x,obj->_right);
    }

}


