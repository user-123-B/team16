# 組別:16
# 系級班級:資工1A 2B 2B
# 成員:呂阡旗(組長)、張紘睿、張育嘉
# 專題題目:養寵物(PET)
# 程式介紹:
此程式為一領養、養成寵物程式，可讓人在程式中找尋到生命力，可以無負擔的扶養，無經費消耗，不需要幫他們洗澡，非常人性，進入程式即可立即領養一隻自己心愛的貓或狗，開啟「我獨自養成」。
# UML圖介紹說明:                                                                                                
# <<abstract>>:表示這是抽象類別，不能直接建立物件，需由子類別（如 Cat、Dog）繼承與實作。
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

+~Pet()
解構子。          

+eat() = 0 
純虛擬函式（=0），子類別必須實作。這些方法代表寵物的互動行為。  

+reactToEnvironment() = 0
讓子類根據當前環境作出反應，例如貓不喜歡雨天。   

+showStatus() const
顯示寵物狀態。const 表示此函式不會改變物件內部資料。 

+getName() const: string
取得寵物名字       

+setLocation(Location*)
設定寵物所在位置         

+getLocation(): Location*
取得目前所在位置    

+increaseBond(int)
增加情感連結數值（最多 100）


# Cat & Dog（繼承自 Pet）
private:

-eat,play,train,sleep Count :
每日互動計數器，用來限制互動次數。

public:                      
+Cat(...)  
建構子，初始化屬性與父類構造。

+eat()、+play() 、+train()、+sleep:
覆寫（override）父類方法，定義貓的專屬反應與行為。

+reactToEnvironment():        
根據 Location 的Environment 做出特定反應。

Dog 類別（繼承自 Pet） 幾乎與 Cat 相同，
差別在於方法實作內容不同（例如狗喜歡晴天、會訓練接飛盤等）

# Location
private:   

-name:
地點名稱（如：家、公園）。

-env: Environment:
地點的環境狀況，包括天氣與溫度。屬於「組合關係」。

public:                                                          
+setEnvironment(e)
設定整個 Environment 狀態。 

+changeWeather(w)
修改天氣（如「晴天」、「雨天」）。

+changeTemperature(t)
修改溫度（攝氏）。    

+getName()
取得地點名稱。      

+getEnvironment()
回傳 Environment 資料。 

+display()
印出地點狀態與環境。

# Environment
private: 

-weather
天氣（string，例如「晴  天」、「陰天」、「雨天」）。

-temperature
溫度（int，例如 25°C）。

public:
+setWeather(w)
改變天氣狀態。                              
+setTemperature(t)
改變溫度。                                      
+getWeather()
取得目前天氣。                            
+getTemperature()
取得目前溫度。                              
+display()
顯示環境資訊。

# 程式規則:
Run the code之後，按下數字鍵 1或2，選取自己想要領養的動物，並為其命名，命名不可包含空格 ; 之後按下數字鍵 1.2.3.4分別代表，吃食物、玩耍、睡覺、以及查看狀態，狀態分為飢餓值以及快樂值，初始狀態皆為50，吃一次食物飢餓值下降8，且每吃三次食物即會觸發特殊條件，特殊條件會使飢餓值上升4，快樂值上升8 ; 玩耍會使快樂值上升8，亦會使飢餓值上升4 ; 睡覺會使快樂值上升4，最後若是要離開程式，按下0即會離開。
# 程式如何安裝執行(圖文講解):
到VirtualPet檔案夾 下載所有內容檔 放到編譯器上即可開始
# 程式畫面截圖(輸出結果):







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











