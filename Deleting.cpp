#include <iostream>
#include <list>
#include <vector>
#include <map>
#include <chrono>

void testList(int size) {
    std::list<int> lst;
    for (int i = 0; i < size; i++) {
        lst.push_back(i);
    }

    int numIterations = 10;
    std::chrono::duration<double> totalDiff(0);

    for (int i = 0; i < numIterations; i++) {
        auto it = lst.begin();
        std::advance(it, size / 2);
        auto start = std::chrono::high_resolution_clock::now();
        lst.erase(it);
        auto end = std::chrono::high_resolution_clock::now();
        totalDiff += end - start;
    }

    std::chrono::duration<double> avgDiff = totalDiff / numIterations;
    std::cout << "List of size " << size << ": " << avgDiff.count() << " seconds" << std::endl;
}
void testVector(int size) {
    std::vector<int> vec;
    for (int i = 0; i < size; i++) {
        vec.push_back(i);
    }

    int numIterations = 10;
    std::chrono::duration<double> totalDiff(0);

    for (int i = 0; i < numIterations; i++) {
        auto start = std::chrono::high_resolution_clock::now();
        vec.erase(vec.begin() + size / 2);
        auto end = std::chrono::high_resolution_clock::now();
        totalDiff += end - start;
    }

    std::chrono::duration<double> avgDiff = totalDiff / numIterations;
    std::cout << "Vector of size " << size << ": " << avgDiff.count() << " seconds" << std::endl;
}

void testMap(int size) {
    std::map<int, int> mp;
    for (int i = 0; i < size; i++) {
        mp[i] = i;
    }

    int numIterations = 10;
    std::chrono::duration<double> totalDiff(0);

    for (int i = 0; i < numIterations; i++) {
        auto it = mp.find(size / 2);
        auto start = std::chrono::high_resolution_clock::now();
        mp.erase(it->first);
        auto end = std::chrono::high_resolution_clock::now();
        totalDiff += end - start;
    }

    std::chrono::duration<double> avgDiff = totalDiff / numIterations;
    std::cout << "Map of size " << size << ": " << avgDiff.count() << " seconds" << std::endl;
}

int main(){
    int sizes[] = {100, 500, 1000, 2000, 5000, 10000, 50000, 100000};
    for (int size : sizes) {
        testList(size);
        testVector(size);
        testMap(size);
    }
}