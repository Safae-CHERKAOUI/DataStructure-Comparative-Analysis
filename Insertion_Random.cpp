#include <iostream>
#include <vector>
#include <random>
#include <list>
#include <chrono>
#include <map>

std::vector<int> Positions_Generator(){

    std::vector<int> Pos;
    int sizes[] = {100, 500, 1000, 2000, 5000, 10000, 50000, 100000};

    std::random_device rd;
    std::mt19937 mt(rd());

    int min = 0;

    for (int max:sizes){
        std::uniform_int_distribution<int> dist(min, max); // create a uniform distribution between min and max
        Pos.push_back(dist(mt)); // generate a random number within the range
                        }       
    return Pos;
                                    }

void testList(int size, int position) {
    std::list<int> lst;
    for (int i = 0; i < size; i++) {
        lst.push_back(i);
    }

    int numIterations = 100;
    std::chrono::duration<double> totalDiff(0);

    for (int i = 0; i < numIterations; i++) {
        auto it = lst.begin();
        std::advance(it, position);
        auto start = std::chrono::high_resolution_clock::now();
        lst.insert(it, 42);
        auto end = std::chrono::high_resolution_clock::now();
        totalDiff += (end - start);
    }

    std::chrono::duration<double> avgDiff = totalDiff / numIterations;
    std::cout << "The insertion in a list of size " << size << " at the position "<< position <<": "<< avgDiff.count() << " seconds" << std::endl;
}

void testVector(int size, int position) {
    std::vector<int> vec;
    for (int i = 0; i < size; i++) {
        vec.push_back(i);
    }

    int numIterations = 100;
    std::chrono::duration<double> totalDiff(0);

    for (int i = 0; i < numIterations; i++) {
        auto it = vec.begin();
        std::advance(it, position);
        auto start = std::chrono::high_resolution_clock::now();
        vec.insert(it, 42);
        auto end = std::chrono::high_resolution_clock::now();
        totalDiff += (end - start);
    }

    std::chrono::duration<double> avgDiff = totalDiff / numIterations;
    std::cout << "The insertion in a vector of size " << size << " at the position "<< position <<": "<< avgDiff.count() << " seconds" << std::endl;
}

void testMap(int size, int position) {
    std::map<int, int> mp;
    for (int i = 0; i < size; i++) {
        mp[i] = i;
    }

    int numIterations = 100;
    std::chrono::duration<double> totalDiff(0);

    for (int i = 0; i < numIterations; i++) {
        auto start = std::chrono::high_resolution_clock::now();
        mp[position] = 42;
        auto end = std::chrono::high_resolution_clock::now();
        totalDiff += (end - start);
    }

    std::chrono::duration<double> avgDiff = totalDiff / numIterations;
    std::cout << "The insertion in a map of size " << size << " at the position "<< position <<": "<< avgDiff.count() << " seconds" << std::endl;
}


int main() {

    std::vector<int> Pos = Positions_Generator();
    // for (int i = 0; i < Pos.size(); i++) {
    //         std::cout << Pos[i] << " ";
    //                                     }
    std::vector<int> sizes = {100, 500, 1000, 2000, 5000, 10000, 50000, 100000};

    for (int i =0; i<sizes.size(); i++){
        testList(sizes[i],Pos[i]);
        testVector(sizes[i],Pos[i]);
        testMap(sizes[i],Pos[i]);
    }
   
    return 0;
}