#include <iostream>

/**
 * given three integers X, Y and D, returns the minimal number of jumps from 
 * position X to a position equal to or greater than Y.
 */
int solution(int X, int Y, int D){

    // distance >= D * jumps
    // jumps <= distance / D
    int distance = (Y - X);

    // jumps = distance / D, if distance % D == 0
    // jumps = distance / D + 1, if distance % D != 0
    // jumps = 1, if distance < D
    return (distance / D + (distance % D == 0 ? 0 : 1));
}

int TestFrogJmp(int ans, int X, int Y, int D) {    
    std::cout << ((ans == solution (X, Y, D)) ? "PASS" : "FAIL") << std::endl;
    return 0;
}

int main () {
    
  //X = 10
  //Y = 85
  //D = 30
  //ans = 3
    TestFrogJmp(3, 10, 85, 30);
    //(1, 5, 2) return 2.
    TestFrogJmp(2, 1, 5, 2);

}