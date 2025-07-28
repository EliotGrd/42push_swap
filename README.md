<h1 align="center">
	Push Swap
</h1>
<p align="center">
	Basically a Quicksort but in three chunks
</p>

## 📊 How it works ?
Push Swap is a exercise where you need to explore sorting algorythms and concepts like algorytm complexity.\
In this exercise you have two stacks that you need to sort only with specific operations and with the minimal operations possible.\

My push swap algorythm is based on this article by Ulysse Gerkens (https://medium.com/@ulysse.gks/push-swap-in-less-than-4200-operations-c292f034f6c0) and talks with other students.\
\
Also before starting, dont look or take as example the parsing, it is really bad.\
For deeper explanations look at the medium article.\
\
First we assume that the two stacks (in my case double linked lists) can be divided in two, so we can access to the top or the bottom of each stack. You need to visualise it like it is four different containers that we can access with very few operations.\
The algorythm looks like a quicksort, it divide recursivly the "chunks" in thirds and move them the others "location" depending of the chunk's own location. Each of these new three chunks contains all min, middle or maximum values. It is a bit annoying to do so much always depending of the location but the result is here.\
We divide chunks until each chunk are composed of 3 or less digit, then starting from the max chunk we sort them and move them into the top of the first stack. And it is there that you say thanks to recursivity, because it sort all by itself ! GG you sorted the stack !\

## 📈 Now, the stats !
For the maximum score I needed to sort in less than :\
- 700 operations for a list of 100 numbers  
- 5500 operations for a list of 500 numbers  
  
My scores on 10000 tests :  
- For 100 numbers  
Worst : 677  
Average : 665  
Best : 650  
Standart Deviation : 3.1  
  
- For 500 numbers  
Worst :4446  
Average :4411  
Best :4372  
Standart Deviation :10.0  
  
I used the complexity tester to get these stats (great tool by SimonCROS : https://github.com/SimonCROS/push_swap_tester)\

## 🖐️ How to use ? 
Git clone the repo, make and make_bonus if you want the checker and you're done !\
You can test with any list of numbers like so ```./push_swap 9 2 5 8 1 0```\
For the checker simply pipe the result like so ```./push_swap 9 2 5 8 1 0 | ./checker 9 2 5 8 1 0```\
You can also set the list in the $ARG so ```ARG="9 2 5 8 1 0"; ./push_swap $ARG | ./checker $ARG```
