# Aplicație de investiții în C++

## Descriere

Acest proiect este o aplicație de consolă scrisă în C++ pentru simularea administrării unui portofoliu de investiții. Utilizatorul poate crea un cont de investitor, poate vizualiza instrumentele financiare disponibile pe piață, poate cumpăra și vinde active și poate urmări soldul, profitul și istoricul tranzacțiilor.

Aplicația include mai multe tipuri de instrumente financiare: acțiuni, criptomonede și obligațiuni.

## Scopul proiectului

Scopul proiectului este demonstrarea conceptelor de programare orientată pe obiect în C++, precum moștenirea, polimorfismul, clasele abstracte, template-urile, excepțiile personalizate și utilizarea unor design pattern-uri precum Singleton, Observer și Strategy.

## Funcționalități principale

- creare și conectare la conturi de investitori;
- vizualizarea pieței financiare;
- afișarea separată a acțiunilor, criptomonedelor și obligațiunilor;
- cumpărarea și vânzarea instrumentelor financiare;
- calcularea soldului liber, balanței totale și profitului;
- afișarea istoricului tranzacțiilor;
- actualizarea prețurilor instrumentelor financiare;
- notificarea investitorilor atunci când piața se schimbă.

## Clasele proiectului

### `InstrumentFinanciar`

Este clasa abstractă de bază pentru toate instrumentele financiare din aplicație. Aceasta conține informațiile comune precum numele instrumentului, prețul curent, prețul de cumpărare și cantitatea deținută.

Definește metode virtuale pentru calculul profitului, calculul valorii totale și clonarea obiectelor, permițând folosirea polimorfismului.

### `Actiune`

Reprezintă un instrument financiar de tip acțiune. Clasa calculează profitul pe baza diferenței dintre prețul curent și prețul de cumpărare.

De asemenea, poate încărca lista de acțiuni disponibile din fișierul `actiuni.in`.

### `Crypto`

Reprezintă un instrument financiar de tip criptomonedă. Pe lângă datele comune, această clasă reține și simbolul criptomonedei, de exemplu `BTC` sau `ETH`.

Clasa permite calculul profitului, afișarea informațiilor specifice și încărcarea criptomonedelor din fișierul `crypto.in`.

### `Obligatiune`

Reprezintă un instrument financiar de tip obligațiune. Pe lângă datele comune, clasa conține rata dobânzii și numărul de ani până la scadență.

Profitul este calculat luând în considerare atât diferența de preț, cât și dobânda acumulată.

### `Investitor`

Reprezintă utilizatorul aplicației. Clasa gestionează portofoliul investitorului, soldul liber și istoricul tranzacțiilor.

Permite cumpărarea și vânzarea instrumentelor financiare, adăugarea sau retragerea fondurilor și calcularea valorii totale a portofoliului.

Această clasă implementează interfața `IObserverPiata`, astfel încât portofoliul investitorului se poate actualiza atunci când piața își modifică prețurile.

### `Piata`

Reprezintă piața financiară a aplicației. Aceasta conține listele de acțiuni, criptomonede și obligațiuni disponibile.

Clasa permite căutarea instrumentelor, afișarea catalogului, actualizarea prețurilor și notificarea investitorilor înregistrați.

`Piata` folosește design pattern-ul Singleton, deoarece aplicația are o singură piață financiară principală.

### `IObserverPiata`

Este o interfață folosită pentru implementarea pattern-ului Observer.

Aceasta definește metoda prin care obiectele interesate, precum investitorii, sunt notificate atunci când piața își actualizează prețurile.

### `IStrategiePret`

Este o interfață folosită pentru implementarea pattern-ului Strategy.

Aceasta definește metoda prin care se generează procentul de modificare a prețurilor.

### `StrategieAleatoare`

Este o implementare concretă a interfeței `IStrategiePret`.

Această clasă generează o variație aleatoare a prețurilor, folosită atunci când aplicația simulează trecerea unei zile.

### `Tranzactie<T>`

Este o clasă template care reprezintă o tranzacție efectuată de investitor.

Reține numele instrumentului, tipul tranzacției, cantitatea și prețul. Este folosită pentru salvarea istoricului de cumpărări și vânzări.

### Clasele de excepții

Fișierul `Exceptii.h` conține clase de excepții personalizate pentru situațiile speciale din aplicație.

Acestea sunt folosite pentru validarea valorilor, verificarea fondurilor, verificarea cantităților și tratarea căutărilor de instrumente.

## Concepte OOP folosite

- clase și obiecte;
- moștenire;
- polimorfism;
- clase abstracte;
- metode virtuale;
- template-uri;
- supraincărcarea operatorilor;
- excepții personalizate;
- gestionarea dinamică a memoriei.

## Design patterns folosite

### Singleton

Folosit în clasa `Piata`, pentru a exista o singură instanță a pieței financiare în aplicație.

### Observer

Folosit pentru notificarea investitorilor atunci când prețurile din piață se actualizează.

### Strategy

Folosit pentru separarea algoritmului de modificare a prețurilor de logica principală a pieței.

## Fișiere de intrare

Aplicația folosește fișiere text pentru încărcarea instrumentelor financiare:

```text
actiuni.in
crypto.in
obligatiuni.in
