> # Problem Solving in C++
>
>> This is where I leave my problem solving process and the c++ solution code.

> ## Solved Problems
>
>> Problem #1: [kick start](#problem-1)
>>
>> Problem #2: [maximum coins](#problem-2)
>>
>> Problem #3: [combination lock](#problem-3)
>>
>> Problem #4: [allocation](#problem-4)
>>
>> Problem #5: [plates](#problem-5)
>>
>> Problem #6: [workout](#problem-6)
>>
>> Problem #7: [two sum](#problem-7)
>>
>> Problem #8: [palindrome number](#problem-8)
>>
>> Problem #9: [reverse integer](#problem-9)
>>
>> Problem #10: [city finding](#problem-10)
>>
>> Problem #11: [eureka](#problem-11)
>>
>> Problem #12: [decomposition sum](#problem-12)
>>
>> ### Problem #1
>>
>>> **Problem Link** 
>>>
>>>> [Kick Start 2020 RoundG - Kick Start](https://codingcompetitions.withgoogle.com/kickstart/round/00000000001a0069/0000000000414bfb) 
>>>
>>> **Solution process**
>>>
>>>> 1) Count number of a word "kick" from the begining of the sentence.
>>>> 2) When a word "start" shows up, add number of a word "kick" to the answer.
>>>>
>>>> **Note**
>>>>> 1) Make sure the substr input is covered in the string size. 
>>>>> 2) Don't make extra unneccessary addition in scanning characters.
>>>
>>> **Solution Code**
>>>>
>>>> [kick_start.cpp](kick_start.cpp)
>>
>> ### Problem #2
>>
>>> **Problem Link** 
>>>
>>>> [Kick Start 2020 RoundG - Maximum Coins](https://codingcompetitions.withgoogle.com/kickstart/round/00000000001a0069/0000000000414a23)
>>>
>>> **Solution process**
>>>
>>>> 1) Calculate every possible candidates.
>>>> 2) Update the maximum result to the answer.
>>>>
>>>> **Note**
>>>>> Make sure the possible maximum is covered in the type of int.
>>>
>>> **Solution Code**
>>>
>>>> [maximum_coins.cpp](maximum_coins.cpp)
>>
>> ### Problem #3
>>
>>> **Problem Link** 
>>>
>>>> [Kick Start 2020 RoundG - Combination Lock](https://codingcompetitions.withgoogle.com/kickstart/round/00000000001a0069/0000000000414a24)
>>>
>>> **Solution process**
>>>
>>>> 1) Calculate the number of moves wheels have to make for every numbers(1-N).
>>>> 2) Update the minimum value.
>>>>
>>>> **Note**
>>>>> 1) Be careful of data type choices.
>>>>
>>>> **Unsolved**
>>>>> 1) I get a TLE for the second testcase.
>>>>> 2) I asked about it on Stack Overflow.(deleted)
>>>
>>> **Solution Code**
>>>
>>>> [combination_lock.cpp](combination_lock.cpp)
>>
>> ### Problem #4
>>
>>> **Problem Link** 
>>>
>>>> [Kick Start 2020 RoundA - Allocation](https://codingcompetitions.withgoogle.com/kickstart/round/000000000019ffc7/00000000001d3f56)
>>>
>>> **Solution process**
>>>
>>>> 1) Sort house prices in ascending order.
>>>> 2) Get the maximum number of houses under buget.
>>>
>>> **Solution Code**
>>>
>>>> [allocation.cpp](allocation.cpp)
>>
>> ### Problem #5
>>
>>> **Problem Link** 
>>>
>>>> [Kick Start 2020 RoundA - Plates](https://codingcompetitions.withgoogle.com/kickstart/round/000000000019ffc7/00000000001d40bb)
>>>
>>> **Solution process**
>>>
>>>> 1) Try every combination of number of plates to take from each stack.
>>>> 2) Update the maximum value.
>>>
>>>> **Note**
>>>>> 1) Combination with repitition : Implementable with DFS algorithm(back tracking)
>>>>
>>>> **Unsolved**
>>>>> 1) I get a TLE for the second testcase.
>>>>> 2) I wonder what could be a faster algorithm than DFS that I used.
>>>
>>> **Solution Code**
>>>
>>>> [plates.cpp](plates.cpp)
>>
>> ### Problem #6
>>
>>> **Problem Link** 
>>>
>>>> [Kick Start 2020 RoundA - Workout](https://codingcompetitions.withgoogle.com/kickstart/round/000000000019ffc7/00000000001d3f5b)
>>>
>>> **Solution process**
>>>
>>>> 1) 
>>>> 2) 
>>>
>>>> **Note**
>>>>> 1) 
>>>
>>> **Solution Code**
>>>
>>>> [workout.cpp](workout.cpp)
>>
>> ### Problem #7
>>
>>> **Problem Link** 
>>>
>>>> [LeetCode - Two Sum](https://leetcode.com/problems/two-sum/)
>>>
>>> **Solution process**
>>>
>>>> 1) Sort input numbers in an ascending order.
>>>> 2) Check if two sum equals to target number until two sum is smaller than the target number.
>>>
>>> **Solution Code**
>>>
>>>> [two_sum.cpp](two_sum.cpp)
>>
>> ### Problem #8
>>
>>> **Problem Link**
>>>
>>>> [Leet Code - Palindrome Number](https://leetcode.com/problems/palindrome-number/)
>>>
>>> **Solution Process**
>>>
>>>> 1) Cast int to string.
>>>> 2) Check if front characters are the same as back characters.
>>>
>>> **Solution Code**
>>>
>>>> [palindrome_number.cpp](palindrome_number.cpp)
>>
>> ### Problem #9
>>
>>> **Problem Link**
>>>
>>>> [Leet Code - Reverse Integer](https://leetcode.com/problems/reverse-integer/)
>>>
>>> **Solution Process**
>>>
>>>> 1) Check the integer sign.
>>>> 2) Find the lowest digit of input.
>>>> 3) Update reverse number.
>>>> 4) Divide input by 10.(Delete the used digit of input.)
>>>> 5) Check overflow before multiplying reverse number by 10.
>>>> 6) Repeate.
>>>
>>> **Solution Code**
>>>
>>>> [reverse_integer.cpp](reverse_integer.cpp)
>>
>> ### Problem #10
>>
>>> **Problem Link**
>>>
>>>> [BAEKJOON - 특정거리의 도시 찾기(City Finding)](https://www.acmicpc.net/problem/18352)
>>>
>>> **Solution Process**
>>>
>>>> DFS
>>>> 1) Put first node(city) to visit and check as visited.
>>>> 2) Find the adjacent nodes and visit if those exists. If not, pop the first node.
>>>> 3) Repeate until stack is empty.
>>>
>>> **Solution Code**
>>>
>>>> [city_finding_DFS.cpp](city_finding_DFS.cpp)
>>>> [city_finding_BFS.cpp](city_finding_BFS.cpp)
>>
>> ### Problem #11
>>
>>> **Problem Link**
>>>
>>>> [BAEKJOON - 유레카 이론(Eureka)](https://www.acmicpc.net/problem/10448)
>>>
>>> **Solution Process**
>>>
>>>> DFS
>>>> 1) Put first node(city) to visit and check as visited.
>>>> 2) Find the adjacent nodes and visit if those exists. If not, pop the first node.
>>>> 3) Repeate until stack is empty.
>>>
>>> **Solution Code**
>>>
>>>> [eureka.cpp](eureka.cpp)
>>
>> ### Problem #12
>>
>>> **Problem Link**
>>>
>>>> [BAEKJOON - 분해합(decomposition sum)](https://www.acmicpc.net/problem/2231)
>>>
>>> **Solution Process**
>>>
>>>> DFS
>>>> 1) Put first node(city) to visit and check as visited.
>>>> 2) Find the adjacent nodes and visit if those exists. If not, pop the first node.
>>>> 3) Repeate until stack is empty.
>>>
>>> **Solution Code**
>>>
>>>> [decomposition_sum.cpp](decomposition_sum.cpp)
>>
