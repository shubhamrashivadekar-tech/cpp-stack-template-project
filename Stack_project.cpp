#include <iostream>
#include <string>
using namespace std;

#define MAX_SIZE 5

template <class Type>
class Stack
{
private:
    Type arr[MAX_SIZE];
    int top;

public:
    Stack()
    {
        top = -1;
    }

    void push()
    {
        if (top == MAX_SIZE - 1)
        {
            cout << "Stack Overflow" << endl;
        }
        else
        {
            Type value;
            cout << "Enter element: ";
            cin >> value;

            top++;
            arr[top] = value;

            cout << "Element pushed successfully" << endl;
        }
    }

    void pop()
    {
        if (top == -1)
        {
            cout << "Stack Underflow" << endl;
        }
        else
        {
            cout << "Popped element: "
                 << arr[top] << endl;
            top--;
        }
    }

    void display()
    {
        if (top == -1)
        {
            cout << "Stack is Empty" << endl;
        }
        else
        {
            cout << "Stack elements (TOP to Bottom): ";
            for (int i = top; i >= 0; i--)
            {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
    }
};

int main()
{
    Stack<int> intStack;
    Stack<char> charStack;
    Stack<float> floatStack;
    Stack<double> doubleStack;
    Stack<string> stringStack;

    bool used[5] = {false, false, false, false, false};
    int invalidCount = 0;
    int choice;

    while (true)
    {
        cout << "\n===== MAIN MENU =====" << endl;
        cout << "1. Integer Stack" << endl;
        cout << "2. Character Stack" << endl;
        cout << "3. Float Stack" << endl;
        cout << "4. Double Stack" << endl;
        cout << "5. String Stack" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";

        if (!(cin >> choice))
        {
            cin.clear();
            cin.ignore(10000, '\n');
            choice = 0;
        }

        if (choice < 1 || choice > 6)
        {
            invalidCount++;
            cout << "Invalid choice. Try again." << endl;

            if (invalidCount == 3)
            {
                cout << "Maximum invalid attempts reached."
                     << endl;
                break;
            }
            continue;
        }

        invalidCount = 0;

        if (choice == 6)
        {
            cout << "Program terminated." << endl;
            break;
        }

        int index = choice - 1;

        if (used[index])
        {
            int option;

            cout << "\n1. Continue with old stack" << endl;
            cout << "2. Create new stack" << endl;
            cout << "Enter your choice: ";

            if (!(cin >> option))
            {
                cin.clear();
                cin.ignore(10000, '\n');
                option = 0;
            }

            if (option != 1 && option != 2)
            {
                invalidCount++;
                cout << "Invalid choice. Try again." << endl;

                if (invalidCount >= 3)
                {
                    cout << "Maximum invalid attempts reached."
                         << endl;
                    break;
                }
                continue;
            }

            invalidCount = 0;

            if (option == 2)
            {
                switch (choice)
                {
                    case 1: intStack = Stack<int>(); break;
                    case 2: charStack = Stack<char>(); break;
                    case 3: floatStack = Stack<float>(); break;
                    case 4: doubleStack = Stack<double>(); break;
                    case 5: stringStack = Stack<string>(); break;
                }
                cout << "New empty stack created." << endl;
            }
        }

        used[index] = true;

        while (true)
        {
            cout << "\n===== STACK MENU =====" << endl;
            cout << "1. Push" << endl;
            cout << "2. Pop" << endl;
            cout << "3. Display Stack" << endl;
            cout << "4. Main Menu" << endl;
            cout << "Enter your choice: ";

            if (!(cin >> choice))
            {
                cin.clear();
                cin.ignore(10000, '\n');
                choice = 0;
            }

            if (choice < 1 || choice > 4)
            {
                invalidCount++;
                cout << "Invalid choice. Try again." << endl;

                if (invalidCount >= 3)
                {
                    cout << "Maximum invalid attempts reached."
                         << endl;
                    return 0;
                }
                continue;
            }

            invalidCount = 0;

            if (choice == 4)
                break;

            switch (index)
            {
                case 0:
                    if (choice == 1) intStack.push();
                    else if (choice == 2) intStack.pop();
                    else intStack.display();
                    break;

                case 1:
                    if (choice == 1) charStack.push();
                    else if (choice == 2) charStack.pop();
                    else charStack.display();
                    break;

                case 2:
                    if (choice == 1) floatStack.push();
                    else if (choice == 2) floatStack.pop();
                    else floatStack.display();
                    break;

                case 3:
                    if (choice == 1) doubleStack.push();
                    else if (choice == 2) doubleStack.pop();
                    else doubleStack.display();
                    break;

                case 4:
                    if (choice == 1) stringStack.push();
                    else if (choice == 2) stringStack.pop();
                    else stringStack.display();
                    break;
            }
        }
    }

    return 0;
}
