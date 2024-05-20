#include <iostream>
#include <vector>
#include <random>
#include <list>
#include <chrono>
#include <algorithm>

// Function to generate positions
std::vector<int> Positions_Generator() {
    std::vector<int> Pos;
    int sizes[] = {100, 500, 1000, 2000, 5000, 10000, 50000, 100000};
    std::random_device rd;
    std::mt19937 mt(rd());
    int min = 0;
    for (int max : sizes) {
        std::uniform_int_distribution<int> dist(min, max);
        Pos.push_back(dist(mt));
    }
    return Pos;
}

int main() {
    // Generate positions
    std::vector<int> Pos = Positions_Generator();

    // Map Phase: Apply insertion operation for each size and position

    std::vector<std::chrono::duration<double>> insertionTimes;
    std::vector<int> sizes = {100, 500, 1000, 2000, 5000, 10000, 50000, 100000};

    auto mapFunction = [&](int size, int position) -> std::chrono::duration<double> {
        std::list<int> lst;
        for (int i = 0; i < size; i++) {
            lst.push_back(i);
        }

        auto it = lst.begin();
        std::advance(it, position);

        int numIterations = 100; // Number of iterations for each insertion
        std::chrono::duration<double> totalDiff(0);
        for (int i = 0; i < numIterations; ++i) {
            auto start = std::chrono::high_resolution_clock::now();
            lst.insert(it, 42);
            auto end = std::chrono::high_resolution_clock::now();
            totalDiff += (end - start);
        }

        // Calculate the average time
        std::chrono::duration<double> avgDiff = totalDiff / numIterations;
        return avgDiff;
    };

    std::transform(sizes.begin(), sizes.end(), Pos.begin(), std::back_inserter(insertionTimes),
                   [&](int size, int pos) { return mapFunction(size, pos); });

    // Reduce Phase: Aggregate the insertion times

    for (int i = 0; i < sizes.size(); i++) {
        std::cout << "Average insertion time for a list of size " << sizes[i] << " at the position " << Pos[i]
                  << ": " << insertionTimes[i].count() << " seconds" << std::endl;
    }

    return 0;
}
