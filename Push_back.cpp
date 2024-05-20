#include <iostream>
#include <vector>
#include<chrono>


using namespace std;

int main(){

    vector<int> vec1 , vec2;
    // Reserve memory for 1000000000 elements
    vec1.reserve(1000000000);
    std::chrono::duration<double> totalDiff1(0);
    auto start1 = std::chrono::high_resolution_clock::now();
    // Push elements into the vector
    for (int i = 0; i < 1000000000; ++i) {
        vec1.push_back(i);
    }
    auto end1 = std::chrono::high_resolution_clock::now();
    totalDiff1 = end1 -start1;

    cout<<" The timing used to push elements into the vector with memory allocation is: "<<totalDiff1.count()<< endl;



    std::chrono::duration<double> totalDiff2(0);
    auto start2 = std::chrono::high_resolution_clock::now();
    // Push elements into the vector
    for (int i = 0; i < 1000000000; ++i) {
        vec2.push_back(i);
    }
    auto end2 = std::chrono::high_resolution_clock::now();
    totalDiff2 = end2 -start2;

    cout<<" The timing used to fill the vector without memory allocation is: "<<totalDiff2.count()<< endl;



}