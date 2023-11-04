# TuringMachine-NEU-ComputationalTheory

This is Course Design (optional) of Computational Theory.



Programming language: C++

Compilation: minGW-based using Cmake

IDE: VScode

Development framework: QT



A simple Turing machine applet which can realize the reading of paper tape and determine whether the paper tape conforms to the rules.

The rules can be modified by yourself, in the bin folder of the ruler.txt. The default rule inside is to recognize 0^(n^2) paper tape.

Unlike many programs developed in the QT framework, mine attempted to be developed and compiled on VSCode, so instead of compiling with QT's Qmake I compiled with Cmake, which is used by more people.

In fact, very quickly done, the first time in VSCode to write QT program is only a few days ago, I strongly recommend that the use of QT framework for everyone to try in the mainstream IDEs such as VSCode can be equipped with QT support compilation environment, programming process is very comfortable.



Functions in detail:

readRuler function is used to read the rules;
printPaper function is used to output the paper tape;
checkPaper function is used to determine whether the paper can be read by the Turing machine;
loadRuler function is used to import rules;
inputPaper function is used to input the paper tape;
The move function is used to determine the movement of the paper tape.

If your Turing machine course Design has been helped, don't forget to point a star, thank you!


东北大学计算理论选做课设

编程语言：C++

编译：基于minGW使用Cmake编译

IDE：VScode

开发框架：QT



一个简易的图灵机小程序，可以实现纸带的读取，判断纸带是否符合规则。

规则可以自己修改，在bin文件夹的ruler.txt内。其中里面的默认规则是识别0^(n^2)的纸带。

和许多QT框架开发的程序不同的是，我的程序尝试在VSCode上进行开发和编译，因此我并没有使用QT的Qmake编译而是使用更多人使用的Cmake编译。

其实很快就做好了，第一次在VSCode上写QT程序也不过是几天前的事，我强烈推荐使用QT框架的大家尝试在主流IDE例如VSCode中搭载可支持QT的编译环境，编程过程很舒服。



函数详解：

readRuler函数用于读取规则；
printPaper函数用于输出纸带；
checkPaper函数用于判断纸带是否可被图灵机读取；
loadRuler函数用于导入规则；
inputPaper函数用于输入纸带；
move函数用于判断纸带的移动。

如果对您的图灵机课设有帮助别忘了点个star哦，谢谢大家。
