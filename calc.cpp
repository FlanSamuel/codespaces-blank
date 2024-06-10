#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
using namespace std;


// 加法函數
void add(const vector<int>& a, const vector<int>& b, vector<int>& c) 
{
    int maxLength = max(a.size(), b.size());// 估計數字大小
    c.resize(maxLength + 1);
    vector<int> copyA(a.begin(), a.end()); // 先複製A的內容
    vector<int> copyB(b.begin(), b.end()); // 複製B的內容
    if (maxLength==a.size())
    {
        int zero = a.size() - b.size(); // 計算兩個的長度差
        copyB.insert(copyB.begin(), zero, 0); // 前面補0
    }
    else 
    {
        int zero = b.size() - a.size(); 
        copyA.insert(copyA.begin(), zero, 0); 
    }
    

    int carry = 0; // 進位

    // 從最低位開始逐位相加
    for (int i = c.size() - 1; i > 0; --i) 
    {
        c[i] = copyA[i-1] + copyB[i-1] + carry;
        if (c[i] >= 10000) 
        {
            c[i] -= 10000;
            carry = 1;
        } 
        else 
        {
            carry = 0;
        }
    }
    c[0] = carry;

    // 移除前面可能有的0
    while (c.size() > 1 && c[0] == 0)
    {
        c.erase(c.begin());
    }

}


// 減法函數
void sub(const vector<int>& a, const vector<int>& b, vector<int>& c) 
{
    int maxLength = max(a.size(), b.size()); 
    c.resize(maxLength); 
    vector<int> copyA(a.begin(), a.end()); // 先複製A的內容
    vector<int> copyB(b.begin(), b.end()); // 複製B的內容
    if (maxLength==a.size())
    {
        int zero = a.size() - b.size(); // 計算兩個的長度差
        copyB.insert(copyB.begin(), zero, 0); // 前面補0
    }
    else 
    {
        int zero = b.size() - a.size(); 
        copyA.insert(copyA.begin(), zero, 0); 
    }

    int borrow = 0; // 借位

    // 從最低位開始逐位相減
    for (int i = c.size() - 1; i >= 0; --i) 
    {
        c[i] = copyA[i] - copyB[i] - borrow;
        if (c[i] < 0) 
        {
            c[i] += 10000;
            borrow = 1;
        }
        else 
        {
            borrow = 0;
        }
    }

    // 移除前面可能有的0
    while (c.size() > 1 && c[0] == 0) 
    {
        c.erase(c.begin()); 
    }
}


//分割函數
void split(const string& line, vector<int>& output) 
{
    int length = line.length();
    for (int i = length; i > 0; i -= 4) {
        int startPos = max(0, i - 4);
        string chunk = line.substr(startPos, i - startPos);
        output.push_back(stoi(chunk));
    }
    reverse(output.begin(), output.end());
}


//獲取函數
void getinput(vector<int> &output)  
{
    string line;
    getline(cin, line);
    split(line, output); // 將用戶輸入的數字按照每4位分割並存入數組中
}



int main() 
{
    vector<int> a, b;

    cout << "輸入數字 a:\n";
    getinput(a);

    cout << "輸入數字 b:\n";
    getinput(b);

    cout << "數字 a: ";
    for (int in : a)
        cout << setw(4) << setfill('0') << in;
    cout << endl;

    cout << "數字 b: ";
    for (int in : b)
        cout << setw(4) << setfill('0') << in;
    cout << endl;


    vector<int> c;

    add(a, b, c); // 加法
        cout << "a + b = ";
        for (int num : c) cout << setw(4) << setfill('0') << num;
            cout << endl;
    
    sub(a, b, c); // 減法
        cout << "a - b = ";
        for (int num : c) cout << setw(4) << setfill('0') << num;
            cout << endl;

    return 0;
}