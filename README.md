# Turing Machine

This is Simulated Turing Machine of Computational Theory.


## Development Environment
Programming language: C++

Compilation: minGW-based using Cmake

IDE: VScode

Development framework: QT

## Introduction
A simple Turing machine applet which can realize the reading of paper tape and determine whether the paper tape conforms to the rules.

The rules can be modified by yourself, in the bin folder of the ruler.txt. The default rule inside is to recognize 0^(n^2) paper tape.

Unlike many programs developed in the QT framework, mine attempted to be developed and compiled on VSCode, so instead of compiling with QT's Qmake I compiled with Cmake, which is used by more people.

## Functions in detail
readRuler function is used to read the rules;

printPaper function is used to output the paper tape;

checkPaper function is used to determine whether the paper can be read by the Turing machine;

loadRuler function is used to import rules;

inputPaper function is used to input the paper tape;

The move function is used to determine the movement of the paper tape.

# 图灵机

计算理论的图灵机模拟

## 开发环境
编程语言：C++

编译：基于minGW使用Cmake编译

IDE：VScode

开发框架：QT

## 介绍
一个简易的图灵机小程序，可以实现纸带的读取，判断纸带是否符合规则。

规则可以自己修改，在bin文件夹的ruler.txt内。其中里面的默认规则是识别0^(n^2)的纸带。

和许多QT框架开发的程序不同的是，我的程序尝试在VSCode上进行开发和编译，因此我并没有使用QT的Qmake编译而是使用更多人使用的Cmake编译。

## 函数详解
readRuler函数用于读取规则；

printPaper函数用于输出纸带；

checkPaper函数用于判断纸带是否可被图灵机读取；

loadRuler函数用于导入规则；

inputPaper函数用于输入纸带；

move函数用于判断纸带的移动。
