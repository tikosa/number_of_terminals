#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

// Taken from hackerrank.com. The problem name is "Trains and Platforms.
//
// Given arrival and departure times of all trains that reach a railway station, find the minimum number of platforms required for the railway station so that no train waits.
//
// Input Format
//
// The first line of input consists of an integer N that represents total number of trains.
//
// The next N lines contain arrival Ta[i] and departure Td[i] time for each train. Time will be given given in 24H format and colons will be omitted for convinience. For ex.: 9:05AM will be given as "905", or 9:10PM will be given as "2110"
//
// Constrains:
//
// 0 < N < 1000
//
// 0000 < T[a] < T[d] < 2359
//
// Output Format
//
// Output integer value of the minimum required platforms.

class Problem
{
public:
    void input()
    {
        int n = 0;
        int a = 0;
        int d = 0;
        std::cin >> n;
        while(n--) {
            std::cin >> a >> d;
            arr.push_back(a);
            dep.push_back(d);
        }

        std::sort(arr.begin(), arr.end());
        std::sort(dep.begin(), dep.end());
    }
    int numOfTerminals() {
        int n = arr.size();
        int i = 0;
        int j = 0;
        int tmp = 0;
        int num_of_terminals = 0;
        while(i < n && j < n) {
            if(arr[i] <= dep[j]) {
                ++i;
                ++tmp;
            } else {
                ++j;
                num_of_terminals = std::max(num_of_terminals, tmp);
                if(arr[i] <= dep[j]) {
                    ++i;
                } else {
                    --tmp;
                }
            }
        }
        
        return std::max(num_of_terminals, tmp);
    }
    
private:
    std::vector<int> arr;
    std::vector<int> dep;
};

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    Problem p;
    p.input();
    std::cout << p.numOfTerminals() << std::endl;
    return 0;
}

