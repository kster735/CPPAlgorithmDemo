#include <iostream>
#include <vector>
#include <algorithm>

//Sorting a vector of integers using the make_heap(), push_heap()
//and pop_heap algorithms.

/***********************************************************
//This code bit is isnspired from Jonathan Boccara's speech
//"105 STL Algorithms in Less Than an Hour" 
//given at the 2018 CppCon
//https://www.youtube.com/watch?v=2olsGf6JIkU&t=1022s
*//////////////////////////////////////////////////////////

using namespace std;

int main(){
    vector<int> v{3,2,5,6,0,-3};

    for (const auto& i: v){
        cout << i << " ";
    }

    // Use the following if prior to C++11
    // for (vector<int>::const_iterator i = v.cbegin(); i != v.cend(); ++i){
    //     cout << *i << " ";
    // }

    make_heap(begin(v), end(v));
    push_heap(begin(v), end(v));

    //Every time you push a new element at the vector
    //you need to push_heap() again the whole vector
    //in order to "bubble" up the new element at the 
    //right position on the max-heap tree.
    //

    v.push_back(9);
    push_heap(begin(v), end(v));
    
    
    //If you ommit the last line 
    // i.e. "push_heap(begin(v), end(v));"
    //the sorting will not work!
    //try it


    cout << "\nOk" <<endl;

    for (const auto& i: v){
        cout << i << " ";
    }
    cout << "\nOk" <<endl;

    auto it = v.end();
    for (int j=0; j<v.size(); ++j){
        //Define a temp vector at each for loop iteration which
        //contains the first v.size() - j elements. After every jth
        //iteration j+1 elements have been "bubbled" at the end of the
        //v vector. Thus only the first v.size() - j + 1 remain to be
        //sorted.
        vector<int> temp(v.begin(), it - j);
        
        //This is the line that actually bubbles down the max element of
        //the heap.
        pop_heap(begin(temp), end(temp));

        //Assign the first v.size()-j+1 elements of the altered
        //temp vector back to the first elements of the original
        //v vector. Thus the pop_heap algorithm will pop the next max element at
        //the end of the new heap vector without altering the last 
        //elements which are allready sorted.
        //Be aware that it's not the elements of temp vector that are sorted,
        //At the end of every iteration the last element of temp should be coppied
        //at the same position on v. The rest of the temp elements should be coppied 
        //anyways for the pop_heap() algorith to work on the remaining unsorted elements
        //We cannot ommit to copy these because the v vector will still contain
        //the max element which has been popped.

        for (int k=0; k < v.size()-j; k++){
            v[k] = temp[k];
        }

        //This use of algorith is only for education.
        //It should be better to sort the vector with the sort algorithm.
    }

    //Uncomment the next line if you want the sorted
    //vector in a reversed order:
    //reverse(v.begin(), v.end());

    for (const auto& i: v){
        cout << i << "";
    }
    cout << "\nOk" <<endl;

}