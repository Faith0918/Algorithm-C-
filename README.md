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
>>>> 2) Update minimum value
>>>>
>>>> **Note**
>>>>> 1) Be careful of the data type choice.
>>>>
>>>> **Unsolved**
>>>>> 1) I get TLE for the second testcase.
>>>>> 2) I asked about it on Stack Overflow.
>>>
>>> **Solution Code**
>>>
>>>> [combination_lock.cpp](combination_lock.cpp)

