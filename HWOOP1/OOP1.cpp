#include <iostream>
#include <cstdint>
using namespace std;

// Task 1
class Power
{
private:
    float a;
    float b;

public:

    Power() 
    {
        a = 3.4f;
        b = 2.5f;
    }

    void SetArgument(float i, float j)
    {
        a = i;
        b = j;
    }

    void Calculate() 
    {
        cout << pow(a, b) << endl;
    }
};

//Task 2

class RGBA
{
private:
    uint8_t m_red = 0;
    uint8_t m_green = 0;
    uint8_t m_blue = 0;
    uint8_t m_alpha = 255;

    public:
    
        RGBA(uint8_t r, uint8_t g, uint8_t b, uint8_t a)
        {
            m_red = r;
            m_green = g;
            m_blue = b;
            m_alpha = a;
        }

        void Print()
        {
            cout << static_cast<short>(m_red) << ", " << static_cast<short>(m_green) << ", " << static_cast<short>(m_blue) << ", " << static_cast<short>(m_alpha) << "." << endl;
        }
};

int main()
{
    {
        Power Data;
        Data.SetArgument(3.4f, 2.5f);
        Data.Calculate();
    }

    {
        short red, green, blue, alpha; // если указать тип uint8_t , если ввесли больше 1 цифры, то каждому из следующих значений присвоит по одной цифре из введенного числа. Почему?
        
        cout << "red: ";
        cin >> red ;
        cout << "green: ";
        cin >> green;
        cout << "blue: ";
        cin >> blue;
        cout << "alpha: ";
        cin >> alpha;
        
        RGBA rgba((uint8_t (red)), (uint8_t (green)), (uint8_t (blue)), (uint8_t (alpha)));
        rgba.Print();


    }
}
 
