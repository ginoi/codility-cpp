#include <iostream>



// given a positive integer N, returns the length of its longest binary gap. 
// The function should return 0 if N doesn't contain a binary gap.
int solution(int N)
{
    bool started = false;
    int longestGap = 0;
    int gap = 0;
    while (N > 0) {
        if (N & 0x1) 
        {
            if (started) {
                if (gap >= longestGap) 
                {
                    // update longest gap
                    longestGap = gap;
                }
                // reset
                gap = 0;
            }
            else
            {
                started = true;
            }
            
        }
        else if (started)
        {
            gap++;
        }
        N >>= 1;
    }
    return longestGap;
}


void BinaryGapTest(int answer, int const N)
{
    int result = solution(N);
    std::cout << " Test:  " << ((result == answer) ? "[PASS]" : "[NG]") << std::flush;
    std::cout << " (The binary gap of number: " << N << " is: " << result << ") " << std::endl;
}

int main()
{
    std::cout << "test starts" << std::endl;

    //561892
    BinaryGapTest(3, 561892);

    // The number 9 has binary representation 1001 and contains a binary gap of length 2. 
    BinaryGapTest(2, 9);

    // The number 529 has binary representation 1000010001 and contains two binary gaps: 
    // one of length 4 and one of length 3. 
    BinaryGapTest(4, 529);

    // The number 20 has binary representation 10100 and contains one binary gap of length 1. 
    BinaryGapTest(1, 20);

    // The number 15 has binary representation 1111 and has no binary gaps. 
    BinaryGapTest(0, 15);

    // The number 32 has binary representation 100000 and has no binary gaps.
    BinaryGapTest(0, 32);

    // 1041 the function should return 5, because N has binary representation 10000010001 
    // and so its longest binary gap is of length 5. 
    BinaryGapTest(5, 1041);

    
    std::cout << "test ends" << std::endl;

}