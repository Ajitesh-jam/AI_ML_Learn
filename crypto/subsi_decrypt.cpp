#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

string findAndReplaceChar(const string &str, char old_char, char new_char)
{
    string modified_str = str;
    replace(modified_str.begin(), modified_str.end(), old_char, new_char);
    return modified_str;
}

string decrypt(const string &encrypted_message)
{
    // Simple decryption logic: reverse the string
    string decrypted_message = encrypted_message;
    for (int i = 0; i <= 25; i++)
    {
        // decrypted_message = findAndReplaceChar(decrypted_message, 'a' + i, 'z' - i);
        // cout << "->" << char('a' + i) << "-> " << char('z' - i) << "' :\t\t " << decrypted_message << endl;
    }
    return decrypted_message;
}

int main()
{
    string encrypted_message = "iq ifcc vqqr fb rdq vfllcq na rdq cfjwhwz hr bnnb hcc hwwhbsqvqbre hwq vhlq";
    // cout << "Enter the encrypted message: ";
    // getline(cin, encrypted_message);

    // Decrypt the message
    string decrypted_message = decrypt(encrypted_message);
    cout << "Decrypted message: " << decrypted_message << endl;
    return 0;
}