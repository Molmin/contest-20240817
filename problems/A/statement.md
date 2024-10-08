## 题目背景

jiazhichen844 在全球知名算法竞赛中获得了两个第 **十二** 名。

![](file://jiazhichen844.png)

Limie 内卷的时候想要看题解，但是把一个 CodeForces 题目题号拆分成比赛编号和题目序号太麻烦了！他希望你能帮他写一个工具让这个过程更加方便。

## 题目描述

给定一个 CodeForces 题目编号，你需要打印这道题目的链接。

具体地，比赛编号是一个不超过 $844844$ 的正整数，题目序号是一个长度为 $1$ 或者 $2$ 的字符串，要么是单个大写字母，要么是单个大写字母和单个数字连接得到的字符串。题目编号则是前缀 `CF` 与这两个字符串拼接组成的字符串。而在 CodeForces 中，你需要访问地址 `https://codeforces.com/contest/<CONTESTID>/problem/<PROBLEMID>` 来访问这道题目，其中 `<CONTESTID>` 表示该题目的比赛编号，`<PROBLEMID>` 则表示该题目的题目序号。

## 输入格式

输入包含一个字符串，表示题目编号。

## 输出格式

输出包含一个字符串，表示题目的链接。

```input1
CF844A
```

```output1
https://codeforces.com/contest/844/problem/A
```

## 子任务

对于所有数据，保证比赛编号是一个不超过 $844844$ 的正整数，题目序号是一个长度为 $1$ 或者 $2$ 的字符串，要么是单个大写字母，要么是单个大写字母和单个数字连接得到的字符串，输入的字符串是是前缀 `CF` 与这两个字符串拼接组成的字符串。

子任务 1（$50$ 分）：保证题目序号只包含一个字符。

子任务 2（$50$ 分）：无特殊限制。

## 提示

不保证输入中给定的题目编号真实存在。
