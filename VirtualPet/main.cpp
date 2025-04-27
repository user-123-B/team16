#include <iostream>
#include "Cat.h"
#include"Dog.h"
using namespace std;
void action(Pet* pet) {
    int choice;
    do {
        cout << "\n1. 吃東西\n2. 玩耍\n3. 睡覺\n4. 查看狀態\n0. 離開\n選擇：";
        cin >> choice;

        switch (choice) {
            case 1:
                pet->eat();
                break;
            case 2:
                pet->play();
                break;
            case 3:
                pet->sleep();
                break;
            case 4:
                pet->showStatus();
                break;
            case 0:
                cout << "出門當社畜"<<endl;
                break;
            default:
                cout << "看不懂字喔，就只有1、2、3、4、0可以按"<<endl;
        }
    } while (choice != 0);
}

int main() {
    int choice;
    cout << "按下按鍵開始養殖遊戲:1.貓 2.狗"<<endl;
    cin >> choice;
    while(choice!=1&&choice!=2){
        cout << "只有狗跟貓可以養，其他是非賣品，重選"<<endl;
        cin >> choice;
    }

    string name;
    cout << "你領養了一隻寵物，給你的寵物取個名字八：";
    cin>>name;

    Pet *myPet;
    

    if (choice == 1) {
        myPet = new Cat(name);  
    } else {
        myPet = new Dog(name);  
    }

    action(myPet);

    delete myPet;

    return 0;
}
