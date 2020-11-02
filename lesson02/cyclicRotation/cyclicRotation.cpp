#include <iostream>
#include <vector>

using namespace std;

vector<int> solution(vector<int> &A, int K)
{
    if (A.empty()) {
        return vector<int>();
    }

    vector<int> rotatedA;
    
    K = K % A.size();
    rotatedA.insert(rotatedA.begin(), A.begin(), A.begin() + (A.size() - K));
    rotatedA.insert(rotatedA.begin(), A.begin() + (A.size() - K), A.end());

    return rotatedA;
}


void TestCyclicRotation(vector<int> &ans, vector<int> &A, int K)
{
    vector<int> res = solution(A, K);
    for (auto &a:res)
        std::cout << a <<std::endl;
    std::cout << ((ans == solution(A, K)) ? "PASS" : "NG") << std::endl;
}
int main ()
{
    vector<int> A{3, 8, 9, 7, 6};
    vector<int> answer{9, 7, 6, 3, 8};
    //A = [3, 8, 9, 7, 6]
    //K = 3
    //answer = [9, 7, 6, 3, 8]

    TestCyclicRotation(answer, A, 3);

    //A = [0, 0, 0]
    //K = 1
    //the function should return [0, 0, 0]
    vector<int> A2{0,0,0};
    vector<int> answer2{0,0,0};
    TestCyclicRotation(answer2, A2, 1);

    //A = [1, 2, 3, 4]
    //K = 4
    //the function should return [1, 2, 3, 4]
    vector<int> A3{1,2,3,4};
    vector<int> answer3{1,2,3,4};
    TestCyclicRotation(answer3, A3, 4);

    return (0);
}
