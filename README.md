# 闺蜜（Girls' Secret）问题 （A motivation to solve websocket's broadcasting cost problem）

![Concept](https://raw.githubusercontent.com/thejourneyofman/girlssecret/master/images/concept.png)

##### 一个正方形网格的每一个房间里住着一位闺蜜。
##### 每一个闺蜜(M)和相邻的闺蜜(M0-M2和O) 要么保持通话状态要么保持窃听状态,但同时只能与一位通话或窃听其中一位。
##### 比如O0有1/3的概率, O2有1/4的概率在窃听M和O的对话。
##### M有一天不小心向闺蜜O说了闺蜜T的一句坏话，由于是爆炸性的，凡是窃听到这个坏话的闺蜜比如O2包括O自身必定会传给其他闺蜜(O2->O20,O21,O22)或者(O->O0,O1,O2),选中闺蜜的概率分别是1/3。
##### 终止条件：每一位闺蜜都后悔八卦，所以只会传一次，比如通过O2,O20和O0的传话再次回到O的时候，O不会再传给其他闺蜜了。
##### 给出闺蜜M和T的房间号(M = (2,1), T=(6,6))和网络边长(N=7)
##### （Q1）请问坏话传到闺蜜T的概率是多少。
##### （Q2）如果有几位闺蜜是Speaker，会将听到的坏话传给相邻的所有闺蜜（也需满足终止条件），请问如何安排最少的闺蜜可以让（Q1的）概率变成100%。

Copyright (c) 2020 Chao (Chase) Xu