 2022/11/30
C板代码基于原本C板陀螺仪发送端

加入串口1 3 CAN1
遥控器可以用



2022、12、16
打符

2022.12.17
解决遥控器失联问题

！！主控任务控制时间两毫秒


//2022/12/30
加入控制模块状态检测

2023/2/11
加入键鼠控制（待测试）
2023/2/11
更改发射逻辑（可以使用）

更改给底盘模式
2023/2/13
解決小陀螺問題

2023/2/14
完整更改操作模式（80%） keyi_ste_4_dafu_RC_1_shootTest


统一遥控器对外输出值（没有问题）//    2/17

2023/2/17
接收到底盘传送上来的数据（没有问题）
更改发送视觉的数据，增加至15位 ，敌方血量最低机器人ID及血量

增加发射热量限制

2023/3/3
电脑控制发射逻辑更改

2023/3/6
解决云台切换模式时，甩头问题
解决PC端控制小陀螺出现间断性前进问题（输入数据进行了斜坡，导致）

2023/3/7
增加上位机（用不了）

2023/3/8
更改yaw pit轴普通pid参数
更改发给视觉的子弹速度及id
解决拨盘开启摩擦轮bug
2023/3/9
加入舵机

更改PC端单发逻辑 以及自瞄PIT轴限位 
增加击打小陀螺模式（未测试）

2023/3/13
更改射击逻辑方式，增加自动击打；更改操作逻辑

2023/3/20
接收到底盘传输的枪管射频，根据底盘的线性热量限制来发送弹丸
2023/3/21
增加等待陀螺仪数据初始化正常时云台才会运动，才会给底盘发送数据
增加蜂鸣器但是好像有问题（未测试）
2023/3/23
更改自动击打时发送逻辑

2023/3/30
发现小陀螺自动击打时如果加视觉 是否识别到目标这个条件时，射频会频繁超出20 
增加射频>20的判断（未实战测试）测试过可用

2023/4/1
加入OLED代码（未测试）
更改发给视觉ID及模式方式

2023/4/5
增加射速自调整（未测试）& 开启摩擦轮时会开红外
换了摩擦轮之后还要测试弹速
改小陀螺的全向移动公式的角度及使用cos_f32函数


改射频

//4 20 
自旋不走的时候就进行变速小陀螺，检测到键盘wasd键按下时不进行变速小陀螺。

更改按键长按转按住


///  5/5 新舵轮
更改遥控器控制函数放进中断里面，因为放在任务里面会导致检测时间太快了（注意 改了之后小陀螺有问题）
更改拨盘逻辑，取消了每拨出去一次重置一下目标角度，和每设置一颗弹丸就重置一下目标角度

///  5/9 
更改云台参数

5/12
更改云台传输的状态标志位

舵机可以用
5/13
更改舵机定时器通道
加入等待电机不处于离线模式遥控器才能有值，解决锁底盘模式遥控器值突变问题（解决）
增加UI刷新键位

5/15
更改射频(还是会)
小陀螺模式下还是会超， 减少射频标志位由4减为1

5/16
加入热量延时发弹 目前还行
5/17
增加对角模式，狂暴模式
增加小陀螺之后的反向跟随过度，更好的在自旋后前进

5/20
更改云台限幅方法（有点小BUG）
更改一些键鼠操作逻辑
可以显示UI了
加入对角模式传输标志位

//优化键鼠模式下的反向跟随


5/21
取消等待云台初始化完成才能发数据给地盘
更改遥控模式下的小陀螺云台输入量（不然会周期性突然增加目标值）（未测试）（可以使用）
加入键鼠模式下的无跟随模式（同时按住ZXC键）（未测试）（可以使用）
取消对角模式
pit限幅解决
5/22
pit都使用码盘限幅
更改80瓦功率下速度由6500变为7500
100瓦功率 由8500转为8000
取消变速小陀螺

5/23
对大符模式下的视觉数据进行低通处理  
更改发送给视觉的数据，由15位改为13位 去除敌方机器人ID和血量（未测试）（可以使用）

q改键鼠
自动击打由X改为V，
注释无跟随模式

右舵机改用定时器1通道1

5/24
更改云台yaw轴PID参数内环P由300改为280

打符模式下进行滑动平均滤波进行过滤（未测试）

增加拨盘重启底盘（未测试）（可以）

5/25
右舵机改回定时器8通道2

6/1
增加等待云台初始化完成才能发数据给地盘

出现车不受控制问题，具体表现所有电机处在伺服状态，车一直时小陀螺自旋不受遥控器控制，除非关闭遥控器才会失能。
失控前当时车的右舵机出现跳来跳去的现象，初步怀疑是由于舵机影响的

6/3
更改定时器通道，将左舵机和右舵机的插口更改