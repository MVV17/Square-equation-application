#include <iostream>

using namespace std;
class equation
{
private:
    double a = 0,
        b = 0,
        c = 0,
        d = 0,
        x1 = 0,
        x2 = 0,
        x1i = 0,
        x2i = 0;
public:
    equation(double a, double b, double c)
    {
        set(a, b, c);
    }
    void set(double a, double b, double c)
    {
        this->a = a;
        this->b = b;
        this->c = c;
    }
    void solve()
    {
        if (a != 0)
        {
            d = pow(b, 2) - 4 * a * c;
            if (d > 0)
            {
                x1 = (-b + pow(d, 0.5)) / (2 * a);
                x2 = (-b - pow(d, 0.5)) / (2 * a);
                getSolution(1);
            }
            else if (d == 0)
            {
                x1 = -b / (2 * a);
                x2 = x1;
                getSolution(1);
            }
            else
            {
                x1 = (-b / 2 * a);
                x1i = pow(-d, 0.5) / (2 * a);
                x2 = (-b / 2 * a);
                x2i = -pow(-d, 0.5) / (2 * a);
                getSolution(3);
            }
        }
        else if (b != 0)
        {
            x1 = -c / b;
            getSolution(2);
        }
        else if (c != 0)
            cout << "No roots";
        else
            cout << "The identity 0 = 0";
    }
    void getSolution(int a)
    {
        if (a == 1)
        {
            toZero();
            cout << "The result is\n";
            cout << "x1 = " << x1 << endl << "x2 = " << x2;
        }
        if (a == 2)
        {
            toZero();
            cout << "The result is\n";
            cout << "x = " << x1;
        }
        if (a == 3)
        {
            toZero();
            cout << "The result is\n";
            cout << "x1 = " << x1 << " + " << x1i << "i" << endl << "x2 = " << x2 << " - " << -x2i << "i";
        }
    }
    void toZero()
    {
        if (abs(x1) < 10e-6)
            x1 = 0;
        if (abs(x2) < 10e-6)
            x2 = 0;
    }
};

int main()
{
    setlocale(LC_ALL, "Russian");
    while (true)
    {
        double a, b, c;
        char r;
        cout << "Input coefficients a, b, c \n";
        cout << "a = ";
        cin >> a;
        cout << "b = ";
        cin >> b;
        cout << "c = ";
        cin >> c;
        equation eq = equation(a, b, c);
        eq.solve();
        cout << "\n\n\nDo you want to calculate another equation? (y/n) ";
        cin >> r;
        while (!(r == 'Y' || r == 'y' || r == 'N' || r == 'n'))
        {
            cout << "input y if you want to continue or n if you want to exit\n";
            cin >> r;
        }
        if (r == 'N' || r == 'n')
            return 0;
    }

}

