#include <iostream>
#include <vector>
#include <algorithm>
#include <stdexcept>

using namespace std;

class Divide {
    int _divisor;

public:
    explicit Divide(int divisor) : _divisor(divisor) {}
    void operator()(int &number) {
        if (_divisor == 0) {
            throw invalid_argument("Division durch 0 ist nicht erlaubt");
        }
        number /= _divisor;
    }
};

int main() {
    vector<int> numbers = {12, 24, 36, 48, 60, 72, 84, 96};

    try {
        Divide divideBySix(6);
        for_each(numbers.begin(), numbers.end(), divideBySix);
    } catch (const invalid_argument &e) {
        cout << e.what() << endl;
    }

    for (int number : numbers) {
        cout << number << " ";
    }
    cout << endl;

    return 0;
}
