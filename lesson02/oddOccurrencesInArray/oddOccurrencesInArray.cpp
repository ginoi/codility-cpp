#include <vector>
#include <iostream>
//has table
#include <unordered_set>

using namespace std;

int solution(vector<int> &A)
{
    unordered_set<int> pairs ;
    for (auto &a:A) {
        auto it = pairs.find(a);
        
        if (it != pairs.end()) {
            // found the key

            pairs.erase(a);    
        } else {
            // not found
            pairs.emplace(a);
        }
    }
    return *pairs.begin();
}

void TestOddOccurrencesInArray(int answer, vector<int> &A)
{
    cout << ((answer == solution(A)) ? "PASS" : "FAIL") << endl;
}

int main (){
    //A[0] = 9  A[1] = 3  A[2] = 9
    //A[3] = 3  A[4] = 9  A[5] = 7
    //A[6] = 9
    vector<int> A{9,3,9,3,9,7,9};
    TestOddOccurrencesInArray(7, A);

    return 0;
}