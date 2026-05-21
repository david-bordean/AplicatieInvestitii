#pragma once
#include <string>
#include <iostream>

// T = tipul valorii monetare (ex: double)
template<typename T>
class Tranzactie {
    std::string numeInstrument;
    std::string tip;
    int cantitate;
    T pret;

public:
    Tranzactie(const std::string& n, const std::string& t, int c, T p)
        : numeInstrument(n), tip(t), cantitate(c), pret(p) {}

    std::string getNume() const { return numeInstrument; }
    std::string getTip() const { return tip; }
    int getCantitate() const { return cantitate; }
    T getPret() const { return pret; }
    void setCantitate(int c) { cantitate = c; }

    T valoareTotala() const { return pret * cantitate; }

    friend std::ostream& operator<<(std::ostream& out, const Tranzactie<T>& t) {
        out << "Tranzactie: " << t.tip
            << " " << t.cantitate << " unitati " << t.numeInstrument
            << " la pret " << t.pret;
        return out;
    }
};
