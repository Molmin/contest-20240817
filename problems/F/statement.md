## 题目背景

ls 职业技术学院和 lx 职业技术学院的小 A 和小 B 都很喜欢念经。

## 题目描述

小 A 有一个念经的节奏，这个节奏可以用一个序列 $a_1, a_2, \cdots, a_n$ 来表示。其中，如果 $a_i = 1$ 就表示 $i$ 时刻小 A 在念经，否则表示小 A 在休息。类似地，小 B 也有一个念经的节奏 $b_1, b_2, \cdots, b_n$。同时，小 A 和小 B 还分别有一个疲劳指数 $x,y$，要求每个人在这 $n$ 个时刻中念经的时刻数正好为自己的疲劳指数。

一天中，小 A 和小 B 同时在念经，并且任意一个人按照自己的节奏念完一轮（我们称正好经过 $n$ 个时刻为一轮）经之后立刻继续按照该节奏念经。每天，由于小 A 和小 B 起床时间的差异，两个人开始念经的时间不同。小 A 起床时间比小 B 早（或同时），但是小 B 在小 A 念完第一轮经之前起床。每天小 A 和小 B 起床的时间差可能不同。

如果一个时刻小 A 和小 B 都没有在休息而是都在念经，那么此时观众会感到非常兴奋。我们称在小 A 和小 B 起床的时间差不同时，连续 $n$ 个时刻观众的最大兴奋的时刻数最大值为兴奋指数。

lhs 职业技术学院的吃瓜群众 \*o\*a\*a 想要知道对于确定的 $n,x,y$，在怎样的念经序列所产生的兴奋指数最小。

**形式化题意：** 给定 $n,x,y$，构造两个长度为 $n$、只包含 `0` 或者 `1` 的、分别包含 $x,y$ 个 `1` 的字符串 $a,b$，最小化在 $b$ 任意循环位移时，$a,b$ 均为 `1` 的位置的最大值。

## 输入格式

一行，包含三个整数 $n,x,y$。

## 输出格式

第一行包含一个整数表示最小的兴奋指数值。

第二行和第三行分别包含一个长度为 $n$ 的字符串表示 $a$ 和 $b$，其中包含字符 `0` 或者 `1`，第 $i$ 个字符表示 $a_i$ 或者 $b_i$ 的值。

```input1
6 4 3
```

```output1
2
011011
101010
```

## 评分标准

本题采用 Special Judge，如果你输出的第一行正确，并且所作出的构造的最小兴奋指数值不为第一行的答案，则你得到该测试点 $50\%$ 的分数（向下取整）。**注意，此时你仍然需要保证后两行的格式正确。**

如果你输出的第一行正确，后两行也正确，则你得到该测试点的全部分数。

你在一个子任务中的得分为你在该子任务所有测试点的得分的最小值。

## 子任务

对于所有数据，保证 $1 \leq n \leq 5 \times 10^5$，$0 \leq x,y \leq n$。

子任务 1（$10$ 分）：保证 $n \leq 12$。

子任务 2（$8$ 分）：保证 $x,y \leq 5$，$n \geq 100$。

子任务 3（$12$ 分）：保证 $x \leq 5$，$n \geq 100$。

子任务 4（$20$ 分）：保证 $\gcd(n,x) = 1$。

子任务 5（$25$ 分）：保证 $n \leq 5 \times 10^3$。

子任务 6（$25$ 分）：无特殊限制。

## 后记

lhs 职业技术学院的吃瓜群众 \*o\*a\*a 决定再也不出这么毒瘤的题目了，因为这题的 Special Judge 程序的文件大小是标准程序的大约 $2.87$ 倍！

如果你不幸 AK 了比赛，你可以思考如何编写本题的 Special Judge，但是这个问题对于能够 AK 本场比赛的选手来说太容易了！
