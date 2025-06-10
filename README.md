# 組別:16
# 系級班級:資工1A 2B 2B
# 成員:呂阡旗(組長)、張紘睿、張育嘉
# 專題題目:養寵物(PET)
# 程式介紹:
此程式為一領養、養成寵物程式，可讓人在程式中找尋到生命力，可以無負擔的扶養，無經費消耗，不需要幫他們洗澡，非常人性，進入程式即可立即領養一隻自己心愛的貓或狗，開啟「我獨自養成」。
# UML圖介紹說明:                                                                                                
 <<abstract>>:表示這是抽象類別，不能直接建立物件，需由子類別（如 Cat、Dog）繼承與實作。
# PET
protected:
#name, #breed, #color:
表示是 protected 保護成員，子類別可以存取，外部不可。

#hunger, #happiness, #bondLevel:
基本的狀態參數，分別代表飢餓值、快樂值與與玩家的情感連結。                                                                                                       
                                                                                         
#eatLimit, #playLimit, #trainLimit, #sleepLimit:
限制每日互動次數，防止無限互動。                                               
                                        
#currentLocation: Location*
指向 Location 物件的指標，表示寵物目前所在的位置。
# PET
public:
+Pet(...)
建構子，初始化寵物基本資料。 
Pet::Pet(const string& name, const string& breed, const string& color)
    : name(name),breed(breed), color(color), hunger(50), happiness(50), bondLevel(0),
      eatLimit(3), playLimit(3), trainLimit(2), sleepLimit(2) ,currentLocation(nullptr){}
+~Pet()
解構子。          

+eat() = 0 
純虛擬函式（=0），子類別必須實作。這些方法代表寵物的互動行為。  

+reactToEnvironment() = 0
讓子類根據當前環境作出反應，例如貓不喜歡雨天。   

+showStatus() const
顯示寵物狀態。const 表示此函式不會改變物件內部資料。 
void Pet::showStatus() const {
    cout << name << " 狀態：" << endl;
    cout << "名字：" << name << endl;
    cout << "品種：" << breed << endl;
    cout << "顏色：" << color << endl;
    cout << "飢餓值：" << hunger << endl;
    cout << "快樂值：" << happiness << endl;
    cout << "情感連結：" << bondLevel << "/100" << endl;
}

+getName() const: string
取得寵物名字       
string Pet::getName() const {
    return name;
}

+setLocation(Location*)
設定寵物所在位置         
void Pet::setLocation(Location* location) {
    currentLocation = location;
}

+getLocation(): Location*
取得目前所在位置    
Location* Pet::getLocation() const {
    return currentLocation;
}

+increaseBond(int)
增加情感連結數值（最多 100）
void Pet::increaseBond(int amount) {
    bondLevel += amount;
    if (bondLevel > 100) bondLevel = 100;
}

# Cat & Dog（繼承自 Pet）
private:

-eat,play,train,sleep Count :
每日互動計數器，用來限制互動次數。
int eatCount, playCount, trainCount, sleepCount;

public:                      
+Cat(...)  
建構子，初始化屬性與父類構造。
Cat::Cat(const string& name, const string& breed, const string& color) : Pet(name, breed, color),
    eatCount(0), playCount(0), trainCount(0), sleepCount(0) {}
    
+eat()、+play() 、+train()、+sleep:
覆寫（override）父類方法，定義貓的專屬反應與行為。
void Cat::eat() {
    if (eatCount >= eatLimit) {
        cout << getName() << " 看著你：『你以為我還會吃嗎？我才不胖呢。』\n";
        return;
    }
    hunger -= 8;
    if (hunger < 0) hunger = 0;
    eatCount++;
    cout << getName() << " 吃了鮪魚罐頭真爽，飢餓值下降。\n";
    increaseBond(4);
    if (eatCount == eatLimit)
        cout << getName() << " 吃太多了想吐了，打了個飽嗝：『喵～我超愛你 ??』\n";
}

void Cat::play() {
    if (playCount >= playLimit) {
        cout << getName() << " 對毛線球失去興趣，斜眼看你。\n";
        return;
    }
    happiness += 10;
    hunger += 4;
    if (hunger > 100) hunger = 100;
    if (happiness > 100) happiness = 100;
    playCount++;
    cout << getName() << " 跟你玩了毛線球，喵喵叫得很開心！\n";
    increaseBond(6);
}

void Cat::train() {
    if (trainCount >= trainLimit) {
        cout << getName() << " 睜大眼睛：『誰想學握手？我是貓欸！』\n";
        return;
    }
    trainCount++;
    cout << getName() << " 才不想聽指令，但你硬是教牠握手...\n";
    happiness += 2;
    increaseBond(7);
}

void Cat::sleep() {
    if (sleepCount >= sleepLimit) {
        cout << getName() << " 在窗邊曬太陽，不想再睡了。\n";
        return;
    }
    sleepCount++;
    happiness += 5;
    if (happiness > 100) happiness = 100;
    cout << getName() << " 蜷縮成一團毛球熟睡，好舒服。\n";
    increaseBond(5);
}

+reactToEnvironment():        
根據 Location 的Environment 做出特定反應。
void Cat::reactToEnvironment() {
    if (getLocation() == nullptr) return;
    
    string weather = getLocation()->getEnvironment().getWeather();
    int temp = getLocation()->getEnvironment().getTemperature();
    
    if (weather == "雨天") {
        cout << getName() << " 討厭雨天，躲到沙發底下了\n";
        happiness -= 10;
    }
    else if (temp > 30) {
        cout << getName() << " 找陰涼處躺下，太熱了不想動\n";
        happiness -= 5;
    }
}

Dog 類別（繼承自 Pet） 幾乎與 Cat 相同，
差別在於方法實作內容不同（例如狗喜歡晴天、會訓練接飛盤等）

+Dog(...)  
建構子，初始化屬性與父類構造。
Dog::Dog(const string& name, const string& breed, const string& color) : Pet(name, breed, color),
    eatCount(0), playCount(0), trainCount(0), sleepCount(0) {}

+eat()、+play() 、+train()、+sleep:
覆寫（override）父類方法，定義貓的專屬反應與行為。
void Dog::eat() {
    if (eatCount >= eatLimit) {
        cout << getName() << " 旺旺，可能吃太飽了，想拉屎了。\n";
        return;
    }
    hunger -= 10;
    if (hunger < 0) hunger = 0;
    eatCount++;
    cout << getName() << " 狂吃 A5牛排 啃骨頭，好餓啊！\n";
    increaseBond(2);
    if (eatCount == eatLimit)
        cout << getName() << " 撲過來舔你臉：『汪！你最棒！』\n";
}
void Dog::play() {
    if (playCount >= playLimit) {
        cout << getName() << " 累了，躺在地上喘氣...\n";
        return;
    }
    happiness += 12;
    hunger += 5;
    if (hunger > 100) hunger = 100;
    if (happiness > 100) happiness = 100;
    playCount++;
    cout << getName() << " 玩了丟球遊戲，開心得不得了！\n";
    increaseBond(6);
}
void Dog::train() {
    if (trainCount >= trainLimit) {
        cout << getName() << " 旺旺，不太想再訓練了...\n";
        return;
    }
    trainCount++;
    happiness += 5;
    increaseBond(8);
    cout << getName() << " 接飛盤，好聰明！\n";
}
void Dog::sleep() {
    if (sleepCount >= sleepLimit) {
        cout << getName() << " 已經睡飽，吐舌頭。\n";
        return;
    }
    sleepCount++;
    trainCount = 0; // 睡覺後訓練次數歸零
    eatCount = 0; // 睡覺後吃飯次數歸零
    playCount = 0; // 睡覺後玩耍次數歸零
    happiness += 4;
    if (happiness > 100) happiness = 100;
    cout << getName() << " 安穩地睡覺做美夢。\n";
    increaseBond(5);
}

+reactToEnvironment():        
根據 Location 的Environment 做出特定反應。
void Dog::reactToEnvironment() {
    if (getLocation() == nullptr) return;
    
    string weather = getLocation()->getEnvironment().getWeather();
    int temp = getLocation()->getEnvironment().getTemperature();
    
    if (weather == "晴天") {
        cout << getName() << " 喜歡晴天，開心地搖尾巴\n";
        happiness += 10;
    }
    else if (temp < 15) {
        cout << getName() << " 覺得冷，縮成一團發抖\n";
        happiness -= 8;
    }
}

# Location
private:   

-name:
地點名稱（如：家、公園）。
string name;

-env: Environment:
地點的環境狀況，包括天氣與溫度。屬於「組合關係」。
Environment env;

public:    

+Location 建構子
初始化地點與環境物件
Location::Location(const string& n, const Environment& e): name(n), env(e) {}

+setEnvironment(e)
設定整個 Environment 狀態。 
void Location::setEnvironment(const Environment& e) {
    env = e;
}

+changeWeather(w)
修改天氣（如「晴天」、「雨天」）。
void Location::changeWeather(const string& w) {
    env.setWeather(w);
}

+changeTemperature(t)
修改溫度（攝氏）。    
void Location::changeTemperature(int temp) {
    env.setTemperature(temp);
}

+getName()
取得地點名稱。      
string Location::getName() const {
    return name;
}

+getEnvironment()
回傳 Environment 資料。 
Environment Location::getEnvironment() const {
    return env;
}

+display()
印出地點狀態與環境。
void Location::display() const {
    cout << "地點: " << name << " | ";
    env.display();
}

# Environment
private: 

-weather
天氣（string，例如「晴  天」、「陰天」、「雨天」）。
string weather;

-temperature
溫度（int，例如 25°C）。
int temperature;

public:

Environment 建構子
初始化天氣與溫度情況
Environment::Environment(const string& w, int temp) : weather(w), temperature(temp) {}

+setWeather(w)
改變天氣狀態。   
void Environment::setWeather(const string& w) {
    weather = w;
}
+setTemperature(t)
改變溫度。    
void Environment::setTemperature(int temp) {
    temperature = temp;
}

+getWeather()
取得目前天氣。  
string Environment::getWeather() const {
    return weather;
}

+getTemperature()
取得目前溫度。      
int Environment::getTemperature() const {
    return temperature;
}

+display()
顯示環境資訊。
void Environment::display() const {
    cout << "天氣: " << weather 
              << " | 溫度: " << temperature << "°C" << endl;
}

# 程式規則:
程式規則說明：寵物成長遊戲
遊戲目標
玩家飼養一隻貓或狗，透過互動讓寵物成長，並建立深厚情誼
1. 選擇寵物
	•	遊戲開始時，玩家需選擇寵物種類（1.貓2.狗）
	•	玩家需為寵物設定名字、品種及顏色
2. 地點與環境
	•	遊戲有兩個地點：「家」與「公園」
	•	每個地點有天氣與溫度設定，公園的天氣和溫度會隨機變化
3. 主選單操作
	•	玩家可選擇：
	•	待在家
	•	去公園
	•	離開遊戲
	•	依據目前所在地，選項會有所不同（如在家可選「去公園」，在公園可選「回家」）
4. 與寵物互動
	•	在不同地點可進行不同互動：
	•	家：吃飯、玩耍、訓練、睡覺、查看狀態、結束互動
	•	公園：吃飯、玩耍、訓練、查看狀態、結束互動
	•	玩家可重複進行互動，直到選擇結束互動
5. 寵物狀態
	•	玩家可隨時查詢寵物狀態（如體力、心情等，依類別定義）
6. 遊戲結束
	•	玩家可隨時選擇退出遊戲，遊戲即結束
互動選單摘要
地點| 可選互動
家| 吃飯、玩耍、訓練、睡覺、查狀態、結束互動
公園| 吃飯、玩耍、訓練、查狀態、結束互動     
備註  
- 每次進入公園時，天氣與溫度會隨機決定
- 玩家每次互動後可選擇繼續或結束互動
- 遊戲流程以選單輪詢方式進行，操作簡單明瞭


# 程式如何安裝執行(圖文講解):
到VirtualPet檔案夾 下載所有內容檔 放到編譯器上即可開始
# 程式畫面截圖(輸出結果):
![image](https://github.com/user-attachments/assets/799f625e-8bf6-452c-99a7-7e5c5b0005d9)
//
![image](https://github.com/user-attachments/assets/230a8621-e646-41d0-bfd0-0db0fe6fef70)
//
![image](https://github.com/user-attachments/assets/116bc7f8-96e9-4543-a49f-05175426888f)
//
![image](https://github.com/user-attachments/assets/640f6292-5902-4245-bfae-ba5e248ea84b)
//
//以下之程式執行截圖畫面為 eatCount, playCount, trainCount, sleepCount;抵達上限時會有之反應 以及如何解除解除之截圖

![image](https://github.com/user-attachments/assets/b1012fdb-b15b-4472-a566-606108932589)
//
//此張截圖為使用eat函示三次之後之結果
![image](https://github.com/user-attachments/assets/dbc2bbaa-f8cd-45b3-aced-cf65994d9016)
//
//此張截圖為抵達eatLimit後會有之反應 按下sleep之後所有之limit值皆會被重製
//
![image](https://github.com/user-attachments/assets/eb4fcafb-e73a-42e8-902a-a22e566d8551) 
//
//此張截圖證明limit值被重新設定


# 分工資訊:
呂阡旗(組長):
開發物件main.cpp

開發物件Cat.h,Cat.cpp

Location.h&.cpp                  

Environment .h&.cpp

Readme.md編輯撰寫

張紘睿:
開發物件Pet.h,Pet.cpp

PPT製作

Readme.md編輯撰寫

張育嘉:
開發物件Dog.h,Dog.cpp

Location.h&.cpp  

Environment .h&.cpp

Readme.md編輯撰寫

PPT製作

UML圖製作











