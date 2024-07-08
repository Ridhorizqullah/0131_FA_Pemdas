#include <iostream>
using namespace std;

class MasukUniversitas {
private:
    int uangPendaftaran;
    int uangSemesterPertama;
    int uangBangunan;
    int totalBiaya;

public:
    MasukUniversitas() : uangPendaftaran(0), uangSemesterPertama(0), uangBangunan(0), totalBiaya(0) {}

    virtual void namaJalurMasuk() = 0; // Metode virtual murni
    virtual void input() = 0; // Metode virtual murni
    virtual void hitungTotalBiaya() = 0; // Metode virtual murni
    virtual void tampilkanTotalBiaya() = 0; // Metode virtual murni

    void setUangPendaftaran(int nilai) {
        this->uangPendaftaran = nilai;
    }

    int getUangPendaftaran() {
        return uangPendaftaran;
    }

    void setUangSemesterPertama(int nilai) {
        this->uangSemesterPertama = nilai;
    }

    int getUangSemesterPertama() {
        return uangSemesterPertama;
    }

    void setUangBangunan(int nilai) {
        this->uangBangunan = nilai;
    }

    int getUangBangunan() {
        return uangBangunan;
    }

    void setTotalBiaya(int nilai) {
        this->totalBiaya = nilai;
    }

    int getTotalBiaya() {
        return totalBiaya;
    }
};

class SNBT : public MasukUniversitas {
public:
    void namaJalurMasuk() override {
        cout << "Jalur Masuk: SNBT" << endl;
    }

    void input() override {
        int pendaftaran, semesterPertama, bangunan;
        cout << "Masukkan uang pendaftaran: ";
        cin >> pendaftaran;
        setUangPendaftaran(pendaftaran);

        cout << "Masukkan uang semester pertama: ";
        cin >> semesterPertama;
        setUangSemesterPertama(semesterPertama);

        cout << "Masukkan uang bangunan: ";
        cin >> bangunan;
        setUangBangunan(bangunan);
    }

    void hitungTotalBiaya() override {
        int total = getUangPendaftaran() + getUangSemesterPertama() + getUangBangunan();
        setTotalBiaya(total);
    }

    void tampilkanTotalBiaya() override {
        hitungTotalBiaya();
        int total = getTotalBiaya();
        cout << "Total Biaya: " << total << endl;

        string kategori;
        string rekomendasi;
        if (total > 40000000) {
            kategori = "Mahal";
            rekomendasi = "Tidak Direkomendasikan";
        }
        else if (total > 20000000) {
            kategori = "Sedang";
            rekomendasi = "Dipertimbangkan";
        }
        else {
            kategori = "Murah";
            rekomendasi = "Direkomendasikan";
        }

        cout << "Kategori: " << kategori << endl;
        cout << "Rekomendasi: " << rekomendasi << endl;
    }
};

class SNBP : public MasukUniversitas {
public:
    void namaJalurMasuk() override {
        cout << "Jalur Masuk: SNBP" << endl;
    }

    void input() override {
        int pendaftaran, semesterPertama;
        cout << "Masukkan uang pendaftaran: ";
        cin >> pendaftaran;
        setUangPendaftaran(pendaftaran);

        cout << "Masukkan uang semester pertama: ";
        cin >> semesterPertama;
        setUangSemesterPertama(semesterPertama);
    }

    void hitungTotalBiaya() override {
        int total = getUangPendaftaran() + getUangSemesterPertama();
        setTotalBiaya(total);
    }

    void tampilkanTotalBiaya() override {
        hitungTotalBiaya();
        int total = getTotalBiaya();
        cout << "Total Biaya: " << total << endl;

        string kategori;
        string rekomendasi;
        if (total > 20000000) {
            kategori = "Mahal";
            rekomendasi = "Tidak Direkomendasikan";
        }
        else if (total > 10000000) {
            kategori = "Sedang";
            rekomendasi = "Dipertimbangkan";
        }
        else {
            kategori = "Murah";
            rekomendasi = "Direkomendasikan";
        }

        cout << "Kategori: " << kategori << endl;
        cout << "Rekomendasi: " << rekomendasi << endl;
    }
};

int main() {
    int pilihan;
    MasukUniversitas* jalurMasuk = nullptr;

    while (true) {
        cout << "Pilih Jalur Masuk:\n1. SNBT\n2. SNBP\n3. Keluar\nPilih: ";
        cin >> pilihan;

        if (pilihan == 3) {
            break;
        }

        switch (pilihan) {
        case 1:
            jalurMasuk = new SNBT();
            break;
        case 2:
            jalurMasuk = new SNBP();
            break;
        default:
            cout << "Pilihan tidak valid. Silakan coba lagi." << endl;
            continue;
        }

        jalurMasuk->namaJalurMasuk();
        jalurMasuk->input();
        jalurMasuk->tampilkanTotalBiaya();

        delete jalurMasuk;
        jalurMasuk = nullptr;
    }

    return 0;
}
