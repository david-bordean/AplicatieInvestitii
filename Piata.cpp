#include "Piata.h"
#include "Exceptii.h"
#include <iomanip>

Piata::Piata()
    : actiuni(Actiune::getCatalog()),
      cryptos(Crypto::getCatalog()),
      obligatiuni(Obligatiune::getCatalog()),
      strategie(new StrategieAleatoare())
{}

Piata& Piata::getInstance() {
    static Piata instanta;
    return instanta;
}

Piata::~Piata() {
    delete strategie;
}

void Piata::setStrategie(IStrategiePret* s) {
    delete strategie;
    strategie = s;
}

void Piata::inregistreaza(IObserverPiata* obs) {
    observatori.push_back(obs);
}

void Piata::dezinregistreaza(IObserverPiata* obs) {
    for (int i = 0; i < (int)observatori.size(); i++) {
        if (observatori[i] == obs) {
            observatori.erase(observatori.begin() + i);
            return;
        }
    }
}

void Piata::actualizeazaPreturi() {
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "\n--- Actualizare preturi (zi noua) ---\n";
    for (auto& a : actiuni) {
        double procent = strategie->genereazaProcent();
        double inainte = a.getPretCurent();
        a.actualizeazaPret(procent);
        std::cout << "  " << a.getNume() << ": " << inainte
                  << " -> " << a.getPretCurent() << " RON\n";
    }
    for (auto& c : cryptos) {
        double procent = strategie->genereazaProcent();
        double inainte = c.getPretCurent();
        c.actualizeazaPret(procent);
        std::cout << "  " << c.getNume() << ": " << inainte
                  << " -> " << c.getPretCurent() << " RON\n";
    }
    for (auto& o : obligatiuni) {
        double procent = strategie->genereazaProcent();
        double inainte = o.getPretCurent();
        o.actualizeazaPret(procent);
        std::cout << "  " << o.getNume() << ": " << inainte
                  << " -> " << o.getPretCurent() << " RON\n";
    }
    // Notifica toti investitorii inregistrati (pattern Observer)
    for (auto* obs : observatori)
        obs->notificaActualizarePret(*this);
}

double Piata::getPret(const std::string& n) const {
    const Actiune* a = cautaDupaNumeIn(actiuni, n);
    if (a) return a->getPretCurent();
    const Crypto* c = cautaDupaNumeIn(cryptos, n);
    if (c) return c->getPretCurent();
    const Obligatiune* o = cautaDupaNumeIn(obligatiuni, n);
    if (o) return o->getPretCurent();
    return 0.0;
}

void Piata::cauta(const std::string& n) const {
    std::cout << std::fixed << std::setprecision(2);
    const Actiune* a = cautaDupaNumeIn(actiuni, n);
    if (a) {
        std::cout << "Actiune: " << a->getNume()
                  << " | Pret: " << a->getPretCurent() << " RON/actiune\n";
        return;
    }
    const Crypto* c = cautaDupaNumeIn(cryptos, n);
    if (c) {
        std::cout << "Crypto: " << c->getNume()
                  << " (" << c->getSimbol() << ")"
                  << " | Pret: " << c->getPretCurent() << " RON\n";
        return;
    }
    const Obligatiune* o = cautaDupaNumeIn(obligatiuni, n);
    if (o) {
        std::cout << "Obligatiune: " << o->getNume()
                  << " | Pret: " << o->getPretCurent() << " RON/unitate"
                  << " | Rata: " << o->getRataDobanzi() << "%"
                  << " | Scadenta: " << o->getAniiPanaLaScadenta() << " ani\n";
        return;
    }
    std::cout << "Instrumentul '" << n << "' nu a fost gasit in piata.\n";
}

void Piata::afiseazaCatalogNumerot() const {
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "\n=== INSTRUMENTE DISPONIBILE ===\n";
    int idx = 1;
    std::cout << "--- ACTIUNI ---\n";
    for (const auto& a : actiuni)
        std::cout << "  " << idx++ << ". " << a.getNume()
                  << " - " << a.getPretCurent() << " RON/actiune\n";
    std::cout << "--- CRYPTO ---\n";
    for (const auto& c : cryptos)
        std::cout << "  " << idx++ << ". " << c.getNume()
                  << " (" << c.getSimbol() << ")"
                  << " - " << c.getPretCurent() << " RON\n";
    std::cout << "--- OBLIGATIUNI ---\n";
    for (const auto& o : obligatiuni)
        std::cout << "  " << idx++ << ". " << o.getNume()
                  << " - " << o.getPretCurent() << " RON/unitate"
                  << " (rata: " << o.getRataDobanzi() << "%"
                  << ", " << o.getAniiPanaLaScadenta() << " ani)\n";
    std::cout << "  0. Anulare\n";
}

void Piata::afiseazaActiuni(std::ostream& out) const {
    out << std::fixed << std::setprecision(2);
    out << "\n--- ACTIUNI ---\n";
    for (const auto& a : actiuni)
        out << "  " << a.getNume()
            << " - " << a.getPretCurent() << " RON/actiune\n";
}

void Piata::afiseazaCrypto(std::ostream& out) const {
    out << std::fixed << std::setprecision(2);
    out << "\n--- CRYPTO ---\n";
    for (const auto& c : cryptos)
        out << "  " << c.getNume()
            << " (" << c.getSimbol() << ")"
            << " - " << c.getPretCurent() << " RON\n";
}

void Piata::afiseazaObligatiuni(std::ostream& out) const {
    out << std::fixed << std::setprecision(2);
    out << "\n--- OBLIGATIUNI ---\n";
    for (const auto& o : obligatiuni)
        out << "  " << o.getNume()
            << " - " << o.getPretCurent() << " RON/unitate"
            << " (rata: " << o.getRataDobanzi() << "%"
            << ", " << o.getAniiPanaLaScadenta() << " ani)\n";
}

const InstrumentFinanciar& Piata::getInstrument(int idx) const {
    int total = numarInstrumente();
    if (idx < 1 || idx > total)
        throw ExceptieIndiceInvalid(idx, total);
    int i = idx - 1;
    if (i < (int)actiuni.size()) return actiuni[i];
    i -= (int)actiuni.size();
    if (i < (int)cryptos.size()) return cryptos[i];
    i -= (int)cryptos.size();
    return obligatiuni[i];
}

int Piata::numarInstrumente() const {
    return (int)(actiuni.size() + cryptos.size() + obligatiuni.size());
}

std::ostream& operator<<(std::ostream& out, const Piata& p) {
    p.afiseazaActiuni(out);
    p.afiseazaCrypto(out);
    p.afiseazaObligatiuni(out);
    return out;
}
