#include <iostream>
#include <cstdio>
#include <ctime>
#include "Tree.h"
#include <vector>
using namespace std;

vector<int> task(std::vector<int> &vec){
    Tree tmp;
    std::vector<int> result;
    for(int i=0;i<vec.size();i++){
        if(tmp.contains(vec[i])){
            result.push_back(vec[i]);
        }
        else{
            tmp.insert(tmp.return_root(),vec[i]);
        }
    }
    return result;
}
int check(){
    int m;
    while(!(cin >> m)){
        cin.clear();
        while(cin.get() != '\n');
        cout << "Error! Enter the number: ";
    }
    return m;
}

int menu() {
    cout << "What are you want to do? To press.." << endl;
    cout << "1 - Create tree"<< endl;
    cout << "2 - Add new root"<< endl;
    cout << "3 - Delete root"<< endl;
    cout << "4 - Check existing root"<< endl;
    cout << "5 - Print tree" << endl;
    cout << "6 - Go out" << endl;
    int m2;
    m2 = check();
    return m2;
}

//create tree
void create_new_tree(Tree &tmp){
    int size_tree;
    int i=1;
    cout << "Enter the size of tree: ";
    cin >> size_tree;
    int key;
    cout << "Enter the key["<<i<<"]" << " of root: ";
    cin >> key;
    tmp.insert(tmp.return_root(),key);
    while(i<size_tree){
        cout << "Enter the key["<<i<< "]" << " of root: ";
        cin >> key;
        while(tmp.contains(key)){
            cout << "This key already exist. Enter another key: ";
            cin >> key;
        }
        tmp.insert(tmp.return_root(),key);
        i++;
    }

}

//add new root
void add_root(Tree &tmp){
    int key;
    cout << "Enter the key of root: ";
    key = check();
    tmp.insert(tmp.return_root(),key);
}

//delete root
void delete_root(Tree &tmp){
    int key;
    cout << "Enter the key of root: ";
    key = check();
    tmp.erase(key, tmp.return_root());
}

//check existing root
void check_root(Tree &tmp){
    int key;
    cout << "Enter the key of root: ";
    key = check();
    if(tmp.contains(key))
        cout << "This root exist" << endl;
    else
        cout << "This root not exist" << endl;
}

//print tree
void print_tree(Tree &tmp){
    tmp.print_Tree(tmp.return_root(),3);
}


//функция генератор
int lcg(){
    srand(time(NULL));
    int x;
    x = rand();
    return x;
}

//создание дерева и заполнение его случ значениями
Tree create_tree(Tree &tmp, int size_tree){
    int i =0;
    int key = lcg();
    while(i < size_tree){
        while(!tmp.contains(key)){key = lcg();}
        tmp.insert(tmp.return_root(),lcg());
        i++;
    }
    return tmp;
}

void insert_time_full(int size_tree){
    clock_t start = clock();
    Tree tmp =create_tree(tmp,size_tree);
    clock_t end = clock();
    double seconds = (double)(end - start) / CLOCKS_PER_SEC;
    printf("The time: %f seconds\n", seconds);
    //запись в файл
    FILE *file;
    file = fopen("insert_time_full.txt", "a+");
    fprintf(file, "%d %f\n", size_tree, seconds);
    fclose(file);
}

void search_time(int size_tree){
    Tree tmp =create_tree(tmp,size_tree);

    int key = lcg();
    while (!tmp.contains(key)){key = lcg();}

    clock_t start = clock();
    tmp.contains(key);
    clock_t end = clock();

    double seconds = (double)(end - start) / CLOCKS_PER_SEC;
    printf("The time: %f seconds\n", seconds);
    FILE *file;
    file = fopen("search_time.txt", "a+");
    fprintf(file, "%d %f\n", size_tree, seconds);
    fclose(file);
}

void insert_and_delete_time(int size_tree){
    Tree tmp =create_tree(tmp,size_tree);
    int key = lcg();
    while (tmp.contains(key)){key = lcg();}
    clock_t start = clock();
    tmp.insert(tmp.return_root(),key);
    clock_t end = clock();
    double seconds = (double)(end - start) / CLOCKS_PER_SEC;
    printf("The time: %f seconds\n", seconds);
    FILE *file;
    file = fopen("insert_time.txt", "a+");
    fprintf(file, "%d %f\n", size_tree, seconds);
    fclose(file);

    while (!tmp.contains(key)){key = lcg();}
    start = clock();
    tmp.erase(key, tmp.return_root());
    end = clock();
    seconds = (double)(end - start) / CLOCKS_PER_SEC;
    printf("The time: %f seconds\n", seconds);
    file = fopen("delete_time.txt", "a+");
    fprintf(file, "%d %f\n", size_tree, seconds);
    fclose(file);
}


void create_file(int loop){
    if(loop==1) {
        insert_time_full(1000);
        insert_time_full(5000);
        insert_time_full(10000);
        insert_time_full(50000);
        insert_time_full(100000);
    }
    if(loop==2) {
        search_time(1000);
        search_time(5000);
        search_time(10000);
        search_time(50000);
        search_time(100000);
    }
    if(loop==3) {
        insert_and_delete_time(1000);
        insert_and_delete_time(5000);
        insert_and_delete_time(10000);
        insert_and_delete_time(50000);
        insert_and_delete_time(100000);
    }
}



int main() {
    //выбор из двух вариантов
    int loop;
    cout << "Enter 1 to check task" << endl;
    cout << "Enter 2 to work with tree" << endl;
    cin >> loop;
    if (loop == 1) {
        std::vector<int> vec = {3,2,2,4,5,22,3};
        std::vector<int> result = task(vec);
        for(int i=0;i<result.size();i++){
            cout << result[i] << " ";
        }
        return 0;
    }
    if (loop == 2) {

        Tree tmp;
        int m1;
        while (true) {
            m1 = menu();
            switch (m1) {
                case 1:
                    create_new_tree(tmp);
                    break;
                case 2:
                    add_root(tmp);
                    break;
                case 3:
                    delete_root(tmp);
                    break;
                case 4:
                    check_root(tmp);
                    break;
                case 5:
                    print_tree(tmp);
                    break;
                case 6:
                    return 0;
                default:
                    cout << "Input correct value" << endl;
                    break;
            }
        }
    }
}




