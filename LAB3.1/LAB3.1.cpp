#include <iostream>
#include <Windows.h>
#include "Car.h"
#include "Lorry.h"

using namespace std;

Car TestSubstitution(Car c) {
    cout << "\n[Ï³äñòàíîâêà] Ôóíêö³ÿ îòðèìàëà áàçîâèé êëàñ Car. Ìàðêà: " << c.GetBrand() << endl;
    c.ChangePower(100.0);
    return c;
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    cout << "=== 1. Ð²ÇÍ² ÑÏÎÑÎÁÈ ÑÒÂÎÐÅÍÍß ÎÁ'ªÊÒ²Â ===" << endl;

    Lorry lorry1("Volvo", 6, 400.0, 20.0);
    cout << "Ñòâîðåíî lorry1:\n" << lorry1 << endl;

    Lorry lorry2 = lorry1;
    cout << "\nÑòâîðåíî lorry2 (êîï³ÿ lorry1):\n" << lorry2 << endl;

    cout << "\n=== 2. ÂÈÊÎÐÈÑÒÀÍÍß ÌÅÒÎÄ²Â ===" << endl;
    lorry2.ReassignBrand("Scania");
    lorry2.ChangeCapacity(25.0);
    cout << "Çì³íåíî lorry2 (ìàðêà òà âàíòàæîï³äéîìí³ñòü):\n" << lorry2 << endl;

    cout << "\n=== 3. ÄÅÌÎÍÑÒÐÀÖ²ß ÏÐÈÍÖÈÏÓ Ï²ÄÑÒÀÍÎÂÊÈ ===" << endl;

    Car substitutedCar = TestSubstitution(lorry1);
    cout << "Ðåçóëüòàò, ÿêèé ïîâåðíóëà ôóíêö³ÿ (âæå ÿê îá'ºêò Car): \n" << substitutedCar << endl;

    cout << "\n=== 4. ÑÒÂÎÐÅÍÍß ÌÀÑÈÂÓ ÒÀ ÂÂÅÄÅÍÍß Ç ÊËÀÂ²ÀÒÓÐÈ ===" << endl;

    const int size = 2;
    Lorry fleet[size]; 

    for (int i = 0; i < size; i++) {
        cout << "\n--- Çàïîâíåííÿ âàíòàæ³âêè #" << (i + 1) << " ---" << endl;
        cin >> fleet[i]; 
    }

    cout << "\n=== ÂÀØ ÀÂÒÎÏÀÐÊ (ÂÈÂ²Ä ÌÀÑÈÂÓ) ===" << endl;
    for (int i = 0; i < size; i++) {
        cout << "[" << (i + 1) << "] " << (string)fleet[i] << endl;
    }

    return 0;
}