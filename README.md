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











