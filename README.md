# 功能描述
1.开机动画:读取img文件下的30张图片，以一定的延时显示出来

2.登录:先通过触摸屏键盘输入管理员账号登录到管理员界面，管理员账号是固定的账号

3.注册:通过触摸屏键盘输入要新增的用户的账号和密码,点击<注册>通过单链表将数据写入文件中.

4.显示用户:将文件中的数据读取到链表中,并在开发板上显示用户的头像和账号.

5.充电设置:通过屏幕上的加减号来增加和减少直流电和交流点每分钟收费标准,点击<确定>写入到文件中去.

6.正在充电:点击<正在充电>,开始计时,当点击<结束>,结束计时,并计算出充电时间和总费用.
# 文档说明
* Source Code\images\img：保存系统需要的文件.0.bmp~30.bmp是开机动画的照片
  
* Source Code\project:保存所有工程代码
  
  1. bin:可执行文件
    
  2. include:头文件
    
  3. src:保存所有的.c文件
  #程序说明
  * Source Code\project\src\Makefile:工程管理器文件
  
* Source Code\project\src\main.c:主代码
  
* Source Code\project\src\display_bmp.c:显示图片的代码
  
* Source Code\project\src\logic.c:登录界面的代码:点击键盘的函数\登录的首页函数
  
* Source Code\project\src\root.c:管理员界面:show_user()显示用户函数\add_user()增加用户函数\power()充电设置函数
  
* Source Code\project\src\touch.c:触摸屏打开和获取点击
  
* Source Code\project\src\user.txt:用户文件
  
* Source Code\project\src\power.txt:直流电交流电文件
  
