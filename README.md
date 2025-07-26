<h1 align="center">
	Push Swap !
</h1>
<p align="center">
	Basically a Quicksort but in three chunks
</p>

## 📊 How it works ?
Push Swap is a exercise where you need to explore sorting algorythms and concepts like algorytm complexity.\
In this exercise you have two stacks that you need to sort only with specific operations and with the minimal operations possible.\

My push swap algorythm is based on this article by Ulysse Gerkens (https://medium.com/@ulysse.gks/push-swap-in-less-than-4200-operations-c292f034f6c0) and talks with other students.\
Also before starting, dont look or take as example the parsing, it is really bad.\
For deeper explanations look at the medium article.\
First we assume that the two stacks (in my case double linked lists) can be divided in two, so we can access to the top or the bottom of each stack. You need to visualise it like it is four different containers that we can access with very few operations.\
The algorythm looks like a quicksort, it divide recursivly the "chunks" in thirds and move them the others "location" depending of the chunk's own location. It is a bit annoying to do so much always depending of the location but the result is here.\
We divide chunks until each chunk are 

## 🖐 How to use ? 
