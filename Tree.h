//
// Created by ��࣠�� ���஢� on 04.04.2023.
//

#ifndef LABA2_2_1_3VAR_AISD_TREE_H
#define LABA2_2_1_3VAR_AISD_TREE_H
#include <cstdio>


struct Node
{
    int _data;
    Node* _father;
    Node* _left;
    Node* _right;
    explicit Node(int data = 0, Node* father = nullptr, Node* left = nullptr, Node* right = nullptr)
    {
        _data = data;
        _father = father;
        _left = left;
        _right = right;
    }
};

class Tree {
    private:
        Node* root;

    public:
        Node* return_root();
        void recursion_destructor(Node* obj);
        void recursion_copy(const Node* obj);

        Tree();
        ~Tree();
        Tree(const Tree& obj);

        void print_Tree(const Node * p,int level)const;
        Node* insert(struct Node* _root , int key);//��⠢�� �����
        Node* search(int key,const Node* obj);//�஢�ઠ ������ �����
        bool contains(int key);//�஢�ઠ ������ �����
        Node* erase(int key, Node* obj);//㤠����� �����


        Tree& operator=(const Tree& obj);
        Node* minNode(Node* obj);

};



#endif //LABA2_2_1_3VAR_AISD_TREE_H
