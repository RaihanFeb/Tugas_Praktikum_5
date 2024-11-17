#include <iostream>
using namespace std;


const int GAJI_POKOK_PER_JAM = 7500;
const float TARIF_LEMBUR = 1.5;
const int UANG_MAKAN = 10000;
const int UANG_TRANSPORT = 13000;

int pokok(int jamKerja) {
    return jamKerja * GAJI_POKOK_PER_JAM;
}

int lembur(int jamKerja) {
    if (jamKerja > 8) {
        int jamLembur = jamKerja - 8;
        return jamLembur * GAJI_POKOK_PER_JAM * TARIF_LEMBUR;
    }
    return 0;
}

int makan(int jamKerja) {
    return (jamKerja >= 9) ? UANG_MAKAN : 0;
}

int transport(int jamKerja) {
    return (jamKerja >= 10) ? UANG_TRANSPORT : 0;
}

int main() {
    string NIP, nama;
    int jamKerja;

    cout << "Masukkan NIP karyawan: ";
    cin >> NIP;
    cout << "Masukkan Nama karyawan: ";
    cin.ignore();
    getline(cin, nama);
    cout << "Masukkan jumlah jam kerja: ";
    cin >> jamKerja;

    int gajiPokok = pokok(jamKerja);
    int gajiLembur = lembur(jamKerja);
    int uangMakan = makan(jamKerja);
    int uangTransport = transport(jamKerja);

    cout << "\n=== Rincian Gaji Harian ===\n";
    cout << "NIP            : " << NIP << endl;
    cout << "Nama           : " << nama << endl;
    cout << "Gaji Pokok     : Rp. " << gajiPokok << endl;
    cout << "Lembur         : Rp. " << gajiLembur << endl;
    cout << "Uang Makan     : Rp. " << uangMakan << endl;
    cout << "Uang Transport : Rp. " << uangTransport << endl;

    int totalGaji = gajiPokok + gajiLembur + uangMakan + uangTransport;
    cout << "Total Gaji     : Rp. " << totalGaji << endl;

    return 0;
}
