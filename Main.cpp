#include <iostream>
#include <string>
#include <chrono>
#include <cstdlib>

using namespace std;
using namespace chrono;

string sentences[] = {
    "kukira kura kura ternyata kira kira",
    "everywhere terkewer kewer",
    "hidup kadang kidding",
    "susu saya susususupernova ",
    "jangan khawatir bila saya tidak bangun, saya akan bangun pada siang hari",
    "hidup berjalan seperti bakekok",
    "im itzy from ryujin",
    "dua tiga ayam berkokok, awokwokwok"
    "sehat selalu orang aring",
    "bakat terpendam yang sebaiknya dipendam",
    "biar apa? biarin",
    "makin kesini makin kesana",
    "didiemin malah diem",
    "gua liat liat lu liatin gua",
    "lu asik bang, asik sendiri"
  
};

string getRandomSentence() {
    int index = rand() % 5; 
    return sentences[index];
}

int main() {
    srand(time(0)); 
    
    cout << "===== TYPING SPEED TEST BY MALSKY =====\n";
    cout << "Ketik kalimat yang muncul secepat dan seakurat mungkin.\n\n";

    string targetSentence = getRandomSentence();
    cout << "Ketik ini:\n" << targetSentence << endl;
    
    auto startTime = high_resolution_clock::now();
    
    string userInput;
    cout << "\nMasukkan teks: ";
    getline(cin, userInput);

    auto endTime = high_resolution_clock::now();
    duration<double> elapsedTime = endTime - startTime;

    int wordCount = targetSentence.length() / 5; 
    double wpm = (wordCount / elapsedTime.count()) * 60;

    int correctChars = 0;
    for (size_t i = 0; i < min(userInput.length(), targetSentence.length()); i++) {
        if (userInput[i] == targetSentence[i]) {
            correctChars++;
        }
    }
    double accuracy = (double(correctChars) / targetSentence.length()) * 100;

    cout << "\n===== HASIL =====\n";
    cout << "Waktu: " << elapsedTime.count() << " detik\n";
    cout << "Kecepatan: " << wpm << " kata per menit (WPM)\n";
    cout << "Akurasi: " << accuracy << "%\n";

    return 0;
}
