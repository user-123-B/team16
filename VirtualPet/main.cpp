#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Cat.h"
#include "Dog.h"
#include "Location.h"
#include "Environment.h"
using namespace std;
void action1(Pet* pet) {//該函示用於家裡的互動
    int choice;
    do {
        cout << "\n1. Eat\n2. Play\n3. Train\n4. Sleep\n5. Look For Status\n0. 結束互動\n選擇：";
        cin >> choice;

        switch (choice) {
            case 1: pet->eat(); break;
            case 2: pet->play(); break;
            case 3: pet->train(); break;
            case 4: pet->sleep(); break;
            case 5: pet->showStatus(); break;
            case 0: cout << "interaction is over，你跟寵物建立了深厚情誼。\n"; break;
            default: cout << "選項無效！請輸入 0 ~ 5。\n";
        }
    } while (choice != 0);
}

void action2(Pet* pet) {//該函示用於公園的互動
    int choice;
    do {
        cout << "\n1. Eat\n2. Play\n3. Train\n4. Look For Status\n0. 結束互動\n選擇：\n";
        cin >> choice;

        switch (choice) {
            case 1: pet->eat(); break;
            case 2: pet->play(); break;
            case 3: pet->train(); break;
            case 4: pet->showStatus(); break;
            case 0: cout << "Interaction is over，你跟寵物建立了深厚情誼。\n"; break;
            default: cout << "選項無效！請輸入 0 ~ 4。\n";
        }
    } while (choice != 0);
}

int main() {
	srand(time(0));
    
    // 創建地點
    Environment homeEnv("晴天", 24); //輸入天氣和溫度參數
    Location home("家", homeEnv); //給定位置參數以及先前的環境物件之參數
    
    Environment parkEnv("晴天", 22);
    Location park("公園", parkEnv);
    
    int choice;
    cout << "Welcome to 寵物成長遊戲！\nChoose your pet：\n1. Cat\n2. Dog\n你的選擇：";
    cin >> choice; //輸入數值選取欲培養隻寵物
    while (choice != 1 && choice != 2) {
        cout << "只能選擇 1 或 2，重新輸入：";
        cin >> choice;
    }

    string name, breed, color;
    cout << "為你的寵物取名字(只能取英文)：";
    cin >> name;
    cout << "請輸入牠的品種：";
    cin >> breed;
    cout << "請輸入牠的顏色：";
    cin >> color;

    Pet* myPet = (choice == 1)
        ? static_cast<Pet*>(new Cat(name, breed, color))
        : static_cast<Pet*>(new Dog(name, breed, color));//建立條件運算子以辨別是貓是狗
        
    myPet->setLocation(&home); // 初始位置在家
    
    int locationChoice;
    int lastLocation = 1; //  1: 家, 2: 公園 預設值:家
    do {
        cout << "\n===== 主選單 =====\n";
        cout << "當前位置各項資訊: ";
        myPet->getLocation()->display();
        
        if (lastLocation == 2) {
            cout << "\n1. 回家\n2. 待在公園\n0. 退出遊戲\n選擇: ";
        } else {
            cout << "\n1. 留在家裡\n2. 去公園\n0. 退出遊戲\n選擇: ";
        }
        cin >> locationChoice;
        
        switch(locationChoice) {
            case 1: 
                myPet->setLocation(&home);
                home.changeWeather("晴天");
                home.changeTemperature(24);
                action1(myPet);
                lastLocation = 1; // 更新最後位置為家
                break;
            case 2: {
                myPet->setLocation(&park);
                
                // 隨機設天氣
                string weathers[] = {"晴天", "雨天", "陰天"};
                string randomWeather = weathers[rand() % 3];
                park.changeWeather(randomWeather);
                park.changeTemperature(18 + rand() % 15);
                action2(myPet);
                lastLocation = 2; // 更新最後位置為公園
                break;
            }
            case 0:
                cout << "遊戲結束，感謝遊玩！\n";
                break;
            default:
                cout << "無效選擇！\n";
        }
    } while(locationChoice != 0);  
    
    delete myPet;
    return 0;
}
