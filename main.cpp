#include <iostream>
using namespace std;

const int maxValue=99;
struct History{
    double num1, num2, res;
    char op;
};
History equation[maxValue];
int historyRecord =0;

double add(double num1, double num2) {
    return num1 + num2;
}

double subtract(double num1, double num2) {
    return num1 - num2;
}

double multiply(double num1, double num2) {
    return num1 * num2;
}

double divide(double num1, double num2) {
    if (num2 == 0) {
        cout << "Undefined" << endl;
        return 0.0;
    }
    return num1 / num2;
}
void ignore(){
    cin.clear();
    cin.ignore(132, '\n');
}

void showHistory(){
    cout << "\nHistory of calculations:\n";
    for (int i=0; i< historyRecord; i++) {
    cout << equation[i].num1 <<" "<< equation[i].op<<" "<< equation[i].num2 <<" = " << equation[i].res << " " <<&equation[i].res << endl;
}
}

int main() {

    double num1, num2;
    char op, back;

    do {
        system("CLS");
        cout << "\t\t#CALCULATOR#" << endl;
        cout << endl << endl;


		cout <<"Enter equation: ";
		while (true){cin >> num1 >> op >> num2;
		if (cin.fail()){
            cout << "Invalid input. Please try again." <<endl;
            ignore();
        else break;
		}

		double result;

        switch (op){
            case '+':
                result = add(num1, num2);
                cout << num1 << " + " << num2 << " = " << result << endl;
                break;
            case '-':
                result = subtract(num1, num2);
                cout << num1 << " - " << num2 << " = " << result << endl;
                break;
            case '*':
                result = multiply(num1, num2);
                cout << num1 << " * " << num2 << " = " << result << endl;
                break;
            case '/':
                result = divide(num1, num2);
                if (result != 0.0) {
                    cout << num1 << " / " << num2 << " = " << result << endl;
                }
                break;
            default:
                cout << "Invalid operator" << endl;
        }
        equation[historyRecord].num1 =num1;
        equation[historyRecord].num2 =num2;
        equation[historyRecord].op =op;
        equation[historyRecord].res =result;
        historyRecord++;
        showHistory();


        cout << "\nContinue [Y/N]: ";
        while (true) {
            cin >> back;
            if (back != 'Y' && back != 'y' && back != 'N' && back != 'n') {
                cout << "Invalid input. Please enter Y or N: ";
                ignore();

            } else {
                break;
            }
        }
        cout << endl << endl;
    } while (back == 'y' || back == 'Y');
    cout << endl;

    return 0;
}
